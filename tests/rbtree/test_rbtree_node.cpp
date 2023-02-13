/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rbtree_node.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:30:00 by maolivei          #+#    #+#             */
/*   Updated: 2023/02/13 11:44:00 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.hpp"

static ft::rb_tree_node<int> root(0, NULL, NULL);
static ft::rb_tree_node<int> node1(1, &root, NULL);
static ft::rb_tree_node<int> node2(2, &node1, &node1);

TEST_CASE("test rb node root")
{
    CHECK(root.value == 0);
    CHECK(!root.parent);
    CHECK(!root.left);
    CHECK(!root.right);
    CHECK(!root.nil);
    CHECK(root.color == ft::black);
}

TEST_CASE("test rb node node1")
{
    CHECK(node1.value == 1);
    CHECK(!node1.parent);
    CHECK(!node1.left);
    CHECK(!node1.right);
    CHECK(!node1.nil);
    CHECK(node1.color == ft::black);
}

TEST_CASE("test rb node node2")
{
    CHECK(node2.value == 2);
    CHECK(!node2.parent);
    CHECK(!node2.left);
    CHECK(!node2.right);
    CHECK(node2.nil == &node1);
    CHECK(node2.color == ft::black);
}
