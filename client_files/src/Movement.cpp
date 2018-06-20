/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** Class movement methods
*/

#include "Movement.hpp"

Movement::Movement() : _path(0)
{
	this->_direction = {"X", "forward", "left", "right"};
}

Movement::~Movement()
{
}

void	Movement::findPath(std::vector<std::vector<int>> sight, int index)
{
	int	pos = 1;
	int	x = 3;
	int	y = 1;
	int	tmp = 3;
	std::vector<int>::iterator	it = this->_path.begin();

	for (; pos < sight.size() && sight[pos][index] < 0; pos++);
	for (;x < pos; x = x + 2, tmp = tmp + tmp + 2, y++);
	pos = (tmp - pos) - (x / 2) + 1;
	it = this->_path.insert(it, y, Movement::Direction::FORWARD);
	tmp = 1;
	if (pos < 0) {
		it = this->_path.insert(it, Movement::Direction::LEFT);
			tmp *= -1;
	}
	else if (pos > 0)
		it = this->_path.insert(it, Movement::Direction::RIGHT);
	it = this->_path.insert(it, pos, Movement::Direction::FORWARD);
}


bool	Movement::verifPath() const
{
	if (this->_path[0] == 0)
		return (false);
	return (true);
}

std::string	Movement::getDirection()
{
	int	ret;

	ret = this->_path[0];
	if (ret != 0)
		this->_path.erase(this->_path.begin());
	return (this->_direction[ret]);
}