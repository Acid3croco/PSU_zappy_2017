/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** identify_cli
*/

#include "server.h"

/**
* @brief identify_cli give some information about the new client
*
* @param infd
* @param client_s
* @param size
*/

void identify_cli(int infd, struct sockaddr_in *client_s, socklen_t size)
{
	int s;
	char hbuf[NI_MAXHOST];
	char sbuf[NI_MAXSERV];

	s = getnameinfo((struct sockaddr *)client_s, size,
		hbuf, sizeof(hbuf),
		sbuf, sizeof(sbuf),
		NI_NUMERICHOST | NI_NUMERICSERV);
	if (s == 0) {
		printf(CYAN"Accepted connection on descriptor %d "
			"(host=%s, port=%s)\n"RESET,
			infd, hbuf, sbuf);
	}
}

/**
* @brief delete_client delete the client and connect the prev to the next
*
* @param prev
* @param cl
*/

void delete_client(tm_t *team, cl_t *cl, cl_t *prev)
{
	team->nb_ia -= 1;
	if (prev != NULL)
		prev->next = cl->next;
	else
		team->client = cl->next;
	if (cl->team != NULL)
		free(cl->team);
	close(cl->fd);
	free(cl);
}

/**
* @brief close_fd close the given fd and free the client
*
* @param fd
*/

void close_fd(srv_t *server)
{
	tm_t *tm = server->team;
	cl_t *cl = NULL;
	cl_t *prev = NULL;
	int fd = server->cnt->events[server->cnt->a].data.fd;
	int done = 0;

	for (;done == 0 && tm != NULL; tm = tm->next) {
		for (cl = tm->client; done == 0 && cl != NULL; cl = cl->next) {
			if (cl->fd == fd) {
				done = 1;
				break;
			}
			prev = cl;
		}
		if (done == 1)
			break;
	}
	if (cl != NULL)
		delete_client(tm, cl, prev);
	printf(YELLOW"Closed connection on descriptor %d\n"RESET, fd);
}