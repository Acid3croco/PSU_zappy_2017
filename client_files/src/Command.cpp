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
Command::Command()
{
}

/**
* @brief Destroy the Command:: Command object
*
*/
Command::~Command()
{
}

bool	Command::startConnection(const char *ip, const int port)
{
	return (this->_so->launchMysocket(ip, port));
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
	if (msg.compare("ko\n") == 0)
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
	if (msg.compare("ko\n") == 0)
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
	if (msg.compare("ko\n") == 0)
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
	if (msg.compare("ko\n") == 0)
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