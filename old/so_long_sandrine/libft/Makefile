NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.

SRC = ft_bzero.c \
	ft_atoi.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strdup.c \
	ft_striteri.c \
	ft_strncmp.c \
	ft_strrchr.c \
	ft_strchr.c \
	ft_strcmp.c \
	ft_strnstr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_calloc.c \
	get_next_line_bonus.c\
	ft_printf.c \
	ft_putchar_pf.c \
	ft_putnbr_hex_pf.c \
	ft_putnbr_hex_ptr_pf.c \
	ft_putnbr_pf.c \
	ft_putnbr_u_pf.c \
	ft_putptr_pf.c \
	ft_putstr_pf.c

SRC_BONUS = ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \

all: ${NAME}

OBJ = ${SRC:%.c=obj/%.o} # Les fichiers objets générés à partir des fichiers sources
OBJ_BONUS = ${SRC_BONUS:%.c=obj/%.o}


# Générer l'exécutable
${NAME}: ${OBJ}
	ar rcs ${NAME} ${OBJ}

bonus: ${OBJ_BONUS}
	ar rcs ${NAME} ${OBJ_BONUS}


# Générer un fichier objet (.o) à partir d'un fichier source (.c)
obj/%.o: src/%.c
	mkdir -p obj
	${CC} ${CFLAGS} -c $< -o $@


# Nettoyer les fichiers temporaires générés
clean:
	rm -f ${OBJ} ${OBJ_BONUS}
	rm -rf /obj

fclean: clean
	rm -f ${NAME}

re: fclean all
