SRCS		=  get_next_line/*.c ft_printf/*.c ft_printf/libft/*.c so_long*.c so_long_imgs/*.c so_long_enemy/*.c

OBJS		= *.o

NAME		= so_long

CC		= gcc

CFLAGS	= -Wall -Wextra -g

RM		= rm -f

.c.o:
			${CC} ${CFLAGS} -c ${SRCS}

all:			${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} -L"minilibx-linux/" -lmlx -lXext -lX11 -lXrender
			mkdir OBJS
			mv *.o OBJS

${NAME}:		all

clean:
			${RM} *.o
			${RM} OBJS/*.o
			${RM} -r OBJS

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: 	all clean fclean re
