#!/usr/bin/python3
import sys, pygame, socket
from pygame.locals import *
from create_window import create_window

#a enlever apres que le pb de mbmap soit regle cote server
SizeX = 10
SizeY = 10

# SIZE OF A BOX BY DEFAULT
size_box = 100

#_______________________________________________________________________________
# DATA MAP
def handle_map(): #socket a rajouter en parametre
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
	create_window(int(width), int(height))

def load_tab_info():
	line = SizeX
	column = SizeY
	lst = [[0] * column for _ in range(line)]
