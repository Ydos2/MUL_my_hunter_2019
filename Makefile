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
COMPIL		= gcc *.c -L $(DIRLIB) -lmy -l csfml-graphics -l csfml-system -l csfml-audio -o $(EXEC)
COMPIL_TEST		= gcc *.c -g3 -L $(DIRLIB) $(DIRTEST) --coverage -lcriterion -lmy -o $(EXEC_TEST)
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