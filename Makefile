# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmei <nmei@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/27 08:57:48 by nmei              #+#    #+#              #
#    Updated: 2018/09/17 14:58:52 by carmenia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler_viz

CFLAGS = -Wall -Wextra -Werror

INCLUDES = ./includes/

SRC = main.c\
	  image.c\
	  key_hooks.c\
	  game_state_list_utils.c\
	  read_utils.c\
	  render.c\
	  render_str.c\
	  general_utils.c\
	  color.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) libft/*.c libft/Makefile
	@printf "\n\033[32m make libft \033[0m"
	@make -C libft
	@cp libft/libft.a ./$(NAME)
	@gcc $(CFLAGS) -I$(INCLUDES) $(OBJ) -o $(NAME) libft/libft.a /usr/local/lib/libmlx.a -framework OpenGL -framework AppKit

%.o: %.c
	@printf "\r\033[31mgcc -c -Wall -Wextra -Werror -o $@ $^                    \033[0m"
	@gcc -c -Wall -Wextra -Werror -o $@ $^

clean:
	@cd libft ; make clean ; cd ..
	@rm -f $(OBJ)


fclean: clean
	@cd libft ; make fclean ; cd ..
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
