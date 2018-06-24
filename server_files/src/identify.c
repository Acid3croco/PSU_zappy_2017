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
* @brief delete_on_map remove the client from his box
*
* @param box
*/

void delete_on_map(box_t *box, cl_t *client)
{
	cl_t *tmp = box->client;
	cl_t *prev = NULL;

	for (;tmp != NULL; tmp = tmp->mnext) {
		if (tmp->fd == client->fd)
			break;
		prev = tmp;
	}
	if (prev == NULL)
		box->client = NULL;
	else
		prev->mnext = tmp->mnext;
}

/**
* @brief delete_client delete the client and connect the prev to the next
*
* @param prev
* @param cl
*/

void delete_client(map_t *map, tm_t *team, cl_t *cl, cl_t *prev)
{
	dprintf(cl->fd, "dead\n");
	team->nb_ia -= 1;
	delete_on_map(map->box[cl->y][cl->x], cl);
	if (prev != NULL)
		prev->next = cl->next;
	else
		team->client = cl->next;
	if (cl->team != NULL)
		free(cl->team);
	free_input(cl->input);
	fclose(cl->fs);
	free(cl);
}

/**
* @brief close_fs check the fs and close it
*
* @param server
* @param fs
* @param fd
*/

void close_fs(srv_t *server, FILE *fs, int fd)
{
	fclose(fs);
	if (fd == server->map->fd)
		server->map->fs = NULL;
}
/**
* @brief close_fd close the opened fd and free the client
*
* @param fd
*/

void close_fd(srv_t *server, int fd, FILE *fs)
{
	tm_t *tm = server->team;
	cl_t *cl, *prev = NULL;

	fd = (fd < 0) ? server->cnt->events[server->cnt->a].data.fd : fd;
	for (int done = 0; done == 0 && tm != NULL; tm = tm->next) {
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
		delete_client(server->map, tm, cl, prev);
	else if (fs)
		close_fs(server, fs, fd);
	printf(YELLOW"Closed connection on descriptor %d\n"RESET, fd);
}