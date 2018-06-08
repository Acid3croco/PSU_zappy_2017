/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** read and write functions
*/

#include "server.h"

/**
* @brief find_client return the client with the fd of the event
*
* @param server
* @param client
*/

t_cl *find_client(t_srv *server)
{
	t_tm *tmp = server->team;
	int done = 0;
	int fd = server->cnt->events[server->cnt->a].data.fd;

	for (;tmp->next != NULL && done == 0; tmp = tmp->next) {
		for (t_cl *cl = tmp->client; cl != NULL;
			cl = cl->next) {
				if (cl->fd == fd)
					return (cl);
			}
	}
	return (NULL);
}

/**
* @brief inter_input interprete the given input
*
* @param server
* @param input
* @param fs
*/

void inter_input(t_srv *server, char *input, FILE *fs)
{
	t_cl *client = NULL;
	char **cmd;
	int fd = server->cnt->events[server->cnt->a].data.fd;

	(void)fs;
	cmd = str_to_wordtab(input, fs);
	if (fd == 1)
		server_cmd(server, cmd, fs);
	if (fd == server->map->fd)
		map_cmd(server, cmd, fs);
	else {
		client = find_client(server);
		if (client == NULL)
			add_cli_to_team(server, cmd, fs);
		else
			sel_cli_cmd(server, cmd, fs);
	}
	free_tab(cmd);
}