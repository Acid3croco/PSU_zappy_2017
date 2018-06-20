/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** class Movement
*/

#ifndef MOVEMENT_HPP_
	#define MOVEMENT_HPP_

#include <vector>
#include <iostream>

class Movement {
public:
	enum	Direction {
		X,
		FORWARD,
		LEFT,
		RIGHT
	};
	Movement();
	~Movement();
	std::string	getDirection();
	bool	verifPath() const;
	void	findPath(std::vector<std::vector<int>> sight, int index);
protected:
private:
	std::vector<int>	_path;
	std::vector<std::string>	_direction;
};

#endif /* !MOVEMENT_HPP_ */
