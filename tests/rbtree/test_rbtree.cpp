/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rbtree.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:30:00 by maolivei          #+#    #+#             */
/*   Updated: 2023/02/13 11:44:37 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.hpp"

void build_lorenipsum_tree(RB_TREE &tree)
{
    tree.insert(TYPE("L", 76));
    tree.insert(TYPE("O", 79));
    tree.insert(TYPE("R", 82));
    tree.insert(TYPE("E", 69));
    tree.insert(TYPE("N", 78));
    tree.insert(TYPE("I", 73));
    tree.insert(TYPE("P", 80));
    tree.insert(TYPE("S", 83));
    tree.insert(TYPE("U", 85));
    tree.insert(TYPE("M", 77));
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

TEST_CASE("test rb_tree empty tree has it's root equal to NIL")
{
    RB_TREE tree;

    CHECK(tree.get_root() == tree.get_nil());
}

TEST_CASE("test rb_tree with only one node has all of it's members equal to NIL")
{
    RB_TREE  tree;
    RB_NODE *root, *nil;

    tree.insert(TYPE("x", 42));
    root = tree.get_root();
    nil  = tree.get_nil();
    CHECK(root->parent == nil);
    CHECK(root->right == nil);
    CHECK(root->left == nil);
    CHECK(root->nil == nil);
}
