NAME = li# ==== Configuración ====
NAME_STATIC = libftprintf.a

LIB_DIR = ft_printf

CC = cc
AR = ar
CFLAGS = -Wall -Wextra -Werror -I. -I$(LIB_DIR)
ARFLAGS = rcs

# ==== Archivos ====
LIBFT_SRC = $(filter-out $(LIB_DIR)/%, $(wildcard *.c))
LIBFT_OBJ = $(LIBFT_SRC:.c=.o)

PRINTF_SRC = $(wildcard $(LIB_DIR)/*.c)
PRINTF_OBJ = $(PRINTF_SRC:.c=.o)

# ==== Targets ====
all: $(NAME_STATIC)

$(NAME_STATIC): $(LIBFT_OBJ) $(PRINTF_OBJ)
	$(AR) $(ARFLAGS) $@ $^


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(LIBFT_OBJ) $(PRINTF_OBJ) *.o $(LIB_DIR)/*.o

fclean: clean
	rm -f $(NAME_STATIC)

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus
