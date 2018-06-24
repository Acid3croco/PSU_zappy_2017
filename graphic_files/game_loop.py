#!/usr/bin/python3

import sys, socket
from handle_foods_stones import first_rocks, resize_rocks, choose_rock
from handle_player import fd_management

#_______________________________________________________________________________
# SORT DATA GIVEN BY SERVER AND SEND IT TO FUNCTINON DISPLAY
def sort_data(data_c, SizeX, SizeY):
	if int(SizeX) < 0 or int(SizeY) < 0 == -1:
		print("size map problem")
		return (-1)
	if data_c.find("new_c") == 0:
		cmd = fd_management(data_c)
		if cmd == -1:
			return (-1)
		else:
			return (cmd, 1)
	elif data_c.find("Eject") == 0:
		cmd = data.split(' ')
		return cmd
	elif data_c.find("Dead") == 0:
		cmd = data.split(' ')
		return cmd
	else:
		return (data_c, 2)

#_______________________________________________________________________________
# GET DATA GIVEN BY SERVER
def get_info(sockett, SizeX, SizeY):
	data = sockett.recv(255)
	data_c = data.decode("utf-8")
	tab = sort_data(data_c, SizeX, SizeY)
	if tab == -1:
		return (-1)
	return(tab)