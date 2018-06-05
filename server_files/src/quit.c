/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** quit functions
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
* @brief free_team free all the names and nodes of the team linked list
*
* @param team
*/

void free_team(t_tm *team)
{
	t_tm *tmp = team;
	t_tm *prev;

	while (tmp != NULL) {
		if (tmp->name != NULL)
			free(tmp->name);
		prev = tmp;
		tmp = tmp->next;
		free(prev);
	}
}

/**
* @brief free_connect free the events array and himself
*
* @param connect
*/

void free_connect(t_cnt *connect)
{
	if (connect != NULL && connect->events != NULL) {
		free(connect->events);
		free(connect);
	}
}

/**
* @brief free_server free server by calling free_connect and free_team
*
* @param server
*/

void free_server(t_srv *server)
{
	free_connect(server->cnt);
	free_team(server->team);
}

/**
* @brief quit just exit the program after freeing all ressources
*
* @param server
*/

void quit(t_srv *server)
{
	perror(RED"error");
	free_server(server);
	exit(84);
}