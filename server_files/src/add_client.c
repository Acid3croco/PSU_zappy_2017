/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** add a client to his team
*/

#include "server.h"

/**
* @brief wrong_teamname close the fd of the client and free cmd
*
* @param server
* @param cmd
* @param fs
*/

void wrong_teamname(srv_t *server, char **cmd, FILE *fs)
{
	printf(RED"%s: Unknow team name or team is full\n"RESET, cmd[0]);
	close(server->cnt->events[server->cnt->a].data.fd);
	fclose(fs);
}

/**
* @brief put_cli_on_map put the new client ramdomly on the map
*
* @param server
* @param team
* @param new
*/

void put_cli_on_map(srv_t *server, cl_t *new)
{
	unsigned int seed = 0;

	new->x = my_rand(&seed) % server->width;
	new->y = my_rand(&seed) % server->height;
	new->look = my_rand(&seed) % 4;
	new->mnext = server->map->box[new->y][new->x]->client;
	server->map->box[new->y][new->x]->client = new;
}

/**
* @brief add_cli add the client to his team
*
* @param server
* @param cmd
* @param fs
*/

void add_cli(srv_t *server, char **cmd, FILE *fs, tm_t *team)
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
	new->next = team->client;
	team->client = new;
	team->nb_ia += 1;
	init_ress_client(new);
	put_cli_on_map(server, new);
	send_new_client(server, team, new, cmd);
}

/**
* @brief add_map add the fd of the map
*
* @param server
* @param fs
*/

void add_map(srv_t *server, FILE *fs)
{
	char *map = calloc(sizeof(char), server->height * server->width * 20);

	server->map->fs = fs;
	server->map->fd = server->cnt->events[server->cnt->a].data.fd;
	for (int y = 0; y < server->height; y++) {
		for (int x = 0; x < server->width; x++) {;
			sprintf(map, "%s/%i;%i:%iD%iF%iL%iM%iP%iS%iT",
				map, x, y,
				server->map->box[y][x]->ress.deraumere,
				server->map->box[y][x]->ress.food,
				server->map->box[y][x]->ress.linemate,
				server->map->box[y][x]->ress.mendiane,
				server->map->box[y][x]->ress.phiras,
				server->map->box[y][x]->ress.sibur,
				server->map->box[y][x]->ress.thystame);
		}
	}
	dprintf(server->map->fd, "%s", map);
	free(map);
}

/**
* @brief add_cli_to_team find the team of the client
*
* @param server
* @param cmd
* @param fs
*/

void add_cli_to_team(srv_t *server, char **cmd, FILE *fs)
{
	tm_t *tmp;
	int done = 0;

	if (strcmp(cmd[0], "GMAP") == 0) {
		add_map(server, fs);
		return;
	}
	for (tmp = server->team; tmp->next != NULL; tmp = tmp->next) {
		if (strcmp(cmd[0], tmp->name) == 0) {
			done = 1;
			break;
		}
	}
	if (done == 1 && server->clientsNB - tmp->nb_ia > 0)
		add_cli(server, cmd, fs, tmp);
	else
		wrong_teamname(server, cmd, fs);
}