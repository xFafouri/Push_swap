NAME = push_swap
CC = gcc #-fsanitize=address -g3
CFLAGS = -Wall -Wextra -Werror
SOURCE = ft_split.c ft_tools.c push_swap.c moves_push.c moves_reverse.c moves_rotate.c reverse_and_rotate.c moves_swap.c
OBJ = ${SOURCE:.c=.o}

all: ${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJ}
		${CC} ${CFLAGS} ${OBJ} -o ${NAME}

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${NAME}

re: fclean all