# --------------------- FLAGS -------------------------------------------
CC     = gcc
CFLAGS = -Wall -Werror -Wextra

#----------------------- LIBFT & MLX ------------------------------------

LIBFT   = libft/libft.a
MLX   = minilibx/libmlx.a

#------------------------ BASE ------------------------------------------

HEADERS = fractol.h
NAME	= fractol
SRC		= 	*.c

#-------------------------------- BONUS ---------------------------------
# non abuses pas j ai assez gaelrer ainsi.
#------------------------------- OBJS -----------------------------------

OBJS=$(SRC:.c=.o)

#- colors
GREEN = \033[1;32m
RED	  = \033[1;31m
#------------------------------- RULES ----------------------------------

all: $(NAME)

$(NAME) : $(LIBFT) $(MINILIBX) $(OBJS)
		Make -C libft
		Make -C minilibx
		$(CC) $(CFLAGS) $(SRC) -o $(NAME) -I $(HEADERS) -L. $(LIBFT) -L ./minilibx -lmlx -framework OpenGL -framework AppKit

		@echo "$(GREEN)COMPIL SUCCESS"

$(OBJS): $(LIBFT)
		$(CC) $(FLAGS) -c $(SRC)
$(LIBFT):
		make libft
$(MINILIBX):
		make minilibx

clean: 
	$(RM) $(OBJS)
	 cd libft && make clean
	 cd minilibx && make clean

	 @echo "$(RED)CLEAN SUCCESS"

fclean: 
		rm -rf fractol
		$(RM) $(OBJS)
		rm -rf *.a
		cd libft && make fclean 
		cd minilibx && make clean

		@echo "$(RED)FCLEAN SUCCESS"

re: fclean all

.PHONY: all clean fclean