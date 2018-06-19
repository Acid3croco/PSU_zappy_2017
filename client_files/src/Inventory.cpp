/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** Inventory handling source
*/

#include "Inventory.hpp"

/**
* @brief Construct a new Inventory:: Inventory object
*
*/
Inventory::Inventory() : _res(7)
{
}

/**
* @brief Destroy the Inventory:: Inventory object
*
*/
Inventory::~Inventory()
{
}

/**
* @brief setInventory prepare the inventory for the Ia
*
* @param buf
*/
void	Inventory::parseInventory(std::string buf)
{
	std::string	token;
	size_t		pos;

	buf.erase(0, 2);
	buf.erase(buf.length() - 2, buf.length());
	for (int i = 0; i < 7; i++) {
		pos = buf.find(", ");
		token = buf.substr(0, pos);
		buf.erase(0, pos + 2);
		this->setInventory(token);
	}
	this->_res[0].first = std::string("linemate");
	this->_res[1].first = std::string("deraumere");
	this->_res[2].first = std::string("sibur");
	this->_res[3].first = std::string("mendiane");
	this->_res[4].first = std::string("phiras");
	this->_res[5].first = std::string("thystame");
	this->_res[6].first = std::string("food");
}

/**
* @brief priority choose the ressource Ia need to find first.
*
* @return std::pair<std::string, int>
*/
std::pair<std::string, int>	Inventory::getPriority(std::vector<int> goal)
{
	if (this->_res[this->FOOD].second < 10)
		return (this->_res[this->FOOD]);
	for (int i = 0; i < 6; i++) {
		if (goal[i] > this->_res[i].second)
			return (this->_res[i]);
	}
	return(this->_res[this->FOOD]);
}

/**
* @brief getInventory return the inventory.
*
* @return std::vector<std::pair<std::string, int>>
*/
std::vector<std::pair<std::string, int>>	Inventory::getInventory() const
{
	return (this->_res);
}

/**
* @brief setInventory assign the value of the last inventory cmd.
*
* @param buf
*/
void	Inventory::setInventory(std::string buf)
{
	std::string	token;
	size_t		pos;

	pos = buf.find(" ");
	token = buf.substr(0, pos);
	buf.erase(0, pos + 1);
	switch((int)token.front()) {
		case 'l' : this->_res[0].second = atoi(buf.c_str());
			break;
		case 'd' : this->_res[1].second = atoi(buf.c_str());
			break;
		case 's' : this->_res[2].second = atoi(buf.c_str());
			break;
		case 'm' : this->_res[3].second = atoi(buf.c_str());
			break;
		case 'p' : this->_res[4].second = atoi(buf.c_str());
			break;
		case 't' : this->_res[5].second = atoi(buf.c_str());
			break;
		case 'f' : this->_res[6].second = atoi(buf.c_str());
			break;
	}
}

/**
* @brief findId find the id of the ressource.
*
* @param goal
* @return int
*/
int	Inventory::findId(std::string goal)
{
	for (int i = 0; i < 7; i++) {
		if (goal.compare(this->_res[i].first) == 0)
			return (i);
	}
	return (-1);
}