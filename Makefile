FT_NAME = ft.out
STD_NAME = std.out

FT_OUT_DIR = ft_out/
STD_OUT_DIR = std_out/

OBJ_DIR = obj/

FT_SRC = ft.cpp
STD_SRC = std.cpp

HEADERS = stack.hpp
FT_OBJ =	$(patsubst %.cpp, %.o, $(FT_SRC))
STD_OBJ =	$(patsubst %.cpp, %.o, $(STD_SRC))

CPP = c++
FLAGS = -Wall -Wextra -Werror  

all: dirs ft std
	@echo -e "\e[92m"
	./ft.out > $(FT_OUT_DIR)ft
	./std.out > $(STD_OUT_DIR)std
	@echo -e "\e[96m"
	@echo -e "diff $(STD_OUT_DIR)ft $(FT_OUT_DIR)std > diff"
	@echo -e "\e[91m"
	@diff $(STD_OUT_DIR)ft $(FT_OUT_DIR)std > diff

ft: $(FT_OBJ)
	@echo -e "\e[93m"
	$(CPP) $^ -o $(FT_NAME) 

std: $(STD_OBJ)
	@echo -e "\e[93m"
	$(CPP) $^ -o $(STD_NAME) 

%.o: %.cpp $(HEADERS)
	@echo -e "\e[93m"
	$(CPP) $(FLAGS) -c $< -o  $@

dirs:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(FT_OUT_DIR)
	@mkdir -p $(STD_OUT_DIR)

clean:
	rm -rf $(FT_OBJ);
	rm -rf $(STD_OBJ);
	rm -f $(FT_OUT_DIR)ft
	rm -f $(STD_OUT_DIR)std
	rm -f diff

fclean: clean
	rm -f $(FT_NAME);
	rm -f $(STD_NAME);

re: fclean all

.PHONY: all clean fclean re
