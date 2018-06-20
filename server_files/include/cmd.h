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
#define NB_CMD_CLI 9
#define NB_OBJ 7

typedef struct cmd_s
{
	char *cmd;
	int (*sel_cmd)(srv_t *server, char **cmd, cl_t *client);
} cmd_t;

typedef struct obj_s
{
	char *obj;
	int (*sel_obj)(box_t *box, cl_t *client, int amount);
} obj_t;

const cmd_t cmd_srv[] = {
	{"QUIT", &quit_cmd}
};

const cmd_t cmd_cli[] = {
	{"Forward", &forward_cmd},
	{"Right", &right_cmd},
	{"Left", &left_cmd},
	{"Look", &look_cmd},
	{"Inventory", &inventory_cmd},
	{"Connect_nbr", &con_cmd},
	{"Take", &take_cmd},
	{"Set", &set_cmd},
	{"Broadcast", &broad_cmd}
/*	{"Fork", &fork_cmd},
	{"Eject", &eject_cmd},
	{"Incentation", &inc_cmd} */
};

const obj_t cmd_obj[] = {
	{"deraumere", &der_obj},
	{"food", &foo_obj},
	{"linemate", &lin_obj},
	{"mendiane", &men_obj},
	{"phiras", &phi_obj},
	{"sibur", &sib_obj},
	{"thystame", &thy_obj}
};

#endif /* !CMD_H_ */
