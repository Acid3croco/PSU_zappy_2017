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
		LINEMATE,
		DERAUMERE,
		SIBUR,
		MENDIANE,
		PHIRAS,
		THYSTAME,
		FOOD
	};
	Inventory();
	~Inventory();
	void	parseInventory(std::string buf);
	std::pair<std::string, int>	getPriority(std::vector<int> goal);
	int	getInventory(std::string ressource) const;
	int	findId(std::string goal);
	std::vector<std::string>	getRessourceName();
protected:
private:
	void	setInventory(std::string buf);
	std::vector<std::pair<std::string, int>>	_res;
};

#endif /* !INVENTORY_HPP_ */
