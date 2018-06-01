/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** server main
*/

#include "server.h"

int main(int ac, char **av)
{
	t_srv server;

	init_srv(&server);
	fill_args(ac, av, &server);
	return (0);
}