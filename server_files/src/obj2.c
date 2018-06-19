/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** object take and set
*/

#include "server.h"

int der_obj(box_t *box, cl_t *client, int amount)
{
	if (amount > 0 && box->ress.deraumere > 0) {
		client->ress.deraumere += amount;
		box->ress.deraumere -= amount;
		dprintf(client->fd, "ok\n");
	} else if (amount < 0 && client->ress.deraumere > 0) {
		client->ress.deraumere += amount;
		box->ress.deraumere -= amount;
		dprintf(client->fd, "ok\n");
	} else
		dprintf(client->fd, "ko\n");
	return (0);
}

int foo_obj(box_t *box, cl_t *client, int amount)
{
	if (amount > 0 && box->ress.food > 0) {
		client->ress.food += amount;
		box->ress.food -= amount;
		dprintf(client->fd, "ok\n");
	} else if (amount < 0 && client->ress.food > 0) {
		client->ress.food += amount;
		box->ress.food -= amount;
		dprintf(client->fd, "ok\n");
	} else
		dprintf(client->fd, "ko\n");
	return (0);
}

int lin_obj(box_t *box, cl_t *client, int amount)
{
	if (amount > 0 && box->ress.linemate > 0) {
		client->ress.linemate += amount;
		box->ress.linemate -= amount;
		dprintf(client->fd, "ok\n");
	} else if (amount < 0 && client->ress.linemate > 0) {
		client->ress.linemate += amount;
		box->ress.linemate -= amount;
		dprintf(client->fd, "ok\n");
	} else
		dprintf(client->fd, "ko\n");
	return (0);
}