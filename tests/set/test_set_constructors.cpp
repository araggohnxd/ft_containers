/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set_constructors.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:35:40 by maolivei          #+#    #+#             */
/*   Updated: 2023/02/20 12:02:14 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.hpp"

TEST_CASE("test set default constructor should be equal to stl")
{
    std::set<char> std;
    ft::set<char>  ft;

    compare_sets(std, ft);
}

TEST_CASE("test set range constructor with values 'lorenipsum' should be equal to stl")
{
    std::set<char> std(base_std_set.begin(), base_std_set.end());
    ft::set<char>  ft(base_ft_set.begin(), base_ft_set.end());

    compare_sets(std, ft);
}

TEST_CASE("test set copy constructor with values 'lorenipsum' should be equal to stl")
{
    std::set<char> std(base_std_set);
    ft::set<char>  ft(base_ft_set);

    compare_sets(std, ft);
}

TEST_CASE("test set assignment operator with values 'lorenipsum' should be equal to stl")
{
    std::set<char> std;
    ft::set<char>  ft;

    std = base_std_set;
    ft  = base_ft_set;

    compare_sets(std, ft);
}

/* This test requires a specific constructor in map to be able to construct an object
 * through std::map iterators. This happens because ft::pair and std::pair are different
 * types, thus cannot be overloaded in the provided constructors */

// TEST_CASE("test set range constructor passing another map with values 'lorenipsum'")
// {
//     std::set<char> base;

//     populate_set(base);

//     std::set<char> std(base.begin(), base.end());
//     ft::set<char> ft(base.begin(), base.end());

//     compare_sets(std, ft);
// }
