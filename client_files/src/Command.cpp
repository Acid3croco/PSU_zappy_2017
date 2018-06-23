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
Command::Command() : _so(new Mysocket()), _lastCmd(0), _team("-1")
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
	std::vector<int>	pos{-1, 0};

	for (int i = 1; i < ac; i += 2) {
		if (std::strcmp(av[i], "-p") == 0)
			pos[0] = i + 1;
		else if (std::strcmp(av[i], "-n") == 0)
			this->_team = std::string(av[i + 1]);
		else if (std::strcmp(av[i], "-h") == 0)
			pos[1] = i + 1;
	}
	if (pos[0] == -1 || this->_team.compare("noTeam") == 0)
		return (false);
	if (this->_so->launchMysocket(std::atoi(av[pos[0]]), av[pos[1]], pos[1])
	== false)
		return (false);
	if (this->_so->wlisten().compare("WELCOME\n") != 0)
		return (false);
	this->_so->wwrite(this->_team.c_str());
	this->_so->wwrite("\n");
	return (true);
}

/**
* @brief move allow Ia to move.
*
* @param direction
*/
void	Command::move(std::string direction)
{
	std::vector<std::string>::iterator	it = this->_lastCmd.begin();

	this->_so->wwrite(direction.c_str());
	this->_so->wwrite("\n");
	this->_lastCmd.insert(it, "move");
}

/**
* @brief look Ia look around.
*
*/
void	Command::look()
{
	std::vector<std::string>::iterator	it = this->_lastCmd.begin();

	this->_so->wwrite("Look\n");
	this->_lastCmd.insert(it, "look");
}

/**
* @brief inventory Ia check his inventory.
*
*/
void	Command::inventory()
{
	std::vector<std::string>::iterator	it = this->_lastCmd.begin();

	this->_so->wwrite("Inventory\n");
	this->_lastCmd.insert(it, "inventory");
}

/**
* @brief broadcast Ia say something.
*
* @param broad
*/
void	Command::broadcast(const std::string broad)
{
	std::vector<std::string>::iterator	it = this->_lastCmd.begin();

	this->_so->wwrite("Broadcast ");
	this->_so->wwrite(broad.c_str());
	this->_so->wwrite("\n");
	this->_lastCmd.insert(it, "broadcast");
}

/**
* @brief connectNbr return the number of unused team number.
*
*/
void	Command::connectNbr()
{
	std::vector<std::string>::iterator	it = this->_lastCmd.begin();

	this->_so->wwrite("Connect_nbr\n");
	this->_lastCmd.insert(it, "connect_nbr");
}

/**
* @brief pfork Ia open a new team slot.
*
*/
void	Command::pfork()
{
	std::vector<std::string>::iterator	it = this->_lastCmd.begin();

	this->_so->wwrite("Fork\n");
	this->_lastCmd.insert(it, "fork");
}

/**
* @brief eject eject other player from Ia actual position.
*
*/
void	Command::eject()
{
	std::vector<std::string>::iterator	it = this->_lastCmd.begin();

	this->_so->wwrite("Eject\n");
	this->_lastCmd.insert(it, "eject");
}

/**
* @brief takeObj Ia take an object on the ground.
*
*/
void	Command::takeObj(const std::string object)
{
	std::vector<std::string>::iterator	it = this->_lastCmd.begin();

	this->_so->wwrite("Take ");
	this->_so->wwrite(object.c_str());
	this->_so->wwrite("\n");
	this->_lastCmd.insert(it, "takeObj");
}

/**
* @brief setObj Ia drop an object on the ground.
*
*/
void	Command::setObj(const std::string object)
{
	std::vector<std::string>::iterator	it = this->_lastCmd.begin();

	this->_so->wwrite("Set ");
	this->_so->wwrite(object.c_str());
	this->_so->wwrite("\n");
	this->_lastCmd.insert(it, "setObj");
}

/**
* @brief incantation Ia start his level up if all requirement are ready.
*
*/
void	Command::incantation()
{
	std::vector<std::string>::iterator	it = this->_lastCmd.begin();

	this->_so->wwrite("Incantation\n");
	this->_lastCmd.insert(it, "incantation");
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

/**
* @brief compareCmd compare the message send by the server and string.
*
* @param cmd
* @return true
* @return false
*/
bool	Command::compareCmd(std::string cmd)
{
	if (this->_lastCmd.back().compare(cmd) == 0)
		return (true);
	return (false);
}

/**
* @brief popBack delete the last element of the message queue.
*
*/
void	Command::popBack()
{
	this->_lastCmd.pop_back();
}

/**
* @brief getTeam return the name of the team.
*
* @return std::string
*/
std::string	Command::getTeam()
{
	return (this->_team);
}

/**
* @brief verifFd verification if the fd exist.
*
* @return int
*/
int	Command::verifFd() const
{
	return (this->_so->getFd());
}

bool	Command::verifExist(std::string cmd) const
{
	for (int i = 0; i < (int)this->_lastCmd.size(); i++) {
		if (this->_lastCmd[i].compare(cmd) == 0)
			return (true);
	}
	return(false);
}