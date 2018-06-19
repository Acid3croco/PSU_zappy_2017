#!/usr/bin/python3

import sys, pygame, socket
from pygame.locals import *
from handle_map.py import handle_map

#_______________________________________________________________________________
# CONNECTION SERVER
def connect_client(port, host):
	welcome = "WELCOME"
	sockett = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	sockett.connect((host, port))
	print("Connected : {}".format(port))
	data = sockett.recv(255)
	if str(data).find(welcome) == 2:
		sockett.send("GMAP\n".encode())
	data = sockett.recv(255)
	handle_map(sockett, data)
	sockett.close()