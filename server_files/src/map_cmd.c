/*
** EPITECH PROJECT, 2018
** zappt
** File description:
** map cmd functions
*/

#include "server.h"

void map_cmd(t_srv *server, char **cmd, FILE *fs)
{
	(void)server;
	(void)fs;
	printf("map_cmd = %s\n", cmd[0]);
}