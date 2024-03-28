# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/21 17:13:32 by sbartoul          #+#    #+#              #
#    Updated: 2024/03/28 10:04:49 by sbartoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLX_PATH = mlx/

MLX_LIB = $(MLX_PATH)libmlx.a

MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

FT_PRINTF_PATH = ft_printf/

FT_PRINTF_LIB = $(FT_PRINTF_PATH)libftprintf.a

LIBFT_PATH = libft/

LIBFT_LIB = $(LIBFT_PATH)libft.a

GETNEXTLINE := get_next_line/*.c

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

CFILES = \
		logic/character_steps.c\
		logic/controls.c\
		logic/errors.c\
		logic/exit_window.c\
		logic/graphics.c\
		logic/maps.c\
		logic/so_long.c\
		logic/valid_characters.c\
		logic/has_ber_extension.c\
		logic/able_to_finish.c\
		logic/able_to_collect.c\
		logic/visited.c\

OBJECTS = $(CFILES:.c=.o)

all: subsystems $(NAME)

%.o : %.c
	@echo $(Y)Compiling [$<]...$(X)
	@$(CC) $(CFLAGS) -Imlx -c -o $@ $<
	@printf $(UP)$(CUT)

subsystems:
	@echo $(B)
	make -C $(MLX_PATH) all
	@echo $(B)
	make -C $(FT_PRINTF_PATH) all
	@echo $(B)
	make -C $(LIBFT_PATH) all

$(NAME): $(OBJECTS)
	@echo $(Y)Compiling [$(CFILES)]...$(X)
	@echo $(G)Finished [$(CFILES)]$(X)
	@echo
	@echo $(Y)Compiling [$(NAME)]...$(X)
	@$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJECTS) $(MLX_LIB) $(FT_PRINTF_LIB) $(LIBFT_LIB) $(GETNEXTLINE) -o $(NAME)
	@echo $(G)Ready to play 🎮 [$(NAME)]$(X)

clean:
	@make -C $(MLX_PATH) clean
	@make -C $(FT_PRINTF_PATH) clean
	@make -C $(LIBFT_PATH) clean
	@rm -f $(OBJECTS)
	@echo $(R)Removed [$(OBJECTS)]$(X)

fclean: clean
	@make -C $(MLX_PATH) clean
	@make -C $(FT_PRINTF_PATH) clean
	@make -C $(LIBFT_PATH) clean
	@rm -f $(NAME)
	@echo $(R)Removed [$(NAME)]$(X)

re: fclean all

.PHONY: all clean fclean re norm
