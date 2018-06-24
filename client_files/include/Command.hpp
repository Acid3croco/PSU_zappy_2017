/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** class command
*/

#ifndef COMMAND_HPP_
	#define COMMAND_HPP_

#include "Client.hpp"
#include "Mysocket.hpp"

/**
* @brief Command : Action to be done by the ia, directly talk to the server.
*
*/
class Command {
public:
	Command();
	~Command();
	bool	startConnection(int ac, char **av);
	void	move(std::string direction);
	void	look();
	void	inventory();
	void	broadcast(const std::string broad);
	void	connectNbr();
	void	pfork();
	void	eject();
	void	takeObj(const std::string object);
	void	setObj(const std::string ocbject);
	void	incantation();
	std::string	getListen();
	bool	compareCmd(std::string cmd);
	std::string	getTeam();
	int		verifFd() const;
	void	popBack();
	bool	verifExist(std::string cmd) const;
protected:
private:
	Mysocket	*_so;
	std::vector<std::string>	_lastCmd;
	std::string	_team;
};

#endif /* !COMMAND_HPP_ */
