/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:25:03 by maolivei          #+#    #+#             */
/*   Updated: 2023/02/21 21:15:27 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_UTILS_HPP
#define TEST_UTILS_HPP

#include "doctest.h"
#include <ctime>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>

#ifdef STL
namespace ft = std;
# define NS_PRINT "STD"
#else
# include "map.hpp"
# include "rb_tree.hpp"
# include "set.hpp"
# include "stack.hpp"
# include "utility.hpp"
# include "vector.hpp"
#endif

#ifndef NS_PRINT
# define NS_PRINT "FT"
#endif

#ifndef ITERATIONS
# define ITERATIONS 100000
#endif

#define RESET     "\033[0m"
#define GREEN     "\033[0m\033[32m"
#define MAGENTA   "\033[0m\033[35m"
#define CYAN      "\033[0m\033[36m"
#define BOLDBLACK "\033[1m\033[30m"
#define BOLDRED   "\033[1m\033[31m"
#define YELLOW    "\033[1m\033[33m"

#define TIME_PRINT MAGENTA "Time elapsed for " NS_PRINT " "

#ifndef STL

# define KEY     char
# define VALUE   std::string
# define TYPE    ft::pair<KEY, VALUE>
# define COMPARE std::less<KEY>
# define KOV     _KeyOfValue
# define VOV     _ValueOfValue
# define RB_TREE ft::rb_tree<KEY, TYPE, KOV<TYPE>, COMPARE>
# define RB_NODE ft::rb_tree_node<TYPE>

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
        typename Pair::first_type       operator()(Pair &x) const { return (x.first); }
        const typename Pair::first_type operator()(Pair const &x) const { return (x.first); }
};

extern RB_TREE base_tree;

extern std::map<char, std::string> base_std_map;
extern ft::map<char, std::string>  base_ft_map;

extern std::map<char, std::string> empty_std_map;
extern ft::map<char, std::string>  empty_ft_map;

extern std::set<char> base_std_set;
extern ft::set<char>  base_ft_set;

extern std::set<char> empty_std_set;
extern ft::set<char>  empty_ft_set;

template <typename VecL, typename VecR>
void compare_vectors(VecL &lhs, VecR &rhs)
{
    CHECK(lhs.size() == rhs.size());
    CHECK(lhs.capacity() == rhs.capacity());
    CHECK(lhs.max_size() == rhs.max_size());
    CHECK(lhs.empty() == rhs.empty());
    CHECK(std::equal(lhs.begin(), lhs.end(), rhs.begin()));
    CHECK(std::equal(rhs.begin(), rhs.end(), lhs.begin()));
}

template <typename TreeL, typename TreeR>
void compare_rbtrees(TreeL &lhs, TreeR &rhs)
{
    CHECK(lhs.size() == rhs.size());
    CHECK(lhs.max_size() == rhs.max_size());
    CHECK(lhs.empty() == rhs.empty());
    CHECK(std::equal(lhs.begin(), lhs.end(), rhs.begin()));
    CHECK(std::equal(rhs.begin(), rhs.end(), lhs.begin()));
}

template <typename MapL, typename MapR>
void compare_maps(MapL &lhs, MapR &rhs)
{
    CHECK(lhs.size() == rhs.size());
    CHECK(lhs.empty() == rhs.empty());

    typename MapL::iterator lhs_it = lhs.begin();
    typename MapR::iterator rhs_it = rhs.begin();

    for (; lhs_it != lhs.end(); ++lhs_it, ++rhs_it) {
        CHECK(lhs_it->first == rhs_it->first);
        CHECK(lhs_it->second == rhs_it->second);
    }
}

template <typename SetL, typename SetR>
void compare_sets(SetL &lhs, SetR &rhs)
{
    CHECK(lhs.size() == rhs.size());
    CHECK(lhs.empty() == rhs.empty());
    CHECK(std::equal(lhs.begin(), lhs.end(), rhs.begin()));
    CHECK(std::equal(rhs.begin(), rhs.end(), lhs.begin()));
}

template <typename T>
T populate_set(T &data)
{
    typedef typename T::value_type value_type;

    T aux;

    aux.insert(value_type('L'));
    aux.insert(value_type('O'));
    aux.insert(value_type('R'));
    aux.insert(value_type('E'));
    aux.insert(value_type('N'));
    aux.insert(value_type('I'));
    aux.insert(value_type('P'));
    aux.insert(value_type('S'));
    aux.insert(value_type('U'));
    aux.insert(value_type('M'));
    (void)data;
    return (aux);
}

template <typename T>
T populate(T &data)
{
    typedef typename T::value_type value_type;

    T aux;

    aux.insert(value_type('L', "L"));
    aux.insert(value_type('O', "O"));
    aux.insert(value_type('R', "R"));
    aux.insert(value_type('E', "E"));
    aux.insert(value_type('N', "N"));
    aux.insert(value_type('I', "I"));
    aux.insert(value_type('P', "P"));
    aux.insert(value_type('S', "S"));
    aux.insert(value_type('U', "U"));
    aux.insert(value_type('M', "M"));
    (void)data;
    return (aux);
}

void print_tree(RB_NODE *node, std::string const &indent, bool last);
void print_tree(RB_NODE *node);

#endif

#endif /* TEST_UTILS_HPP */
