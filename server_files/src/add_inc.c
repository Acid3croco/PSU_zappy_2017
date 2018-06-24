/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** add Incantation to server
*/

#include "server.h"

/**
* @brief free_inc free the incantation struct
*
* @param inc
*/

void free_inc(inc_t *inc)
{
	inc_t *tmp = inc;
	inc_t *prev;

	while (tmp != NULL) {
		prev = tmp;
		tmp = tmp->next;
		free(prev);
	}
}

/**
* @brief add_cli_to_inc add the clients to the Incantation
*
* @param new
* @param box
*/

void add_cli_to_inc(inc_t *new, box_t *box)
{
	cl_t *tmp = box->client;

	new->client = NULL;
	for (; tmp != NULL; tmp = tmp->mnext) {
		tmp->is_inc = 1;
		tmp->inext = new->client;
		new->client = tmp;
	}
}

/**
* @brief new_inc create a new Incantation struct
*
* @param server
* @param client
* @return inc_t *
*/

inc_t *new_inc(srv_t *server, cl_t *client)
{
	inc_t *new = malloc(sizeof(inc_t));

	if (new == NULL)
		quit(server);
	new->x = client->x;
	new->y = client->y;
	gettimeofday(&new->start, NULL);
	new->lv = client->lv + 1;
	add_cli_to_inc(new, server->map->box[new->y][new->x]);
	new->next = NULL;
	return (new);
}

/**
* @brief create_inc create the Incantation struct to add it to the server
*
* @param server
* @param client
*/

void create_inc(srv_t *server, cl_t *client)
{
	inc_t *tmp = server->inc;

	if (server->inc == NULL) {
		server->inc = new_inc(server, client);
	}
	else {
		for (; tmp->next != NULL; tmp = tmp->next);
		tmp->next = new_inc(server, client);
	}
}