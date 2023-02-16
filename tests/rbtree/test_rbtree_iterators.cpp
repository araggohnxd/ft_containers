/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rbtree_iterators.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:32:00 by maolivei          #+#    #+#             */
/*   Updated: 2023/02/15 21:18:19 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.hpp"

TEST_CASE("test rb_tree iterator begin() in 'lorenipsum' tree has the right begin value")
{
    RB_TREE tree;

    build_lorenipsum_tree(tree);
    CHECK(tree.begin()->first == "E");
    CHECK(tree.begin()->second == 'E');
}

TEST_CASE("test rb_tree iterator end() in 'lorenipsum' tree has the right end value")
{
    RB_TREE tree;

    build_lorenipsum_tree(tree);
    CHECK(tree.end().base() == tree.nil());
}

TEST_CASE("test rb_tree iterator returns the correct values in sorted order")
{
    char const *sorted_keys[]   = {"E", "I", "L", "M", "N", "O", "P", "R", "S", "U"};
    char const  sorted_values[] = "EILMNOPRSU";

    RB_TREE           tree;
    RB_TREE::iterator it;

    build_lorenipsum_tree(tree);
    it = tree.begin();
    for (size_t i = 0; i < tree.size(); ++i) {
        CHECK(it->first == sorted_keys[i]);
        CHECK(it->second == sorted_values[i]);
        ++it;
    }
}

TEST_CASE("test rb_tree const iterator returns the correct values in sorted order")
{
    char const *sorted_keys[]   = {"E", "I", "L", "M", "N", "O", "P", "R", "S", "U"};
    char const  sorted_values[] = "EILMNOPRSU";

    RB_TREE                 tree;
    RB_TREE::const_iterator it;

    build_lorenipsum_tree(tree);
    it = tree.begin();
    for (size_t i = 0; i < tree.size(); ++i) {
        CHECK(it->first == sorted_keys[i]);
        CHECK(it->second == sorted_values[i]);
        ++it;
    }
}

TEST_CASE("test rb_tree reverse iterator rbegin() in 'lorenipsum' tree has the right rbegin value")
{
    RB_TREE tree;

    build_lorenipsum_tree(tree);
    CHECK(tree.rbegin()->first == "U");
    CHECK(tree.rbegin()->second == 'U');
}

TEST_CASE("test rb_tree reverse iterator rend() in 'lorenipsum' tree has the right rend value")
{
    RB_TREE tree;

    build_lorenipsum_tree(tree);
    CHECK(tree.rend().base()->first == "E");
    CHECK(tree.rend().base()->second == 'E');
}

TEST_CASE("test rb_tree reverse iterator returns the correct values in sorted order")
{
    char const *reverse_sorted_keys[]   = {"U", "S", "R", "P", "O", "N", "M", "L", "I", "E"};
    char const  reverse_sorted_values[] = "USRPONMLIE";

    RB_TREE                   tree;
    RB_TREE::reverse_iterator it;

    build_lorenipsum_tree(tree);
    it = tree.rbegin();
    for (size_t i = 0; i < tree.size(); ++i) {
        CHECK(it->first == reverse_sorted_keys[i]);
        CHECK(it->second == reverse_sorted_values[i]);
        ++it;
    }
}

TEST_CASE("test rb_tree const reverse iterator returns the correct values in sorted order")
{
    char const *reverse_sorted_keys[]   = {"U", "S", "R", "P", "O", "N", "M", "L", "I", "E"};
    char const  reverse_sorted_values[] = "USRPONMLIE";

    RB_TREE                         tree;
    RB_TREE::const_reverse_iterator it;

    build_lorenipsum_tree(tree);
    it = tree.rbegin();
    for (size_t i = 0; i < tree.size(); ++i) {
        CHECK(it->first == reverse_sorted_keys[i]);
        CHECK(it->second == reverse_sorted_values[i]);
        ++it;
    }
}

TEST_CASE("test rb_tree iterator pointing to nil returns maximum when inc/decremented")
{
    RB_TREE           tree;
    RB_TREE::iterator it;

    build_lorenipsum_tree(tree);

    it = tree.end();
    ++it;
    CHECK(it->first == "U");
    CHECK(it->second == 'U');

    it = tree.end();
    it++;
    CHECK(it->first == "U");
    CHECK(it->second == 'U');

    it = tree.end();
    --it;
    CHECK(it->first == "U");
    CHECK(it->second == 'U');

    it = tree.end();
    it--;
    CHECK(it->first == "U");
    CHECK(it->second == 'U');
}

TEST_CASE("test rb_tree const iterator pointing to nil returns maximum when inc/decremented")
{
    RB_TREE                 tree;
    RB_TREE::const_iterator it;

    build_lorenipsum_tree(tree);

    it = tree.end();
    ++it;
    CHECK(it->first == "U");
    CHECK(it->second == 'U');

    it = tree.end();
    it++;
    CHECK(it->first == "U");
    CHECK(it->second == 'U');

    it = tree.end();
    --it;
    CHECK(it->first == "U");
    CHECK(it->second == 'U');

    it = tree.end();
    it--;
    CHECK(it->first == "U");
    CHECK(it->second == 'U');
}

TEST_CASE("test rb_tree reverse iterator pointing to nil returns maximum when incremented")
{
    RB_TREE                   tree;
    RB_TREE::reverse_iterator it;

    build_lorenipsum_tree(tree);

    it = tree.rend();
    ++it;
    CHECK(it->first == "U");
    CHECK(it->second == 'U');

    it = tree.rend();
    it++;
    CHECK(it->first == "U");
    CHECK(it->second == 'U');
}

TEST_CASE("test rb_tree const reverse iterator pointing to nil returns maximum when incremented")
{
    RB_TREE                         tree;
    RB_TREE::const_reverse_iterator it;

    build_lorenipsum_tree(tree);

    it = tree.rend();
    ++it;
    CHECK(it->first == "U");
    CHECK(it->second == 'U');

    it = tree.rend();
    it++;
    CHECK(it->first == "U");
    CHECK(it->second == 'U');
}

TEST_CASE("test rb_tree reverse iterator pointing to nil returns minimum when decremented")
{
    RB_TREE                   tree;
    RB_TREE::reverse_iterator it;

    build_lorenipsum_tree(tree);

    it = tree.rend();
    --it;
    CHECK(it->first == "E");
    CHECK(it->second == 'E');

    it = tree.rend();
    it--;
    CHECK(it->first == "E");
    CHECK(it->second == 'E');
}

TEST_CASE("test rb_tree const reverse iterator pointing to nil returns minimum when decremented")
{
    RB_TREE                         tree;
    RB_TREE::const_reverse_iterator it;

    build_lorenipsum_tree(tree);

    it = tree.rend();
    --it;
    CHECK(it->first == "E");
    CHECK(it->second == 'E');

    it = tree.rend();
    it--;
    CHECK(it->first == "E");
    CHECK(it->second == 'E');
}
