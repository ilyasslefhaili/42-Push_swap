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

NAME = push_swap.a

CC = gcc -c

FLAGS = -Wall -Wextra -Werror

AR = ar -rc

OUT = push_swap

SRCS = instructions1.c\
		instructions2.c\
		main.c\
		fivesort.c

OBJS = $(subst .c,.o,$(SRCS))

all : $(OUT)
	
$(OUT) : $(NAME)
	gcc $(NAME) -o push_swap

$(NAME) :$(OBJS)
	$(CC) $(FLAGS) $(SRCS)
	$(AR) $(NAME) $(OBJS)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all


