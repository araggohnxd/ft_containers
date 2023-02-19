/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_capacity.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:29:34 by maolivei          #+#    #+#             */
/*   Updated: 2023/02/18 19:16:22 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.hpp"

TEST_CASE("test map size() with 'lorenipsum' values should have size 10")
{
    CHECK(base_ft_map.size() == base_std_map.size());
    CHECK(base_ft_map.size() == 10);
}

TEST_CASE("test map empty() with 'lorenipsum' values should not be empty")
{
    CHECK(base_ft_map.empty() == base_std_map.empty());
    CHECK(base_ft_map.empty() == false);
}

TEST_CASE("test map size() created empty should have size 0")
{
    CHECK(empty_ft_map.size() == empty_std_map.size());
    CHECK(empty_ft_map.size() == 0);
}

TEST_CASE("test map empty() created empty should be empty")
{
    CHECK(empty_ft_map.empty() == empty_std_map.empty());
    CHECK(empty_ft_map.empty() == true);
}

// TODO: move me to modifiers tests
// TEST_CASE("test map size() map with size 10 resizes to 11 when inserted new item")
// {
//     std::map<char, std::string> std(base_std_map);
//     ft::map<char, std::string> ft(base_ft_map);

//     CHECK(ft.size() == std.size());
//     CHECK(ft.size() == 10);

//     std.insert(std::make_pair('X', "X"));
//     ft.insert(ft::make_pair('X', "X"));

//     CHECK(ft.size() == std.size());
//     CHECK(ft.size() == 11);
// }

// TEST_CASE("test map size() map with size 10 resizes to 9 when erased one item")
// {
//     std::map<char, std::string> std(base_std_map);
//     ft::map<char, std::string> ft(base_ft_map);

//     CHECK(ft.size() == std.size());
//     CHECK(ft.size() == 10);

//     std.erase('O');
//     ft.erase('O');

//     CHECK(ft.size() == std.size());
//     CHECK(ft.size() == 9);
// }
