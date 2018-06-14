/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** class Inventory
*/

#ifndef INVENTORY_HPP_
	#define INVENTORY_HPP_

#include <iostream>
#include <vector>

/**
* @brief Inventory : inventory of Ia, and choose what the Ia need to find first.
*
*/
class Inventory {
public:
	enum	Type {
		FOOD,
		LINEMATE,
		DERAUMERE,
		SIBUR,
		MENDIANE,
		PHIRAS,
		THYSTAME
	};
	Inventory();
	~Inventory();
	void	parseInventory(std::string buf);
	std::string	priority();
	//std::vector<std::string>	getRessource(int lvl);
protected:
private:
	void	setInventory(std::string buf);
	std::vector<int>	_res;
};

#endif /* !INVENTORY_HPP_ */
