#!/usr/bin/python3

import sys, socket
from handle_player import create_player
from handle_foods_stones.py import handle_foods_stones

def sort_data(data):
	if str(data).find("new_c") == 2:
		create_player(data)
	else
		create_foods_stones(data)

def get_info(sockett):
	data = sockett.recv(255)
	sort_data(data)
