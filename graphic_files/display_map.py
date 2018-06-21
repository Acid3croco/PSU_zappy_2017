#!/usr/bin/python3

import sys

#_______________________________________________________________________________
# SORT FIRST INFO OF SERVER BEFORE DISPLAY
def sort_info_serv(data, width, height):
	lst = [[0] * height for _ in range(width)]
	tab = data.split('/')
	return (tab)

#_______________________________________________________________________________
# INIT OBJECTS ON MAP 
def init_map(data, width, height):
	lst = sort_info_serv(data)
	#create_map(lst)
	#METTRE TA FONCTION POUR DISPLAY LA MAP EN PREMIER
	return (lst)