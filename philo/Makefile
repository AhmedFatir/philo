# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afatir <afatir@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 14:35:22 by afatir            #+#    #+#              #
#    Updated: 2023/05/13 10:42:53 by afatir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo
CFLAGS	= -Wall -Werror -Wextra 
-fsanitize=thread
CC		= cc
MOBJS	= ${SRCS:%.c=%.o}
SRCS	= philo.c parcing.c routine.c simulation.c simulation2.c

all : $(NAME)

$(NAME) : $(MOBJS)
	@$(CC) $(CFLAGS) $(LIB_FT_A) $(MOBJS) -o $(NAME)
# @make clean

%.o: %.c philo.h
	$(CC) $(CFLAGS)  -c $< -o $@

clean:
	@rm -f $(MOBJS) 

fclean:	clean
	@rm -f $(NAME)

re:	fclean all