# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soutin <soutin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/18 15:41:57 by soutin            #+#    #+#              #
#    Updated: 2023/07/05 20:39:35 by soutin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR		:=		src
OBJ_DIR		:=		obj
LIBFT_DIR	=		libft

NAME		=		push_swap
SRC			=		src/algo_utils.c src/algo.c src/inputs.c src/instructions_1.c src/instructions_2.c src/lists_utils.c src/main.c src/operations.c
OBJ			=		$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
LIBFT		=		libft/libft.a

CPPFLAGS	=		-I./include -I./libft/include
CFLAGS		=		-Wall -Werror -Werror -g3

$(NAME):			$(OBJ) 
						$(MAKE) -C $(LIBFT_DIR)
						$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJ) -o $(NAME) $(LIBFT)

$(OBJ_DIR):
					mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

all:				$(NAME)

clean:
					rm -rf $(OBJ_DIR)
					$(MAKE) clean -C $(LIBFT_DIR)

fclean:				clean
						rm -f $(NAME)
						$(MAKE) fclean -C $(LIBFT_DIR)

re:					fclean all

.PHONY:				all clean fclean re
