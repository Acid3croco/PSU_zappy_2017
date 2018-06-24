/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** send_client
*/

#include "server.h"

/**
* @brief init_ress_client initalize the inventory of the client
*
* @param client
*/

void init_ress_client(cl_t *client)
{
	client->is_inc = 0;
	client->lv = 1;
	client->inext = NULL;
	client->ress.deraumere = 0;
	client->ress.food = 9;
	client->ress.linemate = 0;
	client->ress.mendiane = 0;
	client->ress.phiras = 0;
	client->ress.sibur = 0;
	client->ress.thystame = 0;
}

/**
* @brief send_new_client send information to the client
*
* @param server
* @param team
* @param client
* @param cmd
*/

void send_new_client(srv_t *server, tm_t *team, cl_t *client, char **cmd)
{
	int fd = server->cnt->events[server->cnt->a].data.fd;

	dprintf(client->fd, "%i\n", server->clientsNB - team->nb_ia);
	dprintf(client->fd, "%i %i\n", server->width, server->height);
	if (server->map->fd != -2)
		dprintf(server->map->fd, "new_c %i %s %i %i %i\n", client->fd, \
			client->team, client->x, client->y, client->look);
	printf(MAGENTA"Adding %i to the team %s\n"RESET, fd, cmd[0]);
	printf(MAGENTA"There is %i ia in the team %s\n"RESET,
		team->nb_ia, cmd[0]);
}