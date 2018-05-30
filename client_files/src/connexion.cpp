/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** connexion source
*/

#include "client.hpp"
#include "connexion.hpp"

Connexion::Connexion(const std::string ip, const int port) : _ip(ip), _port(port)
{
}

Connexion::~Connexion()
{
}

int	Connexion::Wgetprotobyname()
{
	this->_pe = getprotobyname("TCP");
	if (this->_pe == NULL)
		return (-1);
	return (0);
}

int	Connexion::Wsocket()
{
	this->_fd = socket(AF_INET, SOCK_STREAM, this->_pe->p_proto);
	return (this->_fd);
}

uint16_t	Connexion::Whtons()
{
	return (htons(this->_port));
}

in_addr_t	Connexion::WinetAddr()
{
	return (inet_addr(this->_ip.c_str));
}

int	Connexion::Wconnect()
{
	return (connect(this->_fd,
	(struct sockaddr *)&this->_addr, sizeof(this->_addr)) == -1);
}

int	Connexion::Wclose()
{
	return (close(this->_fd));
}

int	Connexion::launch_connexion()
{
	if (Wgetprotobyname() == -1)
		return (-1);
	if(Wsocket() == -1)
		return (-1);
	this->_addr.sin_family = AF_INET;
	this->_addr.sin_port = Whtons();
	this->_addr.sin_addr.s_addr = WinetAddr();
	if (Wconnect() == -1) {
		if (Wclose() == -1)
			return (-1);
		return (-1);
	}
	Wclose();
	return (0);
}