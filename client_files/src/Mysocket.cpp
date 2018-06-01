/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** Mysocket source
*/

#include "Mysocket.hpp"

Mysocket::Mysocket()
{
}

Mysocket::Mysocket(const Mysocket &copy) : _ip(copy.getIp()),
_port(copy.getPort()), _fd(copy.getFd()), _addr(copy.getAddr()),
_pe(copy.getPe())
{
}

Mysocket::~Mysocket()
{
}

int	Mysocket::wgetprotobyname()
{
	this->_pe = getprotobyname("TCP");
	if (this->_pe == NULL)
		return (-1);
	return (0);
}

int	Mysocket::wsocket()
{
	this->_fd = socket(AF_INET, SOCK_STREAM, this->_pe->p_proto);
	return (this->_fd);
}

uint16_t	Mysocket::whtons()
{
	return (htons(this->_port));
}

in_addr_t	Mysocket::winetAddr()
{
	return (inet_addr(this->_ip.c_str()));
}

int	Mysocket::wconnect()
{
	return (connect(this->_fd,
	(struct sockaddr *)&this->_addr, sizeof(this->_addr)) == -1);
}

int	Mysocket::wclose()
{
	return (close(this->_fd));
}

std::string	Mysocket::wlisten()
{
	FILE		*fs = fdopen(this->_fd, "r");
	char		*buf = (char *)malloc(4096);
	std::string	str;
	size_t		len = 4096;

	buf = (char *)memset(buf, 0, 4096);
	if (getline(&buf, &len, (FILE *)fs) == -1) {
		perror("");
		free(buf);
		str = "";
		return (str);
	}
	str = std::string(buf);
	free(buf);
	return(str);
}

void	Mysocket::wwrite(const char *s)
{
	write(this->_fd, s, strlen(s));
}

int	Mysocket::launchMysocket(const std::string ip, const int port)
{
	this->_ip = ip;
	this->_port = port;
	if (wgetprotobyname() == -1)
		return (-1);
	if(wsocket() == -1)
		return (-1);
	this->_addr.sin_family = AF_INET;
	this->_addr.sin_port = whtons();
	this->_addr.sin_addr.s_addr = winetAddr();
	if (wconnect() == -1) {
		wclose();
		return (-1);
	}
	return (0);
}

const std::string	Mysocket::getIp() const
{
	return(this->_ip);
}

int	Mysocket::getPort() const
{
	return(this->_port);
}

int	Mysocket::getFd()const
{
	return(this->_fd);
}

struct sockaddr_in	Mysocket::getAddr() const
{
	return(this->_addr);
}

struct protoent	*Mysocket::getPe() const
{
	return(this->_pe);
}