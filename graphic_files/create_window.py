#!/usr/bin/python3

import pygame, socket
from pygame.locals import *
from game_loop import get_info
from handle_player import first_pos
from handle_foods_stones import first_rocks

#_______________________________________________________________________________
# CREATE THE WINDOW AND MAP / SEND INFO FOR DISPLAY OBJECTS ON MAP
def create_window(width, height, sockett, data, SizeX, SizeY):
	print("allo :\n", data)
	screen = pygame.display.set_mode((width, height))
	pygame.display.set_caption('Zappy')
	first_rocks(data, 100, screen)
	running = True
	player = []
	while running:
		pygame.time.Clock().tick(30)

		for event in pygame.event.get():
			if event.type == pygame.QUIT:
				running = False
		tab = get_info(sockett, SizeX, SizeY)
		if tab[1] == 1:
			player.append(tab[0])
			print(tab[0])
			first_pos(tab[0], screen)
												
		print(player)
		if tab == -1:
			break
		if tab[1] == 2:
			first_rocks(tab, 100, screen)