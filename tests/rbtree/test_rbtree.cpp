/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rbtree.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:30:00 by maolivei          #+#    #+#             */
/*   Updated: 2023/02/11 21:58:24 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.hpp"

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

    tree.insert(ft::pair<KEY, VALUE>("x", 42));
    root = tree.get_root();
    nil  = tree.get_nil();
    CHECK(root->parent == nil);
    CHECK(root->right == nil);
    CHECK(root->left == nil);
    CHECK(root->nil == nil);
    // TODO: check if this should be true and if node's root is even necessary
    CHECK(root->root == nil);
}

TEST_CASE("test rb_tree every item including nil has the same root")
{
    RB_TREE  tree;
    RB_NODE *root;
    RB_NODE *nil;

    tree.insert(ft::pair<KEY, VALUE>("M", 77));
    tree.insert(ft::pair<KEY, VALUE>("A", 65));
    tree.insert(ft::pair<KEY, VALUE>("T", 84));
    tree.insert(ft::pair<KEY, VALUE>("H", 72));
    tree.insert(ft::pair<KEY, VALUE>("E", 69));
    tree.insert(ft::pair<KEY, VALUE>("U", 85));
    tree.insert(ft::pair<KEY, VALUE>("S", 83));

    root = tree.get_root();
    nil  = tree.get_nil();
    CHECK(nil->root == root);
    // TODO: SEARCH function to be able to complete this test
    // CHECK(tree.search("M").root == root);
    // CHECK(tree.search("A").root == root);
    // CHECK(tree.search("T").root == root);
    // CHECK(tree.search("H").root == root);
    // CHECK(tree.search("E").root == root);
    // CHECK(tree.search("U").root == root);
    // CHECK(tree.search("S").root == root);
}
