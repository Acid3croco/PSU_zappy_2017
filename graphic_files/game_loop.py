#!/usr/bin/python3

import sys, socket
from handle_foods_stones import first_rocks, resize_rocks, choose_rock

#_______________________________________________________________________________
# SORT DATA GIVEN BY SERVER AND SEND IT TO FUNCTINON DISPLAY
def sort_data(data_c, SizeX, SizeY):
	if int(SizeX) < 0 or int(SizeY) < 0 == -1:
		print("size map problem")
		return (-1)
	if data_c.find("new_c") == 0:
		if handle_player(data_c, SizeB) == -1:
			return (-1)
	elif data_c.find("Eject") == 0:
		cmd = data.split(' ')
		return cmd
	elif data_c.find("Dead") == 0:
		cmd = data.split(' ')
		return cmd
	else:
		return (data_c)

#_______________________________________________________________________________
# GET DATA GIVEN BY SERVER
def get_info(sockett, SizeX, SizeY):
	data = sockett.recv(255)
	data_c = data.decode("utf-8")
	tab = sort_data(data_c, SizeX, SizeY)
	if tab == -1:
		return (-1)
	return(tab)

#_______________________________________________________________________________
# GAME LOOP
def game_loop(sockett, SizeX, SizeY, screen):
	tab = get_info(sockett, SizeX, SizeY)
	if tab == -1:
		return (-1)
	first_rocks(tab, 90, screen)
	return (0)