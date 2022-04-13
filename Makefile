NAME = ft_container

FLAGS = -Wall -Wextra -Werror

CANG = clang++ -std=c++98

SRC = main.cpp

all: $(NAME)

$(NAME): $(SRC)
	$(CLANG) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean
	rm -rf $(NAME)

re: fclean all