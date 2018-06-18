#!/usr/bin/python3

import sys, socket
from handle_player import create_player
from handle_foods_stones.py import handle_foods_stones

def sort_data(data):
	if str(data).find("new_c") == 2:
		create_player(data)
	else
		create_foods_stones(data)

def get_info(sockett, lst):
	data = sockett.recv(255)
	if tab = sort_data(data) == -1:
		return (-1)

def game_loop(sockett, lst):
	get_info(sockett, lst)

