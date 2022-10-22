NAME		=	push_swap

NAME_BONUS	=	checker_bonus

LIB			=	libft.a

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -g

TEST		=	echo $$ARG; ./push_swap $$ARG | ./checker_linux $$ARG; ./push_swap \
				$$ARG | wc -l

TEST_3		=	ARG=$$(shuf -i 0-9999 -n 3) ;

TEST_5		=	ARG=$$(shuf -i 0-9999 -n 5) ;

TEST_25		=	ARG=$$(shuf -i 0-9999 -n 25) ;

TEST_100	=	ARG=$$(shuf -i 0-9999 -n 100) ;

TEST_500	=	ARG=$$(shuf -i 0-9999 -n 500) ;

TEST_VAL	=	echo $$ARG; ./push_swap $$ARG | ./checker_linux $$ARG; valgrind \
				--leak-check=full ./push_swap $$ARG | wc -l

SRCS_CHANGES=	push_swap_changes_lst/pab.c push_swap_changes_lst/rab.c \
				push_swap_changes_lst/rr.c push_swap_changes_lst/rrab.c \
				push_swap_changes_lst/rrr.c push_swap_changes_lst/sab.c \
				push_swap_changes_lst/ss.c

CHECKER_CHANGES=checker/checker_changes/pab.c checker/checker_changes/rab.c \
				checker/checker_changes/rr.c checker/checker_changes/rrab.c \
				checker/checker_changes/rrr.c checker/checker_changes/sab.c \
				checker/checker_changes/ss.c

SRCS		=	push_swap.c push_swap_utils.c push_swap_target_pos.c \
				push_swap_costs.c push_swap_algo_three.c push_swap_perf_move.c \
				push_swap_scases.c push_swap_tri_positionel_algo.c

SRCS_BONUS	=	checker/checker.c checker/checker_verif.c checker/checker_check.c

OBJ_DIR		=	obj

OBJ_DIR_B	=	obj_b

OBJ			=	$(addprefix $(OBJ_DIR)/,$(SRCS:%.c=%.o))

OBJ_CHANGES	=	$(addprefix $(OBJ_DIR)/,$(SRCS_CHANGES:push_swap_changes_lst/%.c=%.o))

OBJ_CK_CHANGES=	$(addprefix $(OBJ_DIR_B)/,$(CHECKER_CHANGES:checker/checker_changes/%.c=%.o))

OBJ_BONUS	=	$(addprefix $(OBJ_DIR_B)/,$(SRCS_BONUS:checker/%.c=%.o))

RM			=	rm -f

all:			${NAME}

bonus:			${NAME_BONUS}

test_3:			${NAME}
				$(TEST_3) $(TEST)

test_5:			${NAME}
				$(TEST_5) $(TEST)

test_25:		${NAME}
				$(TEST_25) $(TEST)

test_100:		${NAME}
				$(TEST_100) $(TEST)

test_500:		${NAME}
				$(TEST_500) $(TEST)

test_3_val:		${NAME}
				$(TEST_3) $(TEST_VAL)

test_5_val:		${NAME}
				$(TEST_5) $(TEST_VAL)

test_25_val:	${NAME}
				$(TEST_25) $(TEST_VAL)

test_100_val:	${NAME}
				$(TEST_100) $(TEST_VAL)

test_500_val:	${NAME}
				$(TEST_500) $(TEST_VAL)

$(OBJ_DIR)/%.o: %.c
				@mkdir -p $(OBJ_DIR)
				$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: push_swap_changes_lst/%.c
				@mkdir -p $(OBJ_DIR)
				$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR_B)/%.o: checker/checker_changes/%.c
				@mkdir -p $(OBJ_DIR_B)
				$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR_B)/%.o: checker/%.c
				@mkdir -p $(OBJ_DIR_B)
				$(CC) $(CFLAGS) -c $< -o $@

${NAME}:		${OBJ} ${OBJ_CHANGES} ${LIB}
				$(CC) $(CFLAGS) $^ -o $@ -L. -lft

${NAME_BONUS}:	${OBJ_BONUS} ${OBJ_CK_CHANGES} ${LIB}
				$(CC) $(CFLAGS) $^ -o $@ -L. -lft

${LIB}:
				cd libft && make bonus && mv $@ .. && cd ..
clean:
				cd libft && make fclean && cd ..
				${RM} ${LIB}
				${RM} -r ${OBJ_DIR}
				${RM} -r ${OBJ_DIR_B}
				${RM} push_swap_bonus/*.o
				${RM} *.o

fclean:			clean
				${RM} ${NAME} ${NAME_BONUS}

re:				fclean all

.PHONY: 		all clean fclean re
