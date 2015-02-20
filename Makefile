##
## Makefile for make in /home/geiger_a/Makefile
## 
## Made by anthony geiger
## Login   <geiger_a@epitech.net>
## 
## Started on  Sat Jan  3 12:39:16 2015 anthony geiger
## Last update Thu Feb 12 13:35:35 2015 anthony geiger
##

RM	= rm -f

DEBUG	= 0

VERIF	= 0

CC	= gcc

NAME	= allum1

LIBMY   = lib/my/

SRCS	= allum1.c \
	  main.c \
	  aff.c \
	  win.c \
	  ia_gen.c \
	  verif.c \
	  ia/lvl1.c \
	  ia/lvl2.c \
	  ia/lvl3.c \
	  ia/lvl4.c \
	  ia/lvl5.c

SRCS_DIR	= src/

SRCS	:= $(addprefix $(SRCS_DIR), $(SRCS))

OBJS	= $(SRCS:.c=.o)

CFLAGS  = -I./include/
CFLAGS  += -Wall -Wextra -W
CFLAGS  += -pedantic

LDFLAGS = -L./lib/
LDFLAGS += -lmy


ifeq ($(DEBUG), 1)
        CFLAGS  += -g -std=c99
        CC      := clang
endif

ifeq ($(VERIF), 1)
        CFLAGS  += -g -std=c99
        LDFLAGS += -lstdc++
        CC      := gcc
endif


all: dependency $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

dependency:
	make -C $(LIBMY)

re:	fclean all

clean:
	$(RM) $(OBJS)
	make -C $(LIBMY) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBMY) fclean

.PHONY: all clean fclean re dependency
