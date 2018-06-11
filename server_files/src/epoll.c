/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** epoll functions
*/

#include "server.h"

/**
* @brief add_stdin add the stdin to the events to read server commands
*
* @param server
*/

void add_stdin(srv_t *server)
{
	memset(&server->cnt->event, 0, sizeof(server->cnt->event));
	server->cnt->event.data.fd = 1;
	server->cnt->event.events = EPOLLIN;
	server->cnt->s = epoll_ctl(server->cnt->efd, EPOLL_CTL_ADD,
				1, &server->cnt->event);
	if (server->cnt->s == -1)
		quit(server);
}

/**
* @brief create_epoll initialize the epoll ressources and the events array
*
* @param server
*/

void create_epoll(srv_t *server)
{
	server->cnt->efd = epoll_create1(0);
	memset(&server->cnt->event, 0, sizeof(server->cnt->event));
	server->cnt->event.data.fd = server->cnt->fd;
	server->cnt->event.events = EPOLLIN;
	server->cnt->s = epoll_ctl(server->cnt->efd, EPOLL_CTL_ADD,
				server->cnt->fd, &server->cnt->event);
	if (server->cnt->s == -1)
		quit(server);
	add_stdin(server);
	server->cnt->events = calloc(MAX_EVENTS, sizeof(server->cnt->event));
}