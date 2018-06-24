#! /usr/bin/env python3
# -*- coding: utf-8 -*-

import pygame, re
import time

pygame.init()
clock = pygame.time.Clock()
CIEL = 0, 200, 255
WHITE = 255, 255, 255
GREEN = 0, 255, 0
RED = 255, 0, 0

def test_right(Img, fenetre, x_size, y_size, pos_x, pos_y):
    tmp = "RIGHT"
    if tmp == "RIGHT":
        print("ok")
        Img = pygame.image.load('../textures/character4.1.png')
        fenetre.blit(Img, ( x_size * pos_x, y_size * pos_y + y_size / 5))
        pygame.display.flip()
        time.sleep(0.15)
        Img = pygame.image.load('../textures/character4.2.png')
        fenetre.blit(Img, (x_size * pos_x, y_size * pos_y + y_size / 1.5))
        pygame.display.flip()
        time.sleep(0.15)
        Img = pygame.image.load('../textures/character4.png')
        fenetre.blit(Img, ( x_size * pos_x, y_size * (pos_y + 1)))
        pygame.display.flip()

def first_rocks(lst, sizeX, sizeY, fenetre):
    background = pygame.image.load("../textures/grass_template.jpg")
    background = pygame.transform.scale(background,(sizeX,sizeY))
    all_map = re.sub('/', " ",  lst).split()
    size_list = len(all_map)
    i = 0
    while i < size_list:
        case = re.sub(':', " ", all_map[i]).split()
        pos = re.sub(';', " ", case[0]).split()
        fenetre.blit(background, (sizeX * int(pos[0]), sizeY * int(pos[1])))
        for x in range(0,14):
            stock = case[1][x -1].isdigit()
            if x >= 1 and stock == True:
                if int(case[1][x-1]) > 0:
                    choose_rock(sizeX,sizeY, case[1][x], pos, fenetre)
        i = i + 1
def resize_rocks(all_rocks, sizeX, sizeY):
    sizeX = int(sizeX)
    sizeY = int(sizeY)
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
def choose_rock(x_square, y_square, rock, pos, fenetre):
    all_rocks = {}
    all_rocks["linemate"] = pygame.image.load('../textures/linemate.png')
    all_rocks["dereaumere"] = pygame.image.load('../textures/deraumere.png')
    all_rocks["sibur"] = pygame.image.load('../textures/sibur.png')
    all_rocks["mendiane"] = pygame.image.load('../textures/Mendiane.png')
    all_rocks["phiras"] = pygame.image.load('../textures/phirras.png')
    all_rocks["thystmane"] = pygame.image.load('../textures/thystame.png')
    all_rocks["food"] = pygame.image.load('../textures/food.png')
    x_pos = x_square * (int(pos[0]) +1)
    y_pos = y_square * (int(pos[1]) +1)
    all_rocks = resize_rocks(all_rocks, x_square / 6, y_square / 6)
    if rock == "L":
        fenetre.blit(all_rocks["linemate"], ((x_pos - x_square / 2), (y_pos - y_square / 4)))
    elif rock == "D":
        fenetre.blit(all_rocks["dereaumere"], ((x_pos - x_square / 1.5), (y_pos - y_square / 4)))
    elif rock == "S":
        fenetre.blit(all_rocks["sibur"], ( ( x_pos - x_square / 1.2), (y_pos - y_square /4)))
    elif rock == "M":
        fenetre.blit(all_rocks["mendiane"], ((x_pos - x_square / 4), (y_pos - y_square / 1.5)))
    elif rock == "P":
        fenetre.blit(all_rocks["phiras"], ((x_pos - x_square / 4), (y_pos - y_square / 2)))
    elif rock == "T":
        fenetre.blit(all_rocks["thystmane"], ((x_pos - x_square / 4), (y_pos - y_square /1.2)))
    elif rock == "F":
        fenetre.blit(all_rocks["food"], ((x_pos - x_square / 4), (y_pos - y_square / 4)))

    pygame.display.flip()
