/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** check all
*/

#include "server.h"

/**
* @brief win end the game
*
* @param server
* @param team
*/

void win(srv_t *server, tm_t *team)
{
	for (tm_t *tm = server->team; tm ; tm = tm->next) {
		for (cl_t *cl = tm->client; cl;) {
			dprintf(cl->fd, "Team %s won\n", team->name);
		}
	}
	if (errno == -1)
		perror(RED"error");
	free_server(server);
	exit(0);
}

/**
* @brief check_win check if a team have 6 players lv 8
*
* @param server
*/

void check_win(srv_t *server)
{
	int nb;

	for (tm_t *tm = server->team; tm ; tm = tm->next) {
		nb = 0;
		for (cl_t *cl = tm->client; cl; cl = cl->next) {
			if (cl->lv == 8)
				nb++;
		}
		if (nb >= 6)
			win(server, tm);
	}
}

/**
* @brief check_all check all the checking functions
*
* @param server
* @param strt_fd
*/

void check_all(srv_t *server, struct timeval *strt_fd)
{
	check_cmd(server, strt_fd);
	check_egg(server);
	check_inc(server);
	check_win(server);
}