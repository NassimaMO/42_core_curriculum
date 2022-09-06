NAME		=	so_long

NAME_BONUS	=	so_long_b

LIB			=	libft.a

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -g

SRCS		=	so_long.c so_long_verif.c so_long_utils.c so_long_parse.c so_long_move.c \
				so_long_input.c so_long_init.c so_long_init_and_free.c so_long_imgs.c \
				so_long_imgs_utils.c so_long_imgs_print.c so_long_end.c

SRCS_BONUS	=	so_long_verif.c so_long_utils.c so_long_parse.c so_long_input.c \
				so_long_bonus/so_long_bonus.c so_long_bonus/so_long_end_bonus.c so_long_bonus/so_long_enemy_imgs_bonus.c \
				so_long_bonus/so_long_imgs_bonus.c so_long_bonus/so_long_imgs_print_bonus.c so_long_bonus/so_long_imgs_utils_bonus.c \
				so_long_bonus/so_long_init_and_free_bonus.c so_long_bonus/so_long_init_bonus.c so_long_bonus/so_long_move_bonus.c \
				so_long_bonus/so_long_place_enemy_bonus.c so_long_bonus/so_long_sprite_anim_imgs_bonus.c

OBJ			=	$(SRCS:.c=.o)

OBJ_BONUS	=	$(SRCS_BONUS:.c=.o)

RM			=	rm -f

all:			${NAME}

bonus:			${NAME_BONUS}

${NAME}:		${OBJ} ${LIB}
				$(CC) $(CFLAGS) $^ -o $@ -L"minilibx-linux/" -lmlx -lXext -lX11 -lXrender -L. -lft

${NAME_BONUS}:	${OBJ_BONUS} ${LIB}
				$(CC) $(CFLAGS) $^ -o $@ -L"minilibx-linux/" -lmlx -lXext -lX11 -lXrender -L. -lft

${LIB}:
				cd libft && make && mv $@ .. && cd ..
				cd minilibx-linux && make laptop && cd ..
clean:
				cd libft && make fclean && cd ..
				cd minilibx-linux && make clean && cd ..
				${RM} ${LIB}
				${RM} so_long_bonus/*.o
				${RM} *.o

fclean:			clean
				${RM} ${NAME} ${NAME_BONUS}

re:				fclean all

.PHONY: 		all clean fclean re
