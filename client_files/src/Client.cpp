/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** client main
*/

#include "Client.hpp"
#include "Command.hpp"

/**
* @brief The main.
*
* @param ac
* @param av
* @return int
*/
int	main(int ac, char **av)
{
	Command		co;
	std::string	buf;

	if (ac != 3)
		return (84);
	if (co.startConnection(av[1], std::atoi(av[2])) == false) {
		perror("");
		return (84);
	}
	for (;;) {
		buf = co.getListen();
		if (buf.compare("Error.\n") == 0) {
			perror("");
			return (84);
		}
		std::cout << buf << std::endl;
	}
	return (0);
}