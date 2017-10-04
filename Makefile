NAME = fillit.a

SRC = 	fillit.c \
		validator.c 

all: $(NAME)

$(NAME):
	gcc -c -Wall -Werror -Wextra $(SRC)
	ar rc $(NAME) *.o
	ranlib $(NAME)

cmain: 
	/bin/rm -f $(NAME)
	gcc -c -Wall -Werror -Wextra $(SRC)
	ar rc $(NAME) *.o
	ranlib $(NAME)
	/bin/rm -f *.o
	gcc  main.c libft/libft.a fillit.a
	./a.out "test.txt"

main: #compiles the main.c file with libft.a after cleaning *.o's take this out when turning in
	/bin/rm -f *.o
	gcc main.c libft/libft.a fillit.a
	./a.out

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
