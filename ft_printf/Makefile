# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/07 21:42:40 by sbartoul          #+#    #+#              #
#    Updated: 2024/01/07 21:57:28 by sbartoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

AR = ar rcs
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
SRCS = 	ft_printchar.c        	\
		ft_printdigit.c       	\
		ft_printf.c				\
		ft_printhex.c			\
		ft_printstr.c			\
		ft_printptr.c			\

OBJECTS = ${SRCS:.c=.o}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
${NAME}: ${OBJECTS}
				${AR} ${NAME} ${OBJECTS}
all: ${NAME}
clean:
	${RM} ${OBJECTS}
fclean: clean
		${RM} ${NAME}
re: fclean all
.PHONY: all clean fclean re