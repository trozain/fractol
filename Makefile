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
#  Pas cette fois..
#------------------------------- OBJS -----------------------------------

OBJS=$(SRC:.c=.o)

#- colors
GREEN = \033[1;32m
RED	  = \033[1;31m
#------------------------------- RULES ----------------------------------

all: $(NAME)

$(NAME) : $(LIBFT) $(MINILIBX) $(OBJS)
		@Make -C libft
		@echo "$(GREEN) libft OK"
		@Make -C minilibx
		@echo "$(GREEN) minilibx OK"
		@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -I $(HEADERS) -L. $(LIBFT) -L ./minilibx -lmlx -framework OpenGL -framework AppKit

		@echo "$(GREEN)COMPIL SUCCESS"

$(OBJS): $(LIBFT)
		$(CC) $(FLAGS) -c $(SRC)
$(LIBFT):
		make libft

clean: 
	$(RM) $(OBJS)
	 @make clean -C libft
	 @make clean -C minilibx

	 @echo "$(RED)CLEAN SUCCESS"

fclean: clean
		@rm -rf fractol
		@echo "$(RED)FCLEAN SUCCESS"

re: fclean all

.PHONY: all clean fclean
