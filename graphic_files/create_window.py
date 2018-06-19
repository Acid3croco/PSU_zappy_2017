#!/usr/bin/python3

import pygame, socket
from pygame.locals import *
from display_map.py import init_map

def create_window(width, height, sockett, data):
	screen = pygame.display.set_mode((width, height))
	my_image = pygame.image.load('textures/grass_template.jpg')
	screen.blit(pygame.transform.scale(my_image, (width, height)), (0, 0))
	pygame.display.flip()
	pygame.display.set_caption('Zappy')
	running = True
	lst = display_map(data, width, height)
	while running:
		pygame.time.Clock().tick(30)

		for event in pygame.event.get():
			if event.type == pygame.QUIT:
				running = False
		if game_loop(sockett, lst) == -1:
			break #ou running = 0