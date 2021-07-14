# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rudykierbel <rkierbel@student.s19.be>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/14 15:04:06 by rudykierb         #+#    #+#              #
#    Updated: 2021/06/14 15:04:40 by rudykierb        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@make --no-print-directory -C ./srcs/push_swap
	@make --no-print-directory -C ./srcs/checker

push_swap:
	@make --no-print-directory -C ./srcs/push_swap

checker:
	@make --no-print-directory -C ./srcs/checker

clean:
	@make --no-print-directory clean -C ./srcs/push_swap
	@make --no-print-directory clean -C ./srcs/checker
	@make --no-print-directory clean -C ./libft

fclean:
	@make --no-print-directory fclean -C ./srcs/push_swap
	@make --no-print-directory fclean -C ./srcs/checker
	@make --no-print-directory fclean -C ./libft

re: fclean all

.PHONY: checker

.PHONY: push_swap
