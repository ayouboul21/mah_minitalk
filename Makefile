SRC_CLIENT = minitalk_utils.c client.c
SRC_SERVER = minitalk_utils.c server.c
SRC_CLIENT_BONUS = minitalk_utils_bonus.c minitalk_utils_2_bonus.c client_bonus.c
SRC_SERVER_BONUS = minitalk_utils_bonus.c server_bonus.c
OBJ_C = ${SRC_CLIENT:.c=.o}
OBJ_S = ${SRC_SERVER:.c=.o}
OBJS_C_BONUS = ${SRC_CLIENT_BONUS:_bonus.c=_bonus.o}
OBJS_S_BONUS = ${SRC_SERVER_BONUS:_bonus.c=_bonus.o}
CFLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -f
NAME_S = server
NAME_C = client
NAME_CLIENT_BONUS = client_bonus
NAME_SERVER_BONUS = server_bonus
PRINTF_DIR = libs/printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

%.o: %.c minitalk.h
	@$(CC) $(CFLAGS) -c -o $@ $<

%_bonus.o: %_bonus.c minitalk_bonus.h
	@$(CC) $(CFLAGS) -c -o $@ $<

first: pre ${NAME_S} ${NAME_C}

${NAME_S}: ${OBJ_S} $(PRINTF_LIB)
		@echo "Linking server with Ftprintf..."
		@$(CC) $(CFLAGS) -o $@ $^

${NAME_C}: ${OBJ_C} $(PRINTF_LIB)
		@echo "Linking client with Ftprintf..."
		@$(CC) $(CFLAGS) -o $@ $^
		@echo "Finished"

${NAME_SERVER_BONUS}: ${OBJS_S_BONUS} $(PRINTF_LIB)
		@echo "Compiling Bonus..."
		@echo "Linking server with Ftprintf..."
		@$(CC) $(CFLAGS) -o $@ $^

${NAME_CLIENT_BONUS}: ${OBJS_C_BONUS} $(PRINTF_LIB)
		@echo "Linking client with Ftprintf..."
		@$(CC) $(CFLAGS) -o $@ $^
		@echo "Finished"

pre:
	@echo "Building Ftprintf..."
	@cd $(PRINTF_DIR) && make
	@echo "Done"

all: ${NAME_S} ${NAME_C}

clean:
	@echo "Cleaning..."
	@${RM} $(OBJ_S) ${OBJ_C} ${OBJS_C_BONUS} ${OBJS_S_BONUS}
	@$(MAKE) -C $(PRINTF_DIR) clean
	@echo "Finished"

fclean: clean
	@$(MAKE) -C $(PRINTF_DIR) fclean
	@${RM} ${NAME_S} ${NAME_C} ${NAME_SERVER_BONUS} ${NAME_CLIENT_BONUS}

re: fclean all

bonus: pre ${NAME_SERVER_BONUS} ${NAME_CLIENT_BONUS}

.PHONY: clean