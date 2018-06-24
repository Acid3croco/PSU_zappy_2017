/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** eggs fuctions
*/

#include "server.h"

/**
* @brief time_egg check the time of the egg to destroy it
*
* @param server
* @param team
* @param egg
* @return egg_t*
*/

egg_t *time_egg(srv_t *server, tm_t *team, egg_t *egg)
{
	struct timeval end;
	long double dif = 0;
	egg_t *next = egg->next;

	gettimeofday(&end, NULL);
	if (team && egg) {
		dif = (end.tv_sec - egg->start.tv_sec) * 1000000;
		dif += (end.tv_usec - egg->start.tv_usec);
		if (dif > 600 / server->freq * 1000000)
			delete_egg(server, team, egg);
	}
	return (next);
}

/**
* @brief check_egg check if the egg is dead
*
* @param server
*/

void check_egg(srv_t *server)
{
	for (tm_t *tm = server->team; tm ; tm = tm->next) {
		for (egg_t *egg = tm->egg; egg;) {
			egg = time_egg(server, tm, egg);
		}
	}
}

/**
* @brief delete_egg delete the given egg and free it
*
* @param server
* @param team
* @param egg
*/

void delete_egg(srv_t *server, tm_t *team, egg_t *egg)
{
	egg_t *next = egg->next;

	(void)server;
	(void)egg;
	team->nb_egg -= 1;
	team->egg = next;
	free(egg);
	printf("destroy egg!\n");
}