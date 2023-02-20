/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set_iterators.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:15:08 by maolivei          #+#    #+#             */
/*   Updated: 2023/02/20 11:47:48 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.hpp"

TEST_CASE("test set iterating through 'lorenipsum' with iterator should equal stl")
{
    std::set<char>::iterator it_std = base_std_set.begin();
    ft::set<char>::iterator  it_ft  = base_ft_set.begin();

    for (; it_std != base_std_set.end(); ++it_std, ++it_ft)
        CHECK(*(it_std) == *(it_ft));
}

TEST_CASE("test set iterating through 'lorenipsum' with const iterator should equal stl")
{
    std::set<char>::const_iterator it_std = base_std_set.begin();
    ft::set<char>::const_iterator  it_ft  = base_ft_set.begin();

    for (; it_std != base_std_set.end(); ++it_std, ++it_ft)
        CHECK(*(it_std) == *(it_ft));
}

TEST_CASE("test set iterating through 'lorenipsum' with reverse iterator should equal stl")
{
    std::set<char>::reverse_iterator it_std = base_std_set.rbegin();
    ft::set<char>::reverse_iterator  it_ft  = base_ft_set.rbegin();

    for (; it_std != base_std_set.rend(); ++it_std, ++it_ft)
        CHECK(*(it_std) == *(it_ft));
}

TEST_CASE("test set iterating through 'lorenipsum' with const reverse iterator should equal stl")
{
    std::set<char>::const_reverse_iterator it_std = base_std_set.rbegin();
    ft::set<char>::const_reverse_iterator  it_ft  = base_ft_set.rbegin();

    for (; it_std != base_std_set.rend(); ++it_std, ++it_ft)
        CHECK(*(it_std) == *(it_ft));
}

TEST_CASE("test set iterator begin() should hold 'E' in its values")
{
    ft::set<char>::iterator it_ft = base_ft_set.begin();

    CHECK(*(it_ft) == 'E');
}

TEST_CASE("test set iterator begin() and incrementing once should hold 'I' in its values")
{
    ft::set<char>::iterator it_ft = base_ft_set.begin();
    ++it_ft;

    CHECK(*(it_ft) == 'I');
}

TEST_CASE("test set iterator end() and decrementing once should hold 'U' in its values")
{
    ft::set<char>::iterator it_ft = base_ft_set.end();
    --it_ft;

    CHECK(*(it_ft) == 'U');
}

TEST_CASE("test set iterator end() and incrementing once should hold 'U' in its values")
{
    ft::set<char>::iterator it_ft = base_ft_set.end();
    ++it_ft;

    CHECK(*(it_ft) == 'U');
}

TEST_CASE("test set iterator rbegin() should hold 'U' in its values")
{
    ft::set<char>::reverse_iterator it_ft = base_ft_set.rbegin();

    CHECK(*(it_ft) == 'U');
}

TEST_CASE("test set iterator rbegin() and decrementing once should hold 'S' in its values")
{
    ft::set<char>::reverse_iterator it_ft = base_ft_set.rbegin();
    --it_ft;

    CHECK(*(it_ft) == 'S');
}

TEST_CASE("test set iterator rbegin() and incrementing once should hold 'S' in its values")
{
    ft::set<char>::reverse_iterator it_ft = base_ft_set.rbegin();
    ++it_ft;

    CHECK(*(it_ft) == 'S');
}

TEST_CASE("test set iterator rend() and decrementing once should hold 'E' in its values")
{
    ft::set<char>::reverse_iterator it_ft = base_ft_set.rend();
    --it_ft;

    CHECK(*(it_ft) == 'E');
}

TEST_CASE("test set iterator rend() and incrementing once should hold 'U' in its values")
{
    ft::set<char>::reverse_iterator it_ft = base_ft_set.rend();
    ++it_ft;

    CHECK(*(it_ft) == 'U');
}

TEST_CASE("test set iterating through 'lorenipsum' with iterator should equal maps' size")
{
    ft::set<char>::iterator it_ft    = base_ft_set.begin();
    size_t                  map_size = 0;

    for (; it_ft != base_ft_set.end(); ++it_ft)
        ++map_size;
    CHECK(map_size == base_ft_set.size());
}

TEST_CASE("test set iterator through 'lorenipsum' with reverse iterator should equal maps' size")
{
    ft::set<char>::reverse_iterator it_ft    = base_ft_set.rbegin();
    size_t                          map_size = 0;

    for (; it_ft != base_ft_set.rend(); ++it_ft)
        ++map_size;
    CHECK(map_size == base_ft_set.size());
}
