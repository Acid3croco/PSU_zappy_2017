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

SRCS_S	= ./server_files/src/server.c

SRCS_C	=	./client_files/src/Client.cpp	\
		./client_files/src/Mysocket.cpp	\
		./client_files/src/Command.cpp

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
