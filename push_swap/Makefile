NAME		=	push_swap

NAME_BONUS	=	push_swap_b

LIB			=	libft.a

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -g

SRCS_CHANGES=	push_swap_changes/pab.c push_swap_changes/rab.c \
				push_swap_changes/rr.c push_swap_changes/rrab.c \
				push_swap_changes/rrr.c push_swap_changes/sab.c \
				push_swap_changes/ss.c

SRCS		=	push_swap_algo_reverse.c push_swap_algo.c \
				push_swap_utils.c push_swap_verif.c push_swap_quick_algo.c \
				push_swap_scases.c push_swap.c push_swap_test_algo_op.c

SRCS_BONUS	=	

OBJ_DIR		=	obj

OBJ_DIR_B	=	obj

OBJ			=	$(addprefix $(OBJ_DIR)/,$(SRCS:%.c=%.o))

OBJ_CHANGES	=	$(addprefix $(OBJ_DIR)/,$(SRCS_CHANGES:push_swap_changes/%.c=%.o))

OBJ_BONUS	=	$(addprefix $(OBJ_DIR_B)/,$(SRCS_BONUS:push_swap_bonus/%.c=%.o))

RM			=	rm -f

all:			${NAME}

bonus:			${NAME_BONUS}

$(OBJ_DIR)/%.o: %.c
				@mkdir -p $(OBJ_DIR)
				$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: push_swap_changes/%.c
				@mkdir -p $(OBJ_DIR)
				$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR_B)/%.o: push_swap_bonus/%.c
				@mkdir -p $(OBJ_DIR_B)
				$(CC) $(CFLAGS) -c $< -o $@

${NAME}:		${OBJ} ${OBJ_CHANGES} ${LIB}
				$(CC) $(CFLAGS) $^ -o $@ -L. -lft

${NAME_BONUS}:	${OBJ_BONUS} ${LIB}
				$(CC) $(CFLAGS) $^ -o $@ -L. -lft

${LIB}:
				cd libft && make && mv $@ .. && cd ..
clean:
				cd libft && make fclean && cd ..
				${RM} ${LIB}
				${RM} -r ${OBJ_DIR}
				${RM} push_swap_bonus/*.o
				${RM} *.o

fclean:			clean
				${RM} ${NAME} ${NAME_BONUS}

re:				fclean all

.PHONY: 		all clean fclean re
