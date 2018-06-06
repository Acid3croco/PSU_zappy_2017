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
		void	forward() const;
		void	right() const;
		void	left() const;
		std::string	look() const;
		std::string	inventory() const;
		void	broadcast(std::string broad) const;
		int	connectNbr() const;
		void	pfork() const;
		bool	eject() const;
		bool	takeObj() const;
		bool	setObj() const;
		int	incantation() const;
		std::string	getListen();
	protected:
	private:
		Mysocket	*_so;
};

#endif /* !COMMAND_HPP_ */
