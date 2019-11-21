##
## EPITECH PROJECT, 2019
## COMPILATION
## File description:
## Makefile
##

NAMELIB		= libmy.a
DIRLIB		=./lib/
DIRLIBMY		=./lib/my/
DIRTEST		=./tests/*.c

SRC		=	duck_anim_1.c		\
			duck_draw_1.c		\
			duck_draw_2.c		\
			duck_event.c		\
			duck_main.c			\
			duck_script.c		\
			duck_sound.c		\
			duck_tools_1.c		\
			duck_ui.c			\
			ui_menu.c			\
			duck_script_ai.c	\
			main_extend.c

SRC_TESTS	=	criterion.c

COMPIL		= gcc $(SRC) -L $(DIRLIB) -lmy -l csfml-graphics -l csfml-system -l csfml-audio -o $(EXEC)
COMPIL_DEBUG		= gcc $(SRC) -L $(DIRLIB) -lmy -l csfml-graphics -l csfml-system -l csfml-audio -o $(EXEC) -g3
COMPIL_TEST		= gcc $(SRC) -g3 -L $(DIRLIB) $(DIRTEST) --coverage -lcriterion -lmy -l csfml-graphics -l csfml-system -l csfml-audio -o $(EXEC_TEST)
EXEC		= my_hunter
EXEC_TEST		= tests_my_hunter
RUN_TESTS	=	./$(EXEC_TEST)

COVERAGE	=	gcovr --exclude tests/
COVERAGE_BRANCH		=	gcovr --exclude tests/ -b

all	: make compilation clean

make:
		cd $(DIRLIBMY) && make

compilation:
		$(COMPIL)

compilation_test:
		$(COMPIL_TEST)

compilation_debug:
		$(COMPIL_DEBUG)

run_test:
		$(RUN_TESTS)
		$(COVERAGE)
		$(COVERAGE_BRANCH)

clean:
		rm -f *.o

test_clean:
		rm -f *.gcda rm -f *.gcno

fclean: clean test_clean
		rm -f $(EXEC) $(EXEC_TEST) $(DIRLIB)$(NAMELIB)

re: fclean all

tests_run: make compilation compilation_test run_test clean test_clean

debug: make compilation compilation_debug clean clean