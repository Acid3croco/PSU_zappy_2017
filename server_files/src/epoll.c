/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** epoll functions
*/

#include "server.h"

/**
* @brief create_epoll initialize the epoll ressources and the events array
*
* @param server
*/

void create_epoll(t_srv *server)
{
	server->cnt->efd = epoll_create1(0);
	memset(&server->cnt->event, 0, sizeof(server->cnt->event));
	server->cnt->event.data.fd = server->cnt->fd;
	server->cnt->event.events = EPOLLIN;
	server->cnt->s = epoll_ctl(server->cnt->efd, EPOLL_CTL_ADD,
				server->cnt->fd, &server->cnt->event);
	if (server->cnt->s == -1)
		quit(server);
	server->cnt->events = calloc(MAX_EVENTS, sizeof(server->cnt->event));
}