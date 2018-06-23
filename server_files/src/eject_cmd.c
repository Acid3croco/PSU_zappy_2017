/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** eject functions
*/

#include "server.h"

/**
* @brief eject_cl eject a client from a box
*
* @param server
* @param client
* @param cl
*/

void eject_cl(srv_t *server, cl_t *client, cl_t *cl)
{
	int k = 0;

	switch (client->look) {
		case 0: go_on(server, cl, client->x, client->y - 1);
			k = 1 + 2 * cl->look;
			break;
		case 1: go_on(server, cl, client->x + 1, client->y);
			k = 7 + 2 * cl->look;
			break;
		case 2: go_on(server, cl, client->x, client->y + 1);
			k = 5 + 2 * cl->look;
			break;
		case 3: go_on(server, cl, client->x - 1, client->y);
			k = 3 + 2 * cl->look;
			break;
	}
	dprintf(server->map->fd, "Eject %i %i %i\n", client->fd, \
		client->x, client->y);
	dprintf(cl->fd, "eject: %i\n", k);
}

/**
* @brief eject_cmd eject all player from a box
*
* @param server
* @param cmd
* @param client
* @return int
*/

int eject_cmd(srv_t *server, char **cmd, cl_t *client)
{
	box_t *box = server->map->box[client->y][client->x];

	(void)cmd;
	for (cl_t *cl = box->client; cl; cl = cl->mnext) {
		if (client->fd != cl->fd)
			eject_cl(server, client, cl);
	}
	dprintf(client->fd, "ok\n");
	return (0);
}