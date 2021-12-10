##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## make files
##

SRC		=	sources/ll_insert/ll_append.c		\
			sources/ll_insert/ll_insert_data.c	\
			sources/ll_insert/ll_insert_list.c	\
			sources/ll_insert/ll_insert_node.c	\
			sources/ll_insert/ll_push_front.c	\
			sources/ll_create_node.c			\
			sources/ll_filter.c					\
			sources/ll_free_list.c				\
			sources/ll_create_list.c			\
			sources/ll_free_node.c				\
			sources/ll_from_array.c				\
			sources/ll_get_len.c				\
			sources/ll_has_node.c				\
			sources/ll_integrity.c				\
			sources/ll_is_empty.c				\
			sources/ll_map.c					\
			sources/ll_move_node.c				\
			sources/ll_node_index.c				\
			sources/ll_one_node.c				\
			sources/ll_print_data.c				\
			sources/ll_remove_node.c			\
			sources/ll_revert.c					\
			sources/ll_sort.c					\
			sources/ll_to_array.c	

TESTS_FILES	=	tests/test_add_list.c 				\
				tests/test_add_node.c 				\
				tests/test_create_node.c			\
				tests/test_filter.c					\
				tests/test_free_list.c				\
				tests/test_free_node.c				\
				tests/test_free_node_and_data.c		\
				tests/test_from_array.c				\
				tests/test_has_node.c				\
				tests/test_index.c					\
				tests/test_integrity.c				\
				tests/test_len.c					\
				tests/test_map.c					\
				tests/test_move_node.c				\
				tests/test_one_node.c				\
				tests/test_print_data.c				\
				tests/test_remove_node.c 			\
				tests/test_revert.c					\
				tests/test_sort.c					\
				tests/test_to_array.c				\

CFLAGS 	= 	-Wall -Werror -Wshadow -Wextra -I./include/

CC		=	gcc

OBJ		=	$(SRC:.c=.o)

NAME	=	liblinked_list.a

all		:	$(NAME)

$(NAME): $(OBJ)
		@ ar rc $(NAME) $(OBJ)

clean	:
			@ rm -f $(OBJ)

clean_tests:
			@ rm -f unit_tests
			@ rm -f *.gcno
			@ rm -f *.gcda

fclean	:	clean clean_tests
			@ rm -f $(NAME)
			@ rm -f *.gcda
			@ rm -f *.gcno
			@ rm -f unit_tests



tests_compile: CFLAGS += --coverage
tests_compile: LDFLAGS += -lcriterion
tests_compile: clean_tests
			@ $(CC) -o unit_tests $(SRC) $(TESTS_FILES) $(CFLAGS) $(LDFLAGS)

tests_run:	tests_compile
			@ ./unit_tests
			@ $(MAKE) coverage

coverage:
			@ gcovr --exclude tests/

re		:	fclean all

.PHONY	:	fclean clean re all tests_compile tests_run coverage
