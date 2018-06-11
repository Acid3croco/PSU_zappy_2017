/*
** EPITECH PROJECT, 2018
** zappyp
** File description:
** client command functions
*/

#include "cmd.h"

/**
* @brief sel_cli_cmd
*
* @param server
* @param cmd
* @param fs
* @return int
*/

int sel_cli_cmd(srv_t *server, char **cmd, FILE *fs)
{
	for (int a = 0; a < NB_CMD_CLI; a++)
		if (strcmp(cmd_cli[a].cmd, cmd[0]) == 0)
			return (cmd_cli[a].sel_cmd(server, cmd, fs));
	return (1);
}

/**
* @brief sel_srv_cmd loop on the array structure to find the command
*
* @param server
* @param cmd
* @param fs
* @return int
*/

int sel_srv_cmd(srv_t *server, char **cmd, FILE *fs)
{
	for (int a = 0; a < NB_CMD_SRV; a++)
		if (strcmp(cmd_srv[a].cmd, cmd[0]) == 0)
			return (cmd_srv[a].sel_cmd(server, cmd, fs));
	return (1);
}