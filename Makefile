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
	./server_files/src/map_cmd.c

SRCS_C	=	./client_files/src/Client.cpp	\
		./client_files/src/Mysocket.cpp	\
		./client_files/src/Command.cpp	\
		./client_files/src/Game.cpp	\
		./client_files/src/Inventory.cpp	\
		./client_files/src/Objectif.cpp

OBJS_S	= $(SRCS_S:.c=.o)

OBJS_C	= $(SRCS_C:.cpp=.o)

WFLAGS	+= -W -Wall -Wextra
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