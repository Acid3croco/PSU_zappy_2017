/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** look command functions
*/

#include "server.h"

int look_cmd(srv_t *server, char **cmd, FILE *fs, cl_t *client)
{
	(void)server;
	(void)cmd;
	(void)client;
	printf("Look!\n");
	fprintf(fs, "Look\n");
	return (0);
}