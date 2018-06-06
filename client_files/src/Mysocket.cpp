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
Mysocket::Mysocket() : _ip("0")
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
* @brief WgetProtoByNamewrap the C function getprotobyname.
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
* @brief wsocket wrap the C function socket.
*
* @return int
*/
int	Mysocket::wsocket()
{
	this->_fd = socket(AF_INET, SOCK_STREAM, this->_pe->p_proto);
	return (this->_fd);
}

/**
* @brief whtons wrap the C function htons.
*
* @return uint16_t
*/
uint16_t	Mysocket::whtons()
{
	return (htons(this->_port));
}

/**
* @brief winetAddr wrap the C function inet_addr.
*
* @return in_addr_t
*/
in_addr_t	Mysocket::winetAddr()
{
	return (inet_addr(this->_ip.c_str()));
}

/**
* @brief wconnect wrap the C function connect.
*
* @return int
*/
int	Mysocket::wconnect()
{
	return (connect(this->_fd,
	(struct sockaddr *)&this->_addr, sizeof(this->_addr)) == -1);
}

/**
* @brief wclose wrap the C function close.
*
* @return int
*/
int	Mysocket::wclose()
{
	return (close(this->_fd));
}

/**
* @brief wlisten read the file descriptor.
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
		str = "Error.\n";
		return (str);
	}
	str = std::string(buf);
	free(buf);
	return(str);
}

/**
* @brief wwrite wrap the C function write.
*
* @param s
*/
void	Mysocket::wwrite(const char *s)
{
	write(this->_fd, s, strlen(s));
}

/**
* @brief launchMysocket connect the client to the server.
*
* @param ip
* @param port
* @return int
*/
bool	Mysocket::launchMysocket(const int port, const std::string ip,
const int pos)
{
	if (pos != 0)
		this->_ip = ip;
	this->_port = port;
	if (wgetprotobyname() == -1)
		return (false);
	if(wsocket() == -1)
		return (false);
	this->_addr.sin_family = AF_INET;
	this->_addr.sin_port = whtons();
	this->_addr.sin_addr.s_addr = winetAddr();
	if (wconnect() == -1) {
		wclose();
		return (false);
	}
	return (true);
}

/**
* @brief getIp gets the server's Ip.
*
* @return const std::string
*/
const std::string	Mysocket::getIp() const
{
	return(this->_ip);
}

/**
* @brief getPort gets the server's port.
*
* @return int
*/
int	Mysocket::getPort() const
{
	return(this->_port);
}

/**
* @brief getFd gets the server's file descriptor.
*
* @return int
*/
int	Mysocket::getFd()const
{
	return(this->_fd);
}

/**
* @brief getAddr gets the server's addr.
*
* @return struct sockaddr_in
*/
struct sockaddr_in	Mysocket::getAddr() const
{
	return(this->_addr);
}

/**
* @brief getPe gets the server's pe.
*
* @return struct protoent*
*/
struct protoent	*Mysocket::getPe() const
{
	return(this->_pe);
}