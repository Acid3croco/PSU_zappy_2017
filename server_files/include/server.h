/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** server headers
*/

#ifndef SERVER_H_
	#define SERVER_H_

/* basics headers */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

/* socket bind listen headers */
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

/* t_srv t_tn t_cl structures header */
#include "struct.h"

/* max events for events tab */
#define MAX_EVENTS 64

/* disable error in vscode */
extern char *optarg;
extern int optind;

/* functions protorypes */
void fill_args(int ac, char **av, t_srv *server);
void add_team(char *name, t_srv *server);
void init_struct(t_srv *server);
void quit(t_srv *server);
int is_team_new(char *name, t_srv *server);
void free_server(t_srv *server);
void socket_bind(t_srv *server);
void create_epoll(t_srv *server);

#endif /* !SERVER_H_ */
