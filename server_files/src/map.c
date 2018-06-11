/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** map functions
*/

#include "server.h"

/**
* @brief create_map create the map and put ressources on it
*
* @param server
*/

void create_map(t_srv *server)
{
	server->map->box = malloc(server->height * server->width *
					sizeof(t_box));

	if (server->map->box == NULL)
		quit(server);
}

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