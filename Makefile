# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpalgi <palgijoel@gmail.com>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/01 17:59:14 by jpalgi            #+#    #+#              #
#    Updated: 2020/07/19 21:09:28 by jpalgi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
LIBFT = ./libft
LIBFTFLAGS= -L$(LIBFT) -lft
DIR_SRC = fillit_src
DIR_OBJ = obj_dir
SRC =	main.c check_file.c valid_tetrimino.c free_functions.c solve.c \
		solve_utils.c check_file_utils.c exit_error.c

YELLOW = "\033[1;33m"
NOCOLOR = "\033[0m"

SRCS = $(addprefix $(DIR_SRC)/, $(SRC))
OBJS = $(addprefix $(DIR_OBJ)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(DIR_OBJ) $(OBJS)
	@echo $(YELLOW)Compiling libft...$(NOCOLOR)
	@make -C $(LIBFT)
	@echo $(YELLOW)Compiling executable...$(NOCOLOR)
	@gcc $(LIBFTFLAGS) -o $(NAME) $(OBJS)

$(DIR_OBJ):
	@echo $(YELLOW)Compiling to .o files...$(NOCOLOR)
	@mkdir $(DIR_OBJ)

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c
	@gcc -Wall -Wextra -Werror -c -o $@ $<

clean:
	@echo $(YELLOW)Cleaning...$(NOCOLOR)
	@/bin/rm -rf $(DIR_OBJ)
	@make -C $(LIBFT) clean

fclean: clean
	@echo $(YELLOW)F-cleaning...$(NOCOLOR)
	@/bin/rm -f $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all

.PHONY: $(NAME), all, clean, fclean, re
