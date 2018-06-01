/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** args
*/

#include "server.h"

void init_srv(t_srv *server)
{
	t_tm *team = malloc(sizeof(t_tm));

	team->name = NULL;
	team->client = NULL;
	team->next = NULL;
	server->port = 1234;
	server->width = 10;
	server->height = 10;
	server->clientsNB = 10;
	server->freq = 100;
	server->team = team;
}

void fill_teams(int ac, char **av, t_srv *server)
{
	optind -= 1;

	(void)server;
	while (optind < ac && av[optind][0] != '-') {
		add_team(av[optind], server);
		optind++;
	}
	t_tm *tmp = server->team;
	while (tmp->next != NULL) {
		printf("name=%s\n", tmp->name);
		tmp = tmp->next;
	}
}

void fill_args(int ac, char **av, t_srv *server)
{
	int opt = 0;

	while ((opt = getopt(ac, av, "pxyn:cf")) != -1) {
		switch (opt) {
			case 'p':
				server->port = atoi(optarg);
				break;
			case 'x':
				server->width = atoi(optarg);
				break;
			case 'y':
				server->height = atoi(optarg);
				break;
			case 'n':
				fill_teams(ac, av, server);
				break;
			case 'c':
				server->clientsNB = atoi(optarg);
				break;
			case 'f':
				server->freq = atoi(optarg);
				break;
		}
	}
}