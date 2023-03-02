/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rbtree.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:30:00 by maolivei          #+#    #+#             */
/*   Updated: 2023/03/02 19:16:24 by maolivei         ###   ########.fr       */
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

    tree.insert(TYPE('X', "X"));
    root = tree.root();
    nil  = tree.nil();
    CHECK(root->parent == nil);
    CHECK(root->right == nil);
    CHECK(root->left == nil);
    CHECK(root->nil == nil);
}

TEST_CASE("test rb_tree initialized with values 'lorenipsum' has size of 10 and increase properly")
{
    RB_TREE tree(base_tree);

    CHECK(tree.size() == 10);
    tree.insert(TYPE('X', "X"));
    CHECK(tree.size() == 11);
}

TEST_CASE("test rb_tree initialized with values 'lorenipsum' has node 'R' with proper values")
{
    RB_NODE *node;

    node = base_tree.find('R').base();
    CHECK((VOV<TYPE>()(node->value)) == "R");
    CHECK(node->parent == base_tree.find('O').base());
    CHECK(node->parent == base_tree.root()); // node 'O' happens to be base_tree's root
    CHECK(node->right == base_tree.find('S').base());
    CHECK(node->left == base_tree.find('P').base());
    CHECK(node->nil == base_tree.nil());
    CHECK(node->color == ft::red);
}

TEST_CASE("test rb_tree initialized with values 'lorenipsum' has node 'N' with proper values")
{
    RB_NODE *node;

    node = base_tree.find('N').base();
    CHECK((VOV<TYPE>()(node->value)) == "N");
    CHECK(node->parent == base_tree.find('L').base());
    CHECK(node->right == base_tree.nil());
    CHECK(node->left == base_tree.find('M').base());
    CHECK(node->nil == base_tree.nil());
    CHECK(node->color == ft::black);
}

TEST_CASE("test rb_tree with values 'lorenipsum' deletes node 'R' has nodes with proper values")
{
    RB_TREE  tree = populate(tree);
    RB_NODE *s, *p, *u, *root, *nil;

    tree.erase('R');
    root = tree.root();
    nil  = tree.nil();
    s    = tree.find('S').base();
    p    = tree.find('P').base();
    u    = tree.find('U').base();

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
    RB_TREE  tree = populate(tree);
    RB_NODE *l, *n, *e, *root, *nil;

    tree.erase('M');
    root = tree.root();
    nil  = tree.nil();
    l    = tree.find('L').base();
    n    = tree.find('N').base();
    e    = tree.find('E').base();

    CHECK(l->parent == root);
    CHECK(l->right == n);
    CHECK(l->left == e);

    CHECK(n->parent == l);
    CHECK(n->right == nil);
    CHECK(n->left == nil);

    CHECK(e->parent == l);
    CHECK(e->right == tree.find('I').base());
    CHECK(e->left == nil);
}

TEST_CASE("test rb_tree with values 'lorenipsum' deletes node and has proper size")
{
    RB_TREE tree(base_tree);

    tree.erase('R');
    CHECK(tree.size() == 9);
    tree.erase('M');
    CHECK(tree.size() == 8);
}

TEST_CASE("test rb_tree copy constructor with values 'lorenipsum'")
{
    RB_TREE cp(base_tree);

    compare_rbtrees(cp, base_tree);
}

TEST_CASE("test rb_tree assign operator with values 'lorenipsum'")
{
    RB_TREE cp;

    cp = base_tree;

    compare_rbtrees(cp, base_tree);
}
