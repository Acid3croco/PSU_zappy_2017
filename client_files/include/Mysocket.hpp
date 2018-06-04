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

/**
* @brief Mysocket : connect to server and communicate with him.
*
*/
class Mysocket {
public:
	Mysocket();
	~Mysocket();
	bool	launchMysocket(const std::string ip, const int port);
	std::string	wlisten();
	void	wwrite(const char *s);
	const std::string	getIp() const;
	int			getPort() const;
	int			getFd() const;
	struct sockaddr_in	getAddr() const;
	struct protoent		*getPe() const;
protected:
private:
	int	wgetprotobyname();
	int	wsocket();
	uint16_t	whtons();
	in_addr_t	winetAddr();
	int	wconnect();
	int	wclose();
	std::string	_ip;
	int			_port;
	int			_fd;
	struct sockaddr_in	_addr;
	struct protoent		*_pe;
};

#endif /* !Mysocket_HPP_ */
