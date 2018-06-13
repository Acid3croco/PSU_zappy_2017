/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** map functions
*/

#include "server.h"

/**
* @brief fill_box fill the box with ressources depending on their rarity
*
* @param box
*/

void fill_box(box_t *box)
{
	unsigned int seed = 0;

	box->ress.deraumere = my_rand(&seed) %2;
	box->ress.food = my_rand(&seed) % 2;
	box->ress.linemate = my_rand(&seed) % 2;
	box->ress.mendiane = my_rand(&seed) % 2;
	box->ress.phiras = my_rand(&seed) % 2;
	box->ress.sibur = my_rand(&seed) % 2;
	box->ress.thystame = my_rand(&seed) % 2;
	box->client = NULL;
}

/**
* @brief fill_map fill all the box in the map by chosing a random box
*
* @param server
*/

void fill_map(srv_t *server)
{
	unsigned int seed = 0;
	int x = 0;
	int y = 0;

	for (int a = 0; a < server->height * server->width; a++) {
		x = my_rand(&seed) % server->width;
		y = my_rand(&seed) % server->height;
		fill_box(server->map->box[y][x]);
	}
}

/**
* @brief create_map create the map and put ressources on it
*
* @param server
*/

void create_map(srv_t *server)
{
	int a;
	int b;

	server->map->box = malloc(server->width * sizeof(box_t *));
	if (server->map->box == NULL)
		quit(server);
	for (a = 0; a < server->width; a++) {
		server->map->box[a] = malloc(server->height * sizeof(box_t));
		for (b = 0; b < server->height; b++)
			server->map->box[a][b] = malloc(sizeof(box_t));
	}
	fill_map(server);
}

/**
* @brief init_map initialize and create the map
*
* @param server
*/

void init_map(srv_t *server)
{
	server->map = malloc(sizeof(map_t));

	if (server->map == NULL)
		quit(server);
	server->map->fd = 0;
	server->map->fs = NULL;
	server->map->box = NULL;
}