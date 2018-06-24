/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** Incantation commands
*/

#include "server.h"
#include "ritual.h"

/**
* @brief nb_plyr check if there is enough playres and their level
*
* @param box
* @param lv
* @return int
*/

int nb_plyr(box_t *box, int lv)
{
	int nb = 0;

	for (cl_t *cl = box->client; cl != NULL; cl = cl->next) {
		if (cl->lv != lv)
			return (-1);
		nb++;
	}
	return (nb);
}

/**
* @brief check_ress check if all the ressources and players are on the box
*
* @param box
* @param lv
* @return int
*/

int check_ress(box_t *box, int lv)
{
	int curr_ress[7];

	curr_ress[0] = nb_plyr(box, lv + 1);
	curr_ress[1] = box->ress.linemate;
	curr_ress[2] = box->ress.deraumere;
	curr_ress[3] = box->ress.sibur;
	curr_ress[4] = box->ress.mendiane;
	curr_ress[5] = box->ress.phiras;
	curr_ress[6] = box->ress.thystame;
	curr_ress[7] = box->ress.food;
	if (curr_ress[0] < ritual[lv][0])
		return (-1);
	for (int a = 1; a < 8; a++) {
		if (curr_ress[a] != ritual[lv][a])
			return (-1);
	}
	return (0);
}

/**
* @brief inc_cmd is the functions for the Incantation command
*
* @param server
* @param cmd
* @param client
* @return int
*/

int inc_cmd(srv_t *server, char **cmd, cl_t *client)
{
	(void)cmd;
	if (check_ress(server->map->box[client->y][client->x],
			client->lv - 1) == -1) {
		dprintf(client->fd, "ko\n");
		return (0);
	}
	create_inc(server, client);
	return (0);
}
