/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** check inc functions to check the current Incantations
*/

#include "server.h"

/**
* @brief delete_inc delete the incantation struct
*
* @param server
* @param inc
* @return inc_t *
*/

inc_t *delete_inc(srv_t *server, inc_t *inc)
{
	inc_t *prev = NULL;
	inc_t *tmp = server->inc;

	for (; tmp != NULL; tmp = tmp->next) {
		if (tmp == inc)
			break;
		prev = tmp;
	}
	if (prev == NULL)
		server->inc = tmp->next;
	else
		prev->next = tmp->next;
	free(tmp);
	if (prev)
		return (prev->next);
	return (NULL);
}

/**
* @brief success_inc incrise the level and free the incentation
*
* @param inc
*/

void success_inc(inc_t *inc)
{
	for (cl_t * cl = inc->client; cl != NULL; cl = cl->inext) {
		cl->is_inc = 0;
		if (cl && cl->input)
			gettimeofday(&cl->input->start, NULL);
		cl->lv += 1;
		dprintf(cl->fd, "Elevation underway\n");
		dprintf(cl->fd, "Current level: %i\n", cl->lv);
	}

}

/**
* @brief cancel_inc cancel the incantation and free the struct
*
* @param inc
*/

void cancel_inc(inc_t *inc)
{
	for (cl_t * cl = inc->client; cl != NULL; cl = cl->inext) {
		cl->is_inc = 0;
		if (cl && cl->input)
			gettimeofday(&cl->input->start, NULL);
		dprintf(cl->fd, "ko\n");
	}
}

/**
* @brief clean_box clean the box and replace ressources
*
* @param server
* @param inc
*/

void clean_box(srv_t *server, inc_t *inc)
{
	unsigned int seed = 0;

	server->map->box[inc->y][inc->x]->ress.food = 0;
	server->map->box[inc->y][inc->x]->ress.linemate = 0;
	server->map->box[inc->y][inc->x]->ress.deraumere = 0;
	server->map->box[inc->y][inc->x]->ress.sibur = 0;
	server->map->box[inc->y][inc->x]->ress.mendiane = 0;
	server->map->box[inc->y][inc->x]->ress.phiras = 0;
	server->map->box[inc->y][inc->x]->ress.thystame = 0;
	for (int x, y;;) {
		x = my_rand(&seed) % server->width;
		y = my_rand(&seed) % server->height;
		if (server->map->box[y][x]->client == NULL) {
			fill_box(server->map->box[y][x]);
			break;
		}
	}
}

/**
* @brief check_inc check all the inc struct
*
* @param server
*/

void check_inc(srv_t *server)
{
	struct timeval end;
	long double dif = 0;
	inc_t *inc = server->inc;

	for (; inc != NULL;) {
		if (check_ress(server->map->box[inc->y][inc->x],
				inc->lv - 2) != 0) {
			cancel_inc(inc);
			inc = delete_inc(server, inc);
		} else {
			gettimeofday(&end, NULL);
			dif = (end.tv_sec - inc->start.tv_sec) * 1000000;
			dif += (end.tv_usec - inc->start.tv_usec);
			if (dif > 10 / server->freq * 1000000) {
				success_inc(inc);
				clean_box(server, inc);
				inc = delete_inc(server, inc);
			}
		}
	}
}