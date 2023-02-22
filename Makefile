NAME				:= ft_containers_tests

SOURCE_DIRS			:= . algorithm iterator type_traits utility rbtree
SOURCE_PATH			:= $(addprefix ./sources/, $(SOURCE_DIRS))
SOURCE_FILES		:= enable_if.hpp integral_constant.hpp is_integral.hpp
SOURCE_FILES		+= iterator_traits.hpp iterator_base.hpp iterator_functions.hpp
SOURCE_FILES		+= iterator.hpp reverse_iterator.hpp reverse_iterator.tpp
SOURCE_FILES		+= random_access_iterator.hpp random_access_iterator.tpp
SOURCE_FILES		+= lexicographical_compare.hpp equal.hpp algorithm.hpp
SOURCE_FILES		+= type_traits.hpp utility.hpp pair.hpp pair.tpp
SOURCE_FILES		+= rb_tree.hpp rb_tree.tpp rb_tree_node.hpp rb_tree_node.tpp
SOURCE_FILES		+= rb_tree_iterator.hpp rb_tree_iterator.tpp vector.hpp vector.tpp
SOURCE_FILES		+= stack.hpp stack.tpp map.hpp map.tpp set.hpp set.tpp

TEST_DIRS			:= . vector stack rbtree map set performance
TEST_PATH			:= $(addprefix ./tests/, $(TEST_DIRS))
TEST_HEADER			:= doctest.h test_utils.hpp
TEST_FILES			:= doctest_main.cpp

TEST_VECTOR_FILES	:= test_vector_constructors.cpp test_vector_iterators.cpp
TEST_VECTOR_FILES	+= test_vector_capacity.cpp test_vector_element_access.cpp
TEST_VECTOR_FILES	+= test_vector_modifiers.cpp test_vector_non_member.cpp

TEST_STACK_FILES	:= test_stack_constructor.cpp test_stack_element_access.cpp
TEST_STACK_FILES	+= test_stack_modifiers.cpp test_stack_non_member.cpp

TEST_RBTREE_FILES	:= test_rbtree.cpp test_rbtree_node.cpp test_rbtree_iterators.cpp

TEST_MAP_FILES		:= test_map_capacity.cpp test_map_element_access.cpp
TEST_MAP_FILES		+= test_map_constructors.cpp test_map_iterators.cpp
TEST_MAP_FILES		+= test_map_lookup.cpp test_map_modifiers.cpp
TEST_MAP_FILES		+= test_map_non_member.cpp

TEST_SET_FILES		:= test_set_capacity.cpp test_set_non_member.cpp
TEST_SET_FILES		+= test_set_constructors.cpp test_set_iterators.cpp
TEST_SET_FILES		+= test_set_lookup.cpp test_set_modifiers.cpp

ALL_TEST_FILES		:= $(TEST_VECTOR_FILES)
ALL_TEST_FILES		+= $(TEST_STACK_FILES)
ALL_TEST_FILES		+= $(TEST_RBTREE_FILES)
ALL_TEST_FILES		+= $(TEST_MAP_FILES)
ALL_TEST_FILES		+= $(TEST_SET_FILES)

TEST_PERFORMANCE	:= test_vector_performance.cpp test_stack_performance.cpp
TEST_PERFORMANCE	+= test_map_performance.cpp

ifdef VECTOR
	TEST_FILES += $(TEST_VECTOR_FILES)
else ifdef STACK
	TEST_FILES += $(TEST_STACK_FILES)
else ifdef RBTREE
	TEST_FILES += $(TEST_RBTREE_FILES)
else ifdef MAP
	TEST_FILES += $(TEST_MAP_FILES)
else ifdef SET
	TEST_FILES += $(TEST_SET_FILES)
else ifdef PERFORMANCE
	TEST_FILES += $(TEST_PERFORMANCE)
else
	TEST_FILES += $(ALL_TEST_FILES)
endif

OBJECT_PATH			:= ./objects
OBJECT_FILES		:= $(TEST_FILES:%.cpp=$(OBJECT_PATH)/%.o)

CC					:= c++
CFLAGS				:= -Wall -Wextra -Werror -std=c++98
IFLAGS				:= $(addprefix -I, $(SOURCE_PATH))
IFLAGS				+= $(addprefix -I, ./tests)
REMOVE				:= rm -rf

ifdef DEBUG
	CFLAGS += -g3
endif

ifdef STL
	CFLAGS += -D STL=1
endif

VPATH				:= $(SOURCE_PATH) $(TEST_PATH)

all:				$(NAME)

$(NAME):			$(OBJECT_FILES) | $(OBJECT_PATH)
					$(CC) $(CFLAGS) -o $@ $(OBJECT_FILES)

$(OBJECT_PATH)/%.o:	%.cpp $(SOURCE_FILES) $(TEST_HEADER) Makefile | $(OBJECT_PATH)
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

vgtest:				CFLAGS += -D ITERATIONS=1000
vgtest:				re
					valgrind ./$(NAME) -nt

performance:
					@make -s re PERFORMANCE=1
					@./ft_containers_tests
					@echo
					@make -s re PERFORMANCE=1 STL=1
					@./ft_containers_tests

.PHONY:				all clean fclean re test vgtest performance
