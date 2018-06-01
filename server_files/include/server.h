/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** server headers
*/

#ifndef SERVER_H_
	#define SERVER_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_client
{
	int fd;
	struct s_client *next;
} t_cl;

typedef struct s_team
{
	char *name;
	struct s_client *client;
	struct s_team *next;
} t_tm;

typedef struct s_server
{
	int port;
	int width;
	int height;
	int clientsNB;
	int freq;
	struct s_team *team;
} t_srv;

void fill_args(int ac, char **av, t_srv *server);
void add_team_member(char *name, t_srv *server);
void init_srv(t_srv *server);

#endif /* !SERVER_H_ */
