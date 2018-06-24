/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** take and set command
*/

#include "server.h"

/**
* @brief send_box send the current ressources on the given box
*
* @param box
* @param x
* @param y
* @param fd
*/

void send_box(box_t *box, int x, int y, int fd)
{
	dprintf(fd, "/%i;%i:%iD%iF%iL%iM%iP%iS%iT\n", x, y,
		box->ress.deraumere,
		box->ress.food,
		box->ress.linemate,
		box->ress.mendiane,
		box->ress.phiras,
		box->ress.sibur,
		box->ress.thystame);
}

/**
* @brief take_cmd execute the take command adding one ressource to the client
*
* @param server
* @param cmd
* @param client
* @return int
*/

int take_cmd(srv_t *server, char **cmd, cl_t *client)
{
	if (cmd[1] != NULL)
		if (sel_obj_cmd(server->map->box[client->y][client->x],
				client, cmd, 1) != 0)
			dprintf(client->fd, "ko\n");
	if (server->map->fd != -2)
		send_box(server->map->box[client->y][client->x],
			client->x, client->y, server->map->fd);
	return (0);
}

/**
* @brief set_cmd execute the set command adding one ressource to the box
*
* @param server
* @param cmd
* @param client
* @return int
*/

int set_cmd(srv_t *server, char **cmd, cl_t *client)
{
	if (cmd[1] != NULL)
		if (sel_obj_cmd(server->map->box[client->y][client->x],
				client, cmd, -1) != 0)
			dprintf(client->fd, "ko\n");
	if (server->map->fd != -2)
		send_box(server->map->box[client->y][client->x],
			client->x, client->y, server->map->fd);
	return (0);
}