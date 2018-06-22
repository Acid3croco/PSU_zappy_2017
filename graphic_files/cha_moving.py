#!/usr/bin/python3

import sys, pygame
from pygame.locals import *

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
def forward (Img, check):
	if check == 1:
		Img = pygame.image.load('./textures/character4.1.png')
		fenetre.blit(Img, ( x+10, y))
		pygame.display.flip()
		time.sleep(0.15)
		Img = pygame.image.load('./textures/character4.2.png')
		fenetre.blit(Img, (x+20, y))
		pygame.display.flip()
		time.sleep(0.15)
		Img = pygame.image.load('./textures/character4.png')
		if (x > 640):
			x = x - 640
		else:
			x = x+20
		fenetre.blit(Img, ( x,y))
		pygame.display.flip()


	elif check == 2:
		Img = pygame.image.load('./textures/character2.1.png')
		fenetre.blit(Img, ( x-10, y))
		pygame.display.flip()
		time.sleep(0.15)
		Img = pygame.image.load('./textures/character2.2.png')
		fenetre.blit(Img, (x-20, y))
		pygame.display.flip()
		time.sleep(0.15)
		Img = pygame.image.load('./textures/character2.png')
		if (x < 0):
			x =  640 + x
		else:
			x = x-20
		fenetre.blit(Img, ( x,y))
		pygame.display.flip()


	elif check == 3:
		Img = pygame.image.load('./textures/character1.1.png')
		fenetre.blit(Img, ( x, y+10))
		pygame.display.flip()
		time.sleep(0.15)
		Img = pygame.image.load('./textures/character1.2.png')
		fenetre.blit(Img, (x, y+20))
		pygame.display.flip()
		time.sleep(0.15)
		Img = pygame.image.load('./textures/character1.png')
		if (y > 480):
			y = y - 480
		else:
			y = y+20
		fenetre.blit(Img, ( x,y))
		pygame.display.flip()


	elif check == 4:
		Img = pygame.image.load('./textures/character3.1.png')
		fenetre.blit(Img, ( x, y-10))
		pygame.display.flip()
		time.sleep(0.15)
		Img = pygame.image.load('./textures/character3.2.png')fenetre.blit(Img, (x, y-20))
		pygame.display.flip()
		time.sleep(0.15)
		Img = pygame.image.load('./textures/character3.png')
		if (y < 480):
			y = 480 + y
		else:
			y = y-20
		fenetre.blit(Img, ( x,y))
		pygame.display.flip()