def main():
    fenetre = pygame.display.set_mode((1000, 1100))
    loop = True
    green_color = GREEN
    white_color = WHITE
    width=350;
    height=200
    x = 40
    y = 80
    test = 1
    tmp = "/0;0:1D8F2L3M1P1S1T/1;0:3D5F4L1M1P2S1T/2;0:3D6F5L2M0P0S1T/3;0:2D1F4L1M0P0S1T/4;0:2D9F4L3M2P0S0T/5;0:0D2F6L3M1P1S0T/6;0:4D6F0L1M2P1S1T/7;0:4D6F4L1M0P0S0T/8;0:0D2F3L0M0P0S0T/9;0:0D8F3L3M0P2S1T/10;0:5D2F3L3M1P0S0T/0;1:0D0F0L0M0P0S0T/1;1:3D8F2L2M1P2S1T/2;1:3D2F6L0M2P2S0T/3;1:1D5F4L0M0P1S0T/4;1:5D3F1L3M2P3S1T/5;1:0D1F1L2M2P4S1T/6;1:3D9F5L2M2P0S0T/7;1:2D0F5L0M2P0S0T/8;1:4D2F4L1M0P0S1T/9;1:5D1F0L0M1P4S0T/10;1:5D3F6L2M2P0S0T/0;2:0D6F1L1M2P3S1T/1;2:1D1F5L0M0P1S0T/2;2:1D2F1L3M2P1S1T/3;2:4D1F6L3M2P1S0T/4;2:4D8F4L3M2P0S1T/5;2:5D7F4L0M1P3S0T/6;2:2D5F1L0M0P4S1T/7;2:2D2F1L3M2P0S1T/8;2:1D1F6L3M0P0S0T/9;2:5D8F3L3M2P1S1T/10;2:1D5F0L0M0P3S0T/0;3:1D3F5L3M0P3S0T/1;3:2D9F2L3M2P3S0T/2;3:3D5F0L2M0P0S0T/3;3:0D2F0L0M1P3S0T/4;3:3D8F4L0M0P3S1T/5;3:4D0F4L1M2P3S0T/6;3:1D4F5L0M1P2S1T/7;3:5D0F5L2M0P3S1T/8;3:3D9F4L3M0P0S1T/9;3:0D5F5L3M0P0S1T/10;3:5D2F5L0M2P1S0T/0;4:5D7F2L0M1P2S0T/1;4:5D3F1L3M2P1S0T/2;4:4D3F1L2M1P3S0T/3;4:3D1F5L2M0P0S0T/4;4:5D9F1L3M0P2S1T/5;4:1D2F0L0M1P3S1T/6;4:3D8F6L2M1P0S1T/7;4:1D6F6L3M1P1S1T/8;4:0D0F0L0M2P0S1T/9;4:2D8F5L1M0P2S0T/10;4:0D2F1L2M0P1S1T/0;5:3D2F0L1M0P3S0T/1;5:1D0F6L3M1P1S1T/2;5:1D3F4L1M2P4S0T/3;5:5D5F1L1M2P1S1T/4;5:3D8F2L1M0P1S0T/5;5:4D4F3L1M2P0S0T/6;5:5D1F1L0M0P1S1T/7;5:0D8F0L2M2P2S0T/8;5:1D4F1L1M1P2S1T/9;5:0D0F3L1M1P1S0T/10;5:4D0F5L3M0P4S1T/0;6:4D2F3L2M0P4S1T/1;6:2D1F0L2M1P0S1T/2;6:1D8F4L0M1P0S1T/3;6:3D1F6L1M0P1S1T/4;6:1D0F3L2M1P2S0T/5;6:1D0F4L1M2P3S0T/6;6:1D9F0L1M1P0S0T/7;6:1D7F6L2M1P4S1T/8;6:0D9F3L1M0P2S1T/9;6:1D8F2L1M1P3S0T/10;6:3D5F6L3M2P1S0T/0;7:4D2F5L2M0P1S0T/1;7:5D7F3L3M2P2S0T/2;7:1D9F0L3M1P4S0T/3;7:5D3F2L2M0P1S1T/4;7:2D6F4L1M1P0S0T/5;7:2D5F2L0M0P4S1T/6;7:3D7F2L1M1P3S1T/7;7:4D6F4L2M1P1S1T/8;7:5D3F1L3M0P0S1T/9;7:3D8F2L0M1P0S1T/10;7:5D2F4L0M0P2S1T/0;8:4D9F3L2M2P0S0T/1;8:1D4F3L0M1P0S1T/2;8:5D5F1L0M0P4S1T/3;8:2D3F3L1M1P4S0T/4;8:2D2F4L0M1P3S1T/5;8:2D5F5L3M1P2S1T/6;8:5D4F5L3M0P1S1T/7;8:2D8F3L0M0P2S1T/8;8:1D1F0L3M0P3S1T/9;8:3D5F2L1M1P3S0T/10;8:3D8F6L3M0P2S1T/0;9:4D2F4L1M1P1S1T/1;9:2D0F1L0M2P2S0T/2;9:4D9F4L1M2P2S0T/3;9:0D2F4L0M2P1S1T/4;9:3D7F1L1M0P3S1T/5;9:0D9F5L2M2P2S0T/6;9:5D0F4L0M2P2S1T/7;9:5D3F6L3M1P2S1T/8;9:0D0F2L0M0P2S0T/9;9:2D4F0L3M0P1S1T/10;9:2D3F5L2M0P1S0T/0;10:3D7F5L3M0P2S0T/1;10:0D3F2L1M1P3S1T/2;10:5D5F2L0M1P2S0T/3;10:1D8F1L0M0P4S1T/4;10:0D5F0L1M2P1S0T/5;10:1D3F2L2M2P3S1T/6;10:1D7F6L1M2P2S1T/7;10:3D5F2L0M2P1S1T/8;10:5D6F3L3M0P0S0T/9;10:1D1F1L2M1P4S0T/10;10:0D4F5L0M2P2S0T"
    wordList = re.sub('/', " ",  tmp).split()
    case = re.sub(':', " ", wordList[0]).split()
    pos = re.sub(';', " ", case[0]).split()
    Img = pygame.image.load("../textures/character2.png")
    Img = pygame.transform.scale(Img, (300,300))
    background = pygame.image.load("../textures/ground.png")
    background = pygame.transform.scale(background,(1000,1000))

    first_rocks(tmp, 100, 100, fenetre)
    time.sleep(2)
    print("LOL MDR")
    x_size = 100
    y_size = 100
    pos_x = pos_y = 1
    print(tmp)
    
    pygame.display.flip()
    print(tmp)
    tmp = "/0;0:0D0F0L0M0P0S0T/1;0:0D0F0L1M1P2S1T/2;0:3D6F5L2M0P0S1T/3;0:2D1F4L1M0P0S1T/4;0:2D9F4L3M2P0S0T/5;0:0D2F6L3M1P1S0T/6;0:4D6F0L1M2P1S1T/7;0:4D6F4L1M0P0S0T/8;0:0D2F3L0M0P0S0T/9;0:0D8F3L3M0P2S1T/10;0:5D2F3L3M1P0S0T/0;1:1D0F3L1M2P1S1T/1;1:3D8F2L2M1P2S0T/2;1:3D2F6L0M2P2S0T/3;1:1D5F4L0M0P1S0T/4;1:5D3F1L3M2P3S1T/5;1:0D1F1L2M2P4S1T/6;1:3D9F5L2M2P0S0T/7;1:2D0F5L0M2P0S0T/8;1:4D2F4L1M0P0S1T/9;1:5D1F0L0M1P4S0T/10;1:5D3F6L2M2P0S0T/"
    
    first_rocks(tmp, 100, 100, fenetre)
    time.sleep(1)
    while loop:

        pygame.display.flip()
        # Ajout du fond dans la fenêtre
        rect_white = pygame.draw.rect(fenetre, white_color, [0, 0, 100, 100],5)
        first_rocks(tmp, 100, 100, fenetre)
        print("I ROCK")
        time.sleep(1)
        test_right(Img, fenetre, x_size, y_size, pos_x, pos_y)
        # Actualisation de l'affichage
        # 10 fps
        clock.tick(100)

if __name__ == '__main__':
    main()
