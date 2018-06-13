/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** structurz
*/

#ifndef STRUCT_H_
	#define STRUCT_H_

#include <sys/epoll.h>
#include <stdio.h>
#include <string.h>

/* color define for printf */
#include "color.h"

/* Players strucutres */
typedef struct ress_s
{
	int linemate;
	int deraumere;
	int sibur;
	int mendiane;
	int phiras;
	int thystame;
	int food;
} rs_t;

typedef struct client_s
{
	int x;
	int y;
	int lv;
	int fd;
	int look;
	int cycle;
	FILE *fs;
	char *team;
	struct ress_s ress;
	struct client_s *next;
	struct client_s *mnext;
} cl_t;

typedef struct team_s
{
	int nb_ia;
	char *name;
	struct client_s *client;
	struct team_s *next;
} tm_t;

/* Epoll and connection structure */
typedef struct connect_s
{
	int a;
	int s;
	int fd;
	int efd;
	struct epoll_event event;
	struct epoll_event *events;

} cnt_t;

/* Map Strucutres */
typedef struct box_s
{
	struct client_s *client;
	struct ress_s ress;

} box_t;

typedef struct map_s
{
	int fd;
	FILE *fs;
	struct box_s ***box;
} map_t;

/* Server structure */
typedef struct server_s
{
	int port;
	int width;
	int height;
	int clientsNB;
	int freq;
	FILE *fs;
	struct map_s *map;
	struct connect_s *cnt;
	struct team_s *team;
} srv_t;

/* server commands functions */
int quit_cmd(srv_t *server, char **cmd, FILE *fs);
int msg_cmd(char *cmd);

/* client commands functions */
int forward_cmd(srv_t *server, char **cmd, FILE *fs);

#endif /* !STRUCT_H_ */
