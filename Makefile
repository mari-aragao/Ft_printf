SRCS = ft_printf.c printf_functions1.c printf_functions2.c printf_functions3.c 

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

fclean:	clean
	${RM} ${NAME}

re:	fclean all

.PHONY: all clean fclean re
