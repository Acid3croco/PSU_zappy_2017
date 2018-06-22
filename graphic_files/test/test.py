#! /usr/bin/env python3
# -*- coding: utf-8 -*-

import pygame
import time

pygame.init()
clock = pygame.time.Clock()
CIEL = 0, 200, 255
WHITE = 255, 255, 255
GREEN = 0, 255, 0
RED = 255, 0, 0

def test_right(Img, fenetre):
    tmp == "RIGHT"
    if tmp == "RIGHT":
        print("ok")
        Img = pygame.image.load('../textures/character4.1.png')
        fenetre.blit(Img, ( x+10, y))
        pygame.display.flip()
        time.sleep(0.15)
        Img = pygame.image.load('../textures/character4.2.png')
        fenetre.blit(Img, (x+20, y))
        pygame.display.flip()
        time.sleep(0.15)
        Img = pygame.image.load('../textures/character4.png')
        if (x > 640):
            x = x - 640
        else:
            x = x+20
        fenetre.blit(Img, ( x,y))
        pygame.display.flip()

def choose_rock(x_square, y_square,  rock, pos, fenetre):
    all_rocks = {}
    all_rocks["linemate"] = pygame.image.load('../textures/linemate.png')
    all_rocks["dereaumere"] = pygame.image.load('../textures/deraumere.png')
    all_rocks["sibur"] = pygame.image.load('../textures/sibur.png')
    all_rocks["mendiane"] = pygame.image.load('../textures/Mendiane.png')
    all_rocks["phiras"] = pygame.image.load('../textures/phirras.png')
    all_rocks["thystmane"] = pygame.image.load('../textures/thystame.png')
    if rock == "L":
        fenetre.blit(all_rocks["linemate"], ((x_square / 2) * pos, (y_square /2) * pos) )
    pygame.display.flip()

def main():
    fenetre = pygame.display.set_mode((1200, 720))
    loop = True
    green_color = GREEN
    white_color = WHITE
    width=350;
    height=200
    x = 40
    y = 80
    tmp = 2
    Img = pygame.image.load('../textures/character4.png')
    all_rocks = {}
    all_rocks["linemate"] = pygame.image.load('../textures/linemate.png')
    all_rocks["dereaumere"] = pygame.image.load('../textures/deraumere.png')
    all_rocks["sibur"] = pygame.image.load('../textures/sibur.png')
    all_rocks["mendiane"] = pygame.image.load('../textures/Mendiane.png')
    all_rocks["phiras"] = pygame.image.load('../textures/phirras.png')
    all_rocks["thystmane"] = pygame.image.load('../textures/thystame.png') 
    all_rocks["Food"] = pygame.image.load('../textures/food.png')
    Img = pygame.transform.scale(Img, (100,100))
    choose_rock(100,  50, "L", 5, fenetre)
    while loop:
        background = pygame.Surface(fenetre.get_size())
        background.fill(CIEL)

        # Ajout du fond dans la fenêtre
        fenetre.blit(background, (0, 0))
        fenetre.blit(Img, ( x,y))
        fenetre.blit(all_rocks["Food"], (300, 300))
        choose_rock(100,  50, "L", 10, fenetre)

        # Draw a rectangle outline
        rect_white = pygame.draw.rect(fenetre, white_color, [75, 10, 100, 50],
                                        5)
        # Draw a solid rectangle
        rect_green = pygame.draw.rect(fenetre, green_color, [250, 10, 100, 50])

        # retourne 1 si le curseur est au dessus du rectangle
        mouse_xy = pygame.mouse.get_pos()
        over_white = rect_white.collidepoint(mouse_xy)
        over_green = rect_green.collidepoint(mouse_xy)

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                loop = False
            elif tmp == 2:
                print("ok")
                Img = pygame.image.load('../textures/character4.1.png')
                fenetre.blit(Img, ( x+10, y))
                pygame.display.flip()
                time.sleep(0.15)
                Img = pygame.image.load('../textures/character4.2.png')
                fenetre.blit(Img, (x+20, y))
                pygame.display.flip()
                time.sleep(0.15)
                Img = pygame.image.load('../textures/character4.png')
                if (x > 640):
                    x = x - 640
                else:
                    x = x+20
                fenetre.blit(Img, ( x,y))
                pygame.display.flip()
            elif event.type == pygame.KEYDOWN:
                
                if event.key == pygame.K_RIGHT:
                    Img = pygame.image.load('../textures/character4.1.png')
                    fenetre.blit(Img, ( x+10, y))
                    pygame.display.flip()
                    time.sleep(0.15)
                    Img = pygame.image.load('../textures/character4.2.png')
                    fenetre.blit(Img, (x+20, y))
                    pygame.display.flip()
                    time.sleep(0.15)
                    Img = pygame.image.load('../textures/character4.png')
                    if (x > 640):
                        x = x - 640
                    else:
                        x = x+20
                    fenetre.blit(Img, ( x,y))
                    pygame.display.flip()


                elif event.key == pygame.K_LEFT:
                    Img = pygame.image.load('../textures/character2.1.png')
                    fenetre.blit(Img, ( x-10, y))
                    pygame.display.flip()
                    time.sleep(0.15)
                    Img = pygame.image.load('../textures/character2.2.png')
                    fenetre.blit(Img, (x-20, y))
                    pygame.display.flip()
                    time.sleep(0.15)
                    Img = pygame.image.load('../textures/character2.png')
                    if (x < 0):
                        x =  640 + x
                    else:
                        x = x-20
                    fenetre.blit(Img, ( x,y))
                    pygame.display.flip()


                elif event.key == pygame.K_DOWN:
                    Img = pygame.image.load('../textures/character1.1.png')
                    fenetre.blit(Img, ( x, y+10))
                    pygame.display.flip()
                    time.sleep(0.15)
                    Img = pygame.image.load('../textures/character1.2.png')
                    fenetre.blit(Img, (x, y+20))
                    pygame.display.flip()
                    time.sleep(0.15)
                    Img = pygame.image.load('../textures/character1.png')
                    if (y > 480):
                        y = y - 480
                    else:
                        y = y+20
                    fenetre.blit(Img, ( x,y))
                    pygame.display.flip()
                    


                elif event.key == pygame.K_UP:
                    Img = pygame.image.load('../textures/character3.1.png')
                    fenetre.blit(Img, ( x, y-10))
                    pygame.display.flip()
                    time.sleep(0.15)
                    Img = pygame.image.load('../textures/character3.2.png')
                    fenetre.blit(Img, (x, y-20))
                    pygame.display.flip()
                    time.sleep(0.15)
                    Img = pygame.image.load('../textures/character3.png')
                    if (y < 480):
                        y = 480 + y
                    else:
                        y = y-20
                    fenetre.blit(Img, ( x,y))
                    pygame.display.flip()
            # le rectangle se cache
                elif event.key == pygame.K_UP:
                    print("ok")
                    all_rocks()
                elif event.type == pygame.MOUSEBUTTONDOWN and over_white:
                    white_color = RED
                    Food = pygame.transform.scale(Food, (100,50))

        # Actualisation de l'affichage
        pygame.display.flip()
        # 10 fps
        clock.tick(100)

if __name__ == '__main__':
    main()
