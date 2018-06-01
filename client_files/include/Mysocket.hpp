/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** class Mysocket
*/

#ifndef Mysocket_HPP_
	#define Mysocket_HPP_

#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include <cstring>

class Mysocket {
public:
	Mysocket(const std::string ip, const int port);
	~Mysocket();
	int	LaunchMysocket();
	char	*Wlisten(char *);
	void	Wwrite(const char *s);
protected:
private:
	int	Wgetprotobyname();
	int	Wsocket();
	uint16_t	Whtons();
	in_addr_t	WinetAddr();
	int	Wconnect();
	int	Wclose();
	const std::string	_ip;
	int			_port;
	int			_fd;
	struct sockaddr_in	_addr;
	struct protoent		*_pe;
};

#endif /* !Mysocket_HPP_ */
