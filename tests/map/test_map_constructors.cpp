/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_constructors.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:35:40 by maolivei          #+#    #+#             */
/*   Updated: 2023/02/18 19:06:45 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.hpp"

TEST_CASE("test map default constructor should be equal to stl")
{
    std::map<char, std::string> std;
    ft::map<char, std::string>  ft;

    compare_maps(std, ft);
}

TEST_CASE("test map range constructor with values 'lorenipsum' should be equal to stl")
{
    std::map<char, std::string> std(base_std_map.begin(), base_std_map.end());
    ft::map<char, std::string>  ft(base_ft_map.begin(), base_ft_map.end());

    compare_maps(std, ft);
}

TEST_CASE("test map copy constructor with values 'lorenipsum' should be equal to stl")
{
    std::map<char, std::string> std(base_std_map);
    ft::map<char, std::string>  ft(base_ft_map);

    compare_maps(std, ft);
}

TEST_CASE("test map assignment operator with values 'lorenipsum' should be equal to stl")
{
    std::map<char, std::string> std;
    ft::map<char, std::string>  ft;

    std = base_std_map;
    ft  = base_ft_map;

    compare_maps(std, ft);
}

/* This test requires a specific constructor in map to be able to construct an object
 * through std::map iterators. This happens because ft::pair and std::pair are different
 * types, thus cannot be overloaded in the provided constructors */

// TEST_CASE("test map range constructor passing another map with values 'lorenipsum'")
// {
//     std::map<char, std::string> base;

//     populate(base);

//     std::map<char, std::string> std(base.begin(), base.end());
//     ft::map<char, std::string> ft(base.begin(), base.end());

//     compare_maps(std, ft);
// }
