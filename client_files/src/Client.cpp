/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** client main
*/

#include "Client.hpp"
#include "Command.hpp"

int	printError(void)
{
	perror("");
	return (-1);
}

int	main(int ac, char **av)
{
	Command		co;
	Mysocket	so;
	std::string	buf;

	if (ac != 3)
		return (-1);
	if (so.launchMysocket(av[1], std::atoi(av[2])) == -1)
		return (printError());
	co.setSo(so);
	for (;;) {
		buf = so.wlisten();
		if (buf.empty())
			return (-1);
		std::cout << buf << std::endl;
	}
	return (0);
}