/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** connect function
*/

#include "server.h"

/**
* @brief find_team juste return the team with a team name
*
* @param server
* @param name
* @return tm_t *
*/

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

int con_cmd(srv_t *server, char **cmd, cl_t *client)
{
	tm_t *tmp = find_team(server, client->team);
	int nb_ia = 0;

	(void)cmd;
	if (tmp == NULL)
		return (1);
	nb_ia = server->clientsNB - tmp->nb_ia;
	nb_ia = (nb_ia < 0) ? 0 : nb_ia;
	dprintf(client->fd, "%i\n", nb_ia);
	return (0);
}