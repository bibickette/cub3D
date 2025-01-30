
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

NAME = cub3D

NAME_BONUS = cub3D_bonus

CC = cc
INCLUDE = include
CFLAGS = -Wall -Werror -Wextra -I$(INCLUDE) -I$(INCLUDE_LIBFT) -g3

MINILIBX_FLAGS = -Lminilibx-linux -lmlx_Linux -lXext -lX11 -lm -lz
INCLUDE_LIBFT = LIBFT

LIBFT = LIBFT/libft.a

# Source directories
SRC_DIR = src/
SRC_COMMON_DIR = $(SRC_DIR)common
SRC_BONUS_DIR =$(SRC_DIR)bonus
SRC_MANDATORY_DIR = $(SRC_DIR)mandatory
OBJ_DIR = obj
OBJ_BONUS_DIR = obj_bonus

#SRC FILES
INIT_MAP_PLAYER_DIR = $(SRC_COMMON_DIR)/init_map_player_mlx
INIT_MAP_PLAYER_FILES = \
		convert_to_tab_int.c \
		init_create_mlx.c \
		init_map.c \
		init_player.c \
		is_valid_map.c \
		is_valid_map_utils.c
INIT_MAP_PLAYER = $(addprefix $(INIT_MAP_PLAYER_DIR)/, $(INIT_MAP_PLAYER_FILES))

KEYSIM_DIR = $(SRC_COMMON_DIR)/keysim_handling
KEYSIM_FILES = \
		cross_exit.c \
		handle_key_utils.c \
		handle_key.c
KEYSIM = $(addprefix $(KEYSIM_DIR)/, $(KEYSIM_FILES))

PARSING_DIR = $(SRC_COMMON_DIR)/parsing
PARSING_FILES = \
		check_texture.c \
		init_arg_data.c \
		init_texture.c \
		is_valid_arg.c \
		is_valid_data.c \
		load_texture.c
PARSING = $(addprefix $(PARSING_DIR)/, $(PARSING_FILES))				

RAYCASTER_DIR = $(SRC_COMMON_DIR)/raycasting
RAYCASTER_FILES = \
		draw_3d_walls.c \
		horizontal_ray.c \
		vertical_ray.c \
		raycaster.c \
		raycasting_utils.c
RAYCASTER = $(addprefix $(RAYCASTER_DIR)/, $(RAYCASTER_FILES))

UTILS_DIR = $(SRC_COMMON_DIR)/utils
UTILS_FILES = \
		apocalypse.c \
		print_error.c \
		print_debug.c \
		utils.c \
		display_intro.c \
		rgb_to_uint.c \
		boussole.c \
		rgb_mix_two_colors.c \
		convert_tab_in_space.c 
UTILS = $(addprefix $(UTILS_DIR)/, $(UTILS_FILES))	



# BONUS PART SRC
PARSING_BONUS_DIR = $(SRC_BONUS_DIR)/parsing_bonus
PARSING_BONUS_FILES = \
		convert_to_tab_int_bonus.c \
		init_arg_data_bonus.c \
		init_map_bonus.c \
		is_valid_data_bonus.c \
		is_valid_map_bonus.c \
		is_valid_map_utils_bonus.c
PARSING_BONUS = $(addprefix $(PARSING_BONUS_DIR)/, $(PARSING_BONUS_FILES))	

RAYCASTER_BONUS_DIR = $(SRC_BONUS_DIR)/raycasting_bonus
RAYCASTER_BONUS_FILES = \
		door_open.c \
		door_closed.c \
		door_utils.c \
		draw_3d_walls_bonus.c \
		raycaster_bonus.c \
		horizontal_ray_bonus.c \
		vertical_ray_bonus.c 
RAYCASTER_BONUS = $(addprefix $(RAYCASTER_BONUS_DIR)/, $(RAYCASTER_BONUS_FILES))

HANDLE_KEY_BONUS_DIR = $(SRC_BONUS_DIR)/handle_key_bonus
HANDLE_KEY_BONUS_FILES = \
		handle_key_bonus.c \
		handle_key_utils_bonus.c \
		handle_door.c \
		collision.c 
HANDLE_KEY_BONUS = $(addprefix $(HANDLE_KEY_BONUS_DIR)/, $(HANDLE_KEY_BONUS_FILES))

