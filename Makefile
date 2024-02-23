SRC1	=	server.c		\
		server2.c

SRC2	=	client.c		\

OBJ1	=	${SRC1:.c=.o}
OBJ2	=	${SRC2:.c=.o}

NAME1	=	server
NAME2	=	client

FLAGS	=	-Wall -Wextra -Werror

all : ${NAME1} ${NAME2}

$(NAME1) : ${OBJ1}
	gcc -Wall -Werror -Wextra -fPIE server.c server2.c -o ${NAME1}

$(NAME2) : ${OBJ2}
	gcc ${FLAGS} ${OBJ2} -o ${NAME2}

clean :
	rm -f ${OBJ1} ${OBJ2}

fclean : clean
	rm -f ${NAME1} ${NAME2}

re : fclean all

.PHONY: all fclean clean re
