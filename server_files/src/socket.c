/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** socket band listen file
*/

#include "server.h"

/**
* @brief Fill sockaddr_in *s_in with the port
*
* @param s_in
* @param port
* @return struct sockaddr_in
*/

struct sockaddr_in get_in(struct sockaddr_in *s_in, int port)
{
	bzero((char *) s_in, sizeof((*s_in)));
	(*s_in).sin_family = AF_INET;
	(*s_in).sin_addr.s_addr = INADDR_ANY;
	(*s_in).sin_port = htons(port);
	return (*s_in);
}

/**
* @brief Function that call socket(), bind() and listen()
*
* @param server
*/

void socket_bind(srv_t *server)
{
	struct protoent *pe;
	struct sockaddr_in s_in;

	s_in = get_in(&s_in, server->port);
	pe = getprotobyname("TCP");
	if (pe == NULL)
		quit(server);
	server->cnt->fd = socket(AF_INET, SOCK_STREAM, pe->p_proto);
	if (server->cnt->fd == -1)
		quit(server);
	if (bind(server->cnt->fd,
		(const struct sockaddr *)&s_in, sizeof(s_in)) == -1)
		quit(server);
	if (listen(server->cnt->fd, 10) == -1)
		quit(server);
}