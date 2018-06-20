/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** broadcast
*/

#include "server.h"

int calc_size(char **cmd)
{
	int len = 0;

	for (int a = 1; cmd[a] != NULL; a++)
		len += strlen(cmd[a]) + 1;
	return (len);
}

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
	int done = 0;
	char *msg = concat_msg(cmd);

	if (msg == NULL)
		return (1);
	for (tm_t *tm = server->team; tm != NULL; tm = tm->next) {
		for (cl_t *cl = tm->client; cl != NULL; cl = cl->next) {
			if (cl->fd == client->fd)
				dprintf(cl->fd, "ok\n");
			else
				dprintf(cl->fd, "%s\n", msg);
		}
		if (done == 1)
			break;
	}
	free(msg);
	return (0);
}