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

void free_client(cl_t *client)
{
	cl_t *tmp = client;
	cl_t *prev;

	while (tmp != NULL) {
		if (tmp->team != NULL)
			free(tmp->team);
		if (tmp->fs != NULL)
			fclose(tmp->fs);
		if (tmp->input != NULL)
			free_input(tmp->input);
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

void free_team(tm_t *team)
{
	tm_t *tmp = team;
	tm_t *prev;

	while (tmp != NULL) {
		if (tmp->name != NULL)
			free(tmp->name);
		if (tmp->client != NULL)
			free_client(tmp->client);
		if (tmp->egg != NULL)
			free_egg(tmp->egg);
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

void free_connect(cnt_t *connect)
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

void free_server(srv_t *server)
{
	free_connect(server->cnt);
	free_team(server->team);
	free_map(server->map, server->width, server->height);
	free_inc(server->inc);
	if (server->fs != NULL)
		fclose(server->fs);
	free(server);
}

/**
* @brief quit just exit the program after freeing all ressources
*
* @param server
*/

void quit(srv_t *server)
{
	if (errno == -1)
		perror(RED"error");
	free_server(server);
	exit(84);
}