/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** send_client
*/

#include "server.h"

void send_new_client(srv_t *server, tm_t *team, cl_t *client, char **cmd)
{
	int fd = server->cnt->events[server->cnt->a].data.fd;

	printf(MAGENTA"Adding %i to the team %s\n"RESET, fd, cmd[0]);
	printf(MAGENTA"There is %i ia in the team %s\n"RESET,
		team->nb_ia, cmd[0]);
	fprintf(client->fs, "%i\n", server->clientsNB - team->nb_ia);
	fprintf(client->fs, "%i %i\n", server->width, server->height);
}