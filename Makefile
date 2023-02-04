NAME				:= ft_containers_tests

SOURCE_DIRS			:= . algorithm iterator type_traits utility
SOURCE_PATH			:= $(addprefix ./sources/, $(SOURCE_DIRS))
SOURCE_FILES		:= enable_if.hpp integral_constant.hpp is_integral.hpp
SOURCE_FILES		+= iterator_traits.hpp iterator_base.hpp iterator_functions.hpp
SOURCE_FILES		+= iterator.hpp reverse_iterator.hpp reverse_iterator.tpp
SOURCE_FILES		+= random_access_iterator.hpp random_access_iterator.tpp
SOURCE_FILES		+= lexicographical_compare.hpp equal.hpp algorithm.hpp
SOURCE_FILES		+= type_traits.hpp utility.hpp pair.hpp pair.tpp
SOURCE_FILES		+= vector.hpp vector.tpp

TEST_DIRS			:= . vector
TEST_PATH			:= $(addprefix ./tests/, $(TEST_DIRS))
TEST_HEADER			:= doctest.h test_utils.hpp
TEST_FILES			:= doctest_main.cpp

TEST_VECTOR_FILES	:= test_vector_constructors.cpp test_vector_iterators.cpp
TEST_VECTOR_FILES	+= test_vector_capacity.cpp test_vector_element_access.cpp
TEST_VECTOR_FILES	+= test_vector_modifiers.cpp

ALL_TEST_FILES		:= $(TEST_VECTOR_FILES)

ifdef VECTOR
	TEST_FILES += $(TEST_VECTOR_FILES)
else
	TEST_FILES += $(ALL_TEST_FILES)
endif

OBJECT_PATH			:= ./objects
OBJECT_FILES		:= $(TEST_FILES:%.cpp=$(OBJECT_PATH)/%.o)

CC					:= c++
CFLAGS				:= -Wall -Wextra -Werror -std=c++98 -g3
IFLAGS				:= $(addprefix -I, $(SOURCE_PATH))
IFLAGS				+= $(addprefix -I, $(TEST_PATH))
REMOVE				:= rm -rf

VPATH				:= $(SOURCE_PATH) $(TEST_PATH)

all:				$(NAME)

$(NAME):			$(OBJECT_FILES) | $(OBJECT_PATH)
					$(CC) $(CFLAGS) -o $@ $(OBJECT_FILES)

$(OBJECT_PATH)/%.o:	%.cpp $(SOURCE_FILES) $(TEST_FILES) Makefile | $(OBJECT_PATH)
					$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJECT_PATH):
					mkdir -p $@

clean:
					$(REMOVE) $(OBJECT_PATH)

fclean:				clean
					$(REMOVE) $(NAME)

re:					fclean all

test:				re
					./$(NAME)

vgtest:				re
					valgrind ./$(NAME) -nt


.PHONY:				all clean fclean re test
