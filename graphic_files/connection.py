#!/usr/bin/python3
import sys, pygame, socket
from pygame.locals import *
from map_handler.py

#_______________________________________________________________________________
# CONNECTION SERVER
def connect_client(port, host):
	welcome = "WELCOME"
	str2 = "mbape"
	sockett = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	sockett.connect((host, port))
	print("Connected : {}".format(port))
	data = sockett.recv(255)
	if str(data).find(welcome) == 2:
		sockett.send("GMAP\n".encode())
	data = sockett.recv(255)
	#if str(data).find(str2) == 2:
		#handle_map(sockett)
	sockett.close()