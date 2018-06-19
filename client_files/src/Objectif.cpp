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

/**
* @brief parseLoop parse the server message and assign the values to a matrix.
*
* @param buf
* @param lvl
* @return std::vector<std::vector<int>>
*/
std::vector<std::vector<int>>	Objectif::parseLoop(std::string buf,
const int lvl)
{
	int				nbrTile = (lvl + 1) * (lvl + 1);
	std::vector<std::vector<int>>	matrix(nbrTile, std::vector<int>(7));
	size_t				pos;
	std::string			token;

	buf.erase(0, 1);
	for (int i = 0; nbrTile > i; i++) {
		if (buf.front() == ' ')
			buf.erase(0, 1);
		pos = buf.find(",");
		token = buf.substr(0, pos);
		matrix[i] = this->getObjectTile(token);
		buf.erase(0, pos + 1);
	}
	return (matrix);
}

/**
* @brief getObjectTile assign value for each element on a single tile.
*
* @param buf
* @return std::vector<int>
*/
std::vector<int>	Objectif::getObjectTile(std::string buf)
{
	std::vector<int>	tile;
	size_t			pos;
	std::string		token;

	tile = {0, 0, 0, 0, 0, 0, 0};
	for (int i = 0; (pos = buf.find(" ")) != std::string::npos; i++) {
		token = buf.substr(0, pos);
		tile = this->addObject(token, tile);
		if (buf.length() <= pos + 1)
			break;
		buf.erase(0, pos + 1);
	}
	tile = this->addObject(buf, tile);
	return (tile);
}

/**
* @brief addObject find and add one to the good element.
*
* @param token
* @param tile
* @return std::vector<int>
*/
std::vector<int>	Objectif::addObject(std::string token,
std::vector<int> tile)
{
	switch((int)token.front()) {
		case 'l' : tile[0]++;
			break;
		case 'd' : tile[1]++;
			break;
		case 's' : tile[2]++;
			break;
		case 'm' : tile[3]++;
			break;
		case 'p' :
			if (token.compare("phiras") == 0)
				tile[4]++;
			break;
		case 't' : tile[5]++;
			break;
		case 'f' : tile[6]++;
			break;
	}
	return (tile);
}