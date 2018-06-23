/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** Class movement methods
*/

#include "Movement.hpp"

/**
* @brief Construct a new Movement:: Movement object
*
*/
Movement::Movement() : _path(1), _size(0)
{
	this->_direction = {"X", "Forward", "Left", "Right"};
}

/**
* @brief Destroy the Movement:: Movement object
*
*/
Movement::~Movement()
{
}

/**
* @brief assignPath assign the different movement needed by the Ia.
*
* @param y
* @param x
*/
void	Movement::assignPath(int y, int x)
{
	std::vector<int>::iterator	it = this->_path.begin();

	it = this->_path.insert(it, y, Movement::Direction::FORWARD);
	if (x > 0) {
		it = this->_path.insert(it, Movement::Direction::RIGHT);
		it = this->_path.insert(it, x, Movement::Direction::FORWARD);
	}
	else if (x < 0) {
		it = this->_path.insert(it, Movement::Direction::LEFT);
		it = this->_path.insert(it, -x, Movement::Direction::FORWARD);
	}
}

/**
* @brief calculPath calcul the path due to the pos.
*
* @param pos
*/
void	Movement::calculPath(int pos)
{
	int	x = 3;
	int	y = 1;
	int	tmp = 0;

	if (pos > 3)
		tmp = 3;
	for (;x < pos; x = x + 2, tmp = tmp + tmp + 2, y++);
	//std::cout << "x : " << x << ", y : " << y << ", tmp :" << tmp << ", pos :" << pos << std::endl;
	x = (x / 2) + 1;
	x = (pos - tmp) - x;
	this->_size = 0;
	this->assignPath(y, x);
}

/**
* @brief checkEmpty check if the tile is empty.
*
* @param tile
* @return true
* @return false
*/
bool	Movement::checkEmpty(std::vector<int> tile)
{
	for (int i = 0; i < 6; i++) {
		if (tile[i] != 0)
			return (false);
	}
	return (true);
}

/**
* @brief findPath parse the message and find a path to follow.
*
* @param sight
* @param index
*/
void	Movement::findPath(std::vector<std::vector<int>> sight, int index,
int size)
{
	int	pos = 1;
	int	x;
	int	y;

	if (index == -1)
		for (; pos < (int)sight.size() &&
		this->checkEmpty(sight[pos]) == true; pos++);
	else
		for (; pos < (int)sight.size() &&
		sight[pos][index] == 0; pos++);
	if (pos < (int)sight.size())
		this->calculPath(pos);
	else {
		x = 0;
		if (this->_size < size) {
			x = 1;
			this->_size = 0;
		}
		y = 1;
		this->_size++;
		this->assignPath(y, x);
	}
}

/**
* @brief verifPath verification of the existence of path.
*
* @return true
* @return false
*/
bool	Movement::verifPath() const
{
	if (this->_path[0] == 0)
		return (false);
	return (true);
}

/**
* @brief getDirection return the direction to follow.
*
* @return std::string
*/
std::string	Movement::getDirection()
{
	int	ret;

	ret = this->_path[0];
	if (ret != 0)
		this->_path.erase(this->_path.begin());
	return (this->_direction[ret]);
}