/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** server main
*/

#include "server.h"

/**
* @brief init_server initialize the server
*
* @param server
*/

void init_server(t_srv *server)
{
	socket_bind(server);
	create_epoll(server);
	(void)server;
}

/**
* @brief THE Main
*
* @param ac
* @param av
* @return int
*/

int main(int ac, char **av)
{
	t_srv *server = malloc(sizeof(t_srv));

	if (server == NULL)
		return (84);
	init_struct(server);
	fill_args(ac, av, server);
	init_map(server);
	init_server(server);
	create_map(server);
	loop_server(server);
	free_server(server);
	return (0);
}