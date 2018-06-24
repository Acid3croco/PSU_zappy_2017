#!/usr/bin/python3

import sys, pygame
from pygame.locals import *
#_______________________________________________________________________________
# HANDLE PLAYERS POSITION ON THE MAP
def hadle_player(data):
	print(data)

#
_______________________________________________________________________________
# CHANGE DIRECTION OF CHARACTER
def right_left(Img, check, r_l):
	tmp = "./textures/character"
	if check == 1 and r_l == 0:
		tmp += str(4)
	elif check == 4 and r_l == 1:
		tmp += str(1)
	elif r_l == 0:
		tmp += str(check - 1)
	elif r_l == 1:
		tmp += str(check + 1)
	tmp += ".png"
	Img = pygame.image.load(tmp)

#
_______________________________________________________________________________
# MAKE THE ANIMATION OF FORWARD 
def forward (Img, fenetre, check, x_size, y_size, pos_x, pos_y):
	if check == 1:
		Img = pygame.image.load('./textures/character4.1.png')
		fenetre.blit(Img, ( x_size * pos_x + x_size / 5, y_size * pos_y))
		pygame.display.flip()
		time.sleep(0.15)
		Img = pygame.image.load('./textures/character4.2.png')
		fenetre.blit(Img, (x_size * pos_x + x_size / 1.5, y_size * pos_y))
		pygame.display.flip()
		time.sleep(0.15)
		Img = pygame.image.load('./textures/character4.png')
		fenetre.blit(Img, ( x * (pos_x + 1),y_size * pos_y))


	elif check == 2:
		Img = pygame.image.load('./textures/character2.1.png')
		fenetre.blit(Img, ( x_size * pos_x - x_size / 5, y_size * pos_y))
		pygame.display.flip()
		time.sleep(0.15)
		Img = pygame.image.load('./textures/character2.2.png')
		fenetre.blit(Img, (x_size * pos_x - x_size / 1.5, y_size * pos_y))
		pygame.display.flip()
		time.sleep(0.15)
		Img = pygame.image.load('./textures/character2.png')
		fenetre.blit(Img, ( x_size * (pos_x - 1),y_size * pos_y))


	elif check == 3:
		Img = pygame.image.load('./textures/character1.1.png')
		fenetre.blit(Img, ( x_size * pos_x, y_size * pos_y + y_size / 5))
		pygame.display.flip()
		time.sleep(0.15)
		Img = pygame.image.load('./textures/character1.2.png')
		fenetre.blit(Img, (x_size * pos_x, y_size * pos_y + y_size / 1.5))
		pygame.display.flip()
		time.sleep(0.15)
		Img = pygame.image.load('./textures/character1.png')
		fenetre.blit(Img, ( x_size * pos_x,y_size * (pos_y + 1)))


	elif check == 4:
		Img = pygame.image.load('./textures/character3.1.png')
		fenetre.blit(Img, ( x_size * pos_x, y_size * pos_y - y_size / 5))
		pygame.display.flip()
		time.sleep(0.15)
		Img = pygame.image.load('./textures/character3.2.png')
		fenetre.blit(Img, (x_size * pos_x, y_size * pos_y - y_size / 1.5))
		pygame.display.flip()
		time.sleep(0.15)
		Img = pygame.image.load('./textures/character3.png')
		fenetre.blit(Img, ( x_size * pos_x, y_size * (pos_y - 1)))
	pygame.image.display.flip