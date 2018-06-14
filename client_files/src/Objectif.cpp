/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** Objectif functions
*/

#include "Objectif.hpp"

/**
* @brief Construct a new Objectif:: Objectif object
*
*/
Objectif::Objectif()
{
}

/**
* @brief Destroy the Objectif:: Objectif object
*
*/
Objectif::~Objectif()
{
}

/**
* @brief getGoal change goal variable at level up.
*
* @param lvl
* @return std::vector<int>
*/
std::vector<int>	Objectif::getGoal(const int lvl) const
{
	std::vector<int>	goal(6, 0);

	switch (lvl) {
		case 1 : goal = {1, 0, 0, 0, 0, 0};
			break;
		case 2 : goal = {1, 1, 1, 0, 0, 0};
			break;
		case 3 : goal = {2, 0, 1, 0, 2, 0};
			break;
		case 4 : goal = {1, 1, 2, 0, 1, 0};
			break;
		case 5 : goal = {1, 2, 1, 3, 0, 0};
			break;
		case 6 : goal = {1, 2, 3, 0, 1, 0};
			break;
		case 7 : goal = {2, 2, 2, 2, 2, 1};
			break;
	}
	return (goal);
}