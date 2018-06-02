/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** teams functions
*/

#define _GNU_SOURCE
#include "server.h"

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

void add_team(char *name, t_srv *server)
{
	t_tm *new = malloc(sizeof(t_tm));

	asprintf(&new->name, "%s", name);
	new->next = server->team;
	server->team = new;
}