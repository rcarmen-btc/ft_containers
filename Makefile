FT_NAME =	ft
STD_NAME =	std

OUT_DIR =	outs/

INC =		stack.hpp templates.hpp utility.hpp
FT_SRC =	ft.cpp
STD_SRC =	std.cpp

FT_OBJ =	$(patsubst %.cpp, %.o, $(FT_SRC))
STD_OBJ =	$(patsubst %.cpp, %.o, $(STD_SRC))

INC_DIR = 	headers/
SRC_DIR = 	src/
OBJ_DIR = 	obj/

INC_PATH =		$(addprefix $(INC_DIR), $(INC))
FT_SRC_PATH =	$(addprefix $(SRC_DIR), $(FT_SRC))
FT_OBJ_PATH =	$(addprefix $(OBJ_DIR), $(FT_OBJ))

STD_SRC_PATH =	$(addprefix $(SRC_DIR), $(STD_SRC))
STD_OBJ_PATH =	$(addprefix $(OBJ_DIR), $(STD_OBJ))

CC = c++ -g
CFLAGS = # -Wall -Wextra -Werror -std=c++98
OPT_FLUGS = -O -g3 -pipe

COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m

OK_STRING    = "[OK]"
ERROR_STRING = "[ERROR]"
WARN_STRING  = "[WARNING]"
COM_STRING   = "Compiling"

define run
printf "%b" "$(COM_COLOR)$(COM_STRING) $(OBJ_COLOR)$(@F)$(NO_COLOR)\r"; \
$(1) 2> $@.log; \
RESULT=$$?; \
if [ $$RESULT -ne 0 ]; then \
  printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"   ; \
elif [ -s $@.log ]; then \
  printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(WARN_COLOR)$(WARN_STRING)$(NO_COLOR)\n"   ; \
else  \
  printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $(@F)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"   ; \
fi; \
cat $@.log; \
rm -f $@.log; \
exit $$RESULT
endef

all: obj $(FT_NAME) $(STD_NAME)  

$(FT_NAME):  $(FT_OBJ_PATH) 
	@$(CC) $^ -o $(FT_NAME) -I$(INC_DIR)

$(STD_NAME):  $(STD_OBJ_PATH) 
	@$(CC) $^ -o $(STD_NAME) -I$(INC_DIR)

VPATH = $(SRC_DIR)

$(OBJ_DIR)%.o: %.cpp $(INC_PATH)
	@$(call run, $(CC) $(CFLAGS) $(OPT_FLUGS) -c $< -o $@ -I$(INC_DIR))
	

diff: $(OUT_DIR)
	./ft > $(OUT_DIR)ft.txt
	./std > $(OUT_DIR)out.txt
	diff $(OUT_DIR)ft.txt $(OUT_DIR)out.txt

$(OUT_DIR):
	@mkdir -p $(OUT_DIR)

obj:
	@mkdir -p obj/

clean:
	@if [ -e $(OBJ_DIR) ]; then \
		rm -rf $(OBJ_DIR); \
  		printf "%-60b%b" "$(COM_COLOR)Deletion $(OBJ_COLOR)$(OBJ_DIR)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"; \
	else \
  		printf "%-41b%b" "$(COM_COLOR)Deletion $(OBJ_COLOR)$(OBJ_DIR)" "$(ERROR_COLOR)[There is no such directory]$(NO_COLOR)\n"; \
	fi;

fclean: clean
	@if [ -e $(NAME) ]; then \
		rm -f $(FT_NAME); \
		rm -f $(STD_NAME); \
		rm -rf $(OUT_DIR); \
  		printf "%-60b%b" "$(COM_COLOR)Deletion $(OBJ_COLOR)$(NAME)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"; \
	else \
  		printf "%-41b%b" "$(COM_COLOR)Deletion $(OBJ_COLOR)$(NAME)" "$(ERROR_COLOR)[There is no such file]$(NO_COLOR)\n"; \
	fi;

re: fclean all

.PHONY: all clean fclean re