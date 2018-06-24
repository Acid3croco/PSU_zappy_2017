/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** client main
*/

#include "Client.hpp"
#include "Game.hpp"

/**
* @brief The main.
*
* @param ac
* @param av
* @return int
*/
int	main(int ac, char **av)
{
	Game		ga;

	if (ac == 2 && std::string(av[1]).compare("-help") == 0) {
		std::cout << "USAGE:\t./zappy_ai -p port -n name -h machine\n";
		std::cout << "\tport\tis the port number\n\tname\t";
		std::cout << "is the name of the team\n\tmachine\t";
		std::cout << "is the name of the machine;";
		std::cout << "localhost by default" << std::endl;
	}
	else {
		if (ac != 5 && ac != 7)
			return (84);
		if (ga.prepGame(ac, av) == false)
			return (84);
		if (ga.gameLoop() == false)
			return (84);
	}
	return (0);
}