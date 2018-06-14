/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** teams functions
*/

#define _GNU_SOURCE
#include "server.h"

/**
* @brief iteam_s_new (?) check if the team name already exist
*
* @param name
* @param server
* @return int
*/

int iteam_s_new(char *name, srv_t *server)
{
	tm_t *tmp = server->team;

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

void add_team(char *name, srv_t *server)
{
	tm_t *new = malloc(sizeof(tm_t));

	asprintf(&new->name, "%s", name);
	new->next = server->team;
	new->client = NULL;
	new->nb_ia = 0;
	server->team = new;
}
