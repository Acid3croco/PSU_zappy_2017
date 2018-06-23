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
* @param buf
*/
void	Game::handleInventory(std::string buf)
{
	this->_msgQ--;
	this->_inv->parseInventory(buf);
	this->_priority = this->_inv->getPriority(this->_goal);
	if (this->_mo->verifPath() == false) {
		this->_co->look();
		this->_msgQ++;
	}
	this->_co->popBack();
}

/**
* @brief takeRessource take nbr quantity of ressources on the ground.
*
* @param nbr
*/
void	Game::takeRessource(int nbr, int index)
{
	if (index != 6) {
		for (int i = 0; 10 > this->_msgQ && i < nbr &&
		this->_goal[index] > i; i++) {
			this->_co->takeObj(this->_priority.first);
			this->_msgQ++;
		}
	}
	else {
		for (int i = 0; 10 > this->_msgQ && i < nbr; i++) {
			this->_co->takeObj("food");
			this->_msgQ++;
		}
	}
}

/**
* @brief getAll get all the ressources of the tile.
*
* @param sight
*/
void	Game::getAll(std::vector<int> sight)
{
	std::vector<std::string>	ressourceName;

	ressourceName = this->_inv->getRessourceName();
	for (int i = 0; i < 6; i++) {
		for (; 0 < sight[i] && this->_msgQ < 10;) {
			this->_co->takeObj(ressourceName[i]);
			sight[i]--;
			this->_msgQ++;
		}
	}
}

/**
* @brief launchIncantation verify if the tile is empty.
*
* @param sight
*/
void	Game::launchIncantation(std::vector<std::vector<int>>	sight)
{
	if (this->_priority.first.compare("incantation") == 0 &&
		this->_inv->getInventory(std::string("food")) >= 10 &&
		this->_mo->checkEmpty(sight[0]) == true)
		this->incantationPrep();
	else
		this->getAll(sight[0]);
}

/**
* @brief handleLook handle look function.
*
* @param buf
*/
void	Game::handleLook(std::string buf)
{
	std::vector<std::vector<int>>	sight;
	int	index;

	this->_msgQ--;
	sight = this->_obj->parseLoop(buf, this->_lvl);
	if (this->_priority.first.compare("incantation") != 0) {
		index = this->_inv->findId(this->_priority.first);
		if (sight[0][index] > 0)
			this->takeRessource(sight[0][index], index);
		else {
			this->takeRessource(sight[0][6], 6);
			if (this->_mo->verifPath() == false)
				this->_mo->findPath(sight, index, this->_x);
		}
	}
	else
		this->launchIncantation(sight);
	this->_co->popBack();
}

/**
* @brief handleIncantation handle answer of incatation.
*
* @param buf
*/
void	Game::handleIncantation(std::string buf)
{
	if (buf.compare(0, 14, "Current level:") == 0) {
		this->_lvl++;
		this->_goal = this->_obj->getGoal(this->_lvl);
		this->_msgQ--;
		this->_co->popBack();
	}
}

/**
* @brief handlingCommand handle command.
*
* @param buf
*/
void	Game::handlingCommand(std::string buf)
{
	if (buf.compare("ok\n") == 0 || buf.compare("ko\n") == 0) {
		if (this->_co->compareCmd("incantation") == true) {
			this->_co->look();
			this->_goal = this->_obj->getGoal(this->_lvl);
		}
		this->_co->popBack();
		this->_msgQ--;
	}
	else if (buf.front() == '[') {
		if (this->_co->compareCmd("inventory") == true)
			this->handleInventory(buf);
		else if (this->_co->compareCmd("look") == true)
			this->handleLook(buf);
	}
	else if (this->_co->compareCmd("incantation") == true)
		this->handleIncantation(buf);
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

/**
* @brief incantationPrep preparation for incantation.
*
*/
void	Game::incantationPrep()
{
	std::vector<std::string>	ressourceName;

	ressourceName = this->_inv->getRessourceName();
	for (int i = 0; i < 6; i++) {
		for (; 0 < this->_goal[i] && this->_msgQ < 10;) {
			this->_co->setObj(ressourceName[i]);
			this->_goal[i]--;
			this->_msgQ++;
		}
	}
	if (this->_msgQ < 10) {
		this->_co->incantation();
		this->_msgQ++;
		this->_priority.first = "food";
	}
}

/**
* @brief launchCommand all the command start here.
*
*/
void	Game::launchCommand()
{
	if (this->_mo->verifPath() == true && this->_msgQ < 10) {
		this->_co->move(this->_mo->getDirection());
		this->_msgQ++;
	}
	else if (this->_msgQ == 0) {
			if (this->_co->verifExist("inventory") == false) {
			this->_co->inventory();
			this->_msgQ++;
		}
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