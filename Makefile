##
## EPITECH PROJECT, 2022
## makefile_gen_epitech
## File description:
## Makefile
##

NAME_BINARY 	=	game

SRC = $(shell find ./src/ -name "*.cpp")

CSFML_FLAG	=	-lsfml-graphics	\
	     		-lsfml-network 	\
				-lsfml-system 		\
				-lsfml-window		\
				-lsfml-audio

OBJ	=	$(SRC:.c=.o) \
		$(shell find . -name '*.gcda' -exec rm -rf {} \;)	\
		$(shell find . -name '*.gcno' -exec rm -rf {} \;)	\
		$(shell find . -name '*.gcov' -exec rm -rf {} \;)

LIB	=	$(CSFML_FLAG)

INCLUDE	=	-I include/ -I include_struct/

WARNING	=	-W \
			-Wall \
			-Wextra \
			-Werror \
			-Wwrite-strings

COMPILATOR	=	g++

COMPILATOR_DEBUG	=	g++ -g

start:
	@echo compiling lib
	@echo
	@echo "succes"
	@echo
	@make all -s

all: $(OBJ)
	echo
	echo all file compiled ready
	echo
	echo
	echo "\033[5m\033[1;92m\033[40m\e[48;2;0;0;0m\
	 __        __                              ___  ___         ___\033[0m"
	echo "\033[5m\033[1;92m\033[40m\e[48;2;0;0;0m\
	|__) |  | |__) |  |        |\/|  /\  |__/ |__  |__  | |    |__ \033[0m"
	echo "\033[5m\033[1;92m\033[40m\e[48;2;0;0;0m\
	|  \ \__/ |  \ \__/        |  | /~~\ |  \ |___ |    | |___ |___\033[0m"
	echo
	echo
	echo remove writing, use make all for watch
	$(COMPILATOR) $^ -o $(NAME_BINARY) $(LIB) $(INCLUDE)

debug: $(OBJ)
	@echo
	@echo all file compiled ready
	@echo
	@echo
	@echo "\033[5m\033[1;92m\033[40m\e[48;2;0;0;0m\
	 __        __                              ___  ___         ___\
	        __   ___  __        __ \033[0m"
	@echo "\033[5m\033[1;92m\033[40m\e[48;2;0;0;0m\
	|__) |  | |__) |  |        |\/|  /\  |__/ |__  |__  | |    |__ \
	       |  \ |__  |__) |  | / _ \033[0m"
	@echo "\033[5m\033[1;92m\033[40m\e[48;2;0;0;0m\
	|  \ \__/ |  \ \__/        |  | /~~\ |  \ |___ |    | |___ |___\
	       |__/ |___ |__) \__/ \__>\033[0m"
	@echo
	@echo
	@echo remove writing, use make all for watch
	$(COMPILATOR_DEBUG) $^ -o $(NAME_BINARY) $(LIB) $(INCLUDE)

.cpp.o:
	@echo compile $(notdir $(basename $^)) in $^
	@g++ -g -c -o $(basename $^).o $< $(LIB) $(INCLUDE)

re:
	@make clean -s
	@make
	@echo
	@echo all file compiled ready
	@echo
	@echo
	@echo
	@echo

run: debug
	@echo
	@echo execute binary without args ...
	@echo
	@./$(NAME_BINARY)
	@echo
	@echo coverage :
	@echo $(shell gcov object/*)
	@echo
	@echo

clean:
	@rm -f $(OBJS)
	@rm -f $(NAME_BINARY)
	@find -name '*.o' -exec rm -rf {} \;
	@find . -name '*.gcda' -exec rm -rf {} \;
	@find . -name '*.gcno' -exec rm -rf {} \;
	@find . -name '*.gcov' -exec rm -rf {} \;

fclean:
	@rm -f $(OBJS)
	@rm -f $(NAME_BINARY)
	@find -name '*.o' -exec rm -rf {} \;
	@find -name '*.gcda' -exec rm -rf {} \;
	@find -name '*.gcno' -exec rm -rf {} \;
	@find -name '*.gcov' -exec rm -rf {} \;
