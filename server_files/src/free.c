/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** free functions
*/

#include "server.h"

/**
* @brief free_input frre the linked list of the input of a client
*
* @param input
*/

void free_input(inpt_t *input)
{
	inpt_t *tmp = input;
	inpt_t *prev;

	while (tmp != NULL) {
		if (tmp->input)
			free(tmp->input);
		prev = tmp;
		tmp = tmp->next;
		free(prev);
	}
}

/**
* @brief free_tab free the given array
*
* @param cmd
*/

void free_tab(char **tab)
{
	for (int a = 0; tab[a] != NULL; a++)
		free(tab[a]);
	free(tab);
}

/**
* @brief free_map free the map ressources
*
* @param map
*/

void free_map(map_t *map, int x, int y)
{
	if (map != NULL && map->fs != NULL)
		fclose(map->fs);
	if (map != NULL && map->box != NULL) {
		for (int a = 0; a < y; a++) {
			for (int b = 0; b < x; b++)
				free(map->box[a][b]);
			free(map->box[a]);
		}
		free(map->box);
	}
	if (map != NULL)
		free(map);
}

/**
* @brief getline_close close and free the ressources if getline return -1
*
* @param server
* @param input
* @param fs
*/

void getline_close(srv_t *server, char *input, FILE *fs)
{
	free(input);
	fclose(fs);
	if (server->map->fd == server->cnt->events[server->cnt->a].data.fd)
		server->map->fs = NULL;
	close_fd(server);
}