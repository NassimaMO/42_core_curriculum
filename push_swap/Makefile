SRCS		= push_swap*.c push_swap_changes/*.c ft_printf/*.c ft_printf/libft/*.c 

OBJS		= *.o

NAME		= push_swap

CC		= gcc

CFLAGS	= -Wall -Wextra -g

RM		= rm -f

.c.o:
			${CC} ${CFLAGS} -c ${SRCS}

all:			${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} -g
			mkdir -p OBJS
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
