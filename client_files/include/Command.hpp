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
		void	look() const;
		void	inventory() const;
		void	broadcast(const std::string broad) const;
		void	connectNbr() const;
		void	pfork() const;
		void	eject() const;
		void	takeObj(const std::string object) const;
		void	setObj(const std::string ocbject) const;
		void	incantation() const;
		std::string	getListen();
	protected:
	private:
		Mysocket	*_so;
};

#endif /* !COMMAND_HPP_ */
