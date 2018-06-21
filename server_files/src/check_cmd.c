/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** check all the command of the clients
*/

#include "server.h"

void delete_input(cl_t *client)
{
	inpt_t *delete = client->input;

	client->input = client->input->next;
	if (client->input)
		gettimeofday(&client->input->start, NULL);
	free(delete->input);
	free(delete);
}

/**
* @brief time_cmd check the duration of the cmd and execute it
*
* @param server
* @param cl
*/

void time_cmd(srv_t *server, cl_t *cl)
{
	struct timeval end;
	long double dif = 0;
	char **cmd;

	gettimeofday(&end, NULL);
	dif = (end.tv_sec - cl->input->start.tv_sec) * 1000000;
	dif += (end.tv_usec - cl->input->start.tv_usec);
	if (dif > cl->input->timer / server->freq * 1000000) {
		cmd = str_to_wordtab(cl->input->input);
		sel_cli_cmd(server, cmd, cl);
		free_tab(cmd);
		delete_input(cl);
	}
}

/**
* @brief check_cmd check for every client if a command is available
*
* @param server
*/

void check_cmd(srv_t *server)
{
	for (tm_t *tm = server->team; tm ; tm = tm->next) {
		for (cl_t *cl = tm->client; cl ; cl = cl->next) {
			if (cl->input)
				time_cmd(server, cl);
		}
	}
}