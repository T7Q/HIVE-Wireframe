# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkuumola <tkuumola@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/19 18:53:27 by tkuumola          #+#    #+#              #
#    Updated: 2019/12/20 16:50:05 by tkuumola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Flags & colors

GRN = \033[0;32m
RED = \033[0;31m
MAG = \033[0;35m
RESET = \033[0m

FLAGS = -Wall -Wextra -Werror

LIBNAME = libft.a

# Executable files

NAME	= fdf

SRC		= main.c	\
		draw_grid.c \
		color.c	\
		controls.c \
		draw.c \
		init_fdf.c \
		manipulations.c	\
		palettes.c	\
		plot_line.c \
		reader.c	\
		z_buff.c	\
		support.c	\

EXECSRCS = $(addprefix $(SRCDIR), $(SRC))
LIBFILE= $(addprefix $(LIBDIR), $(LIBNAME))

OBJ = $(SRC:.c=.o)

HEADER = ./includes/

# Directories 

LIBDIR = ./libft/
SRCDIR = ./src/

MLX_LINK = /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

all: $(NAME)
$(NAME): $(LIBNAME) 
	@gcc $(FLAGS) -c $(EXECSRCS) -I $(HEADER)
	@gcc -o $(NAME) $(OBJ) $(FLAGS) $(LIBFILE) -I $(HEADER) -L $(MLX_LINK)
	@echo "$(GRN)(∩｀-´)⊃━✿✿✿✿✿✿ $(GRN) $(NAME) generated! $(RESET)"

$(LIBNAME):
	@make -C libft/ 

clean:
	@make clean -C libft
	@rm -f $(OBJ)
	@echo "$(MAG)(￣＾￣) $(MAG) objects removed $(RESET)"

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)
	@echo "$(MAG)ｄ(*￣o￣) $(MAG) $(NAME) removed! $(RESET)"

re: fclean all