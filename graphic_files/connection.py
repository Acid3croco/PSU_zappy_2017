#!/usr/bin/python3
import sys, pygame, socket
from pygame.locals import *

#_______________________________________________________________________________
# CONNECTION SERVER
def connect_client(port, host):
	str1 = "WELCOME"
	str2 = "mbape"
	sockett = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	sockett.connect((host, port))
	print("Connected : {}".format(port))
	data = sockett.recv(255)
	if str(data).find(str1) == 2:
		sockett.send("GMAP\n".encode())
	data = sockett.recv(255)
	#if str(data).find(str2) == 2:
		#handle_map()
	sockett.close()

#_______________________________________________________________________________
# GESTION CLIENT
def get_port(arg1):
	port = int(arg1)
	if port < 0 or port > 65535:
		return (-1)
	return (port)