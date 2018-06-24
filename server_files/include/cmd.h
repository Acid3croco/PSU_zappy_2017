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
#define NB_CMD_CLI 12
#define NB_OBJ 7

typedef struct cmd_s
{
	char *cmd;
	int (*sel_cmd)(srv_t *server, char **cmd, cl_t *client);
	float timer;
} cmd_t;

typedef struct obj_s
{
	char *obj;
	int (*sel_obj)(box_t *box, cl_t *client, int amount);
} obj_t;

const cmd_t cmd_srv[] = {
	{"QUIT", &quit_cmd, 0}
};

const cmd_t cmd_cli[] = {
	{"Forward", &forward_cmd, 7},
	{"Right", &right_cmd, 7},
	{"Left", &left_cmd, 7},
	{"Look", &look_cmd, 7},
	{"Inventory", &inventory_cmd, 1},
	{"Connect_nbr", &con_cmd, 0},
	{"Take", &take_cmd, 7},
	{"Set", &set_cmd, 7},
	{"Broadcast", &broad_cmd, 7},
	{"Eject", &eject_cmd, 7},
	{"Fork", &fork_cmd, 42},
	{"Incentation", &inc_cmd, 0}
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
