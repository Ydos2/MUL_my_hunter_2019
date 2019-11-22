##
## EPITECH PROJECT, 2019
## LIB
## File description:
## Makefile
##

NAMELIB		= libmy.a
LIBCREATE		= ar rc $(NAMELIB) $(SRC_O)
LIBCOMPILE		= gcc -c $(SRC)

SRC		=	my_atoi.c					\
			my_compute_power_rec.c		\
			my_compute_square_root.c	\
			my_find_prime_sup.c			\
			my_getnbr.c					\
			my_int_to_str.c				\
			my_intlen.c					\
			my_is_prime.c				\
			my_isneg.c					\
			my_itoa.c					\
			my_put_nbr_base.c			\
			my_put_nbr.c				\
			my_putchar.c				\
			my_putstr.c					\
			my_revstr.c					\
			my_showmem.c				\
			my_showstr.c				\
			my_sort_int_array.c			\
			my_str_isalpha.c			\
			my_str_islower.c			\
			my_str_isnum.c				\
			my_str_isprintable.c		\
			my_str_isupper.c			\
			my_str_to_word_array.c		\
			my_strcapitalize.c			\
			my_strcat.c					\
			my_strcmp.c					\
			my_strcpy.c					\
			my_strstr.c					\
			my_strupcase.c				\
			my_swap.c

SRC_O	=	my_atoi.o					\
			my_compute_power_rec.o		\
			my_compute_square_root.o	\
			my_find_prime_sup.o			\
			my_getnbr.o					\
			my_int_to_str.o				\
			my_intlen.o					\
			my_is_prime.o				\
			my_isneg.o					\
			my_itoa.o					\
			my_put_nbr_base.o			\
			my_put_nbr.o				\
			my_putchar.o				\
			my_putstr.o					\
			my_revstr.o					\
			my_showmem.o				\
			my_showstr.o				\
			my_sort_int_array.o			\
			my_str_isalpha.o			\
			my_str_islower.o			\
			my_str_isnum.o				\
			my_str_isprintable.o		\
			my_str_isupper.o			\
			my_str_to_word_array.o		\
			my_strcapitalize.o			\
			my_strcat.o					\
			my_strcmp.o					\
			my_strcpy.o					\
			my_strstr.o					\
			my_strupcase.o				\
			my_swap.o


all	: libc deplacerlib clean

libc:
		$(LIBCOMPILE); $(LIBCREATE)

deplacerlib:
		mv $(NAMELIB) ./../

clean:
		rm -f $(SRC_O)