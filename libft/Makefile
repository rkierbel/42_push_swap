# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkierbel <rkierbel@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/14 14:43:28 by rkierbel          #+#    #+#              #
#    Updated: 2021/06/14 14:43:31 by rkierbel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
INC_DIR = includes
SRC_DIR = sources

NAME = libft.a

SRC_FILES =	ft_strcpy.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
  			ft_memchr.c \
			ft_memcmp.c \
			ft_strlen.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
  			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_uintlen.c \
			ft_intlen.c \
			ft_strdel.c \
			ft_isspace.c \
			ft_delchar.c \
			ft_delspace.c \
			ft_ullitoa_base.c \
			ft_free_array_string.c \
			ft_free.c \
			ft_swap.c \
			ft_atol.c
			
SRCS = $(addprefix $(SRC_DIR)/,$(SRC_FILES))

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "\033[1;32m\n[OK]\033[0m    \033[1;33mCreating \033[0m $@"

%.o: %.c
	@gcc $(FLAGS) -I $(INC_DIR) -c $< -o $@
	@echo "\033[1;32m[OK]\033[0m    \033[1;33mCompiling\033[0m $(<F)"

clean:
	@rm -f $(OBJS)
	@echo "\033[1;32m[OK]\033[0m    \033[1;33mDeleting \033[0m object files of libft\n"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[1;32m[OK]\033[0m    \033[1;33mDeleting \033[0m $(NAME)\n"

re: fclean all
