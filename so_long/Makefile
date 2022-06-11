SRCS		=  so_long.c get_next_line/*.c so_long_*.c

OBJS		= *.o

NAME		= so_long

CC		= gcc

CFLAGS	= -Wall -Wextra -g

RM		= rm -f

.c.o:
			${CC} ${CFLAGS} -c ${SRCS}

all:			${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} -L"minilibx-linux/" -lmlx -lXext -lX11 -lXrender

${NAME}:		all

clean:
			${RM} *.o

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: 	all clean fclean re
