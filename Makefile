# --------------------- FLAGS -------------------------------------------
CC       = gcc
CFLAGS   = -Wall -Werror -Wextra
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

#----------------------- LIBFT & MLX ------------------------------------

LIBFT  =		libft/libft.a
MLX    =		minilibx/libmlx.a
MMLX   =		./minilibx
LLIBFT =		./libft

#------------------------ BASE ------------------------------------------

HEADERS =   fractol.h
NAME	=   fractol
SRC		= 	fractales/julia.c \
			mainstruct/fractol1.c \
			fractales/mandelbrot.c \
			mainstruct/main.c \

			
#-------------------------------- BONUS ---------------------------------
#  Pas cette fois.. (en vrai ya un changement de couleur mais c'est pas ouf)
#------------------------------- OBJS -----------------------------------

OBJS=$(SRC:.c=.o)

#- colors
GREEN  	  = \033[1;32m
RED	  	  = \033[1;31m
YELLOW    = \033[1;33m
END_COLOR = \033[0m

#------------------------------- RULES ----------------------------------

all: $(NAME)

$(NAME) : $(OBJS)
		@Make -C $(LLIBFT)
		@echo "$(GREEN) LIBFT OK $(END_COLOR)"
		@Make -C $(MMLX)
		@$(CC) $(CFLAGS) $(SRC) -o $(NAME) -I $(HEADERS) -L. $(LIBFT) -I $(MMLX) -L $(MMLX) $(MLXFLAGS)
		@echo "$(GREEN) MLX OK $(END_COLOR)"
		@echo "$(GREEN)COMPIL SUCCESS $(END_COLOR)"

clean: 
		@$(RM) $(OBJS)
		@make clean -C libft
		@echo "$(YELLOW) libft cleaned $(END_COLOR)"
		@make clean -C minilibx
		@echo "$(YELLOW) minilibx cleaned $(END_COLOR)"
		@echo "$(YELLOW) all ".o" cleaned $(END_COLOR)"

fclean:
		@$(RM) $(OBJS)
		@echo "$(YELLOW) all ".o" cleaned $(END_COLOR)"
		@rm -rf fractol
		@make fclean -C libft
		@echo "$(RED) libft fcleaned $(END_COLOR)"
		@make clean -C minilibx
		@echo "$(YELLOW) minilibx cleaned $(END_COLOR)"
		@echo "$(RED) fractol fcleaned $(END_COLOR)"

# Pourquoi je n'ai pas demander au fclean de clean? sinon libft.a est pas refais 
# ou je lui demande de faire a double...

re: fclean all

.PHONY: all clean fclean re