# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rudykierbel <rkierbel@student.s19.be>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/14 14:59:37 by rudykierb         #+#    #+#              #
#    Updated: 2021/06/14 14:59:39 by rudykierb        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		../../push_swap

CC =		clang
CFLAGS =	-Wall -Wextra -Werror

INCLUDES =	-I ./includes -I ../../libft/includes
LIBFT = -L ../../libft -lft

SRC_FILES  =	main.c \
				get_arguments.c \
				check_arguments.c \
				quicksort.c \
				first_step_sort.c \
				first_step_utils.c \
				second_step_sort.c \
				second_step_utils.c \
				sort_utils.c \
				ft_push_swap.c \
				ft_rotations.c \
				ft_list_and_error.c		

SRCS = $(addprefix srcs/,$(SRC_FILES))

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo ' '
	@make --no-print-directory -C ../../libft
	@clang $(OBJS) $(INCLUDES) $(CFLAGS) $(LIBFT) -o $@
	@echo "\033[1;32m\n[OK]\033[0m    \033[1;33mCreating \033[0m push_swap"

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "\033[1;32m[OK]\033[0m    \033[1;33mCompiling\033[0m $(<F)"

clean:
	@$(RM) $(OBJS)
	@echo "\033[1;32m[OK]\033[0m    \033[1;33mDeleting \033[0m object files of push_swap\n"

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[1;32m[OK]\033[0m    \033[1;33mDeleting \033[0m push_swap\n"
	

re: fclean all
