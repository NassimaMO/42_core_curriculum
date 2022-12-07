NAME		=	so_long

NAME_BONUS	=	so_long_b

NAME_LAPTOP	=	so_long_L

LIB			=	libft.a

MLX			=	libmlx.a

MLX_LAPTOP	=	libmlx_L.a

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -g

SRCS		=	so_long.c so_long_verif.c so_long_utils.c so_long_parse.c so_long_move.c \
				so_long_input.c so_long_init.c so_long_init_and_free.c so_long_imgs.c \
				so_long_imgs_utils.c so_long_imgs_print.c so_long_end.c so_long_mapsize_verif.c

SRCS_BONUS	=	so_long_bonus/so_long_verif_bonus.c so_long_bonus/so_long_utils_bonus.c \
				so_long_bonus/so_long_parse_bonus.c so_long_bonus/so_long_input_bonus.c \
				so_long_bonus/so_long_bonus.c so_long_bonus/so_long_end_bonus.c \
				so_long_bonus/so_long_enemy_imgs_bonus.c so_long_bonus/so_long_imgs_bonus.c \
				so_long_bonus/so_long_imgs_print_bonus.c so_long_bonus/so_long_imgs_utils_bonus.c \
				so_long_bonus/so_long_init_and_free_bonus.c so_long_bonus/so_long_init_bonus.c \
				so_long_bonus/so_long_move_bonus.c so_long_bonus/so_long_place_enemy_bonus.c \
				so_long_bonus/so_long_sprite_anim_imgs_bonus.c so_long_bonus/so_long_mapsize_verif_bonus.c \
				so_long_bonus/so_long_n_sprite_animation.c

OBJ_DIR		=	obj

OBJ_DIR_B	=	obj

OBJ			=	$(addprefix $(OBJ_DIR)/,$(SRCS:%.c=%.o))

OBJ_BONUS	=	$(addprefix $(OBJ_DIR_B)/,$(SRCS_BONUS:so_long_bonus/%.c=%.o))

RM			=	rm -f

all:			${NAME}

bonus:			${NAME_BONUS}

laptop:			${NAME_LAPTOP}

$(OBJ_DIR)/%.o: %.c
				@mkdir -p $(OBJ_DIR)
				$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR_B)/%.o: so_long_bonus/%.c
				@mkdir -p $(OBJ_DIR_B)
				$(CC) $(CFLAGS) -c $< -o $@

${NAME}:		${OBJ} ${LIB} ${MLX}
				$(CC) $(CFLAGS) $^ -o $@ -L"minilibx-linux/" -lmlx -lXext -lX11 -lXrender -L. -lft

${NAME_BONUS}:	${OBJ_BONUS} ${LIB} ${MLX}
				$(CC) $(CFLAGS) -o $@ $(OBJ_BONUS) -L"minilibx-linux/" -lmlx -lXext -lX11 -lXrender -L. -lft

${NAME_LAPTOP}:	${OBJ_BONUS} ${LIB} ${MLX_LAPTOP}
				$(CC) $(CFLAGS) -o $@ $(OBJ_BONUS) -L"minilibx-linux/" -lmlx_L -lXext -lX11 -lXrender -L. -lft
${LIB}:
				cd libft && make && mv $@ .. && cd ..

${MLX}:
				make -C minilibx-linux 

${MLX_LAPTOP}:
				make laptop -C minilibx-linux
clean:
				cd libft && make fclean && cd ..
				cd minilibx-linux && make clean && cd ..
				${RM} ${LIB}
				${RM} -r ${OBJ_DIR}
				${RM} so_long_bonus/*.o
				${RM} *.o

fclean:			clean
				${RM} ${NAME} ${NAME_BONUS}

re:				fclean all

.PHONY: 		all clean fclean re
