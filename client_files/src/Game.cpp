/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** Game loop
*/

#include "Game.hpp"

/**
* @brief Construct a new Game:: Game object
*
*/
Game::Game() : _co(new Command()), _inv(new Inventory()), _obj(new Objectif()),
_mo(new Movement()), _msgQ(0), _lvl(1), _priority("food", 5), _goal(7)
{
}

/**
* @brief Destroy the Game:: Game object
*
*/
Game::~Game()
{
	delete this->_co;
	delete this->_inv;
	delete this->_obj;
	delete this->_mo;
}

/**
* @brief prepGame Do all the action the game need before start.
*
* @param ac
* @param av
* @return true
* @return false
*/
bool	Game::prepGame(int ac, char **av)
{
	size_t		pos;
	std::string	token;
	std::string	buf;

	if (this->_co->startConnection(ac, av) == false)
		return (false);
	buf = this->_co->getListen();
	if (buf.compare("ko\n") == 0)
		return (false);
	std::cout << buf << std::endl;
	buf = this->_co->getListen();
	if (buf.compare("ko\n") == 0)
		return (false);
	pos = buf.find(" ");
	token = buf.substr(0, pos);
	buf.erase(0, pos + 1);
	this->_x = atoi(token.c_str());
	this->_y = atoi(buf.c_str());
	this->_goal = this->_obj->getGoal(this->_lvl);
	std::cout << this->_x << " " << this->_y << std::endl;
	return (true);
}

/**
* @brief handleInventory handle inventory function.
*
*/
void	Game::handleInventory(std::string buf)
{
	std::vector<std::pair<std::string, int>>	inventory;

	this->_msgQ--;
	this->_co->look();
	this->_msgQ++;
	this->_inv->parseInventory(buf);
	inventory = this->_inv->getInventory();
	this->_priority = this->_inv->getPriority(this->_goal);
}

/**
* @brief takeRessource take nbr quantity of ressources on the ground.
*
* @param nbr
*/
void	Game::takeRessource(int nbr, std::pair<std::string, int> invent)
{
	(void)invent;
	for (int i = 0; 10 > this->_msgQ && i < nbr &&
	this->_priority.second > i ; i++) {
		this->_co->takeObj(this->_priority.first);
		this->_msgQ++;
	}
}

/**
* @brief handleLook handle look function.
*
* @param buf
*/
void	Game::handleLook(std::string buf)
{
	std::vector<std::pair<std::string, int>>	inventory;
	std::vector<std::vector<int>>	sight;
	int	index = this->_inv->findId(this->_priority.first);

	this->_msgQ--;
	inventory = this->_inv->getInventory();
	sight = this->_obj->parseLoop(buf, this->_lvl);
	std::cout << sight[0][index] << std::endl;
	if (sight[0][index] > 0)
		this->takeRessource(sight[0][index], inventory[index]);
	else {
		this->takeRessource(sight[0][6], inventory[6]);
		this->_mo->findPath(sight, index);
	}
}

/**
* @brief handlingCommand handle command.
*
* @param buf
*/
void	Game::handlingCommand(std::string buf)
{
	if (buf.compare("ok\n") == 0 || buf.compare("ko\n") == 0)
		this->_msgQ--;
	else if (buf.front() == '[') {
		if (this->_co->compareCmd("inventory") == true)
			this->handleInventory(buf);
		else
			this->handleLook(buf);
	}
}

/**
* @brief handlingMsg handle the server message.
*
* @param buf
*/
void	Game::handlingMsg(std::string buf)
{
	size_t		pos;
	std::string	token;

	pos = buf.find(" ");
	token = buf.substr(0, pos);
	if (token.compare("text") == 0) {
		buf.erase(0, pos + 1);
		pos = buf.find(" ");
		token = buf.substr(0, pos);
		if (token.compare(this->_co->getTeam()) == 0)
			std::cout << "My broadcast" << std::endl;
	}
	else
		this->handlingCommand(buf);
}

void	Game::launchCommand()
{
	if (this->_msgQ == 0) {
			this->_co->inventory();
			this->_msgQ++;
	}
	if (this->_mo->verifPath() == true && this->_msgQ < 10) {
		this->_co->move(this->_mo->getDirection());
		this->_msgQ++;
	}
}

/**
* @brief gameLoop the loop where the game take place.
*
* @param ac
* @param av
* @return bool
*/
bool	Game::gameLoop()
{
	std::string	buf;

	for (;;) {
		this->launchCommand();
		if (this->_co->verifFd() == -1)
			return false;
		buf = this->_co->getListen();
		std::cout << buf << std::endl;
		if (buf.compare("Error\n") == 0) {
			perror("");
			return (false);
		}
		else if (buf.compare("dead\n") == 0)
			break;
		this->handlingMsg(buf);
	}
	return (true);
}