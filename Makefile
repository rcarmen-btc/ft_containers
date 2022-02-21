NAME = a.out

SRC = main.cpp
HEADERS = stack.hpp
OBJ =	$(patsubst %.cpp, %.o, $(SRC))

CPP = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(OBJ)
	$(CPP) $^ -o $(NAME) 

%.o: %.cpp $(HEADERS)
	$(CPP) $(FLAGS) -c $< -o  $@

clean:
	rm -rf $(OBJ);

fclean: clean
	rm -f $(NAME);

re: fclean all

.PHONY: all clean fclean re
