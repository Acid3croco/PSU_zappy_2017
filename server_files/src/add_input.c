/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** add input to the client
*/

#include "server.h"

void disp_input(inpt_t *input)
{
	printf("DISP_INPUTS\n");
	for (inpt_t *tmp = input; tmp != NULL; tmp = tmp->next) {
		printf("INPUT > %s\n", tmp->input);
	}
}

inpt_t *new_input(srv_t *server, char *input)
{
	inpt_t *new = malloc(sizeof(inpt_t));

	if (new == NULL)
		quit(server);
	new->input = input;
	new->next = NULL;
	return (new);
}

void add_input(srv_t *server, char *save, cl_t *client)
{
	inpt_t *tmp = client->input;
	char *input = strdup(save);

	if (client->input == NULL)
		client->input = new_input(server, input);
	else {
		for (; tmp->next != NULL; tmp = tmp->next);
		tmp->next = new_input(server, input);
	}
	client->nb_inpt++;
	disp_input(client->input);
}