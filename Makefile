##
## EPITECH PROJECT, 2018
## zappy
## File description:
## makefile
##

NAME_S	= zappy_server

NAME_C	= zappy_ia

CC	= gcc

CPP	= g++

RM	= rm -f

SRCS_S	= ./server_files/src/server.c \
	./server_files/src/args.c \
	./server_files/src/teams.c \
	./server_files/src/quit.c \
	./server_files/src/socket.c \
	./server_files/src/epoll.c \
	./server_files/src/loop.c \
	./server_files/src/identify.c \
	./server_files/src/inter_input.c \
	./server_files/src/server_cmd.c \
	./server_files/src/quit_srv_cmd.c \
	./server_files/src/add_client.c \
	./server_files/src/map.c \
	./server_files/src/map_cmd.c \
	./server_files/src/move_cmd.c \
	./server_files/src/turn_cmd.c \
	./server_files/src/sel_cmd.c \
	./server_files/src/free.c \
	./server_files/src/my.c \
	./server_files/src/send_client.c \
	./server_files/src/look_cmd.c \
	./server_files/src/inventory_cmd.c \
	./server_files/src/con_cmd.c \
	./server_files/src/take_cmd.c \
	./server_files/src/obj1.c \
	./server_files/src/obj2.c \
	./server_files/src/broad_cmd.c \
	./server_files/src/eject_cmd.c \
	./server_files/src/add_input.c \
	./server_files/src/check_cmd.c \
	./server_files/src/help.c \
	./server_files/src/look_cell.c \
	./server_files/src/fork_cmd.c \
	./server_files/src/egg.c

SRCS_C	=	./client_files/src/Client.cpp	\
		./client_files/src/Mysocket.cpp	\
		./client_files/src/Command.cpp	\
		./client_files/src/Game.cpp	\
		./client_files/src/Inventory.cpp	\
		./client_files/src/Objectif.cpp

OBJS_S	= $(SRCS_S:.c=.o)

OBJS_C	= $(SRCS_C:.cpp=.o)

WFLAGS	+= -W -Wall -Wextra -g3
CFLAGS	+= -I ./server_files/include/ $(WFLAGS)
CPPFLAGS	= -I ./client_files/include/ $(WFLAGS)

all: $(NAME_S) $(NAME_C)

$(NAME_S): $(OBJS_S)
	$(CC) $(OBJS_S) -o $(NAME_S) $(CFLAGS)

$(NAME_C): $(OBJS_C)
	$(CPP) $(OBJS_C) -o $(NAME_C) $(CPPFLAGS)

clean:
	$(RM) $(OBJS_S) $(OBJS_C)

fclean: clean
	$(RM) $(NAME_S) $(NAME_C)

re: fclean all

.PHONY: all clean fclean re