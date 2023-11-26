# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/30 15:03:56 by eguelin           #+#    #+#              #
#    Updated: 2023/11/26 17:41:17 by eguelin          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re $(OUT_DIR)
.SILENT:

# **************************************************************************** #
#                                   Variable                                   #
# **************************************************************************** #

NAME	= My_Awesome_PhoneBook
OUT_DIR	= build/
CLS_DIR = class/
INC_DIR	= include/
SRC_DIR	= src/
CC		= c++
CFLAGS	= -Wall -Werror -Wextra -std=c++98
INC		= -I $(INC_DIR) -I $(CLS_DIR)
RM		= rm -fr

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
RESET	= \033[0;0m

# **************************************************************************** #
#                                    Message                                   #
# **************************************************************************** #

COMP_MSG		= "$(GREEN)Compilation $(NAME) $(RESET)done on $(YELLOW)$(shell date +'%Y-%m-%d %H:%M:%S')$(RESET)"
CLEAN_MSG		= "$(RED)Cleaning $(NAME) $(RESET)done on $(YELLOW)$(shell date +'%Y-%m-%d %H:%M:%S')$(RESET)"
FULL_CLEAN_MSG	= "$(PURPLE)Full cleaning $(NAME) $(RESET)done on $(YELLOW)$(shell date +'%Y-%m-%d %H:%M:%S')$(RESET)"

# **************************************************************************** #
#                                    Sources                                   #
# **************************************************************************** #

CLS_FILES	= Contact.cpp \
			  PhoneBook.cpp

ALL_FILES	= $(addprefix $(CLS_DIR), $(CLS_FILES))

SRC_FILES	= main.cpp

ALL_FILES	+= $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ_FILES	= $(addprefix $(OUT_DIR), $(ALL_FILES:.cpp=.o))

DEP_FILES	= $(OBJ_FILES:.o=.d)

# **************************************************************************** #
#                                     Rules                                    #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(INC) $(OBJ_FILES) -o $(NAME)
	echo $(COMP_MSG)

$(OUT_DIR)%.o: %.cpp | $(OUT_DIR)
	$(CC) $(CFLAGS) $(INC) -MMD -c $< -o $@
clean:
	$(RM) $(OUT_DIR)
	echo $(CLEAN_MSG)

fclean: clean
	$(RM) $(NAME)
	echo $(FULL_CLEAN_MSG)

re: fclean all

$(OUT_DIR):
	mkdir -p $(OUT_DIR)$(CLS_DIR) $(OUT_DIR)$(SRC_DIR)

-include $(DEP_FILES)
