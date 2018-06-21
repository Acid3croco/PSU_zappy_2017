/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** broadcast
*/

#include "server.h"

/**
* @brief calc_size calcul the size of the message to allocate memory
*
* @param cmd
* @return int
*/

int calc_size(char **cmd)
{
	int len = 0;

	for (int a = 1; cmd[a] != NULL; a++)
		len += strlen(cmd[a]) + 1;
	return (len);
}

/**
* @brief concat_msg concat all the word of the message
*
* @param cmd
* @return char*
*/

char *concat_msg(char **cmd)
{
	int size = calc_size(cmd);
	char *msg;

	if (size == 0)
		return (NULL);
	printf("len %i\n", size);
	msg = malloc(size + 1);
	if (msg == NULL)
		return (NULL);
	memset(msg, 0, size + 1);
	for (int a = 1; cmd[a] != NULL; a++) {
		strcat(msg, cmd[a]);
		strcat(msg, " ");
	}
	return (msg);
}

int calc_dir(cl_t *client, cl_t *cl)
{
	int dir = 0;
	(void)client;
	(void)cl;

	return dir;
}

/**
* @brief broad_cmd send the message to every client
*
* @param server
* @param cmd
* @param client
* @return int
*/

int broad_cmd(srv_t *server, char **cmd, cl_t *client)
{
	int dir = 0;
	char *msg = concat_msg(cmd);

	if (msg == NULL)
		return (1);
	for (tm_t *tm = server->team; tm != NULL; tm = tm->next) {
		for (cl_t *cl = tm->client; cl != NULL; cl = cl->next) {
			if (cl->fd == client->fd)
				dprintf(cl->fd, "ok\n");
			else {
				dir = calc_dir(client, cl);
				dprintf(cl->fd, "message %i, %s\n", dir, msg);
			}
		}
	}
	free(msg);
	return (0);
}