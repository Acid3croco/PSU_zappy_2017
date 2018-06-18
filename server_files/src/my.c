/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** my functions
*/

#include "server.h"

/**
* @brief my_fopen do a fopen after a check of the clients
*
* @param server
* @return FILE*
*/

FILE *my_fdopen(srv_t *server)
{
	cl_t *client = NULL;
	int fd = server->cnt->events[server->cnt->a].data.fd;

	if (fd == 1) {
		if (server->fs == NULL)
			return (fdopen(fd, "w+"));
		else
			return (server->fs);
	}
	if (fd == server->map->fd)
		return (server->map->fs);
	client = find_client(server);
	if (client == NULL)
		return (fdopen(fd, "w+"));
	else
		return (client->fs);
}

/**
* @brief my_rand return a random number
*
* @return int
*/

int my_rand(unsigned int *seed)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	*seed += time.tv_usec;
	srand(*seed);
	return (rand());
}