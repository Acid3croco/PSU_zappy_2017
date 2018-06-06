/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** cmd header with array of structur of functions pointers
*/

#ifndef CMD_H_
	#define CMD_H_

#include "struct.h"
#include <stdio.h>

#define NB_CMD_SRV 1

typedef struct s_cmd
{
	char *cmd;
	int (*sel_cmd)(t_srv *server, char **cmd, FILE *fs);
} t_cmd;

const t_cmd cmd_srv[] = {
	{"QUIT", &quit_cmd}
};

#endif /* !CMD_H_ */
