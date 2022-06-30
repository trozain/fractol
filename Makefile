# --------------------- FLAGS ----------------------------
CC     = gcc -framework OpenGL -framework AppKit
CFLAGS = -Wall -Werror -Wextra

#----------------------- LIBFT & MLX -----------------------------

LIBFT = cd libft && make
ML.X  = cd mlx && make
LIB   = libft/libft.a
MLX   = mlx/libmlx.a

#------------------------ BASE -------------------------------

WINDOW = windows.c
FRACT1 = fractol1.c
MANDEL = mandelbrot.c
JULIA  = julia.c

# transfo .c en .o ici

#-------------------------------- BONUS -------------------------------

#------------------------------- OBJS ----------------

OBJS = *.o

#- colors

#------------------------------- RULES --------------------------

all: $(NAME) -framework OpenGL -framework AppKit
		echo '\033[1;32m COMPIL SUCCESS'; tput sgr0

$(NAME): bibli mlx fractales

bibli: 
		@$(LIBFT)

mlx: 
		@$(ML.X)

fractales: $(FRACT1) bibli mlx
		@$(CC) $(CFLAGS)

mandelbrot:
		@$(CC) $(CFLAGS)

julia:
		@$(CC) $(CFLAGS)

clean: 
	$(RM) $(OBJS)
	 cd libft && make clean
	 cd mlx && make clean
	 echo '\033[1;31m CLEANED SUCCESS'; tput sgr0

fclean: 
		$(RM) $(OBJS)
		rm -rf *.a
		cd libft && make fclean 
		cd mlx && make clean
		echo '\033[1;31m FCLEANED SUCCESS'; tput sgr0

re: fclean all

.PHONY: all server client clean fclean re bibli fractales mlx