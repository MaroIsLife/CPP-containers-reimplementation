SRC = main.cpp
CC = clang++ -Wall -Werror -Wextra -std=c++98

all: ft_containers

ft_containers:
	@$(CC) $(SRC) -Wall -Wextra -Werror -o ft_containers
clean :
	@rm -rf ft_containers.o
fclean : clean
		@rm -rf ./ft_containers ft_containers.dSYM
re : fclean all