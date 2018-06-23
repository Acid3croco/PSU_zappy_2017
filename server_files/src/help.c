/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** help
*/

#include "server.h"

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

void check_args(srv_t *server)
{
	if (server->port > 65535 || server->port < 0)
		help(server);
	if (server->width < 10 || server->width > 30)
		help(server);
	if (server->height < 10 || server->height > 30)
		help(server);
	if (server->freq < 2 || server->freq > 10000)
		help(server);
	if (server->clientsNB < 1)
		help(server);
}