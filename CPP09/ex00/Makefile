# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/03 15:24:38 by aweizman          #+#    #+#              #
#    Updated: 2024/09/12 16:18:48 by aweizman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++

CFLAGS = -g3 -Wall -Werror -Wextra -std=c++17

NAME = btc

SRCS = main.cpp BitcoinExchange.cpp

INCLUDES = -I./includes

SRC_PATH = src
OBJ_PATH = obj

SRC =	$(addprefix src/,	$(SRCS))

RED = \033[1;31m
GREEN = \033[1;32m
BLUE = \033[1;34m
YELLOW = \033[1;33m
RESET = \033[0m

OBJ = $(SRCS:.cpp=.o)

OBJS = $(addprefix $(OBJ_PATH)/,$(OBJ))

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) -o $(NAME) $(CFLAGS) $(INCLUDES) $(OBJS)
	@printf "%-100s\n" "$(NAME) compiled"

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp | $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean:
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -f $(NAME)

re: fclean all
