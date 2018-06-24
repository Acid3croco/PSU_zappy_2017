/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** fork command finctions
*/

#include "server.h"

/**
* @brief find_egg find the first egg
*
* @param team
* @return egg_t*
*/

egg_t *find_egg(tm_t *team)
{
	if (team && team->egg)
		return (team->egg);
	return (NULL);
}

/**
* @brief put_egg_on_map put the client on the egg
*
* @param server
* @param new
* @param team
*/

void put_egg_on_map(srv_t *server, cl_t *new, tm_t *team)
{
	unsigned int seed = 0;
	egg_t *egg = find_egg(team);

	if (egg == NULL)
		quit(server);
	new->x = egg->x;
	new->y = egg->y;
	new->look = my_rand(&seed) % 4;
	new->mnext = server->map->box[new->y][new->x]->client;
	server->map->box[new->y][new->x]->client = new;
	printf("pos egg %i %i\n", egg->x, egg->y);
	delete_egg(server, team, egg);
}

/**
* @brief add_cli_egg add a client from a egg
*
* @param server
* @param cmd
* @param fs
* @param team
*/

void add_cli_egg(srv_t *server, char **cmd, FILE *fs, tm_t *team)
{
	cl_t *new = malloc(sizeof(cl_t));
	int fd = server->cnt->events[server->cnt->a].data.fd;

	if (new == NULL) {
		fclose(fs);
		free_tab(cmd);
		quit(server);
	}
	new->team = malloc(strlen(cmd[0]) + 1);
	strcpy(new->team, cmd[0]);
	new->fs = fs;
	new->fd = fd;
	new->input = NULL;
	new->nb_inpt = 0;
	new->next = team->client;
	team->client = new;
	team->nb_ia += 1;
	init_ress_client(new);
	put_egg_on_map(server, new, team);
	send_new_client(server, team, new, cmd);
}

/**
* @brief new_egg create the egg
*
* @param server
* @param client
* @return egg_t*
*/

egg_t *new_egg(srv_t *server, cl_t *client)
{
	egg_t *new = malloc(sizeof(egg_t));

	if (new == NULL)
		quit(server);
	new->x = client->x;
	new->y = client->y;
	new->next = NULL;
	gettimeofday(&new->start, NULL);
	return (new);
}

/**
* @brief fork_cmd execute the fork cmd to create a new egg
*
* @param server
* @param cmd
* @param client
* @return int
*/

int fork_cmd(srv_t *server, char **cmd, cl_t *client)
{
	tm_t *team = find_team(server, client->team);

	(void)cmd;
	if (team->egg == NULL) {
		team->egg = new_egg(server, client);
	}
	else {
		for (; team->next != NULL; team = team->next);
		team->egg->next = new_egg(server, client);
	}
	team->nb_egg += 1;
	dprintf(client->fd, "ok\n");
	return (0);
}