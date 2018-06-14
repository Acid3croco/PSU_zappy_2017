/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** class Objectif
*/

#ifndef OBJECTIF_HPP_
	#define OBJECTIF_HPP_

#include <vector>

/**
* @brief Objectif : find and go to objectif defined by the _goal variable.
*
*/
class Objectif {
public:
	Objectif();
	~Objectif();
	std::vector<int>	getGoal(const int lvl) const;
protected:
private:
};

#endif /* !OBJECTIF_HPP_ */
