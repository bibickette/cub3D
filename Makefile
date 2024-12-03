# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phwang <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/22 14:29:17 by phwang            #+#    #+#              #
#    Updated: 2024/12/03 18:34:45 by phwang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = cc
CFLAGS = -Wall -Wextra $(INCLUDE) -g3
MINILIBX_FLAGS = -Lminilibx-linux -lmlx_Linux -lXext -lX11 -lm -lz


INCLUDE = -I./include

# Source directories
SRC_DIR = src
OBJ_DIR = obj

# SIMU_DIR = $(SRC_DIR)/simulation
# SIMU_FILES = \
# 		dead_or_full.c \
# 		eat_fork.c \
# 		getters.c \
# 		start_monitoring.c \
# 		routine.c
# SIMULATION = $(addprefix $(SIMU_DIR)/, $(SIMU_FILES))				

SRC = \
	$(SRC_DIR)/main.c

OBJ	= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

#PROGRESS BAR
TOTAL_SRCS := $(words $(SRC))
COMPILED_SRCS := 0
#COLOR SET
COLOR_RESET = \e[0m
COLOR_GREEN = \e[0;35m
COLOR_BLUE = \e[0;35m

.PHONY: all clean fclean re

all: $(NAME)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

	@$(eval COMPILED_SRCS=$(shell echo $$(($(COMPILED_SRCS)+1))))
	@echo -n "$(COLOR_BLUE)Compiling Objects cub3d: $(COLOR_RESET)[$(COLOR_GREEN)"
	@for i in $(shell seq 1 25); do \
		if [ $$i -le $$(($(COMPILED_SRCS)*25/$(TOTAL_SRCS))) ]; then \
			echo -n "♣"; \
		else \
			echo -n "."; \
		fi; \
	done
	@echo -n "$(COLOR_RESET)] $(COMPILED_SRCS)/$(TOTAL_SRCS)\r"

$(NAME) : $(OBJ)
	@echo "$(COLOR_BLUE)\nCompiling cub3d...$(COLOR_RESET)"
	@make -s -C LIBFT
	@make -s -C minilibx-linux
	@$(CC) $(CFLAGS) $(OBJ) $(OBJ_MAIN) $(MINILIBX_FLAGS) -o $(NAME) $(LIBFT)
	@echo "$(COLOR_GREEN)cub3d Compilation complete !$(COLOR_RESET)        "

clean:
	@make -s -C LIBFT clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(COLOR_BLUE)✘✘✘ Deleting cub3d... ✘✘✘$(COLOR_RESET)"
	@make -s -C LIBFT fclean
	@rm -f $(NAME)
	@echo "$(COLOR_GREEN)✘✘✘ cub3d fcleaned ! ✘✘✘$(COLOR_RESET)        "

re: fclean all
