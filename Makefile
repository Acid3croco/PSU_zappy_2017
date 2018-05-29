##
## EPITECH PROJECT, 2018
## zappy
## File description:
## makefile
##

NAME_S	= zappy_server

NAME_C	= zappy_ia

CC	= gcc

RM	= rm -f

SRCS_S	= ./server_files/src/server.c

SRCS_C	= ./client_files/src/client.c

OBJS_S	= $(SRCS_S:.c=.o)

OBJS_C	= $(SRCS_C:.c=.o)

CFLAGS	+= -I ./server_files/include/
CFLAGS	+= -I ./client_files/include/
CFLAGS	+= -W -Wall -Wextra -g3

all: $(NAME_S) $(NAME_C)

$(NAME_S): $(OBJS_S)
	$(CC) $(OBJS_S) -o $(NAME_S) $(CFLAGS)

$(NAME_C): $(OBJS_C)
	$(CC) $(OBJS_C) -o $(NAME_C) $(CFLAGS)

clean:
	$(RM) $(OBJS_S) $(OBJS_C)

fclean: clean
	$(RM) $(NAME_S) $(NAME_C)

re: fclean all

.PHONY: all clean fclean re
