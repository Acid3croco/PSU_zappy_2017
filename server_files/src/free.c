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