NAME= run

CC= cc
FLAGS = -Wall -Werror -Wextra -pthread

SRC= teste00.c
OBJ= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(FLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

e:	$(NAME)
	./run

.PHONE: all clean fclean re
