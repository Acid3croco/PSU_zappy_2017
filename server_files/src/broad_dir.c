/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** boradcast direction
*/

#include "server.h"

int get_dir(float angle, cl_t *recev)
{
	int dir = 0;

	dir = (int)angle / 45 + 1;
	dir = (dir > 8) ? 1 : dir;
	switch (recev->look) {
		case 1: dir -= 2;
			dir = (dir < 0) ? dir + 8 : dir;
			break;
		case 2: dir -= 4;
			dir = (dir < 0) ? dir + 8 : dir;
			break;
		case 3: dir -= 6;
			dir = (dir < 0) ? dir + 8 : dir;
			break;
	}
	return (dir);
}

int calc_dir(cl_t *sender, cl_t *recev)
{
	double coef = 0;
	double angle = 0;

	if (recev->y - sender->y != 0)
		coef = (recev->x - sender->x) / (recev->y - sender->y);
	angle = atan(coef);
	angle = angle * 180 / M_PI;
	if (sender->x > recev->x)
		angle += 90;
	if (sender->x < recev->x)
		angle += 270;
	return (get_dir(angle, recev));
}