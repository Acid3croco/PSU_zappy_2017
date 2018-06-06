/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** structurz
*/

#ifndef STRUCT_H_
	#define STRUCT_H_

#include <sys/epoll.h>

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
typedef struct s_stones
{
	int linemate;
	int deraumere;
	int sibur;
	int mendiane;
	int phiras;
	int thystame;
	int food;
} t_st;

typedef struct s_box
{
	struct s_client *client;
	struct s_stones *stones;

} t_box;

typedef struct s_map
{
	int width;
	int height;
	int fd;
	FILE *fs;
	struct s_case *box;
} t_map;

/* Server structure */
typedef struct s_server
{
	int port;
	int width;
	int height;
	int clientsNB;
	int freq;
	struct s_map *map;
	struct s_connect *cnt;
	struct s_team *team;
} t_srv;

#endif /* !STRUCT_H_ */
