/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** add input to the client
*/

#include "server.h"

/**
* @brief disp_input is to display all the input of a client
*
* @param input
*/

void disp_input(inpt_t *input)
{
	printf("DISP_INPUTS\n");
	for (inpt_t *tmp = input; tmp != NULL; tmp = tmp->next) {
		printf("INPUT > %s > %f\n", tmp->input, tmp->timer);
	}
}

/**
* @brief new_input create the new inpt_t struct for the input
*
* @param server
* @param input
* @return inpt_t*
*/

inpt_t *new_input(srv_t *server, char *input)
{
	inpt_t *new = malloc(sizeof(inpt_t));

	if (new == NULL)
		quit(server);
	new->input = input;
	new->next = NULL;
	new->timer = get_timer(input);
	return (new);
}

/**
* @brief add_input add the input to the linkedlist of all the inputs
*
* @param server
* @param save
* @param client
*/

void add_input(srv_t *server, char *save, cl_t *client)
{
	inpt_t *tmp = client->input;
	char *input = strdup(save);

	if (client->nb_inpt >= 10) {
		free(input);
		close_fd(server);
		return;
	}
	if (client->input == NULL) {
		client->input = new_input(server, input);
		gettimeofday(&client->input->start, NULL);
	}
	else {
		for (; tmp->next != NULL; tmp = tmp->next);
		tmp->next = new_input(server, input);
	}
	client->nb_inpt += 1;
}