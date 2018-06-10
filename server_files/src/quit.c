/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** quit functions
*/

#include "server.h"

/**
* @brief free_client free all ressources of all the clients
*
* @param client
*/

void free_client(t_cl *client)
{
	t_cl *tmp = client;
	t_cl *prev;

	while (tmp != NULL) {
		if (tmp->team != NULL)
			free(tmp->team);
		if (tmp->inventory != NULL)
			free(tmp->inventory);
		if (tmp->fs != NULL)
			fclose(tmp->fs);
		prev = tmp;
		tmp = tmp->next;
		free(prev);
	}
}

/**
* @brief free_team free all the names and nodes of the team linked list
*
* @param team
*/

void free_team(t_tm *team)
{
	t_tm *tmp = team;
	t_tm *prev;

	while (tmp != NULL) {
		if (tmp->name != NULL)
			free(tmp->name);
		if (tmp->client != NULL)
			free_client(tmp->client);
		prev = tmp;
		tmp = tmp->next;
		free(prev);
	}
}

/**
* @brief free_connect free the events array and himself
*
* @param connect
*/

void free_connect(t_cnt *connect)
{
	if (connect != NULL) {
		if (connect->events != NULL)
			free(connect->events);
		free(connect);
	}
}

/**
* @brief free_server free server by calling free_connect and free_team
*
* @param server
*/

void free_server(t_srv *server)
{
	free_connect(server->cnt);
	free_team(server->team);
	if (server->map->fs != NULL)
		fclose(server->map->fs);
	free(server->map);
	if (server->fs != NULL)
		fclose(server->fs);
	free(server);
}

/**
* @brief quit just exit the program after freeing all ressources
*
* @param server
*/

void quit(t_srv *server)
{
	if (errno == -1)
		perror(RED"error");
	free_server(server);
	exit(84);
}