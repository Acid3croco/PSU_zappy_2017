/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** class Objectif
*/

#ifndef OBJECTIF_HPP_
	#define OBJECTIF_HPP_

#include <vector>
#include <iostream>

/**
* @brief Objectif : find and go to objectif defined by the _goal variable.
*
*/
class Objectif {
public:
	Objectif();
	~Objectif();
	std::vector<int>	getGoal(const int lvl) const;
	std::vector<std::vector<int>>	parseLoop(std::string buf, const int lvl);
protected:
private:
	std::vector<int>	getObjectTile(std::string buf);
	std::vector<int>	addObject(std::string token, std::vector<int> tile);
};

#endif /* !OBJECTIF_HPP_ */
