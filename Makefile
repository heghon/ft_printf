# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmenant <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/15 14:29:32 by bmenant           #+#    #+#              #
#    Updated: 2020/01/06 15:39:01 by bmenant          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	check_all.c check_flags.c check_length.c check_precision.c \
check_space.c check_space_f.c check_type.c check_width.c ft_atof.c \
ft_printf.c init.c large_f.c manage_width_star.c print_bx.c print_c.c \
print_call.c print_d.c print_f.c print_nothing.c print_o.c print_p.c \
print_percent.c print_s.c print_u.c print_x.c round_f.c small_f.c	

GREEN =			\033[0;32m
BLUE =			\033[1;34m
YELLOW =		\033[1;33m
WHITE =			\033[1;37m
OK =			$(GREEN)-OK-$(WHITE)

CC =			gcc
NAME =			libftprintf.a

LOGIN = 		`whoami`

SRC_FILE =		./src/
OBJ_FILE =		./obj/

LIB_DIR = 		./libft/

OBJ =			$(SRC:.c=.o)

SRCS =			$(addprefix $(SRC_FILE),$(SRC))
OBJS =			$(addprefix $(OBJ_FILE),$(OBJ))

FLAGS =			-Wall -Wextra -Werror
IFLAGS =		-I ./inc/
CFLAGS =		-g3 -fsanitize=address

RM =			/bin/rm -f

.PHONY:			all clean fclean re


all : $(NAME)

libft_maker :
	$(MAKE) -C $(LIB_DIR)

$(OBJ_FILE)%.o : $(SRC_FILE)%.c
	@mkdir $(OBJ_FILE) 2> /dev/null || true
	@$(CC) -c $(FLAGS) -o $@ $<
	@echo "$@\r				$(OK)"

$(NAME) : libft_maker $(OBJS)
	@cp ./libft/libft.a $(NAME)
#	@clang $(FLAGS) -c $(SRCS)
	@ar rc $(NAME) $(OBJS)
	@echo "$(BLUE)-$(NAME)-\r				$(OK)"
	@echo "\n ft_printf disponible \r\n"

clean :
	@rm -Rf $(OBJ_FILE)
	@ $(MAKE) -C $(LIB_DIR) clean
	@echo "$(BLUE)-clean-\r				$(OK)"

fclean : clean
	@rm -f $(NAME)
	@ $(MAKE) -C $(LIB_DIR) fclean
	@echo "$(BLUE)-fclean-\r				$(OK)"

re	: fclean all
