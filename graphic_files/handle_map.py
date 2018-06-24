#!/usr/bin/python3

import sys, pygame, socket
from pygame.locals import *
from create_window import create_window

# SIZE OF A BOX BY DEFAULT
size_box = 100

#_______________________________________________________________________________
# RECOVER SIZE OF MAP : X
def recover_x(data):
	tab = data.split('/')
	count = len(tab) - 1
	x = tab[count].split(';')
	return (int(x[0]))

#_______________________________________________________________________________
# RECOVER SIZE OF MAP : Y
def recover_y(data):
	tab = data.split('/')
	count = len(tab) - 1
	tmp = tab[count].split(';')
	y = tmp[1].split(':')
	return (int(y[0]))

#_______________________________________________________________________________
# RECOVER SIZE OF THE WINDOW
def handle_map(sockett, data):
	SizeX = recover_x(data)
	SizeY = recover_y(data)
	width = SizeX * size_box
	height = SizeY * size_box
	create_window(int(width), int(height), sockett, data,
			SizeX, SizeY)