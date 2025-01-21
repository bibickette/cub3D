
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
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE) -I$(INCLUDE_LIBFT) -g3

MINILIBX_FLAGS = -Lminilibx-linux -lmlx_Linux -lXext -lX11 -lm -lz
INCLUDE_LIBFT = LIBFT

LIBFT = LIBFT/libft.a

# Source directories
SRC_DIR = src
SRC_BONUS_DIR = src/src_bonus
OBJ_DIR = obj

INIT_MAP_PLAYER_DIR = $(SRC_DIR)/init_map_player_mlx
INIT_MAP_PLAYER_FILES = \
		convert_to_tab_int.c \
		init_create_mlx.c \
		init_map.c \
		init_player.c \
		is_valid_map.c \
		is_valid_map_utils.c
INIT_MAP_PLAYER = $(addprefix $(INIT_MAP_PLAYER_DIR)/, $(INIT_MAP_PLAYER_FILES))

KEYSIM_DIR = $(SRC_DIR)/keysim_handling
KEYSIM_FILES = \
		cross_exit.c \
		handle_key_utils.c \
		handle_key.c
KEYSIM = $(addprefix $(KEYSIM_DIR)/, $(KEYSIM_FILES))

MINIMAP_DIR = $(SRC_DIR)/minimap
MINIMAP_FILES = \
		draw_line_minimap.c \
		draw_player_minimap.c \
		minimap_utils.c \
		draw_circle_minimap.c
MINIMAP = $(addprefix $(MINIMAP_DIR)/, $(MINIMAP_FILES))

PARSING_DIR = $(SRC_DIR)/parsing
PARSING_FILES = \
		check_texture.c \
		init_arg_data.c \
		init_texture.c \
		is_valid_arg.c \
		is_valid_data.c \
		load_texture.c
PARSING = $(addprefix $(PARSING_DIR)/, $(PARSING_FILES))				

RAYCASTER_DIR = $(SRC_DIR)/raycasting
RAYCASTER_FILES = \
		draw_3d_walls.c \
		horizontal_ray.c \
		vertical_ray.c \
		raycaster.c \
		raycasting_utils.c
RAYCASTER = $(addprefix $(RAYCASTER_DIR)/, $(RAYCASTER_FILES))

UTILS_DIR = $(SRC_DIR)/utils
UTILS_FILES = \
		apocalypse.c \
		print_error.c \
		print_debug.c \
		utils.c \
		convert_tab_in_space.c 
UTILS = $(addprefix $(UTILS_DIR)/, $(UTILS_FILES))	

# SRC = \
# 		$(INIT_MAP_PLAYER) \
# 		$(KEYSIM) \
# 		$(MINIMAP) \
# 		$(PARSING) \
# 		$(RAYCASTER) \
# 		$(UTILS) \
# 		$(SRC_DIR)/main.c \
# 		$(SRC_DIR)/display.c \
# 		$(SRC_DIR)/might_be_useless.c

COMMON_SRCS =  \
		$(INIT_MAP_PLAYER) \
		$(KEYSIM) \
		$(MINIMAP) \
		$(PARSING) \
		$(RAYCASTER) \
		$(UTILS) \

			
MANDATORY_SRCS = \
		$(SRC_DIR)/main.c \
		$(SRC_DIR)/display.c \

BONUS_SRCS = \
		$(SRC_BONUS_DIR)/main_bonus.c \
		$(SRC_BONUS_DIR)/display_bonus.c \
		$(SRC_BONUS_DIR)/handle_key_bonus.c \
		$(SRC_BONUS_DIR)/handle_key_utils_bonus.c \
		$(SRC_BONUS_DIR)/collision.c \
		$(SRC_BONUS_DIR)/boussole.c \
		$(SRC_DIR)/might_be_useless.c \

PMANDATORY = $(MANDATORY_SRCS) $(COMMON_SRCS)
PBONUS = $(BONUS_SRCS) $(COMMON_SRCS)
B_OBJS = $(PBONUS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
M_OBJS = $(PMANDATORY:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)


# OBJ	= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

#PROGRESS BAR
TOTAL_SRCS := $(words $(COMMON_SRCS) $(MANDATORY_SRCS))
TOTA_SRCS_BONUS := $(words $(COMMON_SRCS) $(BONUS_SRCS))
COMPILED_SRCS := 0
#COLOR SET
COLOR_RESET = \e[0m
COLOR_GREEN = \e[0;35m
COLOR_BLUE = \e[0;35m


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

$(NAME) : $(M_OBJS)
	
	@echo "$(COLOR_BLUE)\nCompiling cub3d...$(COLOR_RESET)"
	@make -s -C LIBFT
	@make -s -C minilibx-linux
	@$(CC) $(CFLAGS) $(M_OBJS) $(MINILIBX_FLAGS) -o $(NAME) $(LIBFT)
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

bonus : $(B_OBJS)
	@echo "$(COLOR_BLUE)\nCompiling cub3d bonus...$(COLOR_RESET)"
	@make -s -C LIBFT
	@make -s -C minilibx-linux
	@$(CC) $(CFLAGS) $(B_OBJS) $(MINILIBX_FLAGS) -o $(NAME) $(LIBFT)
	@echo "$(COLOR_GREEN)cub3d bonus Compilation complete !$(COLOR_RESET)        "

rebonus : fclean bonus


.PHONY: all clean fclean re