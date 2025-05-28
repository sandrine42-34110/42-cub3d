NAME = cub3d

LIBFT = libft.a

MINILIB = libmlx.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -O3

HEADER_DIR = includes
SRCS_DIR = srcs
OBJS_DIR = objs

LIBFT_DIR = ./libft
MINILIB_DIR = ./minilibx-linux

#Pour compiler  sur mac & ubuntu
UNAME_S = $(shell uname -s)

ifeq ($(UNAME_S), Linux)
	MLX_FLAGS = -L$(MLX_PATH) -lmlx -lX11 -lXext -lm
else
	MLX_FLAGS = -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit
endif

INCLUDES = -I$(HEADER_DIR) -I$(MINILIB_DIR) -I$(LIBFT_DIR)
LIBS = -L$(LIBFT_DIR) -lft -L$(MINILIB_DIR) $(MLX_FLAGS)

#listing fin de projet
#SRCS_FILES = main.c
SRCS_FILES = $(shell find $(SRCS_DIR) -name "*.c")

OBJS = $(patsubst srcs/%.c, objs/%.o, $(SRCS_FILES))

all: $(LIBFT) $(MINILIB) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) --silent
	@echo ✅ "libft compiled"

$(MINILIB):
	@$(MAKE) -C $(MINILIB_DIR) --silent
	@echo ✅ "minilibx compiled"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBS) -o $(NAME) -lncurses -lreadline
	@echo ✅ "$(NAME) compiled"

objs/%.o: srcs/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJS_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean --silent
	@$(MAKE) -C $(MINILIB_DIR) clean
	@echo "✅ Object files removed"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR) --silent
	@$(MAKE) clean -C $(MINILIB_DIR) --silent
	@echo "✅ Executable files removed"
	
re: fclean all

.PHONY: all clean fclean re header