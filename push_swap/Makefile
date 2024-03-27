NAME = push_swap
Name2 = checker
CC = gcc 
CFLAGS = -Wall -Wextra -Werror
SOURCE = ./src/turk_sort.c ./src/target_of_a.c ./src/free.c ./src/target_of_b.c  ./src/ft_split2.c ./src/ft_tools2.c ./src/ft_check_above.c ./src/sort_two_three.c ./src/check_targets.c\
		./src/check_stacks.c ./src/get_index.c ./src/ft_tools.c ./src/check_arg.c ./src/to_a.c ./src/to_b.c\
		./src/push_swap.c ./src/moves_push.c ./src/moves_reverse.c ./src/moves_rotate.c ./src/reverse_and_rotate.c\
		./src/moves_swap.c
SOURCEB = 	./bonus/check_sorted_bonus.c ./bonus/free_bonus.c ./bonus/checker_bonus.c ./bonus/check_arg_bonus.c ./bonus/ft_tools_bonus.c ./bonus/ft_tools2_bonus.c ./bonus/moves_push_bonus.c\
			./bonus/moves_reverse_bonus.c ./bonus/moves_rotate_bonus.c ./bonus/reverse_and_rotate_bonus.c ./bonus/moves_swap_bonus.c\
			./bonus/get_next_line/get_next_line.c ./bonus/get_next_line/get_next_line_utils.c ./bonus/ft_split2_bonus.c
OBJ = ${SOURCE:.c=.o}
BOBJ = ${SOURCEB:.c=.o}

all: ${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJ}
		${CC} ${CFLAGS} ${OBJ} -o ${NAME}

bonus: ${Name2}

${Name2}: ${BOBJ}
		${CC} ${CFLAGS} ${BOBJ} -o ${Name2}

clean:
	rm -rf ${OBJ} ${BOBJ}

fclean: clean
	rm -rf ${NAME} ${Name2}

re: fclean all

.SECONDARY: ${OBJ} ${BOBJ}