MINIMAP_DIR = $(SRC_BONUS_DIR)/minimap
MINIMAP_FILES = \
		draw_mini_map.c \
		draw_player_minimap.c \
		minimap_utils.c \
		draw_circle_minimap.c 
MINIMAP = $(addprefix $(MINIMAP_DIR)/, $(MINIMAP_FILES))



# PUT FILES TOGETHER
COMMON_SRCS =  \
		$(INIT_MAP_PLAYER) \
		$(KEYSIM) \
		$(PARSING) \
		$(RAYCASTER) \
		$(UTILS) \
			
MANDATORY_SRCS = \
		$(SRC_MANDATORY_DIR)/main.c \
		$(SRC_MANDATORY_DIR)/display.c \

BONUS_SRCS = \
		$(PARSING_BONUS) \
		$(MINIMAP) \
		$(RAYCASTER_BONUS) \
		$(HANDLE_KEY_BONUS) \
		$(SRC_BONUS_DIR)/main_bonus.c \
		$(SRC_BONUS_DIR)/display_bonus.c \
		$(SRC_BONUS_DIR)/load_door.c \
		$(SRC_BONUS_DIR)/sprite.c \


PMANDATORY =  $(addprefix , $(MANDATORY_SRCS)) $(addprefix , $(COMMON_SRCS)) 
PBONUS = $(addprefix , $(BONUS_SRCS)) $(addprefix , $(COMMON_SRCS)) 
B_OBJS = $(PBONUS:$(SRC_DIR)%.c=$(OBJ_DIR)/%.o)
M_OBJS = $(PMANDATORY:$(SRC_DIR)%.c=$(OBJ_DIR)/%.o)


#PROGRESS BAR
TOTAL_SRCS := $(words $(COMMON_SRCS) $(MANDATORY_SRCS))
TOTA_SRCS_BONUS := $(words $(COMMON_SRCS) $(BONUS_SRCS))
COMPILED_SRCS := 0
#COLOR SET
COLOR_RESET = \e[0m
COLOR_GREEN = \e[0;35m
COLOR_BLUE = \e[0;35m


all: $(NAME)

$(OBJ_DIR)/%.o :  $(SRC_DIR)%.c 
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

	@$(eval COMPILED_SRCS=$(shell echo $$(($(COMPILED_SRCS)+1))))
	@echo -n "$(COLOR_BLUE)Compiling Objects cub3D $(COLOR_RESET)[$(COLOR_GREEN)"
	@for i in $(shell seq 1 25); do \
		if [ $$i -le $$(($(COMPILED_SRCS)*25/$(TOTAL_SRCS))) ]; then \
			echo -n "♣"; \
		else \
			echo -n "."; \
		fi; \
	done
	@echo -n "$(COLOR_RESET)] $(COMPILED_SRCS)/$(TOTAL_SRCS)\r"

$(NAME) : $(M_OBJS)
	
	@echo "$(COLOR_BLUE)\nCompiling cub3D...$(COLOR_RESET)"
	@make -s -C LIBFT
	@make -s -C minilibx-linux
	@$(CC) $(CFLAGS) $(M_OBJS) $(MINILIBX_FLAGS) -o $(NAME) $(LIBFT)
	@echo "$(COLOR_GREEN)cub3D Compilation complete !$(COLOR_RESET)        "

clean:
	@make -s -C LIBFT clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(COLOR_BLUE)✘✘✘ Deleting cub3D... ✘✘✘$(COLOR_RESET)"
	@make -s -C LIBFT fclean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@echo "$(COLOR_GREEN)✘✘✘ cub3D fcleaned ! ✘✘✘$(COLOR_RESET)        "

re: fclean all

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(B_OBJS)

	@echo "$(COLOR_BLUE)\nCompiling cub3D bonus...$(COLOR_RESET)"
	@make -s -C LIBFT
	@make -s -C minilibx-linux
	@$(CC) $(CFLAGS) $(B_OBJS) $(MINILIBX_FLAGS) -o $(NAME_BONUS) $(LIBFT)
	@echo "$(COLOR_GREEN)cub3D bonus Compilation complete !$(COLOR_RESET)        "

rebonus : fclean bonus


.PHONY: all clean fclean re