/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set_capacity.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:29:34 by maolivei          #+#    #+#             */
/*   Updated: 2023/02/20 11:45:30 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.hpp"

TEST_CASE("test set size() with 'lorenipsum' values should have size 10")
{
    CHECK(base_ft_set.size() == base_std_set.size());
    CHECK(base_ft_set.size() == 10);
}

TEST_CASE("test set empty() with 'lorenipsum' values should not be empty")
{
    CHECK(base_ft_set.empty() == base_std_set.empty());
    CHECK(base_ft_set.empty() == false);
}

TEST_CASE("test set size() created empty should have size 0")
{
    CHECK(empty_ft_set.size() == empty_std_set.size());
    CHECK(empty_ft_set.size() == 0);
}

TEST_CASE("test set empty() created empty should be empty")
{
    CHECK(empty_ft_set.empty() == empty_std_set.empty());
    CHECK(empty_ft_set.empty() == true);
}

// TODO: move me to modifiers tests
// TEST_CASE("test set size() map with size 10 resizes to 11 when inserted new item")
// {
//     std::set<char> std(base_std_set);
//     ft::set<char> ft(base_ft_set);

//     CHECK(ft.size() == std.size());
//     CHECK(ft.size() == 10);

//     std.insert(std::make_pair('X', 'X'));
//     ft.insert(ft::make_pair('X', 'X'));

//     CHECK(ft.size() == std.size());
//     CHECK(ft.size() == 11);
// }

// TEST_CASE("test set size() map with size 10 resizes to 9 when erased one item")
// {
//     std::set<char> std(base_std_set);
//     ft::set<char> ft(base_ft_set);

//     CHECK(ft.size() == std.size());
//     CHECK(ft.size() == 10);

//     std.erase('O');
//     ft.erase('O');

//     CHECK(ft.size() == std.size());
//     CHECK(ft.size() == 9);
// }
