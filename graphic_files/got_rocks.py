#!/usr/bin/python3

import sys, pygame
from pygame.locals import *

#_______________________________________________________________________________
# CHOOSE ROCK AND DISPLAY IT
def choose_rock(x_square, y_square, rock, pos):
	all_rocks = {}
	all_rocks["linemate"] = pygame.image.load('../textures/linemate.png')
	all_rocks["dereaumere"] = pygame.image.load('../textures/deraumere.png')
	all_rocks["sibur"] = pygame.image.load('../textures/sibur.png')
	all_rocks["mendiane"] = pygame.image.load('../textures/Mendiane.png')
	all_rocks["phiras"] = pygame.image.load('../textures/phirras.png')
	all_rocks["thystmane"] = pygame.image.load('../textures/thystame.png')
	all_rocks["food"] = pygame.image.load('../textures/food.png')
	if rock == "L":
		fenetre.blit(all_rocks["linemate"], ((x_square / 2) * pos, (y_square /2)) * pos )
	pygame.display.flip()
	elif rock == "D":
		fenetre.blit(all_rocks["dereamere"], ((x_square / 2) * pos, (y_square /2)) * pos )
	pygame.display.flip()
	elif rock == "S":
		fenetre.blit(all_rocks["sibur"], ((x_square / 2) * pos, (y_square /2)) * pos )
	pygame.display.flip()
	elif rock == "M":
		fenetre.blit(all_rocks["mendiane"], ((x_square / 2) * pos, (y_square /2)) * pos )
	pygame.display.flip()
	elif rock == "P":
		fenetre.blit(all_rocks["phiras"], ((x_square / 2) * pos, (y_square /2)) * pos )
	pygame.display.flip()
	elif rock == "T":
		fenetre.blit(all_rocks["thystmane"], ((x_square / 2) * pos, (y_square /2)) * pos )
	pygame.display.flip()
	elif rock == "F":
		fenetre.blit(all_rocks["thystmane"], ((x_square / 2) * pos, (y_square /2)) * pos )
	pygame.display.flip()
