/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set_lookup.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 22:33:25 by maolivei          #+#    #+#             */
/*   Updated: 2023/02/20 11:49:14 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.hpp"

TEST_CASE("test set find() iterator succesfully returns 'o' in 'lorenipsum'")
{
    ft::set<char>::iterator it;

    it = base_ft_set.find('O');

    CHECK(*it == 'O');
}

TEST_CASE("test set find() iterator returns end when value doesn't exist")
{
    ft::set<char>::iterator it;

    it = base_ft_set.find('X');

    CHECK(it == base_ft_set.end());
}

TEST_CASE("test set find() const iterator succesfully returns 'o' in 'lorenipsum'")
{
    ft::set<char>::const_iterator it;

    it = base_ft_set.find('O');

    CHECK(*it == 'O');
}

TEST_CASE("test set find() const iterator returns end when value doesn't exist")
{
    ft::set<char>::const_iterator it;

    it = base_ft_set.find('X');

    CHECK(it == base_ft_set.end());
}

TEST_CASE("test set count() returns 1 for existing value") { CHECK(base_ft_set.count('O') == 1); }

TEST_CASE("test set count() returns 0 for non existing value")
{
    CHECK(base_ft_set.count('X') == 0);
}

TEST_CASE("test set lower_bound() returns iterator to value itself when exists")
{
    CHECK(*(base_ft_set.lower_bound('O')) == 'O');
}

TEST_CASE("test set lower_bound() returns iterator to end when value doesn't exist")
{
    CHECK(base_ft_set.lower_bound('X') == base_ft_set.end());
}

TEST_CASE("test set upper_bound() returns iterator to next when value exists")
{
    CHECK(*(base_ft_set.upper_bound('O')) == 'P');
}

TEST_CASE("test set upper_bound() returns iterator to end when value doesn't exist")
{
    CHECK(base_ft_set.upper_bound('X') == base_ft_set.end());
}

TEST_CASE("test set equal_range() returns pair lower bound and upper bound when value exists")
{
    CHECK(*(base_ft_set.equal_range('O').first) == 'O');
    CHECK(*(base_ft_set.equal_range('O').second) == 'P');
}

TEST_CASE("test set equal_range() returns pair to end when value doesn't exist")
{
    CHECK(base_ft_set.equal_range('X').first == base_ft_set.end());
    CHECK(base_ft_set.equal_range('X').first == base_ft_set.end());
    CHECK(base_ft_set.equal_range('X').second == base_ft_set.end());
    CHECK(base_ft_set.equal_range('X').second == base_ft_set.end());
}
