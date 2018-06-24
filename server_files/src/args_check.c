/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** check arguments
*/

#include "server.h"

/**
* @brief check_p check if the port is correct
*
* @param server
*/

void check_p(srv_t *server)
{
	if (server->port > 65535 || server->port < 0)
	{
		printf("\n-p option only accepts valid ports\n\n");
		help(server);
	}
}

/**
* @brief check_width check if the width is correct
*
* @param server
*/

void check_width(srv_t *server)
{
	if (server->width < 10 || server->width > 30)
	{
		printf("\n-x option only accepts integer values between 10 and 30\n\n");
		help(server);
	}
}

/**
* @brief check_height check if the height is correct
*
* @param server
*/

void check_height(srv_t *server)
{
	if (server->height < 10 || server->height > 30)
	{
		printf("\n-y option only accepts integer values between 10 and 30\n\n");
		help(server);
	}
}

/**
* @brief check_freq check if the frequence is correct
*
* @param server
*/

void check_freq(srv_t *server)
{
	if (server->freq < 2 || server->freq > 10000)
	{
		printf("\n");
		printf("-f option only accepts integer values between 2 and 10000\n\n");
		help(server);
	}
}

/**
* @brief check_clientsNB check if there is a correct number of clients
*
* @param server
*/

void check_clientsNB(srv_t *server)
{
	if (server->clientsNB < 1)
	{
		printf("\n");
		printf("-c option only accepts integer values greater or equal to 1\n");
		printf("\n\n");
		help(server);
	}
}