/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** check all the command of the clients
*/

#include "server.h"

void time_cmd(srv_t *server, cl_t *cl)
{
	struct timeval end;
	long double dif = 0;

	gettimeofday(&end, NULL);
	printf("start %ld , %ld\n", cl->input->start.tv_sec, cl->input->start.tv_usec);
	printf("end %ld , %ld\n", end.tv_sec, end.tv_usec);
	dif = (end.tv_sec - cl->input->start.tv_sec) * 1000000;
	dif += (end.tv_usec - cl->input->start.tv_usec);
	printf("%i clock = %Lf\n", cl->fd, dif);
}

/**
* @brief check_cmd check for every client if a command is available
*
* @param server
*/

void check_cmd(srv_t *server)
{
	for (tm_t *tm = server->team; tm ; tm = tm->next) {
		for (cl_t *cl = tm->client; cl ; cl = cl->next) {
			if (cl->input)
				time_cmd(server, cl);
		}
	}
}