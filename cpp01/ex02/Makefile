# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbitca <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/09 17:05:28 by cbitca            #+#    #+#              #
#    Updated: 2026/03/09 17:06:23 by cbitca           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPP     = c++
CFLAGS  = -Wall -Wextra -Werror -std=c++98

NAME    = Brain

SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj

SRCS    = $(shell find -name "*.cpp")
OBJS    = $(patsubst /%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CPP) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CPP) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re