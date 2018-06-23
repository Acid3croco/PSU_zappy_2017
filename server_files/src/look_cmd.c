/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** look command functions
*/

#include "server.h"

void look_up(srv_t *server, cl_t *client)
{
	int xp;
	int yp;

	printf("up %i %i\n", client->x, client->y);
	for (int a = 0, y = client->y, c = 0; a <= client->lv; a++, y--) {
		for (int x = client->x - a; x <= client->x + a; x++, c++) {
			if (c > 0)
				dprintf(client->fd, ",");
			xp = x % server->width;
			yp = y % server->height;
			xp = (xp < 0) ? xp + server->width : xp;
			yp = (yp < 0) ? yp + server->height : yp;
			printf("%i %i\n", xp, yp);
			ress_cell(server->map->box[yp][xp], client);
		}
	}
}

void look_left(srv_t *server, cl_t *client)
{
	int xp;
	int yp;

	printf("left %i %i\n", client->x, client->y);
	for (int a = 0, y = client->x, c = 0; a <= client->lv; a++, y--) {
		for (int x = client->y - a; x <= client->y + a; x++, c++) {
			if (c > 0)
				dprintf(client->fd, ",");
			xp = x % server->width;
			yp = y % server->height;
			xp = (xp < 0) ? xp + server->width : xp;
			yp = (yp < 0) ? yp + server->height : yp;
			printf("%i %i\n", xp, yp);
			ress_cell(server->map->box[yp][xp], client);
		}
	}
}

void look_down(srv_t *server, cl_t *client)
{
	int xp;
	int yp;

	printf("down %i %i\n", client->x, client->y);
	for (int a = 0, y = client->y, c = 0; a <= client->lv; a++, y++) {
		for (int x = client->x - a; x <= client->x + a; x++, c++) {
			if (c > 0)
				dprintf(client->fd, ",");
			xp = x % server->width;
			yp = y % server->height;
			xp = (xp < 0) ? xp + server->width : xp;
			yp = (yp < 0) ? yp + server->height : yp;
			printf("%i %i\n", xp, yp);
			ress_cell(server->map->box[yp][xp], client);
		}
	}
}

void look_right(srv_t *server, cl_t *client)
{
	int xp;
	int yp;

	printf("right %i %i\n", client->x, client->y);
	for (int a = 0, y = client->x, c = 0; a <= client->lv; a++, y++) {
		for (int x = client->y - a; x <= client->y + a; x++, c++) {
			if (c > 0)
				dprintf(client->fd, ",");
			xp = x % server->width;
			yp = y % server->height;
			xp = (xp < 0) ? xp + server->width : xp;
			yp = (yp < 0) ? yp + server->height : yp;
			printf("%i %i\n", xp, yp);
			ress_cell(server->map->box[yp][xp], client);
		}
	}
}

/**
* @brief look_cmd check the direction of the client and look
*
* @param server
* @param cmd
* @param client
* @return int
*/

int look_cmd(srv_t *server, char **cmd, cl_t *client)
{
	(void)cmd;
	dprintf(client->fd, "[");
	switch (client->look) {
		case 0: look_up(server, client);
			break;
		case 1: look_left(server, client);
			break;
		case 2: look_down(server, client);
			break;
		case 3: look_right(server, client);
			break;
	}
	dprintf(client->fd, "]\n");
	return (0);
}