#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS
#include "test_utils.hpp"

/*
 * Commented tests work fine but will most likely get Killed in workspaces
 * due to the virtual machine's limited memory.
 *
 * Feel free to uncomment it if you're running on your local machine or
 * an environment with more memory available.
 */

void build_lorenipsum_tree(RB_TREE &tree)
{
    tree.insert_node(TYPE("L", 'L'));
    tree.insert_node(TYPE("O", 'O'));
    tree.insert_node(TYPE("R", 'R'));
    tree.insert_node(TYPE("E", 'E'));
    tree.insert_node(TYPE("N", 'N'));
    tree.insert_node(TYPE("I", 'I'));
    tree.insert_node(TYPE("P", 'P'));
    tree.insert_node(TYPE("S", 'S'));
    tree.insert_node(TYPE("U", 'U'));
    tree.insert_node(TYPE("M", 'M'));
}

void print_tree(RB_NODE *node, std::string const &indent, bool last)
{
    if (!node || KOV<TYPE>()(node->value) == PRINT_EMPTY)
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
