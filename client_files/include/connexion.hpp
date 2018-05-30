/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** class connexion
*/

#ifndef CONNEXION_HPP_
	#define CONNEXION_HPP_

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>

class Connexion {
public:
	Connexion(const std::string ip, const int port);
	~Connexion();
	int	launch_connexion();
	int	Wgetprotobyname();
	int	Wsocket();
	uint16_t	Whtons();
	in_addr_t	WinetAddr();
	int	Wconnect();
	int	Wclose();
protected:
private:
	int			_fd;
	int			_port;
	struct sockaddr_in	_addr;
	struct protoent		*_pe;
	std::string		_ip;
};

#endif /* !CONNEXION_HPP_ */
