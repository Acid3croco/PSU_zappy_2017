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

	if (ac != 5 && ac != 7)
		return (84);
	if (ga.prepGame(ac, av) == false)
		return (84);
	if (ga.gameLoop() == false)
		return (84);
	return (0);
}