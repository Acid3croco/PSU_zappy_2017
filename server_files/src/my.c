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

FILE *my_fdopen(t_srv *server)
{
	t_cl *client = NULL;
	int fd = server->cnt->events[server->cnt->a].data.fd;

	if (fd == 1) {
		if (server->fs == NULL)
			return (fdopen(fd, "r"));
		else
			return (server->fs);
	}
	client = find_client(server);
	if (client == NULL)
		return (fdopen(fd, "w+"));
	else
		return (client->fs);
}