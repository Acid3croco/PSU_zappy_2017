/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** teams functions
*/

#define _GNU_SOURCE
#include "server.h"

void add_team(char *name, t_srv *server)
{
	t_tm *new = malloc(sizeof(t_tm));

	asprintf(&new->name, "%s", name);
	new->next = server->team;
	server->team = new;
}