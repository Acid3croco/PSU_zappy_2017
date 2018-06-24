/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** check inc functions to check the current incentations
*/

#include "server.h"

void cancel_inc(inc_t *inc)
{
	return ;
}

void check_inc(srv_t *server)
{
	for (inc_t *inc = server->inc; inc != NULL; inc = inc->next) {
		if (check_ress(server->map->box[inc->y][inc->x],
				inc->lv - 2) != 0)
			cancel_inc(inc);
	}
}