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

/* t_srv t_cnt t_tn t_cl structures header */
#include "struct.h"

/* color define for printf */
#include "color.h"

/**
* @brief MAX_EVENTS define the number of max events in the events array
*
*/
#define MAX_EVENTS 64

/**
* @brief disable error in vscode
*
*/
extern char *optarg;
/**
* @brief disable error in vscode
*
*/
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
void loop_server(t_srv *server);
void identify_cli(int infd, struct sockaddr_in *s_client, socklen_t size);
void close_fd(int fd);

#endif /* !SERVER_H_ */
