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
#define NB_CMD_CLI 4

typedef struct s_cmd
{
	char *cmd;
	int (*sel_cmd)(srv_t *server, char **cmd, FILE *fs, cl_t *client);
} t_cmd;

const t_cmd cmd_srv[] = {
	{"QUIT", &quit_cmd}
};

const t_cmd cmd_cli[] = {
	{"Forward", &forward_cmd},
	{"Right", &right_cmd},
	{"Left", &left_cmd},
	{"Look", &look_cmd}
/*	{"Inventory", &inv_cmd},
	{"Broadcast", &broad_cmd},
	{"Connect_nbr", &conn_cmd},
	{"Fork", &fork_cmd},
	{"Eject", &eject_cmd},
	{"Take", &take_cmd},
	{"Set", &set_cmd},
	{"Incentation", &inc_cmd} */
};

#endif /* !CMD_H_ */
