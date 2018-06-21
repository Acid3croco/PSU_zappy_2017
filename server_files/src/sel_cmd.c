/*
** EPITECH PROJECT, 2018
** zappyp
** File description:
** client command functions
*/

#include "cmd.h"

/**
* @brief sel_cli_cmd loop on the array structure to find the command
*
* @param server
* @param cmd
* @param fs
* @return int
*/

int sel_cli_cmd(srv_t *server, char **cmd, cl_t *client)
{
	for (int a = 0; a < NB_CMD_CLI; a++)
		if (strcmp(cmd_cli[a].cmd, cmd[0]) == 0)
			return (cmd_cli[a].sel_cmd(server, cmd, client));
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

int sel_srv_cmd(srv_t *server, char **cmd)
{
	for (int a = 0; a < NB_CMD_SRV; a++)
		if (strcmp(cmd_srv[a].cmd, cmd[0]) == 0)
			return (cmd_srv[a].sel_cmd(server, cmd, NULL));
	return (1);
}

/**
* @brief sel_obj_cmd loop on the array structure to find the good object
*
* @param box
* @param client
* @param cmd
* @return int
*/

int sel_obj_cmd(box_t *box, cl_t *client, char **cmd, int amount)
{
	for (int a = 0; a < NB_OBJ; a++)
		if (strcmp(cmd_obj[a].obj, cmd[1]) == 0)
			return (cmd_obj[a].sel_obj(box, client, amount));
	return (1);
}

/**
* @brief get_tiner get the timer for the given input
*
* @param input
* @return float
*/

float get_timer(char *input)
{
	char *tmp = strdup(input);
	char *token;
	char *save;

	token = strtok_r(tmp, " \n\0", &save);
	for (int a = 0; a < NB_CMD_CLI; a++)
			if (strcmp(cmd_cli[a].cmd, token) == 0) {
				free(tmp);
				return (cmd_cli[a].timer);
			}
	free(tmp);
	return (0);
}