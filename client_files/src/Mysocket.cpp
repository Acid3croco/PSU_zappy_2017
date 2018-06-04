/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** Mysocket source
*/

#include "Mysocket.hpp"

/**
 * @brief Construct a new Mysocket:: Mysocket object
 *
 */
Mysocket::Mysocket()
{
}

/**
* @brief Construct a new Mysocket:: Mysocket object
*
* @param copy
*/
Mysocket::Mysocket(const Mysocket &copy) : _ip(copy.getIp()),
_port(copy.getPort()), _fd(copy.getFd()), _addr(copy.getAddr()),
_pe(copy.getPe())
{
}

/**
* @brief Destroy the Mysocket:: Mysocket object
*
*/
Mysocket::~Mysocket()
{
}

/**
* @brief
*
* @return int
*/
int	Mysocket::wgetprotobyname()
{
	this->_pe = getprotobyname("TCP");
	if (this->_pe == NULL)
		return (-1);
	return (0);
}

/**
* @brief
*
* @return int
*/
int	Mysocket::wsocket()
{
	this->_fd = socket(AF_INET, SOCK_STREAM, this->_pe->p_proto);
	return (this->_fd);
}

/**
* @brief
*
* @return uint16_t
*/
uint16_t	Mysocket::whtons()
{
	return (htons(this->_port));
}

/**
* @brief
*
* @return in_addr_t
*/
in_addr_t	Mysocket::winetAddr()
{
	return (inet_addr(this->_ip.c_str()));
}

/**
* @brief
*
* @return int
*/
int	Mysocket::wconnect()
{
	return (connect(this->_fd,
	(struct sockaddr *)&this->_addr, sizeof(this->_addr)) == -1);
}

/**
* @brief
*
* @return int
*/
int	Mysocket::wclose()
{
	return (close(this->_fd));
}

/**
* @brief
*
* @return std::string
*/
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

/**
* @brief
*
* @param s
*/
void	Mysocket::wwrite(const char *s)
{
	write(this->_fd, s, strlen(s));
}

/**
* @brief
*
* @param ip
* @param port
* @return int
*/
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

/**
* @brief
*
* @return const std::string
*/
const std::string	Mysocket::getIp() const
{
	return(this->_ip);
}

/**
* @brief
*
* @return int
*/
int	Mysocket::getPort() const
{
	return(this->_port);
}

/**
* @brief
*
* @return int
*/
int	Mysocket::getFd()const
{
	return(this->_fd);
}

/**
* @brief
*
* @return struct sockaddr_in
*/
struct sockaddr_in	Mysocket::getAddr() const
{
	return(this->_addr);
}

/**
* @brief
*
* @return struct protoent*
*/
struct protoent	*Mysocket::getPe() const
{
	return(this->_pe);
}