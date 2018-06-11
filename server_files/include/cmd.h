/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** cmd header with array of structur of functions pointers
*/

#ifndef CMD_H_
	#define CMD_H_

#include "struct.h"

#define NB_CMD_SRV 1
#define NB_CMD_CLI 1

typedef struct s_cmd
{
	char *cmd;
	int (*sel_cmd)(srv_t *server, char **cmd, FILE *fs);
} t_cmd;

const t_cmd cmd_srv[] = {
	{"QUIT", &quit_cmd}
};

const t_cmd cmd_cli[] = {
	{"Forward", &forward_cmd}
};

#endif /* !CMD_H_ */
