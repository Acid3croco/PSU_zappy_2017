#!/usr/bin/python3

import sys, socket
from handle_player import create_player
from handle_foods_stones.py import handle_foods_stones


def sort_data(data, width, height):
	SizeB = width * height
	if str(data).find("new_c") == 2:
		if create_player(data, SizeB) == -1:
			return (-1)
	else
		if create_foods_stones(data, SizeB) == -1:
			return (-1)

def get_info(sockett, lst, width, height):
	data = sockett.recv(255)
	tab = sort_data(data, width, height)
	if tab == -1:
		return (-1)

def game_loop(sockett, lst, width, height):
	if get_info(sockett, lst, width, height) == -1:
		return (-1)

