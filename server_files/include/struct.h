/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** structurz
*/

#ifndef STRUCT_H_
	#define STRUCT_H_

#include <sys/epoll.h>

typedef struct s_client
{
	int fd;
	int x;
	int y;
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

typedef struct s_connect
{
	int a;
	int s;
	int fd;
	int efd;
	struct epoll_event event;
	struct epoll_event *events;

} t_cnt;

typedef struct s_server
{
	int port;
	int width;
	int height;
	int clientsNB;
	int freq;
	char **map;
	struct s_connect *cnt;
	struct s_team *team;
} t_srv;

#endif /* !STRUCT_H_ */
