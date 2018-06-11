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
* @param s_client
* @param size
*/

void identify_cli(int infd, struct sockaddr_in *s_client, socklen_t size)
{
	int s;
	char hbuf[NI_MAXHOST];
	char sbuf[NI_MAXSERV];

	s = getnameinfo((struct sockaddr *)s_client, size,
		hbuf, sizeof(hbuf),
		sbuf, sizeof(sbuf),
		NI_NUMERICHOST | NI_NUMERICSERV);
	if (s == 0) {
		printf("Accepted connection on descriptor %d "
			"(host=%s, port=%s)\n",
			infd, hbuf, sbuf);
	}
}

/**
* @brief delete_client delete the client and connect the prev to the next
*
* @param prev
* @param cl
*/

void delete_client(t_tm *team, t_cl *cl, t_cl *prev)
{
	printf("team %s\n", team->name);
	if (prev != NULL)
		printf("prev fd %i\n", prev->fd);
	if (cl != NULL)
		printf("cl fd %i\n", cl->fd);
	if (prev != NULL)
		prev->next = cl->next;
	else
		team->client = cl->next;
	if (cl->team != NULL)
		free(cl->team);
	if (cl->inventory != NULL)
		free(cl->inventory);
	if (cl->fs != NULL)
		fclose(cl->fs);
	close(cl->fd);
	free(cl);
}

/**
* @brief close_fd close the given fd and free the client
*
* @param fd
*/

void close_fd(t_srv *server)
{
	t_tm *tm = server->team;
	t_cl *cl = NULL;
	t_cl *prev = NULL;
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