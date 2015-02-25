#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcarmet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/25 16:48:52 by tcarmet           #+#    #+#              #
#    Updated: 2015/02/26 00:25:59 by tcarmet          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

FAST	= yes
ifeq ($(FAST),no)
	CFLAGS=-Wall -Wextra -Werror
else
	CFLAGS= -Wall -Wextra -Werror -Ofast
endif
NAME	= fractol
LDFLAGS = -L/usr/X11/lib -lmlx -lXext -lX11 -I./includes/ -I minilibx/ -L./libft/ -lft \
		-I/usr/X11R6/include -L/usr/X11R6/lib -lX11 -g
SRC 	= \
			main.c ft_julia_mandelbrot.c misc.c update.c inits_rabbit_chromo.c \
			hooks.c inits.c mouse_hooks.c displays.c color.c \
			llitoa.c
OBJ		= $(SRC:.c=.o)
INC		= fractol.h
SRCDIR	= ./srcs/
OBJDIR	= ./objs/
INCDIR	= ./includes/
SRCS	= $(addprefix $(SRCDIR), $(SRC))
OBJS	= $(addprefix $(OBJDIR), $(OBJ))
INCS	= $(addprefix $(INCDIR), $(INC))

.SILENT:

all: $(NAME)

$(NAME): $(OBJS) $(INCS)
	make -C libft/
	gcc $(CFLAGS) -o $@ $^ $(LDFLAGS)
	echo "\\033[1;32mSuccess.\\033[0;39m"

$(OBJS): $(SRCS)
ifeq ($(FAST),yes)
		echo "\\033[1;31mOFAST FLAG COMPILATION.. (all flags are on)\\033[0;39m"
else
		echo "\\033[1;31mCompilation with -Wall -Wextra -Werror...\\033[0;39m"
endif
	echo "\\033[1;34mGenerating objects... Please wait.\\033[0;39m"
	gcc $(CFLAGS) -c $(SRCS) $(LDFLAGS)
	mkdir -p $(OBJDIR)
	mv $(OBJ) $(OBJDIR)

.PHONY: clean fclean re

clean:
	echo "\\033[1;34mDeleting objects...\\033[0;39m"
	rm -f $(OBJS)

fclean: clean
	make fclean -C libft/
	echo "\\033[1;34mDeleting binary...\\033[0;39m"
	rm -f $(NAME)

re: fclean all

git:
		git add .
		echo "Enter Your Commit :"
		read var1 ; git commit -m "$$var1"
		git push
