/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** map functions
*/

#include "server.h"

/**
* @brief init_map initialize and create the map
*
* @param server
*/

void init_map(t_srv *server)
{
	server->map = malloc(sizeof(t_map));

	if (server->map == NULL)
		quit(server);
	server->map->fd = 0;
	server->map->fs = NULL;
	server->map->box = NULL;
}