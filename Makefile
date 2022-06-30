# --------------------- FLAGS ----------------------------
CC = gcc
CFLAGS = -Wall -Werror -Wextra

#----------------------- LIBFT -----------------------------

LIBFT = cd libft && make
LIB = libft/libft.a

#------------------------ BASE -------------------------------

SERVER = server.c
CLIENT = client.c

NAME = serv
SERV_NAME = server
CLIENT_NAME = client

SERVER_SRC = $(SERVER)
SERVER_OBJ = $(SERVER_SRC:.c=.o)

CLIENT_SRC = $(CLIENT)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

#-------------------------------- BONUS -------------------------------

SERVER_BONUS = server_bonus.c
CLIENT_BONUS = client_bonus.c

SERV_NAME_BONUS = server_bonus
CLIENT_NAME_BONUS = client_bonus

SERVER_SRC_BONUS = $(SERVER_BONUS)
SERVER_OBJ_BONUS = $(SERVER_SRC_BONUS:.c=.o)

CLIENT_SRC_BONUS = $(CLIENT_BONUS)
CLIENT_OBJ_BONUS = $(CLIENT_SRC_BONUS:.c=.o)

#------------------------------- OBJS ----------------

OBJS = $(CLIENT_OBJ) $(SERVER_OBJ) $(CLIENT_OBJ_BONUS) $(SERVER_OBJ_BONUS)

#- colors

#------------------------------- RULES --------------------------

all: $(NAME) 
		echo '\033[1;32m COMPIL SUCCESS'; tput sgr0

$(NAME): bibli server client server_bonus client_bonus

bibli: 
		@$(LIBFT)

server: $(SERVER_OBJ)
		@$(CC) $(CFLAGS) $(SERVER_OBJ) $(LIB) -o $(SERV_NAME)

client: $(CLIENT_OBJ) bibli
		@$(CC) $(CFLAGS) $(CLIENT_OBJ) $(LIB) -o $(CLIENT_NAME)

server_bonus: $(SERVER_OBJ_BONUS)
		@$(CC) $(CFLAGS) $(SERVER_OBJ_BONUS) $(LIB) -o $(SERV_NAME_BONUS)

client_bonus: $(CLIENT_OBJ_BONUS) bibli
		@$(CC) $(CFLAGS) $(CLIENT_OBJ_BONUS) $(LIB) -o $(CLIENT_NAME_BONUS)
clean: 
	$(RM) $(OBJS)
	 cd libft && make clean
	 echo '\033[1;31m CLEANED SUCCESS'; tput sgr0

fclean: 
		$(RM) $(CLIENT_NAME) $(SERV_NAME) $(OBJS) $(CLIENT_NAME_BONUS) $(SERV_NAME_BONUS)
		cd libft && make fclean 
		echo '\033[1;31m FCLEANED SUCCESS'; tput sgr0

re: fclean all

.PHONY: all server client clean fclean re bibli server_bonus client_bonus