#!/usr/bin/python3

import sys, pygame, re

#_______________________________________________________________________________
# HANDLE DISPLAY OF FOOD AND STONES ON MAP
def first_rocks(lst, size, screen):
	background = pygame.image.load("./textures/grass_template.jpg")
	background = pygame.transform.scale(background,(size,size))
	all_map = re.sub('/', " ", lst).split()
	size_list = len(all_map)
	i = 0
	while i < size_list:
		print(all_map[i])
		case = re.sub(':', " ", all_map[i]).split()
		pos = re.sub(';', " ", case[0]).split()
		screen.blit(background, (size * int(pos[0]), size * int(pos[1])))
		pygame.display.flip()
		pos[0] = int(pos[0]) + 1
		pos[1] = int(pos[1]) + 1
		for x in range(0,14):
			stock = case[1][x -1].isdigit()
			if x >= 1 and stock == True:
				if int(case[1][x-1]) > 0:
					choose_rock(size, case[1][x], pos, screen)
		i = i + 1

def resize_rocks(all_rocks, size):
	sizeX = int(size)
	sizeY = int(size)
	all_rocks["linemate"] = pygame.transform.scale(all_rocks["linemate"], (sizeX, sizeY))
	all_rocks["dereaumere"] = pygame.transform.scale(all_rocks["dereaumere"], (sizeX, sizeY))
	all_rocks["sibur"] = pygame.transform.scale(all_rocks["sibur"], (sizeX, sizeY))
	all_rocks["mendiane"] = pygame.transform.scale(all_rocks["mendiane"], (sizeX, sizeY))
	all_rocks["phiras"] = pygame.transform.scale(all_rocks["phiras"], (sizeX, sizeY))
	all_rocks["thystmane"] = pygame.transform.scale(all_rocks["thystmane"], (sizeX, sizeY))
	all_rocks["food"] = pygame.transform.scale(all_rocks["food"], (sizeX, int(sizeY / 1.5)))
	return all_rocks
#_______________________________________________________________________________
# CHOOSE ROCK/FOOD AND DISPLAY IT
def choose_rock(size, rock, pos, screen):
	all_rocks = {}
	all_rocks["linemate"] = pygame.image.load('./textures/linemate.png')
	all_rocks["dereaumere"] = pygame.image.load('./textures/deraumere.png')
	all_rocks["sibur"] = pygame.image.load('./textures/sibur.png')
	all_rocks["mendiane"] = pygame.image.load('./textures/Mendiane.png')
	all_rocks["phiras"] = pygame.image.load('./textures/phirras.png')
	all_rocks["thystmane"] = pygame.image.load('./textures/thystame.png')
	all_rocks["food"] = pygame.image.load('./textures/food.png')
	x_pos = size * int(pos[0])
	y_pos = size * int(pos[1])
	all_rocks = resize_rocks(all_rocks, size / 6)
	if rock == "L":
		screen.blit(all_rocks["linemate"], ((x_pos - size / 2), (y_pos - size / 4)))
	elif rock == "D":
		screen.blit(all_rocks["dereaumere"], ((x_pos - size / 1.5), (y_pos - size / 4)))
	elif rock == "S":
		screen.blit(all_rocks["sibur"], ( ( x_pos - size / 1.2), (y_pos - size /4)))
	elif rock == "M":
		screen.blit(all_rocks["mendiane"], ((x_pos - size / 4), (y_pos - size / 1.5)))
	elif rock == "P":
		screen.blit(all_rocks["phiras"], ((x_pos - size / 4), (y_pos - size / 2)))
	elif rock == "T":
		screen.blit(all_rocks["thystmane"], ((x_pos - size / 4), (y_pos - size /1.2)))
	elif rock == "F":
		screen.blit(all_rocks["food"], ((x_pos - size / 4), (y_pos - size / 4)))
	pygame.display.flip()