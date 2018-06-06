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
	this->_so->wlisten();
}

/**
* @brief right Ia move to the right.
*
*/
void	Command::right() const
{
	this->_so->wwrite("Right\n");
	this->_so->wlisten();
}

/**
* @brief left Ia move to the left.
*
*/
void	Command::left() const
{
	this->_so->wwrite("Left\n");
	this->_so->wlisten();
}

/**
* @brief look Ia look around.
*
* @return std::string
*/
std::string	Command::look() const
{
	std::string	msg;

	this->_so->wwrite("Look\n");
	msg = this->_so->wlisten();
	return (msg);
}

/**
* @brief inventory Ia check his inventory.
*
* @return std::string
*/
std::string	Command::inventory() const
{
	std::string	msg;

	this->_so->wwrite("Inventory\n");
	msg = this->_so->wlisten();
	return (msg);
}

/**
* @brief broadcast Ia say something.
*
* @param broad
*/
void	Command::broadcast(std::string broad) const
{
	this->_so->wwrite(broad.c_str());
	this->_so->wlisten();
}

/**
* @brief connectNbr return the number of unused team number.
*
* @return int
*/
int	Command::connectNbr() const
{
	int		nbr;
	std::string	msg;

	this->_so->wwrite("Connect_nbr\n");
	msg = this->_so->wlisten();
	nbr = stoi(msg, nullptr);
	return (nbr);
}

/**
* @brief pfork Ia open a new team slot.
*
*/
void	Command::pfork() const
{
	this->_so->wwrite("Fork\n");
	this->_so->wlisten();
}

/**
* @brief eject eject other player from Ia actual position.
*
* @return true
* @return false
*/
bool	Command::eject() const
{
	std::string	msg;

	this->_so->wwrite("Eject\n");
	msg = this->_so->wlisten();
	if (msg.compare("ko e\n") == 0)
		return (false);
	return (true);
}

/**
* @brief takeObj Ia take an object on the ground.
*
* @return true
* @return false
*/
bool	Command::takeObj() const
{
	std::string	msg;

	this->_so->wwrite("Take object\n");
	msg = this->_so->wlisten();
	if (msg.compare("ko t\n") == 0)
		return (false);
	return (true);
}

/**
* @brief setObj Ia drop an object on the ground.
*
* @return true
* @return false
*/
bool	Command::setObj() const
{
	std::string	msg;

	this->_so->wwrite("Set object\n");
	msg = this->_so->wlisten();
	if (msg.compare("ko s\n") == 0)
		return (false);
	return (true);
}

/**
* @brief incantation Ia start his level up if all requirement are ready.
*
* @return int
*/
int	Command::incantation() const
{
	std::string	msg;
	int		nbr;

	this->_so->wwrite("Incantation");
	if (msg.compare("ko i\n") == 0)
		return (-1);
	nbr = stoi(msg, nullptr);
	return (nbr);
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