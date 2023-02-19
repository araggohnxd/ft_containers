/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_iterators.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:15:08 by maolivei          #+#    #+#             */
/*   Updated: 2023/02/18 19:06:50 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.hpp"

TEST_CASE("test map iterating through 'lorenipsum' with iterator should equal stl")
{
    std::map<char, std::string>::iterator it_std = base_std_map.begin();
    ft::map<char, std::string>::iterator  it_ft  = base_ft_map.begin();

    for (; it_std != base_std_map.end(); ++it_std, ++it_ft) {
        CHECK(it_std->first == it_ft->first);
        CHECK(it_std->second == it_ft->second);
    }
}

TEST_CASE("test map iterating through 'lorenipsum' with const iterator should equal stl")
{
    std::map<char, std::string>::const_iterator it_std = base_std_map.begin();
    ft::map<char, std::string>::const_iterator  it_ft  = base_ft_map.begin();

    for (; it_std != base_std_map.end(); ++it_std, ++it_ft) {
        CHECK(it_std->first == it_ft->first);
        CHECK(it_std->second == it_ft->second);
    }
}

TEST_CASE("test map iterating through 'lorenipsum' with reverse iterator should equal stl")
{
    std::map<char, std::string>::reverse_iterator it_std = base_std_map.rbegin();
    ft::map<char, std::string>::reverse_iterator  it_ft  = base_ft_map.rbegin();

    for (; it_std != base_std_map.rend(); ++it_std, ++it_ft) {
        CHECK(it_std->first == it_ft->first);
        CHECK(it_std->second == it_ft->second);
    }
}

TEST_CASE("test map iterating through 'lorenipsum' with const reverse iterator should equal stl")
{
    std::map<char, std::string>::const_reverse_iterator it_std = base_std_map.rbegin();
    ft::map<char, std::string>::const_reverse_iterator  it_ft  = base_ft_map.rbegin();

    for (; it_std != base_std_map.rend(); ++it_std, ++it_ft) {
        CHECK(it_std->first == it_ft->first);
        CHECK(it_std->second == it_ft->second);
    }
}

TEST_CASE("test map iterator begin() should hold 'E' in its values")
{
    ft::map<char, std::string>::iterator it_ft = base_ft_map.begin();

    CHECK(it_ft->first == 'E');
    CHECK(it_ft->second == "E");
}

TEST_CASE("test map iterator begin() and incrementing once should hold 'I' in its values")
{
    ft::map<char, std::string>::iterator it_ft = base_ft_map.begin();
    ++it_ft;

    CHECK(it_ft->first == 'I');
    CHECK(it_ft->second == "I");
}

TEST_CASE("test map iterator end() and decrementing once should hold 'U' in its values")
{
    ft::map<char, std::string>::iterator it_ft = base_ft_map.end();
    --it_ft;

    CHECK(it_ft->first == 'U');
    CHECK(it_ft->second == "U");
}

TEST_CASE("test map iterator end() and incrementing once should hold 'U' in its values")
{
    ft::map<char, std::string>::iterator it_ft = base_ft_map.end();
    ++it_ft;

    CHECK(it_ft->first == 'U');
    CHECK(it_ft->second == "U");
}

TEST_CASE("test map iterator rbegin() should hold 'U' in its values")
{
    ft::map<char, std::string>::reverse_iterator it_ft = base_ft_map.rbegin();

    CHECK(it_ft->first == 'U');
    CHECK(it_ft->second == "U");
}

TEST_CASE("test map iterator rbegin() and decrementing once should hold 'S' in its values")
{
    ft::map<char, std::string>::reverse_iterator it_ft = base_ft_map.rbegin();
    --it_ft;

    CHECK(it_ft->first == 'S');
    CHECK(it_ft->second == "S");
}

TEST_CASE("test map iterator rbegin() and incrementing once should hold 'S' in its values")
{
    ft::map<char, std::string>::reverse_iterator it_ft = base_ft_map.rbegin();
    ++it_ft;

    CHECK(it_ft->first == 'S');
    CHECK(it_ft->second == "S");
}

TEST_CASE("test map iterator rend() and decrementing once should hold 'E' in its values")
{
    ft::map<char, std::string>::reverse_iterator it_ft = base_ft_map.rend();
    --it_ft;

    CHECK(it_ft->first == 'E');
    CHECK(it_ft->second == "E");
}

TEST_CASE("test map iterator rend() and incrementing once should hold 'U' in its values")
{
    ft::map<char, std::string>::reverse_iterator it_ft = base_ft_map.rend();
    ++it_ft;

    CHECK(it_ft->first == 'U');
    CHECK(it_ft->second == "U");
}

TEST_CASE("test map iterating through 'lorenipsum' with iterator should equal maps' size")
{
    ft::map<char, std::string>::iterator it_ft    = base_ft_map.begin();
    size_t                               map_size = 0;

    for (; it_ft != base_ft_map.end(); ++it_ft)
        ++map_size;
    CHECK(map_size == base_ft_map.size());
}

TEST_CASE("test map iterator through 'lorenipsum' with reverse iterator should equal maps' size")
{
    ft::map<char, std::string>::reverse_iterator it_ft    = base_ft_map.rbegin();
    size_t                                       map_size = 0;

    for (; it_ft != base_ft_map.rend(); ++it_ft)
        ++map_size;
    CHECK(map_size == base_ft_map.size());
}
