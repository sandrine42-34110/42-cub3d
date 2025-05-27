
NAME	=	cub3d

CC		=	cc
CFLAGS	=	-g -Wall -Wextra -Werror

LIBFT_PATH	= libft/
LIBFT_FILE	= $(LIBFT_PATH)libft.a
MLX_PATH	= minilibx-linux/
MLX_FILE	= $(MLX_PATH)libmlx.a

OBJ_DIR = build

UNAME_S = $(shell uname -s)

ifeq ($(UNAME_S), Linux)
	MLX_FLAGS = -L$(MLX_PATH) -lmlx -lX11 -lXext -lm
else
	MLX_FLAGS = -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit
endif

#SRC = srcs/main.c \
#		srcs/utils/xxx.c ...
#ligne ci-dessous a remplacer par le listing comme ci-dessus
SRC		= $(shell find srcs -name "*.c")

OBJ		= $(SRC:srcs/%.c=$(OBJ_DIR)/%.o)

LIBS	= $(MLX_FLAGS) $(LIBFT_FILE)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(MLX_PATH) > /dev/null
	@make -C $(LIBFT_PATH) --silent
	@$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME) -I includes/
	@echo ✅ "$(NAME) compiled"

$(OBJ_DIR)/%.o: srcs/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ -I includes/ -I $(LIBFT_PATH) -I $(MLX_PATH)

clean:
	@make clean -C $(LIBFT_PATH) --silent
	@make clean -C $(MLX_PATH) --silent
	@rm -f $(OBJ)
	@echo "✅ Object files removed"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH) --silent
	@make clean -C $(MLX_PATH) --silent
	@echo "✅ Executable files removed"

re: fclean all

.PHONY: all clean fclean re