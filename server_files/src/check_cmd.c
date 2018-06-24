/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** check all the command of the clients
*/

#include "server.h"

/**
* @brief delete_input delete the input and restart the timer
*
* @param client
*/

void delete_input(cl_t *client)
{
	inpt_t *delete = client->input;

	client->input = client->input->next;
	if (client->input)
		gettimeofday(&client->input->start, NULL);
	free(delete->input);
	free(delete);
}

/**
* @brief check_food check the time and decrement the food
*
* @param server
* @param client
* @param strt_fd
* @param end
*/

int check_food(srv_t *server, cl_t *client,
		struct timeval *strt_fd, struct timeval *end)
{
	long double dif = 0;
	dif = (end->tv_sec - strt_fd->tv_sec) * 1000000;
	dif += (end->tv_usec - strt_fd->tv_usec);
	if (dif > 126 / server->freq * 1000000) {
		client->ress.food -= 1;
		gettimeofday(strt_fd, NULL);
		if (client->ress.food < 0) {
			if (server->map->fd != -2)
				dprintf(server->map->fd, "Dead %i\n", \
					client->fd);
			epoll_ctl(server->cnt->efd, EPOLL_CTL_DEL, client->fd,
				server->cnt->events);
			close_fd(server, client->fd, NULL);
			return (1);
		}
	}
	return (0);
}

/**
* @brief time_cmd check the duration of the cmd and execute it
*
* @param server
* @param cl
*/

cl_t *time_cmd(srv_t *server, cl_t *cl, struct timeval *strt_fd)
{
	struct timeval end;
	long double dif = 0;
	char **cmd;
	cl_t *next = cl->next;

	gettimeofday(&end, NULL);
	if (cl && check_food(server, cl, strt_fd, &end) == 0 && cl->input) {
		dif = (end.tv_sec - cl->input->start.tv_sec) * 1000000;
		dif += (end.tv_usec - cl->input->start.tv_usec);
		if (dif > cl->input->timer / server->freq * 1000000) {
			cmd = str_to_wordtab(cl->input->input);
			sel_cli_cmd(server, cmd, cl);
			free_tab(cmd);
			delete_input(cl);
			cl->nb_inpt -= 1;
		}
	}
	return (next);
}

/**
* @brief check_cmd check for every client if a command is available
*
* @param server
*/

void check_cmd(srv_t *server, struct timeval *strt_fd)
{
	for (tm_t *tm = server->team; tm ; tm = tm->next) {
		for (cl_t *cl = tm->client; cl;) {
			cl = time_cmd(server, cl, strt_fd);
		}
	}
}