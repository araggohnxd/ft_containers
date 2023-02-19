/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_element_access.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 19:17:13 by maolivei          #+#    #+#             */
/*   Updated: 2023/02/18 19:50:21 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.hpp"

TEST_CASE("test map operator[] with values 'lorenipsum'")
{
    CHECK(base_ft_map['L'] == base_std_map['L']);
    CHECK(base_ft_map['L'] == "L");

    CHECK(base_ft_map['O'] == base_std_map['O']);
    CHECK(base_ft_map['O'] == "O");

    CHECK(base_ft_map['R'] == base_std_map['R']);
    CHECK(base_ft_map['R'] == "R");

    CHECK(base_ft_map['E'] == base_std_map['E']);
    CHECK(base_ft_map['E'] == "E");

    CHECK(base_ft_map['N'] == base_std_map['N']);
    CHECK(base_ft_map['N'] == "N");

    CHECK(base_ft_map['I'] == base_std_map['I']);
    CHECK(base_ft_map['I'] == "I");

    CHECK(base_ft_map['P'] == base_std_map['P']);
    CHECK(base_ft_map['P'] == "P");

    CHECK(base_ft_map['S'] == base_std_map['S']);
    CHECK(base_ft_map['S'] == "S");

    CHECK(base_ft_map['U'] == base_std_map['U']);
    CHECK(base_ft_map['U'] == "U");

    CHECK(base_ft_map['M'] == base_std_map['M']);
    CHECK(base_ft_map['M'] == "M");
}

TEST_CASE("test map operator[] inserts new value in map if it doesn't already exists")
{
    std::map<char, std::string> std(base_std_map);
    ft::map<char, std::string>  ft(base_ft_map);

    CHECK(std.find('X') == std.end());
    CHECK(ft.find('X') == ft.end());

    std['X'] = "X";
    ft['X'] = "X";

    CHECK(ft.find('X')->second == std.find('X')->second);
    CHECK(ft.find('X')->second == "X");
}

TEST_CASE("test map operator[] updates a value in map if it already exists")
{
    std::map<char, std::string> std(base_std_map);
    ft::map<char, std::string>  ft(base_ft_map);

    CHECK(ft.find('O')->second == std.find('O')->second);
    CHECK(ft.find('O')->second == "O");

    std['O'] = "X";
    ft['O'] = "X";

    CHECK(ft.find('O')->second == std.find('O')->second);
    CHECK(ft.find('O')->second == "X");
}

TEST_CASE("test at() with values 'lorenipsum'")
{
    CHECK(base_ft_map.at('L') == base_std_map.at('L'));
    CHECK(base_ft_map.at('L') == "L");

    CHECK(base_ft_map.at('O') == base_std_map.at('O'));
    CHECK(base_ft_map.at('O') == "O");

    CHECK(base_ft_map.at('R') == base_std_map.at('R'));
    CHECK(base_ft_map.at('R') == "R");

    CHECK(base_ft_map.at('E') == base_std_map.at('E'));
    CHECK(base_ft_map.at('E') == "E");

    CHECK(base_ft_map.at('N') == base_std_map.at('N'));
    CHECK(base_ft_map.at('N') == "N");

    CHECK(base_ft_map.at('I') == base_std_map.at('I'));
    CHECK(base_ft_map.at('I') == "I");

    CHECK(base_ft_map.at('P') == base_std_map.at('P'));
    CHECK(base_ft_map.at('P') == "P");

    CHECK(base_ft_map.at('S') == base_std_map.at('S'));
    CHECK(base_ft_map.at('S') == "S");

    CHECK(base_ft_map.at('U') == base_std_map.at('U'));
    CHECK(base_ft_map.at('U') == "U");

    CHECK(base_ft_map.at('M') == base_std_map.at('M'));
    CHECK(base_ft_map.at('M') == "M");
}

TEST_CASE("test at() with value that doesn't exist throws exception")
{
    CHECK_THROWS_AS(base_ft_map.at('X'), std::out_of_range);
}
