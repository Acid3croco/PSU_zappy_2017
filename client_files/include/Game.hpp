/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** class Game
*/

#ifndef GAME_HPP_
	#define GAME_HPP_

#include "Command.hpp"
#include "Inventory.hpp"
#include "Objectif.hpp"
#include "Movement.hpp"

/**
* @brief Game : The game is directed here.
*
*/
class Game {
public:
	Game();
	~Game();
	bool	prepGame(int ac, char **av);
	bool	gameLoop();
	void	setCo(const Command &copy);
	void	handlingCommand(std::string buf);
	void	handlingMsg(std::string buf);
	void	handleInventory(std::string buf);
	void	handleLook(std::string buf);
	void	takeRessource(int nbrRes, std::pair<std::string, int> invent);
	void	launchCommand();
protected:
private:
	Command			*_co;
	Inventory		*_inv;
	Objectif		*_obj;
	Movement		*_mo;
	int			_msgQ;
	int			_lvl;
	std::pair<std::string, int>	_priority;
	std::vector<int>	_goal;
	int			_x;
	int			_y;
};

#endif /* !GAME_HPP_ */
