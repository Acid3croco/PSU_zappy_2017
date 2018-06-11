/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** source command
*/

#include "Command.hpp"

/**
* @brief Construct a new Command:: Command object
*
*/
Command::Command() : _so(new Mysocket())
{
}

/**
* @brief Destroy the Command:: Command object
*
*/
Command::~Command()
{
	delete this->_so;
}

/**
* @brief startConnection connect the client to the server and launch the game.
*
* @param ac
* @param av
* @return true
* @return false
*/
bool	Command::startConnection(int ac, char **av)
{
	std::vector<int>	pos{-1, -1, 0};

	for (int i = 1; i < ac; i += 2) {
		if (std::strcmp(av[i], "-p") == 0)
			pos[0] = i + 1;
		else if (std::strcmp(av[i], "-n") == 0)
			pos[1] = i + 1;
		else if (std::strcmp(av[i], "-h") == 0)
			pos[2] = i + 1;
	}
	if (pos[0] == -1 || pos[1] == -1)
		return (false);
	if (this->_so->launchMysocket(std::atoi(av[pos[0]]), av[pos[2]], pos[2])
	== false) {
		perror("");
		return (false);
	}
	std::cout << this->_so->wlisten() << std::endl;
	this->_so->wwrite(av[pos[1]]);
	this->_so->wwrite("\n");
	return (true);
}

/**
* @brief forward Ia move forward.
*
*/
void	Command::forward() const
{
	this->_so->wwrite("Forward\n");
}

/**
* @brief right Ia move to the right.
*
*/
void	Command::right() const
{
	this->_so->wwrite("Right\n");
}

/**
* @brief left Ia move to the left.
*
*/
void	Command::left() const
{
	this->_so->wwrite("Left\n");
}

/**
* @brief look Ia look around.
*
*/
void	Command::look() const
{
	this->_so->wwrite("Look\n");
}

/**
* @brief inventory Ia check his inventory.
*
*/
void	Command::inventory() const
{
	this->_so->wwrite("Inventory\n");
}

/**
* @brief broadcast Ia say something.
*
* @param broad
*/
void	Command::broadcast(const std::string broad) const
{
	this->_so->wwrite("Broadcast ");
	this->_so->wwrite(broad.c_str());
	this->_so->wwrite(" \n");
}

/**
* @brief connectNbr return the number of unused team number.
*
*/
void	Command::connectNbr() const
{
	this->_so->wwrite("Connect_nbr\n");
}

/**
* @brief pfork Ia open a new team slot.
*
*/
void	Command::pfork() const
{
	this->_so->wwrite("Fork\n");
}

/**
* @brief eject eject other player from Ia actual position.
*
*/
void	Command::eject() const
{
	this->_so->wwrite("Eject\n");
}

/**
* @brief takeObj Ia take an object on the ground.
*
*/
void	Command::takeObj(const std::string object) const
{
	this->_so->wwrite("Take ");
	this->_so->wwrite(object.c_str());
	this->_so->wwrite(" \n");
}

/**
* @brief setObj Ia drop an object on the ground.
*
*/
void	Command::setObj(const std::string object) const
{
	this->_so->wwrite("Set ");
	this->_so->wwrite(object.c_str());
	this->_so->wwrite(" \n");
}

/**
* @brief incantation Ia start his level up if all requirement are ready.
*
*/
void	Command::incantation() const
{
	this->_so->wwrite("Incantation");
}

/**
* @brief getListen Ia listen around him.
*
* @return std::string
*/
std::string	Command::getListen()
{
	return (this->_so->wlisten());
}