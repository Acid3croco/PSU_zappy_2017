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
typedef struct s_client
{
	int fd;
	int x;
	int y;
	int lv;
	FILE *fs;
	char *team;
	char *inventory;
	struct s_client *next;
} t_cl;

typedef struct s_team
{
	int nb_ia;
	char *name;
	struct s_client *client;
	struct s_team *next;
} t_tm;

/* Epoll and connection structure */
typedef struct s_connect
{
	int a;
	int s;
	int fd;
	int efd;
	struct epoll_event event;
	struct epoll_event *events;

} t_cnt;

/* Map Strucutres */
typedef struct s_ress
{
	int linemate;
	int deraumere;
	int sibur;
	int mendiane;
	int phiras;
	int thystame;
	int food;
} t_rs;

typedef struct s_box
{
	struct s_client *client;
	struct s_ress ress;

} t_box;

typedef struct s_map
{
	int fd;
	FILE *fs;
	struct s_case **box;
} t_map;

/* Server structure */
typedef struct s_server
{
	int port;
	int width;
	int height;
	int clientsNB;
	int freq;
	FILE *fs;
	struct s_map *map;
	struct s_connect *cnt;
	struct s_team *team;
} t_srv;

/* server commands functions */
int quit_cmd(t_srv *server, char **cmd, FILE *fs);
int msg_cmd(char *cmd);

/* client commands functions */
int forward_cmd(t_srv *server, char **cmd, FILE *fs);

#endif /* !STRUCT_H_ */
