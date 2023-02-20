#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS
#include "test_utils.hpp"

RB_TREE base_tree = populate(base_tree);

std::map<char, std::string> base_std_map = populate(base_std_map);
ft::map<char, std::string>  base_ft_map  = populate(base_ft_map);

std::map<char, std::string> empty_std_map;
ft::map<char, std::string>  empty_ft_map;

std::set<char> base_std_set = populate_set(base_std_set);
ft::set<char>  base_ft_set  = populate_set(base_ft_set);

std::set<char> empty_std_set;
ft::set<char>  empty_ft_set;

void print_tree(RB_NODE *node, std::string const &indent, bool last)
{
    if (!node || !KOV<TYPE>()(node->value))
        return;
    std::cout << indent;
    std::cout << (last ? "R└─────" : "L├─────");
    std::string scolor = node->color ? BOLDRED "RED" RESET : BOLDBLACK "BLACK" RESET;
    std::cout << CYAN "[" << KOV<TYPE>()(node->value) << "]" RESET << '=';
    std::cout << GREEN "'" << VOV<TYPE>()(node->value) << "'" RESET;
    std::cout << "(" << scolor << ")" << std::endl;
    print_tree(node->left, (indent + (last ? "      " : " │     ")), false);
    print_tree(node->right, (indent + (last ? "      " : " │     ")), true);
}

void print_tree(RB_NODE *node) { print_tree(node, "", true); }
