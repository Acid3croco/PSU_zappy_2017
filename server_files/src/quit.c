/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** quit functions
*/

#include "server.h"

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

void free_connect(t_cnt *connect)
{
	if (connect != NULL && connect->events != NULL) {
		free(connect->events);
		free(connect);
	}
}

void free_server(t_srv *server)
{
	free_connect(server->cnt);
	free_team(server->team);
}

void quit(t_srv *server)
{
	perror("error");
	free_server(server);
	exit(84);
}