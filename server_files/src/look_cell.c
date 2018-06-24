/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** look cell and dprintf the ressources
*/

#include "server.h"

/**
* @brief player_cell print player if there is players on the box
*
* @param box
* @param client
*/

void player_cell(box_t *box, cl_t *client)
{
	for (cl_t *cl = box->client; cl != NULL; cl = cl->mnext) {
		dprintf(client->fd, " player");
	}
}

/**
* @brief look_cell print the given ressources of a box
*
* @param fd
* @param name
* @param nb
*/

void look_cell(int fd, char *name, int nb)
{
	for (; nb > 0; nb--) {
		dprintf(fd, " %s", name);
	}
}

/**
* @brief ress_cell print all the ressources of a box
*
* @param box
* @param client
*/

void ress_cell(box_t *box, cl_t *client)
{
	player_cell(box, client);
	look_cell(client->fd, "linemate", box->ress.linemate);
	look_cell(client->fd, "deraumere", box->ress.deraumere);
	look_cell(client->fd, "sibur", box->ress.sibur);
	look_cell(client->fd, "mendiane", box->ress.mendiane);
	look_cell(client->fd, "phiras", box->ress.phiras);
	look_cell(client->fd, "thystame", box->ress.thystame);
	look_cell(client->fd, "food", box->ress.food);
}