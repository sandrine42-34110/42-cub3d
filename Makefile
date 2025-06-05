NAME = cub3d

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

MINILIBX_LINUX_DIR = ./minilibx-linux
MLX = $(MINILIBX_LINUX_DIR)/libmlx.a

SRC_DIR = srcs

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I . -I includes

SRC =	srcs/check/check_text_and_map.c \
		srcs/check/floodfill.c \
		srcs/free/free.c \
		srcs/init/init.c \
		srcs/parsing/handle_map.c \
		srcs/parsing/handle_textures.c \
		srcs/parsing/handles_colors.c \
		srcs/parsing/parsing.c \
		srcs/main.c \
		srcs/utils.c

OBJ = ${SRC:srcs/%.c=srcs/obj/%.o}

#valgrind: re all
#	valgrind --leak-check=full --show-leak-kinds=all -track-origins=yes ./$(NAME)

all: ${NAME}
${NAME}: $(LIBFT) $(MLX) ${OBJ}
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) -lXext -lX11 -lm -lbsd -o $(NAME)

$(LIBFT):
	@make -s -C $(LIBFT_DIR)
	@make -s -C $(LIBFT_DIR) bonus
#	@echo "compilating $@"

$(MLX):
	@make -s -C $(MINILIBX_LINUX_DIR)
	@echo ✅ "mlx compiled"

srcs/obj/%.o: srcs/%.c
#	@mkdir -p obj
	@mkdir -p $(dir $@)
	@${CC} ${CFLAGS} -I $(LIBFT_DIR) -I $(MINILIBX_LINUX_DIR) -I . -c $< -o $@

clean:
	@make -s -C $(LIBFT_DIR) clean
	@make -s -C $(MINILIBX_LINUX_DIR) clean
#	@rm -rf obj
	@rm -rf srcs/obj

fclean: clean
	@make -s -C $(LIBFT_DIR) fclean
	@rm -f ${NAME}

re: fclean all