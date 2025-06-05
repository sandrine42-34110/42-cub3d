NAME = so_long

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

MINILIBX-LINUX_DIR = ./minilibx-linux
MLX = $(MINILIBX-LINUX_DIR)/libmlx.a


CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I .

SRC = img.c \
		floodfill.c \
		maps.c \
		main.c \
		utils.c \
		utils2.c \
		movements.c \
		player.c


OBJ = ${SRC:%.c=obj/%.o}

#valgrind: re all
#	valgrind --leak-check=full --show-leak-kinds=all -track-origins=yes ./$(NAME)

all: ${NAME}
${NAME}: $(LIBFT) $(MLX) ${OBJ}
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) -lXext -lX11 -lm -o $(NAME)

$(LIBFT):
	@make -s -C $(LIBFT_DIR)
	@make -s -C $(LIBFT_DIR) bonus
	@echo "compilating $@"

$(MLX):
	@make -s -C $(MINILIBX-LINUX_DIR)
	@echo "compilating $@"

obj/%.o: src/%.c
	@mkdir -p obj
	@${CC} ${CFLAGS} -I $(LIBFT_DIR) -I $(MINILIBX-LINUX_DIR) -I . -c $< -o $@

clean:
	@make -s -C $(LIBFT_DIR) clean
	@make -s -C $(MINILIBX-LINUX_DIR) clean
	@rm -rf obj

fclean: clean
	@make -s -C $(LIBFT_DIR) fclean
	@rm -f ${NAME}

re: fclean all