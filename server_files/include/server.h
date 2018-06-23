/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** server headers
*/

#ifndef SERVER_H_
	#define SERVER_H_
#define _GNU_SOURCE

/* basics headers */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <errno.h>
#include <time.h>
#include <sys/time.h>
#include <sys/timeb.h>

/* socket bind listen headers */
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

/* srv_t cnt_t t_tn cl_t structures header */
#include "struct.h"

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
void fill_args(int ac, char **av, srv_t *server);
void add_team(char *name, srv_t *server);
void init_struct(srv_t *server);
void quit(srv_t *server);
int iteam_s_new(char *name, srv_t *server);
void free_server(srv_t *server);
void socket_bind(srv_t *server);
void create_epoll(srv_t *server);
void loop_server(srv_t *server);
void identify_cli(int infd, struct sockaddr_in *client_s, socklen_t size);
void close_fd(srv_t *server, int fd, FILE *fs);
void inter_input(srv_t *server, char *input, FILE *fs);
void server_cmd(srv_t *server, char **cmd, FILE *fs, char *save);
void add_cli_to_team(srv_t *server, char **cmd, FILE *fs);
char **str_to_wordtab(char *input);
void free_tab(char **tab);
void init_map(srv_t *server);
void map_cmd(srv_t *server, char **cmd, FILE *fs, char *save);
int sel_cli_cmd(srv_t *server, char **cmd, cl_t *client);
int sel_srv_cmd(srv_t *server, char **cmd);
void free_tab(char **tab);
FILE *my_fdopen(srv_t *server);
cl_t *find_client(srv_t *server);
void create_map(srv_t *server);
void free_map(map_t *map, int x, int y);
int my_rand(unsigned int *seed);
void send_new_client(srv_t *server, tm_t *team, cl_t *client, char **cmd);
void init_ress_client(cl_t *client);
void getline_close(srv_t *server, char *input, FILE *fs);
int sel_obj_cmd(box_t *box, cl_t *client, char **cmd, int amount);
void add_input(srv_t *server, char *input, cl_t *client);
void free_input(inpt_t *input);
float get_timer(char *input);
void check_cmd(srv_t *server, struct timeval *strt_fd);
void go_on(srv_t *s, cl_t *client, int x, int y);
void help(srv_t *server);

#endif /* !SERVER_H_ */
