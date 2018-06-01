/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** client main
*/

#include "client.hpp"
#include "Mysocket.hpp"

int	printError(void)
{
	perror("");
	return (-1);
}

int	main(int ac, char **av)
{
	Mysocket	*so;
	char		*buf;

	if (ac != 3)
		return (-1);
	so = new Mysocket(av[1], std::atoi(av[2]));
	if (so->LaunchMysocket() == -1)
		return (printError());
	buf = (char *)malloc(4096);
	for (;;) {
		buf = so->Wlisten(buf);
		if (buf == NULL)
			return (-1);
	}
	free(buf);
	return (0);
}