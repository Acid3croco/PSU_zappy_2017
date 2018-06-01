/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** source command
*/

#include "Command.hpp"

Command::Command()
{
}

Command::~Command()
{
}

void	Command::forward() const
{
	this->_so->wwrite("Forward\n");
	this->_so->wlisten();
}

void	Command::right() const
{
	this->_so->wwrite("Right\n");
	this->_so->wlisten();
}

void	Command::left() const
{
	this->_so->wwrite("Left\n");
	this->_so->wlisten();
}

std::string	Command::look() const
{
	std::string	msg;

	this->_so->wwrite("Look\n");
	msg = this->_so->wlisten();
	return (msg);
}

std::string	Command::inventory() const
{
	std::string	msg;

	this->_so->wwrite("Inventory\n");
	msg = this->_so->wlisten();
	return (msg);
}

void	Command::broadcast(std::string broad) const
{
	this->_so->wwrite(broad.c_str());
	this->_so->wlisten();
}

int	Command::connectNbr() const
{
	int		nbr;
	std::string	msg;

	this->_so->wwrite("Connect_nbr\n");
	msg = this->_so->wlisten();
	nbr = stoi(msg, nullptr);
	return (nbr);
}

void	Command::pfork() const
{
	this->_so->wwrite("Fork\n");
	this->_so->wlisten();
}

bool	Command::eject() const
{
	std::string	msg;

	this->_so->wwrite("Eject\n");
	msg = this->_so->wlisten();
	if (msg.compare("ko\n") == 0)
		return (false);
	return (true);
}

bool	Command::takeObj() const
{
	std::string	msg;

	this->_so->wwrite("Take object\n");
	msg = this->_so->wlisten();
	if (msg.compare("ko\n") == 0)
		return (false);
	return (true);
}

bool	Command::setObj() const
{
	std::string	msg;

	this->_so->wwrite("Set object\n");
	msg = this->_so->wlisten();
	if (msg.compare("ko\n") == 0)
		return (false);
	return (true);
}

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

void	Command::setSo(const Mysocket &socket)
{
	this->_so = new Mysocket(socket);
}