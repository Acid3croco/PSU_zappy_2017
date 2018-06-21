#!/usr/bin/python3

import sys, socket
from handle_player import create_player
from handle_foods_stones.py import handle_foods_stones

# SIZE OF A BOX BY DEFAULT
size_box = 100

#_______________________________________________________________________________
# DEFINE SIZE OF BOX
def size_box(SizeX, SizeY):
	if (SizeX >= 100 and SizeX < 1000 or
		 SizeY >= 100 and SizeY < 1000):
		 return int(box = size_box / 10)
	elif (SizeX >= 1000 and SizeX < 10000 or
		 SizeY >= 1000 and SizeY < 10000):
		 return int(size_box / 100)
	elif (SizeX >= 10000 and SizeX >= 10000
		 return int(size_box / 1000)
	else:
		return (-1)

#_______________________________________________________________________________
# SORT DATA GIVEN BY SERVER AND SEND IT TO FUNCTINON DISPLAY
def sort_data(data, SizeX, SizeY):
	SizeB = size_box(SizeX, SizeY)
	if SizeB == -1:
		print("size map problem")
		return (-1)
	if str(data).find("new_c") == 2:
		if create_player(data, SizeB) == -1:
			return (-1)
	else
		if create_foods_stones(data, SizeB) == -1:
			return (-1)
	return (0)

#_______________________________________________________________________________
# GET DATA GIVEN BY SERVER
def get_info(sockett, lst):
	data = sockett.recv(255)
	tab = sort_data(data, SizeX, SizeY)
	if tab == -1:
		return (-1)
	return(0)

#_______________________________________________________________________________
# GAME LOOP
def game_loop(sockett, lst, SizeX, SizeY):
	if get_info(sockett, lst, SizeX, SizeY) == -1:
		return (-1)
	return (0)