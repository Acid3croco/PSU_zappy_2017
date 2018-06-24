/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** turning functions
*/

#include "server.h"

/**
* @brief left_cmf turn the client to the left
*
* @param server
* @param cmd
* @param fs
* @return int
*/

int left_cmd(srv_t *server, char **cmd, cl_t *client)
{
	(void)server;
	(void)cmd;

	client->look = client->look + 1 % 4;
	if (client->look > 3)
		client->look -= 4;
	if (server->map->fd != -2)
		dprintf(server->map->fd, "Left %i\n", client->fd);
	dprintf(client->fd, "ok\n");
	return (0);
}

/**
* @brief right_cmd turn the client to the right
*
* @param server
* @param cmd
* @param fs
* @return int
*/

int right_cmd(srv_t *server, char **cmd, cl_t *client)
{
	(void)server;
	(void)cmd;

	client->look = client->look - 1 % 4;
	if (client->look < 0)
		client->look += 4;
	if (server->map->fd != -2)
		dprintf(server->map->fd, "Right %i\n", client->fd);
	dprintf(client->fd, "ok\n");
	return (0);
}