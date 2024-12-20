
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/22 14:29:17 by phwang            #+#    #+#              #
#    Updated: 2024/12/06 14:06:37 by fsalomon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = cc
INCLUDE = include
CFLAGS = -Wall -Wextra -I$(INCLUDE) -I$(INCLUDE_LIBFT) -g3

MINILIBX_FLAGS = -Lminilibx-linux -lmlx_Linux -lXext -lX11 -lm -lz
INCLUDE_LIBFT = LIBFT

LIBFT = LIBFT/libft.a

# Source directories
SRC_DIR = src
OBJ_DIR = obj

PARSING_DIR = $(SRC_DIR)/parsing
PARSING_FILES = \
		check_arg.c \
		check_texture.c \
		get_map.c \
		init_texture.c \
		parse_file.c \
		is_valid_map.c \
		is_valid_map_utils.c \
		initialization.c \
		init_player.c
PARSING = $(addprefix $(PARSING_DIR)/, $(PARSING_FILES))				

UTILS_DIR = $(SRC_DIR)/utils
UTILS_FILES = \
		apocalypse.c \
		error.c \
		print_debug.c \
		utils.c \
		convert_tab_in_space.c \
		convert_to_tab_int.c 
UTILS = $(addprefix $(UTILS_DIR)/, $(UTILS_FILES))	

SRC = \
		$(PARSING) \
		$(UTILS) \
		$(SRC_DIR)/main.c \
		$(SRC_DIR)/draw_player_map.c \
		$(SRC_DIR)/draw_line.c \
		$(SRC_DIR)/background.c \
		$(SRC_DIR)/handle_key.c \
		$(SRC_DIR)/fonction_for_mlx.c \
		$(SRC_DIR)/draw_utils.c \
		$(SRC_DIR)/draw_ray.c 
			

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