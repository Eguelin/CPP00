# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/30 15:03:56 by eguelin           #+#    #+#              #
#    Updated: 2023/11/21 20:26:16 by eguelin          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re $(OUT_DIR)
.SILENT:

# **************************************************************************** #
#                                   Variable                                   #
# **************************************************************************** #

NAME	= Class_Account_tests
OUT_DIR	= build/
CLS_DIR = class/
SRC_DIR	= src/
CC		= c++
CFLAGS	= -Wall -Werror -Wextra -std=c++98
INC		= -I $(CLS_DIR)
RM		= rm -rf

# **************************************************************************** #
#                                    Colors                                    #
# **************************************************************************** #

BLACK	= \033[0;30m
RED		= \033[0;31m
GREEN	= \033[0;32m
YELLOW	= \033[0;33m
BLUE	= \033[0;34m
PURPLE	= \033[0;35m
CYAN	= \033[0;36m
WHITE	= \033[0;37m
NCOLOR	= \033[0;0m

# **************************************************************************** #
#                                    Message                                   #
# **************************************************************************** #

COMP_MSG		= "$(GREEN)Compilation $(NAME) $(NCOLOR)done on $(YELLOW)$(shell date +'%Y-%m-%d %H:%M:%S')$(NCOLOR)"
CLEAN_MSG		= "$(RED)Cleaning $(NAME) $(NCOLOR)done on $(YELLOW)$(shell date +'%Y-%m-%d %H:%M:%S')$(NCOLOR)"
FULL_CLEAN_MSG	= "$(PURPLE)Full cleaning $(NAME) $(NCOLOR)done on $(YELLOW)$(shell date +'%Y-%m-%d %H:%M:%S')$(NCOLOR)"

# **************************************************************************** #
#                                    Sources                                   #
# **************************************************************************** #

INC_CLS			= Account.hpp

HEADERS			= $(addprefix $(CLS_DIR), $(INC_CLS))

ALL_FILES		= tests.cpp

CLS_FILES		= Account.cpp

OBJS			+= $(addprefix $(OUT_DIR), $(ALL_FILES:.cpp=.o) $(CLS_FILES:.cpp=.o))

# **************************************************************************** #
#                                     Rules                                    #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INC) $(OBJS) -o $(NAME)
	@echo $(COMP_MSG)

$(OUT_DIR)%.o : $(SRC_DIR)%.cpp $(HEADERS) | $(OUT_DIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OUT_DIR)%.o : $(CLS_DIR)%.cpp $(HEADERS) | $(OUT_DIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	$(RM) $(OUT_DIR)
	echo $(CLEAN_MSG)

fclean: clean
	$(RM) $(NAME)
	echo $(FULL_CLEAN_MSG)

re: fclean all

$(OUT_DIR):
	mkdir -p $(OUT_DIR)
