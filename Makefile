NAME			=	philosophers

SRCS			=	core/act.c \
					core/create.c \
					core/mutex.c \
					core/parsing.c \
					threads/check.c \
					threads/routine.c \
					threads/threads.c \
					utils/print.c \
					utils/time.c \
					utils/utils.c \
					main.c

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