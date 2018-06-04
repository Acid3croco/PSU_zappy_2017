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

/**
* @brief
*
*/
void	Command::forward() const
{
	this->_so->wwrite("Forward\n");
	this->_so->wlisten();
}

/**
* @brief
*
*/
void	Command::right() const
{
	this->_so->wwrite("Right\n");
	this->_so->wlisten();
}

/**
* @brief
*
*/
void	Command::left() const
{
	this->_so->wwrite("Left\n");
	this->_so->wlisten();
}

/**
* @brief
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
* @brief
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
* @brief
*
* @param broad
*/
void	Command::broadcast(std::string broad) const
{
	this->_so->wwrite(broad.c_str());
	this->_so->wlisten();
}

/**
* @brief
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
* @brief
*
*/
void	Command::pfork() const
{
	this->_so->wwrite("Fork\n");
	this->_so->wlisten();
}

/**
* @brief
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
* @brief
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
* @brief
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
* @brief
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
* @brief
*
* @param socket
*/
void	Command::setSo(const Mysocket &socket)
{
	this->_so = new Mysocket(socket);
}