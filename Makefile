NAME=	getnextline.a

CC=		cc
CFLAGS=	-Wall -Wextra -Werror

INCLUDE= get_next_line.h

TEST_NAME=	test

SRCS =	get_next_line.c

OBJS =	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

test: all
	$(CC) $(CFLAGS) -D BUFFER_SIZE=42 main.c $(NAME) -o $(TEST_NAME)

.PHONY: all clean fclean re