/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** teams functions
*/

#define _GNU_SOURCE
#include "server.h"

/**
* @brief is_team_new (?) check if the team name already exist
*
* @param name
* @param server
* @return int
*/

int is_team_new(char *name, t_srv *server)
{
	t_tm *tmp = server->team;

	while (tmp->next != NULL) {
		if (strcmp(name, tmp->name) == 0)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}

/**
* @brief add_team create a new team node to the linked list
*
* @param name
* @param server
*/

void add_team(char *name, t_srv *server)
{
	t_tm *new = malloc(sizeof(t_tm));

	asprintf(&new->name, "%s", name);
	new->next = server->team;
	new->client = NULL;
	server->team = new;
}
