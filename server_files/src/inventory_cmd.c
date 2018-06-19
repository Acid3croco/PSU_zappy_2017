/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** inventory
*/

#include "server.h"

/**
* @brief inventory_cmd send his inventory to the ia
*
* @param server
* @param cmd
* @param fs
* @param client
* @return int
*/

int inventory_cmd(srv_t *server, char **cmd, FILE *fs, cl_t *client)
{
    (void)server;
    (void)cmd;
    (void)fs;
    dprintf(client->fd, "[food %i, linemate %i, deraumere %i, ", client->ress.food,
    client->ress.linemate, client->ress.deraumere);

    dprintf(client->fd, "sibur %i, mendiane %i, phiras %i, thystame %i]\n",
    client->ress.sibur,
    client->ress.mendiane, client->ress.phiras, client->ress.thystame);
    return (0);
}