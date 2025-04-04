# Nombre del ejecutable
NAME = fractol

# Compilador y flags
CC = cc
CFLAGS = -Wall -Werror -Wextra -g

# Fuente: compila todos los .c del directorio
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

# Directorio y nombre de la miniLibX
MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a

# Directorio y nombre de la libft (ajusta el nombre si es diferente)
LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libftprintf.a

# Flags y librerías para el enlazado (Linux)
LIBS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -L$(LIBFT_DIR) -l:libftprintf.a

# Regla por defecto: compila el ejecutable
all: $(NAME)

# Para compilar el ejecutable, dependemos de que se hayan generado la miniLibX y libft
$(NAME): $(OBJ) $(MLX_LIB) $(LIBFT_LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBS)

# Regla para compilar la miniLibX
$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

# Regla para compilar la libft
$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

# Regla para limpiar archivos objeto
clean:
	rm -f $(OBJ)
	$(MAKE) clean -C $(MLX_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)

# Regla para borrar el ejecutable y archivos objeto
fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

# Regla para recompilar desde cero
re: fclean all

# Regla bonus (ajústala según tus archivos bonus)
bonus:
	@echo "No se han definido reglas para bonus aún."

.PHONY: all clean fclean re bonus