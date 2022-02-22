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

BONUS = checker

PU = push_swap.a

PUB = checker.a

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

SRCSB = checker.c\
		get_next_line_bonus.c\
		get_next_line_utils_bonus.c

OBJS = $(subst .c,.o,$(SRCS))

OBJSB = $(subst .c,.o,$(SRCSB))

all : $(NAME)
	
$(NAME) : $(PU)
	$(CC) $(PU) -o $(NAME)
	@echo [executable Created]

$(PU) : $(OBJS)
	$(CC) -c $(FLAGS) $(SRCS)
	$(AR) $(PU) $(OBJS)

bonus : $(BONUS)

$(BONUS) : $(PUB) $(PU)
	$(CC) $(PUB) $(PU) -o $(BONUS)

$(PUB) : $(OBJSB)
	$(CC) -c $(FLAGS) $(SRCSB)
	$(AR) $(PUB) $(OBJSB)

clean :
	@rm -rf *.o

fclean : clean
	@rm -rf $(PU) $(PUB)

re : fclean all
