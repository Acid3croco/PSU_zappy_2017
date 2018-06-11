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
	printf(RED"%s: Unknow team name\n"RESET, cmd[0]);
	close(server->cnt->events[server->cnt->a].data.fd);
	fclose(fs);
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
		free_tab(cmd);
		quit(server);
	}
	new->team = malloc(strlen(cmd[0]) + 1);
	strcpy(new->team, cmd[0]);
	new->fs = fs;
	new->fd = fd;
	new->inventory = NULL;
	new->next = team->client;
	team->client = new;
	team->nb_ia += 1;
	printf(MAGENTA"Adding %i to the team %s\n"RESET, fd, cmd[0]);
	printf(MAGENTA"There is %i ia in the team %s\n"RESET,
		team->nb_ia, cmd[0]);
}

/**
* @brief add_map add the fd of the map
*
* @param server
* @param fs
*/

void add_map(srv_t *server, FILE *fs)
{
	server->map->fs = fs;
	server->map->fd = server->cnt->events[server->cnt->a].data.fd;
	dprintf(server->map->fd, "mbape\n");
	return;
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
	if (done == 0)
		wrong_teamname(server, cmd, fs);
	else {
		add_cli(server, cmd, fs, tmp);
	}
}