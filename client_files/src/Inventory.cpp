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
	for (int i = 0; i < 7; i++)
		std::cout << this->_res[i] << std::endl;
}

/**
* @brief priority choose the ressource Ia need to find first.
*
* @return std::string
*/
std::string	Inventory::priority()
{
	if (this->_res[this->FOOD] < 10)
		return ("food");
	return("food");
}

/**
* @brief getInventory return the inventory.
*
* @return std::vector<int>
*/
std::vector<int>	Inventory::getInventory() const
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
		case 'f' : this->_res[0] = atoi(buf.c_str());
			break;
		case 'l' : this->_res[1] = atoi(buf.c_str());
			break;
		case 'd' : this->_res[2] = atoi(buf.c_str());
			break;
		case 's' : this->_res[3] = atoi(buf.c_str());
			break;
		case 'm' : this->_res[4] = atoi(buf.c_str());
			break;
		case 'p' : this->_res[5] = atoi(buf.c_str());
			break;
		case 't' : this->_res[6] = atoi(buf.c_str());
			break;
	}
}