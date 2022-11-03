# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/15 11:39:18 by pamartin          #+#    #+#              #
#    Updated: 2022/06/15 11:39:21 by pamartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		 	= 	init.c \
				utils_init.c \
				main.c \
				utils.c \
				parsing.c \
				action.c \
				dinner.c
				
OBJ 		= $(SRC:.c=.o)

NAME		= philo
CC			= gcc
RM			= rm -f
FLAG		= -Wall -Wextra -Werror -pthread -Iinclude #-fsanitize=thread


$(NAME):	$(OBJ)
			$(CC) $(FLAG) -o $(NAME) $(OBJ)

all		:	$(NAME)
clean	:	
			${RM} $(OBJ)
fclean	:	clean
			$(RM) $(NAME)
re		:	fclean all
.PHONY	:	all clean fclean re
