##
## EPITECH PROJECT, 2019
## LIB
## File description:
## Makefile
##

NAMELIB		= libmy.a
LIBCREATE		= ar rc $(NAMELIB) *.o
LIBCOMPILE		= gcc -c *.c

all	: libc deplacerlib clean

libc:
		$(LIBCOMPILE); $(LIBCREATE)

deplacerlib:
		mv $(NAMELIB) ./../

clean:
		rm -f *.o