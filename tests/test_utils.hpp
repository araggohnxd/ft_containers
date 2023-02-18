/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:25:03 by maolivei          #+#    #+#             */
/*   Updated: 2023/02/17 22:57:22 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_UTILS_HPP
#define TEST_UTILS_HPP

#include "doctest.h"
#include "map.hpp"
#include "rb_tree.hpp"
#include "utility.hpp"
#include "vector.hpp"
#include <iostream>
#include <map>
#include <string>
#include <vector>

#define RESET     "\033[0m"
#define GREEN     "\033[0m\033[32m"
#define CYAN      "\033[0m\033[36m"
#define BOLDRED   "\033[1m\033[31m"
#define BOLDBLACK "\033[1m\033[30m"
#define YELLOW    "\033[1m\033[33m"

#define KEY         std::string
#define VALUE       int
#define TYPE        ft::pair<KEY, VALUE>
#define COMPARE     std::less<KEY>
#define NEWLINE     std::cout << "\n";
#define PRINT_EMPTY ""
#define KOV         _KeyOfValue
#define VOV         _ValueOfValue
#define RB_TREE     ft::rb_tree<KEY, TYPE, KOV<TYPE>, COMPARE>
#define RB_NODE     ft::rb_tree_node<TYPE>

template <typename T>
struct _KeyOfValue {
        KEY operator()(T const &x) const { return (x.first); }
};

template <typename T>
struct _ValueOfValue {
        VALUE operator()(T const &x) const { return (x.second); }
};

template <typename Pair>
struct Select1st {
        typename Pair::first_type       &operator()(Pair &x) const { return (x.first); }
        const typename Pair::first_type &operator()(Pair const &x) const { return (x.first); }
};

template <typename VEC1, typename VEC2>
void compare_vectors(VEC1 &v1, VEC2 &v2)
{
    CHECK(v1.size() == v2.size());
    CHECK(v1.capacity() == v2.capacity());
    CHECK(v1.max_size() == v2.max_size());
    CHECK(v1.empty() == v2.empty());
    CHECK(std::equal(v1.begin(), v1.end(), v2.begin()));
    CHECK(std::equal(v2.begin(), v2.end(), v1.begin()));
}

template <typename MAP1, typename MAP2>
void compare_maps(MAP1 &m1, MAP2 &m2)
{
    CHECK(m1.size() == m2.size());
    CHECK(m1.empty() == m2.empty());

    typename MAP1::iterator m1_it = m1.begin();
    typename MAP2::iterator m2_it = m2.begin();

    for (; m1_it != m1.end(); ++m1_it, ++m2_it) {
        CHECK(m1_it->first == m2_it->first);
        CHECK(m1_it->second == m2_it->second);
    }
}

template <typename Key, typename T>
void compare_rbtrees(ft::rb_tree<Key, T, KOV<T>, COMPARE> &ft1,
                     ft::rb_tree<Key, T, KOV<T>, COMPARE> &ft2)
{
    CHECK(ft1.size() == ft2.size());
    CHECK(ft1.max_size() == ft2.max_size());
    CHECK(ft1.empty() == ft2.empty());
    CHECK(std::equal(ft1.begin(), ft1.end(), ft2.begin()));
    CHECK(std::equal(ft2.begin(), ft2.end(), ft1.begin()));
}

template <typename Map>
void build_lorenipsum_map(Map& map)
{
    typedef typename Map::key_type key_type;
    typedef typename Map::mapped_type mapped_type;
    typedef typename Map::value_type value_type;

    map.insert(value_type(key_type('L'), mapped_type("L")));
    map.insert(value_type(key_type('O'), mapped_type("O")));
    map.insert(value_type(key_type('R'), mapped_type("R")));
    map.insert(value_type(key_type('E'), mapped_type("E")));
    map.insert(value_type(key_type('N'), mapped_type("N")));
    map.insert(value_type(key_type('I'), mapped_type("I")));
    map.insert(value_type(key_type('P'), mapped_type("P")));
    map.insert(value_type(key_type('S'), mapped_type("S")));
    map.insert(value_type(key_type('U'), mapped_type("U")));
    map.insert(value_type(key_type('M'), mapped_type("M")));
}

void build_lorenipsum_tree(RB_TREE &tree);
void print_tree(RB_NODE *node, std::string const &indent, bool last);
void print_tree(RB_NODE *node);

#endif /* TEST_UTILS_HPP */
