/*
** EPITECH PROJECT, 2018
** zappt
** File description:
** map cmd functions
*/

#include "server.h"

/**
* @brief map_cmd take the command given by
*
* @param server
* @param cmd
* @param fs
*/

void map_cmd(srv_t *server, char **cmd, FILE *fs, char *save)
{
	(void)server;
	(void)fs;
	free(save);
	printf("map = %s\n", cmd[0]);
}