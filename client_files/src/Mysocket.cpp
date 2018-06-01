/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** Mysocket source
*/

#include "Mysocket.hpp"

Mysocket::Mysocket(const std::string ip, const int port) : _ip(ip),
_port(port)
{
}

Mysocket::~Mysocket()
{
}

int	Mysocket::Wgetprotobyname()
{
	this->_pe = getprotobyname("TCP");
	if (this->_pe == NULL)
		return (-1);
	return (0);
}

int	Mysocket::Wsocket()
{
	this->_fd = socket(AF_INET, SOCK_STREAM, this->_pe->p_proto);
	return (this->_fd);
}

uint16_t	Mysocket::Whtons()
{
	return (htons(this->_port));
}

in_addr_t	Mysocket::WinetAddr()
{
	return (inet_addr(this->_ip.c_str()));
}

int	Mysocket::Wconnect()
{
	return (connect(this->_fd,
	(struct sockaddr *)&this->_addr, sizeof(this->_addr)) == -1);
}

int	Mysocket::Wclose()
{
	return (close(this->_fd));
}

int	Mysocket::LaunchMysocket()
{
	if (Wgetprotobyname() == -1)
		return (-1);
	if(Wsocket() == -1)
		return (-1);
	this->_addr.sin_family = AF_INET;
	this->_addr.sin_port = Whtons();
	this->_addr.sin_addr.s_addr = WinetAddr();
	if (Wconnect() == -1) {
		Wclose();
		return (-1);
	}
	return (0);
}

char	*Mysocket::Wlisten(char *buf)
{
	FILE	*fs = fdopen(this->_fd, "r");
	size_t	len = 4096;

	buf = (char *)memset(buf, 0, 4096);
	if (getline(&buf, &len, (FILE *)fs) == -1) {
		perror("");
		free(buf);
		return (NULL);
	}
	return (buf);
}

void	Mysocket::Wwrite(const char *s)
{
	write(this->_fd, s, strlen(s));
}