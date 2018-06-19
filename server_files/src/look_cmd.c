/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** look command functions
*/

#include "server.h"

int look_cmd(srv_t *server, char **cmd, cl_t *client)
{
	(void)server;
	(void)cmd;

	printf("Look!\n");
	dprintf(client->fd, "Look\n");
	return (0);
}