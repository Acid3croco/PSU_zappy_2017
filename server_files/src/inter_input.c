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

void find_client(t_srv *server, t_cl *client)
{
	t_tm *tmp = server->team;

	(void)client;
	for (;tmp->next != NULL; tmp = tmp->next) {
		for (t_cl *cl = tmp->client; cl != NULL && cl->next != NULL;
			cl = cl->next) {
				printf("jew code = %i\n", cl->fd);
			}
	}
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

	(void)fs;
	printf(CYAN"%s"RESET, input);
	cmd = str_to_wordtab(input, fs);
	if (server->cnt->events[server->cnt->a].data.fd == 1)
		server_cmd(server, cmd, fs);
	else {
		find_client(server, client);
		if (client == NULL)
			add_cli_to_team(server, cmd, fs);
		else
			msg_cmd(cmd[0]);
	}
	free_tab(cmd);
}