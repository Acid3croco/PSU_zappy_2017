/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** connect function
*/

#include "server.h"

tm_t *find_team(srv_t *server, char *name)
{
	tm_t *tmp = server->team;
	int done = 0;

	for (;tmp->next != NULL && done == 0; tmp = tmp->next) {
		if (strcmp(tmp->name, name) == 0)
			return (tmp);
	}
	return (NULL);
}

/**
* @brief con_cmd
*
* @param server
* @param cmd
* @param fs
* @param client
* @return int
*/

int con_cmd(srv_t *server, char **cmd, FILE *fs, cl_t *client)
{
	tm_t *tmp = find_team(server, client->team);

	if (tmp == NULL)
		return (1);
	(void)cmd;
	(void)fs;
	dprintf(client->fd, "%i\n", server->clientsNB - tmp->nb_ia);
	return (0);
}