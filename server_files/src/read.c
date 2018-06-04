/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** read and write functions
*/

#include "server.h"

/**
* @brief inter_input interprete the given input
*
* @param server
* @param input
* @param fs
*/

void inter_input(t_srv *server, char *input, FILE *fs)
{
	(void)fs;
	(void)server;
	printf(CYAN"%s\n"RESET, input);
	if (server->cnt->events[server->cnt->a].data.fd == 1
		&& strcmp("stop\n", input) == 0) {
			free(input);
			fclose(fs);
			free_server(server);
			exit(0);
		}
}