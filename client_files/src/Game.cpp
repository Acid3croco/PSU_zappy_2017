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
_msgQ(0), _lvl(1), _priority("food"), _goal(7)
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
	for (int i = 0; i < 6; i++)
		std::cout << this->_goal[i] << std::endl;
	std::cout << this->_x << " " << this->_y << std::endl;
	return (true);
}

/**
* @brief handlingCommand handle command.
*
* @param buf
*/
void	Game::handlingCommand(std::string buf)
{
	if (buf.compare("ok") == 0)
		this->_msgQ--;
	else if (buf.front() == '[') {
		if (this->_co->compareCmd("inventory") == true)
			this->handleInventory(buf);
		else
			this->handleLook(buf);
	}
}

/**
* @brief handleInventory handle inventory function.
*
*/
void	Game::handleInventory(std::string buf)
{
	this->_inv->parseInventory(buf);
	this->_co->look();
}

/**
* @brief handleLook handle look function.
*
* @param buf
*/
void	Game::handleLook(std::string buf)
{
	std:vector<int>	inventory;

	inventory = this->_inv->getInventory();
	this->_obj->
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
		if (token.compare("Pierrotie") == 0)
			std::cout << "My broadcast" << std::endl;
	}
	else
		this->handlingCommand(buf);
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

	this->_co->inventory();
	for (;;) {
		buf = this->_co->getListen();
		if (buf.compare("Error\n") == 0) {
			perror("");
			return (false);
		}
		else if (buf.compare("dead\n") == 0)
			break;
		std::cout << buf << std::endl;
		this->handlingMsg(buf);
	}
	return (true);
}