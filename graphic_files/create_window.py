#!/usr/bin/python3

import pygame, socket
from pygame.locals import *
from game_loop import game_loop, get_info
from handle_foods_stones import first_rocks

#_______________________________________________________________________________
# CREATE THE WINDOW AND MAP / SEND INFO FOR DISPLAY OBJECTS ON MAP
def create_window(width, height, sockett, data, SizeX, SizeY):
	print("allo :\n", data)
	screen = pygame.display.set_mode((width, height))
	pygame.display.set_caption('Zappy')
	first_rocks(data, 100, screen)
	running = True
	while running:
		pygame.time.Clock().tick(30)

		for event in pygame.event.get():
			if event.type == pygame.QUIT:
				running = False
		tab = get_info(sockett, SizeX, SizeY)
		print(tab)
		if tab == -1:
			break
		print("i go in rocks second time\n")
		first_rocks(tab, 100, screen)
	