/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** help
*/

#include "server.h"

/**
* @brief help print the help and quit if an error occurs
*
* @param server
*/

void help(srv_t *server)
{
	printf("USAGE: ./zappy_server -p port -x width -y height -n name1 ");
	printf("name2 ... -c clientsNb -f freq\n");
	printf("\n\tport\t\tis the port number\n");
	printf("\twidth\t\tis the width of the world\n");
	printf("\theight\t\tis the height of the world\n");
	printf("\tnameX\t\tis the name of the team X\n");
	printf("\tclientsNb\tis the number of authorized clients per team\n");
	printf("\tfreq\t\tis the reciprocal of time unit for execution ");
	printf("of actions\n");
	quit(server);
}

/**
* @brief check_args call all functions that checks all the arguments
*
* @param server
*/

void check_args(srv_t *server)
{
	check_p(server);
	check_width(server);
	check_height(server);
	check_freq(server);
	check_clientsNB(server);
}