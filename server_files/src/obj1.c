/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** object take and set
*/

#include "server.h"

int men_obj(box_t *box, cl_t *client, int amount)
{
	if (amount > 0 && box->ress.mendiane > 0) {
		client->ress.mendiane += amount;
		box->ress.mendiane -= amount;
	} else if (amount < 0 && client->ress.mendiane > 0) {
		client->ress.mendiane += amount;
		box->ress.mendiane -= amount;
	} else
		dprintf(client->fd, "ko\n");
	return (0);
}

int phi_obj(box_t *box, cl_t *client, int amount)
{
	if (amount > 0 && box->ress.phiras > 0) {
		client->ress.phiras += amount;
		box->ress.phiras -= amount;
		dprintf(client->fd, "ok\n");
	} else if (amount < 0 && client->ress.phiras > 0) {
		client->ress.phiras += amount;
		box->ress.phiras -= amount;
		dprintf(client->fd, "ok\n");
	} else
		dprintf(client->fd, "ko\n");
	return (0);
}

int sib_obj(box_t *box, cl_t *client, int amount)
{
	if (amount > 0 && box->ress.sibur > 0) {
		client->ress.sibur += amount;
		box->ress.sibur -= amount;
		dprintf(client->fd, "ok\n");
	} else if (amount < 0 && client->ress.sibur > 0) {
		client->ress.sibur += amount;
		box->ress.sibur -= amount;
		dprintf(client->fd, "ok\n");
	} else
		dprintf(client->fd, "ko\n");
	return (0);
}

int thy_obj(box_t *box, cl_t *client, int amount)
{
	if (amount > 0 && box->ress.thystame > 0) {
		client->ress.thystame += amount;
		box->ress.thystame -= amount;
		dprintf(client->fd, "ok\n");
	} else if (amount < 0 && client->ress.thystame > 0) {
		client->ress.thystame += amount;
		box->ress.thystame -= amount;
		dprintf(client->fd, "ok\n");
	} else
		dprintf(client->fd, "ko\n");
	return (0);
}
