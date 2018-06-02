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
#include <string.h>

/* t_srv t_tn t_cl structures header */
#include "struct.h"

/* disable error in vscode */
extern char *optarg;
extern int optind;

void fill_args(int ac, char **av, t_srv *server);
void add_team(char *name, t_srv *server);
void init_struct(t_srv *server);
void quit(t_srv *server);
int is_team_new(char *name, t_srv *server);

#endif /* !SERVER_H_ */
