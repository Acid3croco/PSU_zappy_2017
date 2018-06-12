/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** map functions
*/

#include "server.h"

void fill_map(srv_t *server)
{
	struct timeb time;
	unsigned int seed = 0;
	int x = 0;
	int y = 0;

	(void)server;
	ftime(&time);
	seed += time.millitm;
	srand(seed);
	x = rand() % server->width;
	ftime(&time);
	seed += time.millitm;
	srand(seed);
	y = rand() % server->height;
	printf("x=%i, y=%i\n", x, y);
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