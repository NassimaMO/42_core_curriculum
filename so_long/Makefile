SRCS		=  get_next_line/*.c ft_printf/*.c ft_printf/libft/*.c so_long*.c so_long_imgs/*.c

SRCS_BONUS	=  get_next_line/*.c ft_printf/*.c ft_printf/libft/*.c so_long_verif.c so_long_utils.c so_long_parse.c so_long_input.c so_long_bonus/*.c so_long_bonus/so_long_imgs_bonus/*.c

OBJS		= *.o

NAME		= so_long

CC		= gcc

CFLAGS	= -Wall -Wextra -g

RM		= rm -f

.c.o:
			${CC} ${CFLAGS} -c ${SRCS}

all:			${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} -L"minilibx-linux/" -lmlx -lXext -lX11 -lXrender
			mkdir -p OBJS
			mv *.o OBJS

bonus:		
			${CC} ${CFLAGS} -c ${SRCS_BONUS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} -L"minilibx-linux/" -lmlx -lXext -lX11 -lXrender
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
