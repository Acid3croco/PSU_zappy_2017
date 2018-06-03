/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** identify_cli
*/

#include "server.h"

/**
* @brief identify_cli give some information about the new client
*
* @param infd
* @param s_client
* @param size
*/

void identify_cli(int infd, struct sockaddr_in *s_client, socklen_t size)
{
	int s;
	char hbuf[NI_MAXHOST];
	char sbuf[NI_MAXSERV];

	s = getnameinfo((struct sockaddr *)s_client, size,
		hbuf, sizeof(hbuf),
		sbuf, sizeof(sbuf),
		NI_NUMERICHOST | NI_NUMERICSERV);
	if (s == 0) {
		printf("Accepted connection on descriptor %d "
			"(host=%s, port=%s)\n",
			infd, hbuf, sbuf);
	}
}

/**
* @brief close_fd close the given fd and print a message
*
* @param fd
*/

void close_fd(int fd)
{
	close(fd);
	printf("Closed connection on descriptor %d\n", fd);
}