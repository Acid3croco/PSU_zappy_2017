/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** server commands functions
*/

#include "server.h"

/**
* @brief Get the tab size counting the number of space js
*
* @param buf
* @return int
*/

int get_tab_size(char *buf)
{
	int len = 0;
	unsigned int max = strlen(buf);

	for (unsigned int a = 0; a < max; a++) {
		if (buf[a] == ' ')
			len++;
	}
	return (len + 2);
}

/**
* @brief str_to_wordtab transform the input intou an array
*
* @param server
* @param input
* @param fs
* @return char **
*/

char **str_to_wordtab(char *input, FILE *fs)
{
	char **cmd;
	char *token;
	char *save;
	int a;
	int tab_size = get_tab_size(input);

	(void)fs;
	cmd = malloc(sizeof(char *) * tab_size);
	token = strtok_r(input, " \n\0", &save);
	for (a = 0; token != NULL; a++) {
		cmd[a] = malloc(strlen(token) + 1);
		strcpy(cmd[a], token);
		token = strtok_r(NULL, " \n\0", &save);
	}
	cmd[a] = NULL;
	return (cmd);
}

/**
* @brief upper_case capitalize the given command
*
* @param cmd
*/

void upper_case(char *cmd)
{
	int len = strlen(cmd);

	for (int a = 0; a < len; a++)
		cmd[a] = toupper(cmd[a]);
}

/**
* @brief server_cmd transform the input into an array
*
* @param server
* @param input
* @param fs
*/

void server_cmd(srv_t *server, char **cmd, FILE *fs)
{
	server->fs = fs;
	if (cmd[0] != NULL) {
		upper_case(cmd[0]);
		if (sel_srv_cmd(server, cmd, fs) == 1)
			msg_cmd(cmd[0]);
	}
}