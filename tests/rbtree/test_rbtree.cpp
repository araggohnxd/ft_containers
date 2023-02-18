/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rbtree.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:30:00 by maolivei          #+#    #+#             */
/*   Updated: 2023/02/16 20:35:43 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.hpp"

TEST_CASE("test rb_tree empty tree has it's root equal to NIL")
{
    RB_TREE tree;

    CHECK(tree.root() == tree.nil());
}

TEST_CASE("test rb_tree with only one node has all of it's members equal to NIL")
{
    RB_TREE  tree;
    RB_NODE *root, *nil;

    tree.insert(TYPE("x", 42));
    root = tree.root();
    nil  = tree.nil();
    CHECK(root->parent == nil);
    CHECK(root->right == nil);
    CHECK(root->left == nil);
    CHECK(root->nil == nil);
}

TEST_CASE("test rb_tree initialized with values 'lorenipsum' has size of 10 and increase properly")
{
    RB_TREE tree;

    build_lorenipsum_tree(tree);
    CHECK(tree.size() == 10);
    tree.insert(TYPE("X", 'X'));
    CHECK(tree.size() == 11);
}

TEST_CASE("test rb_tree initialized with values 'lorenipsum' has node 'R' with proper values")
{
    RB_TREE  tree;
    RB_NODE *node;

    build_lorenipsum_tree(tree);
    node = tree.find("R");
    CHECK((VOV<TYPE>()(node->value)) == 'R');
    CHECK(node->parent == tree.find("O"));
    CHECK(node->parent == tree.root()); // node "O" happens to be tree's root
    CHECK(node->right == tree.find("S"));
    CHECK(node->left == tree.find("P"));
    CHECK(node->nil == tree.nil());
    CHECK(node->color == ft::red);
}

TEST_CASE("test rb_tree initialized with values 'lorenipsum' has node 'N' with proper values")
{
    RB_TREE  tree;
    RB_NODE *node;

    build_lorenipsum_tree(tree);
    node = tree.find("N");
    CHECK((VOV<TYPE>()(node->value)) == 'N');
    CHECK(node->parent == tree.find("L"));
    CHECK(node->right == tree.nil());
    CHECK(node->left == tree.find("M"));
    CHECK(node->nil == tree.nil());
    CHECK(node->color == ft::black);
}

TEST_CASE("test rb_tree with values 'lorenipsum' deletes node 'R' has nodes with proper values")
{
    RB_TREE  tree;
    RB_NODE *s, *p, *u, *root, *nil;

    build_lorenipsum_tree(tree);
    tree.erase("R");
    root = tree.root();
    nil  = tree.nil();
    s    = tree.find("S");
    p    = tree.find("P");
    u    = tree.find("U");

    CHECK(s->parent == root);
    CHECK(s->right == u);
    CHECK(s->left == p);

    CHECK(p->parent == s);
    CHECK(p->right == nil);
    CHECK(p->left == nil);

    CHECK(u->parent == s);
    CHECK(u->right == nil);
    CHECK(u->left == nil);
}

TEST_CASE("test rb_tree with values 'lorenipsum' deletes node 'M' has nodes with proper values")
{
    RB_TREE  tree;
    RB_NODE *l, *n, *e, *root, *nil;

    build_lorenipsum_tree(tree);
    tree.erase("M");
    root = tree.root();
    nil  = tree.nil();
    l    = tree.find("L");
    n    = tree.find("N");
    e    = tree.find("E");

    CHECK(l->parent == root);
    CHECK(l->right == n);
    CHECK(l->left == e);

    CHECK(n->parent == l);
    CHECK(n->right == nil);
    CHECK(n->left == nil);

    CHECK(e->parent == l);
    CHECK(e->right == tree.find("I"));
    CHECK(e->left == nil);
}

TEST_CASE("test rb_tree with values 'lorenipsum' deletes node and has proper size")
{
    RB_TREE tree;

    build_lorenipsum_tree(tree);
    tree.erase("R");
    CHECK(tree.size() == 9);
    tree.erase("M");
    CHECK(tree.size() == 8);
}

TEST_CASE("test rb_tree copy constructor with values 'lorenipsum'")
{
    RB_TREE ft;

    build_lorenipsum_tree(ft);

    RB_TREE cp(ft);

    compare_rbtrees(ft, cp);
}

TEST_CASE("test rb_tree assign operator with values 'lorenipsum'")
{
    RB_TREE ft, cp;

    build_lorenipsum_tree(ft);

    cp = ft;

    compare_rbtrees(ft, cp);
}
