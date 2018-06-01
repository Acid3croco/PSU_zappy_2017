/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** teams functions
*/

#define _GNU_SOURCE
#include "server.h"

void create_team(char *name, t_srv *server)
{
	t_tm new;

	asprintf(&new.name, "%s", name);
	new.next = NULL;
	server->team = &new;
}

void add_team(char *name, t_srv *server)
{
	t_tm new;

	asprintf(&new.name, "%s", name);
	new.next = NULL;
	server->team->next = &new;
}

void add_team_member(char *name, t_srv *server)
{
	(void)name;
	(void)server;
	if (server->team == NULL)
		create_team(name, server);
	else
		add_team(name, server);
}