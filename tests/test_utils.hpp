/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:25:03 by maolivei          #+#    #+#             */
/*   Updated: 2023/02/15 19:43:15 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_UTILS_HPP
#define TEST_UTILS_HPP

#include "doctest.h"
#include "rb_tree.hpp"
#include "utility.hpp"
#include "vector.hpp"
#include <iostream>
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
        typename Pair::first_type       &operator()(Pair &x) const { return x.first; }
        const typename Pair::first_type &operator()(Pair const &x) const { return x.first; }
};

void build_lorenipsum_tree(RB_TREE &tree);
void print_tree(RB_NODE *node, std::string const &indent, bool last);
void print_tree(RB_NODE *node);

#endif /* TEST_UTILS_HPP */
