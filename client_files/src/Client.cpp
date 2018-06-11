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

	if (ac != 5 && ac != 7)
		return (84);
	if (co.startConnection(ac, av) == false)
		return (84);
	buf = co.getListen();
	std::cout << buf << std::endl;
	buf = co.getListen();
	std::cout << buf << std::endl;
	for (;;) {
		buf = co.getListen();
		if (buf.compare("Error\n") == 0) {
			perror("");
			return (84);
		}
		else if (buf.compare("dead\n") == 0)
			break;
		std::cout << buf << std::endl;
	}
	return (0);
}