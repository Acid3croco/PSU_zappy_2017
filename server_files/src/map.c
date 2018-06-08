/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** map functions
*/

#include "server.h"

void init_map(t_srv *server)
{
	server->map = malloc(sizeof(t_map));

	if (server->map == NULL)
		quit(server);
	server->map->fd = 0;
}