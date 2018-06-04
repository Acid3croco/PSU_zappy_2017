/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** client main
*/

#include "Client.hpp"
#include "Command.hpp"

/**
* @brief
*
* @param ac
* @param av
* @return int
*/

int	main(int ac, char **av)
{
	Command		co;
	Mysocket	so;
	std::string	buf;

	if (ac != 3)
		return (84);
	if (so.launchMysocket(av[1], std::atoi(av[2])) == -1) {
		perror("");
		return (84);
	}
	co.setSo(so);
	for (;;) {
		buf = so.wlisten();
		if (buf.empty()) {
			perror();
			return (84);
		}
		std::cout << buf << std::endl;
	}
	return (0);
}