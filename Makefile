NAME = cub3d
NAME_BONUS = cub3d_bonus

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

MINILIBX_LINUX_DIR = ./minilibx-linux
MLX = $(MINILIBX_LINUX_DIR)/libmlx.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I . -I includes -DGL_SILENCE_DEPRECATION

SRC =	srcs/check/check_text_and_map.c \
		srcs/check/floodfill.c \
		srcs/display/dda.c \
		srcs/display/display_3d.c \
		srcs/display/display_map.c \
		srcs/display/draw_line.c \
		srcs/display/handle_win.c \
		srcs/display/raycasting.c \
		srcs/display/utils_display.c \
		srcs/free/free.c \
		srcs/free/free1.c \
		srcs/init/init_display.c \
		srcs/init/init.c \
		srcs/init/utils_init.c \
		srcs/move/move_player.c \
		srcs/parsing/handle_map.c \
		srcs/parsing/handle_textures.c \
		srcs/parsing/handles_colors.c \
		srcs/parsing/parsing.c \
		srcs/main.c \
		srcs/utils.c

SRC_BONUS =	srcs_bonus/check/check_text_and_map.c \
			srcs_bonus/check/floodfill.c \
			srcs_bonus/display/dda.c \
			srcs_bonus/display/display_3d.c \
			srcs_bonus/display/display_map.c \
			srcs_bonus/display/draw_line.c \
			srcs_bonus/display/handle_win.c \
			srcs_bonus/display/raycasting.c \
			srcs_bonus/display/utils_display.c \
			srcs_bonus/free/free.c \
			srcs_bonus/free/free1.c \
			srcs_bonus/init/init_display.c \
			srcs_bonus/init/init.c \
			srcs_bonus/init/utils_init.c \
			srcs_bonus/move/move_player.c \
			srcs_bonus/move/move_mouse.c \
			srcs_bonus/parsing/handle_map.c \
			srcs_bonus/parsing/handle_textures.c \
			srcs_bonus/parsing/handles_colors.c \
			srcs_bonus/parsing/parsing.c \
			srcs_bonus/main.c \
			srcs_bonus/utils.c

OBJ = ${SRC:srcs/%.c=srcs/obj/%.o}
OBJ_BONUS = ${SRC_BONUS:srcs_bonus/%.c=srcs_bonus/obj/%.o}

# Détection système
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S), Darwin)
	MLX_DIR = minilibx_macos
	MLX = $(MLX_DIR)/libmlx.a
	MLX_FLAGS = -framework OpenGL -framework AppKit
else
	MLX_DIR = minilibx-linux
	MLX = $(MLX_DIR)/libmlx.a
	MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
endif

all: ${NAME}

$(NAME): $(OBJ) $(LIBFT)
	@make -s -C $(MLX_DIR)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)

bonus: $(OBJ_BONUS) $(LIBFT)
	@make -s -C $(MLX_DIR)
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME_BONUS)

$(LIBFT):
	@make -s -C $(LIBFT_DIR)
	@make -s -C $(LIBFT_DIR) bonus

$(MLX):
	@make -s -C $(MLX_DIR)
	@echo ✅ "mlx compiled"

srcs/obj/%.o: srcs/%.c
	@mkdir -p $(dir $@)
	@${CC} ${CFLAGS} -I $(LIBFT_DIR) -I $(MINILIBX_LINUX_DIR) -I . -c $< -o $@

srcs_bonus/obj/%.o: srcs_bonus/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I $(LIBFT_DIR) -I $(MLX_DIR) -I . -c $< -o $@

clean:
	@make -s -C $(LIBFT_DIR) clean
	@make -s -C $(MLX_DIR) clean
	@rm -rf srcs/obj srcs_bonus/obj

fclean: clean
	@make -s -C $(LIBFT_DIR) fclean
	@rm -f ${NAME} ${NAME_BONUS}

re: fclean all