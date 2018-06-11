/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** free functions
*/

#include "server.h"

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

void free_map(map_t *map)
{
	if (map->fs != NULL)
		fclose(map->fs);
	free(map->box);
	free(map);
}