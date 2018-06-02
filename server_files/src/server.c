/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** server main
*/

#include "server.h"

void init_server(t_srv *server)
{
	(void)server;
}

int main(int ac, char **av)
{
	t_srv server;

	init_struct(&server);
	fill_args(ac, av, &server);
	init_server(&server);
	free_server(&server);
	return (0);
}