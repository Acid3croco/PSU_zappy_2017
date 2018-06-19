#!/usr/bin/python3

import sys, pygame, socket
from pygame.locals import *
from create_window import create_window

# SIZE OF A BOX BY DEFAULT
size_box = 100

def recover_x(data):
	tab = data.split('/')
	count = len(tab) - 1
	x = tab[count].split(';')
	return (int(x[0]))

def recover_y(data):
	tab = data.split('/')
	count = len(tab) - 1
	tmp = tab[count].split(';')
	y = tmp[1].split(':')
	return (int(y[0]))

#_______________________________________________________________________________
# DATA MAP
def handle_map(sockett, data):
	SizeX = recover_x(data)
	SizeY = recover_y(data)
	if (SizeX >= 100 and SizeX < 1000 or
		 SizeY >= 100 and SizeY < 1000):
		width = SizeX * (size_box / 10)
		height = SizeY * (size_box / 10)
	elif (SizeX >= 1000 and SizeX < 10000 or
		 SizeY >= 1000 and SizeY < 10000):
		width = SizeX * (size_box / 100)
		height = SizeY * (size_box / 100)
	elif (SizeX >= 10000 or SizeY >= 10000):
		width = SizeX * (size_box / 1000)
		height = SizeY * (size_box / 1000)
	else:
		width = SizeX * size_box
		height = SizeY * size_box
	create_window(int(width), int(height), sockett, data)