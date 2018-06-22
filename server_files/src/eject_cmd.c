/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** eject functions
*/

#include "server.h"

int eject_cmd(srv_t *server, char **cmd, cl_t *client)
{
	(void)server;
	(void)cmd;
	dprintf(client->fd, "ok\n");
	return (0);
}