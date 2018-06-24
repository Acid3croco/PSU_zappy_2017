#!/usr/bin/python3

import sys, pygame
from pygame.locals import *

#new_c FD “team-name” X Y O
#      0
#    1   3
#      2

#_______________________________________________________________________________
# HANDLE PLAYERS POSITION ON THE MAP
def fd_management(data):
	fd_info = data.split(' ')
	return (fd_info)

def first_pos(tab, screen, ):
	Img = 0
	if tab[5] == "0\n":
		Img = right_left(Img, 2, 1)
	elif tab[5] == "1\n":
		Img = right_left(Img, 1, 1)
	elif tab[5] == "2\n":
		Img = right_left(Img, 2, 0)
	elif tab[5] == "3\n":
		Img = right_left(Img, 3, 1)
	screen.blit(Img, (100 * int(tab[3]) + 30,  100 * int(tab[4]) + 30))
	pygame.display.flip()
	
#_______________________________________________________________________________
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
	return (Img)

#_______________________________________________________________________________
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