# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msidqi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/23 00:08:25 by msidqi            #+#    #+#              #
#    Updated: 2019/05/14 16:02:41 by msidqi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgl.a
SRC_PATH = src
GLSRC_PATH = src/libgl
SRC = ft_lerp.c ft_min_max.c ft_vec_normalize_magnitude.c \
ft_vector_operations.c ft_matrix.c ft_vec_create.c ft_vec_scalar.c \
ft_vector_sub.c ft_matrix_destroy.c ft_vec_cross_dot_prod.c ft_vector_add.c
INCLUDE = include
INC = include/libgl.h
OBJS_DIR = .objs
CC = sudo gcc -Wall -Wextra -Werror 
OBJ = $(addprefix $(OBJS_DIR)/,$(SRC:.c=.o))

all : $(NAME)

$(OBJ) : $(OBJS_DIR)/%.o : $(GLSRC_PATH)/%.c $(INC)| $(OBJS_DIR)
	$(CC) -c $< -o $@ -I$(INCLUDE)
$(NAME) : $(OBJ)
	sudo ar rc $@ $^
	sudo ranlib $@

clean : 
	rm -rf $(OBJ) $(LIBGLL)
fclean : clean
	rm -rf $(NAME)
re : fclean all

$(OBJS_DIR):
	mkdir $(OBJS_DIR)
