SRCS		=  fdf.c get_next_line/*.c fdf_*.c

OBJS		= *.o

NAME		= fdf

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
