/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** loop functions
*/

#include "server.h"

/**
* @brief check_error checks erros of the event and can close it
*
* @param server
*/

void check_errors(t_srv *server)
{
	int b = 0;

	if ((server->cnt->events[server->cnt->a].events & EPOLLERR) ||
		(server->cnt->events[server->cnt->a].events & EPOLLHUP) ||
		(!(server->cnt->events[server->cnt->a].events & EPOLLIN))) {
			b = close(server->cnt->events[server->cnt->a].data.fd);
			if (b == -1)
				quit(server);
	}
}

/**
* @brief new_client will accept new ia client and put them in their team
*
* @param server
*/

void new_client(t_srv *server)
{
	struct sockaddr_in s_in_client;
	socklen_t s_in_size = sizeof(s_in_client);
	int infd = 0;
	int s = 0;

	infd = accept(server->cnt->fd,
			(struct sockaddr *)&s_in_client, &s_in_size);
	if (infd == -1)
		quit(server);
	identify_cli(infd, &s_in_client, s_in_size);
	server->cnt->event.data.fd = infd;
	server->cnt->event.events = EPOLLIN | EPOLLET;
	s = epoll_ctl(server->cnt->efd,
			EPOLL_CTL_ADD, infd, &server->cnt->event);
	if (s == -1)
		quit(server);
	dprintf(infd, "WELCOME\n");
}

/**
* @brief read_event read every input in the designated file descriptor
*
* @param server
*/

void read_event(t_srv *server)
{
	FILE *fs = my_fdopen(server);
	char *input;
	size_t bufsize = 1;
	ssize_t characters;

	input = malloc(bufsize);
	if (input == NULL)
		quit(server);
	characters = getline(&input, &bufsize, fs);
	if (characters < 1) {
		free(input);
		close_fd(server);
	}
	else if (characters > 1)
		inter_input(server, input, fs);
	else
		free(input);
}

/**
* @brief loop_server is the function within every event will be handled
*
* @param server
*/

void loop_server(t_srv *server)
{
	int n = 0;

	printf(GREEN"Ready to accept new client on port %i\n"RESET,
		server->port);
	for (;;) {
		n = epoll_wait(server->cnt->efd,
				server->cnt->events, MAX_EVENTS, -1);
		for (server->cnt->a = 0; server->cnt->a < n; server->cnt->a++) {
			check_errors(server);
			if (server->cnt->fd ==
				server->cnt->events[server->cnt->a].data.fd)
				new_client(server);
			else
				read_event(server);
		}
	}
}