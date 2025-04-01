NAME = libftprintf.a
LIBCOMPILER = ar
COMPILER = cc
LIBFLAGS = rcs
CFLAGS = -Wall -Werror -Wextra
CFILES = ft_printf.c ft_putptr_fd.c ft_string_utils.c ft_nbr_utils.c ft_print_hexa.c
LIBFT = libft/libft.a
COBJ = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(COBJ)
	make -C libft
	mv $(LIBFT) $(NAME)
	$(LIBCOMPILER) $(LIBFLAGS) $(NAME) $(COBJ)

%.o: %.c ft_printf.h
	$(COMPILER) $(CFLAGS) -c $< -o $@ 
clean: 
	rm -rf $(COBJ) libft/*.o

fclean: clean
	rm -rf $(NAME)

cleanall:

fcleanall:

re: fclean all

.PHONY: all $(NAME) clean fclean re