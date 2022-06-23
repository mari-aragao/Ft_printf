SRCS = ft_printf.c ft_putchar_fd.c ft_putnbr_u.c ft_hexa.c ft_putstr_fd.c ft_putnbr_fd.c ft_strchr.c ft_hexa_long.c

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

.c.o:
	cc ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	ar rcs ${NAME} ${OBJS} 

all: ${NAME}

clean:
	${RM} ${OBJS}

fclen:	clean
	${RM} ${NAME}

re:	fclean all

.PHONY: all clean fclean re
