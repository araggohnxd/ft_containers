/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rbtree_iterators.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:32:00 by maolivei          #+#    #+#             */
/*   Updated: 2023/02/18 19:09:54 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.hpp"

TEST_CASE("test rb_tree iterator begin() in 'lorenipsum' tree has the right begin value")
{
    CHECK(base_tree.begin()->first == 'E');
    CHECK(base_tree.begin()->second == "E");
}

TEST_CASE("test rb_tree iterator end() in 'lorenipsum' tree has the right end value")
{
    CHECK(base_tree.end().base() == base_tree.nil());
}

TEST_CASE("test rb_tree iterator returns the correct values in sorted order")
{
    char const  sorted_keys[] = "EILMNOPRSU";
    char const *sorted_values[]   = {"E", "I", "L", "M", "N", "O", "P", "R", "S", "U"};

    RB_TREE::iterator it;

    it = base_tree.begin();
    for (size_t i = 0; i < base_tree.size(); ++i) {
        CHECK(it->first == sorted_keys[i]);
        CHECK(it->second == sorted_values[i]);
        ++it;
    }
}

TEST_CASE("test rb_tree const iterator returns the correct values in sorted order")
{
    char const  sorted_keys[] = "EILMNOPRSU";
    char const *sorted_values[]   = {"E", "I", "L", "M", "N", "O", "P", "R", "S", "U"};

    RB_TREE::const_iterator it;

    it = base_tree.begin();
    for (size_t i = 0; i < base_tree.size(); ++i) {
        CHECK(it->first == sorted_keys[i]);
        CHECK(it->second == sorted_values[i]);
        ++it;
    }
}

TEST_CASE("test rb_tree reverse iterator rbegin() in 'lorenipsum' tree has the right rbegin value")
{
    CHECK(base_tree.rbegin()->first == 'U');
    CHECK(base_tree.rbegin()->second == "U");
}

TEST_CASE("test rb_tree reverse iterator rend() in 'lorenipsum' tree has the right rend value")
{
    CHECK(base_tree.rend().base()->first == 'E');
    CHECK(base_tree.rend().base()->second == "E");
}

TEST_CASE("test rb_tree reverse iterator returns the correct values in sorted order")
{
    char const  reverse_sorted_keys[] = "USRPONMLIE";
    char const *reverse_sorted_values[]   = {"U", "S", "R", "P", "O", "N", "M", "L", "I", "E"};

    RB_TREE::reverse_iterator it;

    it = base_tree.rbegin();
    for (size_t i = 0; i < base_tree.size(); ++i) {
        CHECK(it->first == reverse_sorted_keys[i]);
        CHECK(it->second == reverse_sorted_values[i]);
        ++it;
    }
}

TEST_CASE("test rb_tree const reverse iterator returns the correct values in sorted order")
{
    char const  reverse_sorted_keys[] = "USRPONMLIE";
    char const *reverse_sorted_values[]   = {"U", "S", "R", "P", "O", "N", "M", "L", "I", "E"};

    RB_TREE::const_reverse_iterator it;

    it = base_tree.rbegin();
    for (size_t i = 0; i < base_tree.size(); ++i) {
        CHECK(it->first == reverse_sorted_keys[i]);
        CHECK(it->second == reverse_sorted_values[i]);
        ++it;
    }
}

TEST_CASE("test rb_tree iterator pointing to nil returns maximum when inc/decremented")
{
    RB_TREE::iterator it;

    it = base_tree.end();
    ++it;
    CHECK(it->first == 'U');
    CHECK(it->second == "U");

    it = base_tree.end();
    it++;
    CHECK(it->first == 'U');
    CHECK(it->second == "U");

    it = base_tree.end();
    --it;
    CHECK(it->first == 'U');
    CHECK(it->second == "U");

    it = base_tree.end();
    it--;
    CHECK(it->first == 'U');
    CHECK(it->second == "U");
}

TEST_CASE("test rb_tree const iterator pointing to nil returns maximum when inc/decremented")
{
    RB_TREE::const_iterator it;

    it = base_tree.end();
    ++it;
    CHECK(it->first == 'U');
    CHECK(it->second == "U");

    it = base_tree.end();
    it++;
    CHECK(it->first == 'U');
    CHECK(it->second == "U");

    it = base_tree.end();
    --it;
    CHECK(it->first == 'U');
    CHECK(it->second == "U");

    it = base_tree.end();
    it--;
    CHECK(it->first == 'U');
    CHECK(it->second == "U");
}

TEST_CASE("test rb_tree reverse iterator pointing to nil returns maximum when incremented")
{
    RB_TREE::reverse_iterator it;

    it = base_tree.rend();
    ++it;
    CHECK(it->first == 'U');
    CHECK(it->second == "U");

    it = base_tree.rend();
    it++;
    CHECK(it->first == 'U');
    CHECK(it->second == "U");
}

TEST_CASE("test rb_tree const reverse iterator pointing to nil returns maximum when incremented")
{
    RB_TREE::const_reverse_iterator it;

    it = base_tree.rend();
    ++it;
    CHECK(it->first == 'U');
    CHECK(it->second == "U");

    it = base_tree.rend();
    it++;
    CHECK(it->first == 'U');
    CHECK(it->second == "U");
}

TEST_CASE("test rb_tree reverse iterator pointing to nil returns minimum when decremented")
{
    RB_TREE::reverse_iterator it;

    it = base_tree.rend();
    --it;
    CHECK(it->first == 'E');
    CHECK(it->second == "E");

    it = base_tree.rend();
    it--;
    CHECK(it->first == 'E');
    CHECK(it->second == "E");
}

TEST_CASE("test rb_tree const reverse iterator pointing to nil returns minimum when decremented")
{
    RB_TREE::const_reverse_iterator it;

    it = base_tree.rend();
    --it;
    CHECK(it->first == 'E');
    CHECK(it->second == "E");

    it = base_tree.rend();
    it--;
    CHECK(it->first == 'E');
    CHECK(it->second == "E");
}
