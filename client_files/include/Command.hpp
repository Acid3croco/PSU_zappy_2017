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
* @brief
*
*/
class Command {
	public:
		Command();
		~Command();
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
		void	setSo(const Mysocket &so);
	protected:
	private:
		Mysocket	*_so;
};

#endif /* !COMMAND_HPP_ */
