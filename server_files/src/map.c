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

void create_map(srv_t *server)
{
	server->map->box = malloc(server->height * server->width *
					sizeof(box_t));

	if (server->map->box == NULL)
		quit(server);
}

/**
* @brief inimap_t initialize and create the map
*
* @param server
*/

void inimap_t(srv_t *server)
{
	server->map = malloc(sizeof(map_t));

	if (server->map == NULL)
		quit(server);
	server->map->fd = 0;
	server->map->fs = NULL;
	server->map->box = NULL;
}