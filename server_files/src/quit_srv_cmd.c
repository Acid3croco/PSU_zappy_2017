/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** quit ans msg functions for server
*/

#include "server.h"

/**
* @brief quit_cmd stop the server and free all ressources
*
* @param server
* @param cmd
* @param fs
* @return int
*/

int quit_cmd(srv_t *server, char **cmd, FILE *fs, cl_t *client)
{
	(void)cmd;
	(void)fs;
	(void)client;
	free_tab(cmd);
	free_server(server);
	exit(0);
}

/**
* @brief msg_cmd just write on the server if the command is unknow
*
* @param cmd
* @return int
*/

int msg_cmd(char *cmd)
{
	printf("%s: unknow command...\n", cmd);
	return (0);
}