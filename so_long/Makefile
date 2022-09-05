SRCS		=  get_next_line/*.c ft_printf/*.c ft_printf/libft/*.c so_long*.c so_long_imgs/*.c

SRCS_BONUS	=  get_next_line/*.c ft_printf/*.c ft_printf/libft/*.c so_long_verif.c so_long_utils.c so_long_parse.c so_long_input.c so_long_bonus/*.c so_long_bonus/so_long_imgs_bonus/*.c

OBJ_DIR		= objs

OBJ			= $(addprefix $(OBJ_DIR)/,$(SRC:%.c=%.o))

OBJ_BONUS	= $(addprefix $(OBJ_DIR)/,$(SRC:%.c=%.o))

NAME		= so_long

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -g

RM			= rm -f

all:		${NAME}

$(OBJ_DIR)/%.o: %.c
			mkdir -p $(OBJ_DIR)
			cd minilibx-linux && make && cd ..
			$(CC) $(CFLAGS) -c $< -o $@ -L"minilibx-linux/" -lmlx -lXext -lX11 -lXrender

${NAME}:	${OBJ}

bonus:		${OBJ_BONUS}

clean:
			${RM} *.o
			${RM} ${OBJ_DIR}/*.o
			${RM} -r ${OBJ_DIR}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: 	all clean fclean re
