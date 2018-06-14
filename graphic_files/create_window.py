#!/usr/bin/python3

import pygame
from pygame.locals import *

def create_window(width, height):
	screen = pygame.display.set_mode((width, height))
	my_image = pygame.image.load('textures/grass_template.jpg')
	screen.blit(pygame.transform.scale(my_image, (width, height)), (0, 0))
	pygame.display.flip()
	pygame.display.set_caption('Zappy')
	running = True
	while running:
		for event in pygame.event.get():
			if event.type == pygame.QUIT:
				running = False