NAME			= philosophers

SRCS			=	main.c \
					parsing.c \
					temp.c	\
					utils.c

OBJS			= ${SRCS:.c=.o}

CC 				=	clang

CFLAGS 			=	-Wall -Werror -Wextra -g3

RM				=	rm -rf

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		${CC} -pthread ${CFLAGS} ${OBJS} -o ${NAME}

all:	${NAME}

clean:	
		${RM} ${OBJS}

fclean:	
		${RM} ${OBJS} ${NAME}

re:		clean
	${MAKE} all

.PHONY: all clean fclean re