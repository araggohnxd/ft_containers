/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_lookup.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 22:33:25 by maolivei          #+#    #+#             */
/*   Updated: 2023/02/18 23:09:50 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.hpp"

TEST_CASE("test map find() iterator succesfully returns 'o' in 'lorenipsum'")
{
    ft::map<char, std::string>::iterator it;

    it = base_ft_map.find('O');

    CHECK(it->first == 'O');
    CHECK(it->second == "O");
}

TEST_CASE("test map find() iterator returns end when value doesn't exist")
{
    ft::map<char, std::string>::iterator it;

    it = base_ft_map.find('X');

    CHECK(it == base_ft_map.end());
}

TEST_CASE("test map find() const iterator succesfully returns 'o' in 'lorenipsum'")
{
    ft::map<char, std::string>::const_iterator it;

    it = base_ft_map.find('O');

    CHECK(it->first == 'O');
    CHECK(it->second == "O");
}

TEST_CASE("test map find() const iterator returns end when value doesn't exist")
{
    ft::map<char, std::string>::const_iterator it;

    it = base_ft_map.find('X');

    CHECK(it == base_ft_map.end());
}

TEST_CASE("test map count() returns 1 for existing value")
{
    CHECK(base_ft_map.count('O') == 1);
}

TEST_CASE("test map count() returns 0 for non existing value")
{
    CHECK(base_ft_map.count('X') == 0);
}

TEST_CASE("test map lower_bound() returns iterator to value itself when exists")
{
    CHECK(base_ft_map.lower_bound('O')->first == 'O');
    CHECK(base_ft_map.lower_bound('O')->second == "O");
}

TEST_CASE("test map lower_bound() returns iterator to end when value doesn't exist")
{
    CHECK(base_ft_map.lower_bound('X') == base_ft_map.end());
}

TEST_CASE("test map upper_bound() returns iterator to next when value exists")
{
    CHECK(base_ft_map.upper_bound('O')->first == 'P');
    CHECK(base_ft_map.upper_bound('O')->second == "P");
}

TEST_CASE("test map upper_bound() returns iterator to end when value doesn't exist")
{
    CHECK(base_ft_map.upper_bound('X') == base_ft_map.end());
}

TEST_CASE("test map equal_range() returns pair lower bound and upper bound when value exists")
{
    CHECK(base_ft_map.equal_range('O').first->first == 'O');
    CHECK(base_ft_map.equal_range('O').first->second == "O");
    CHECK(base_ft_map.equal_range('O').second->first == 'P');
    CHECK(base_ft_map.equal_range('O').second->second == "P");
}

TEST_CASE("test map equal_range() returns pair to end when value doesn't exist")
{
    CHECK(base_ft_map.equal_range('X').first == base_ft_map.end());
    CHECK(base_ft_map.equal_range('X').first == base_ft_map.end());
    CHECK(base_ft_map.equal_range('X').second == base_ft_map.end());
    CHECK(base_ft_map.equal_range('X').second == base_ft_map.end());
}
