/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** client main
*/

#include "client.hpp"
#include "connexion.hpp"

int	printError()
{
	perror("");
	return (-1);
}

int	main(int ac, char **av)
{
	Connexion	*co;

	if (ac != 3)
		return (printError());
	co = new Connexion(av[1], std::atoi(av[2]));
	co->launch_connexion();
	return (0);
}