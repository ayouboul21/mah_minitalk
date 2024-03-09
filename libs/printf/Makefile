SRC = 	ft_printf.c ft_putnbr.c ft_putnbr_u.c \
		ft_putchar.c ft_puthexa.c ft_putstr.c
OBJS = ${SRC:.c=.o}
LIBC = ar -rcs
CFLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -f
NAME = libftprintf.a


%.o: %.c ft_printf.h
	@$(CC) $(CFLAGS) -c -o $@ $<
	
${NAME}: ${OBJS}
	@${LIBC} ${NAME} ${OBJS}

all: ${NAME}

clean:
	@${RM} $(OBJS)

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: clean