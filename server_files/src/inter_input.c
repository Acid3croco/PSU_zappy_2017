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

cl_t *find_client(srv_t *server)
{
	tm_t *tmp = server->team;
	int done = 0;
	int fd = server->cnt->events[server->cnt->a].data.fd;

	for (;tmp->next != NULL && done == 0; tmp = tmp->next) {
		for (cl_t *cl = tmp->client; cl != NULL;
			cl = cl->next) {
				if (cl->fd == fd)
					return (cl);
			}
	}
	return (NULL);
}

/**
* @brief unknow_cmd send ko to the client becasue of an unknow command
*
* @param server
* @param cmd
* @param fs
*/

void unknow_cmd(int fd)
{
	dprintf(fd, "ko\n");
}

/**
* @brief inter_input interprete the given input
*
* @param server
* @param input
* @param fs
*/

void inter_input(srv_t *server, char *input, FILE *fs)
{
	cl_t *client = NULL;
	char **cmd;
	int fd = server->cnt->events[server->cnt->a].data.fd;


	cmd = str_to_wordtab(input);
	free(input);
	if (fd == 1)
		server_cmd(server, cmd, fs);
	else if (fd == server->map->fd)
		map_cmd(server, cmd, fs);
	else {
		client = find_client(server);
		if (client == NULL)
			add_cli_to_team(server, cmd, fs);
		else
			if (sel_cli_cmd(server, cmd, client))
				unknow_cmd(client->fd);
	}
	free_tab(cmd);
}