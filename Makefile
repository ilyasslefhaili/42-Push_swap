# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilefhail <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/20 16:27:50 by ilefhail          #+#    #+#              #
#    Updated: 2022/02/20 16:27:52 by ilefhail         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

FLAGS = -Wall -Wextra -Werror

AR = ar -rc

OUT = push_swap

SRCS = instructions1.c\
		instructions2.c\
		main.c\
		fivesort.c\
		atoi.c\
		check.c\
		ft_fill_stack.c\
		fun_for_help.c

OBJS = $(subst .c,.o,$(SRCS))

all : $(NAME)
	
$(NAME) : $(OBJS)
	$(CC) $(FLAGS)  $(SRCS) -o  $(NAME)
	@echo [executable Created]

clean :
	@rm -rf $(OBJS)
	@rm -rf push_swap.a

fclean : clean
	@rm -rf $(NAME)

re : fclean all
