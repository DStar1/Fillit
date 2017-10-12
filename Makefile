NAME = fillit.a

SRC =	validator.c \
		backtrack.c \
		get_shape.c
#fillit.c \


all: $(NAME)

$(NAME):
	gcc -g -c -Wall -Werror -Wextra $(SRC)
	ar rc $(NAME) *.o
	ranlib $(NAME)

# add back -Wall -Werror -Wextra
cmain:
	/bin/rm -f $(NAME)
	gcc -g -c $(SRC)
	ar rc $(NAME) *.o
	ranlib $(NAME)
	/bin/rm -f *.o
	gcc -g main.c libft/libft.a fillit.a
	./a.out "test.txt"

main: #compiles the main.c file with libft.a after cleaning *.o's take this out when turning in
	/bin/rm -f *.o
	gcc -g main.c libft/libft.a fillit.a
	./a.out

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
