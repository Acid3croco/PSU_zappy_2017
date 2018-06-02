/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** args
*/

#include "server.h"

/**
* @brief init_struct initialize the server struct with default values
*
* @param server
*/

void init_struct(t_srv *server)
{
	t_tm *team = malloc(sizeof(t_tm));
	t_cnt *cnt = malloc(sizeof(t_cnt));

	if (team == NULL || cnt == NULL)
		quit(server);
	team->name = NULL;
	team->client = NULL;
	team->next = NULL;
	server->port = 1234;
	server->width = 10;
	server->height = 10;
	server->clientsNB = 10;
	server->freq = 100;
	server->team = team;
	server->cnt = cnt;
}

/**
* @brief fill_teams create and initialize all the teams
*
* @param ac
* @param av
* @param server
*/

void fill_teams(int ac, char **av, t_srv *server)
{
	optind -= 1;

	(void)server;
	while (optind < ac && av[optind][0] != '-') {
		if (is_team_new(av[optind], server) == 0)
			add_team(av[optind], server);
		optind++;
	}
}

/**
* @brief fill_args put all arguments with optget in the server structure
*
* @param ac
* @param av
* @param server
*/

void fill_args(int ac, char **av, t_srv *server)
{
	int opt = 0;

	while ((opt = getopt(ac, av, "p:x:y:n:c:f:")) != -1) {
		switch (opt) {
			case 'p':
				server->port = strtol(optarg, NULL, 10);
				break;
			case 'x':
				server->width = strtol(optarg, NULL, 10);
				break;
			case 'y':
				server->height = strtol(optarg, NULL, 10);
				break;
			case 'n':
				fill_teams(ac, av, server);
				break;
			case 'c':
				server->clientsNB = strtol(optarg, NULL, 10);
				break;
			case 'f':
				server->freq = strtol(optarg, NULL, 10);
				break;
			default:
				quit(server);
				break;
		}
	}
}