/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** check inc functions to check the current Incantations
*/

#include "server.h"

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

void cancel_inc(inc_t *inc)
{
	for (cl_t * cl = inc->client; cl != NULL; cl = cl->inext) {
		cl->is_inc = 0;
		if (cl && cl->input)
			gettimeofday(&cl->input->start, NULL);
		dprintf(cl->fd, "ko\n");
	}
}

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
				inc = delete_inc(server, inc);
			}
		}
	}
}