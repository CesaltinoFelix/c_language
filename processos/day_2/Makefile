NAME = run

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC= teste00.c

OBJS=$(SRC:.c=.o)

all: $(NAME)
	

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

e:	$(NAME)
	./run

.PHONE: all clean fclean re