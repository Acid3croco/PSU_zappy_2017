/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** forward cmd
*/

#include "server.h"

/**
* @brief set_coords set the coords x and y for the client
*
* @param s
* @param client
* @param x
* @param y
*/

void set_coords(srv_t *s, cl_t *client, int x, int y)
{
	x = (x >= s->width) ? x % s->width : x;
	y = (y >= s->height) ? y % s->height : y;
	x = (x < 0) ? x + s->width : x;
	y = (y < 0) ? y + s->height : y;
	client->x = x;
	client->y = y;
	client->mnext = s->map->box[y][x]->client;
	s->map->box[y][x]->client = client;
}

/**
* @brief go_on move th eplayer to his new box
*
* @param s
* @param client
* @param x
* @param y
*/

void go_on(srv_t *s, cl_t *client, int x, int y)
{
	cl_t *prev = NULL;
	cl_t *tmp = NULL;

	for (tmp = client; tmp != NULL; tmp = tmp->mnext) {
			if (tmp->fd == client->fd)
				break;
			prev = tmp;
		}
	if (prev == NULL)
		s->map->box[client->y][client->x]->client = tmp->mnext;
	else
		prev->mnext = tmp->mnext;
	set_coords(s, client, x, y);
}

/**
* @brief forward_cmd move a client forward
*
* @param server
* @param cmd
* @param fs
* @return int
*/

int forward_cmd(srv_t *server, char **cmd, cl_t *client)
{
	(void)cmd;

	switch (client->look) {
		case 0:go_on(server, client, client->x, client->y - 1);
			break;
		case 1:go_on(server, client, client->x - 1, client->y);
			break;
		case 2:go_on(server, client, client->x, client->y + 1);
			break;
		case 3:go_on(server, client, client->x + 1, client->y);
			break;
	}
	dprintf(client->fd, "ok\n");
	return (0);
}