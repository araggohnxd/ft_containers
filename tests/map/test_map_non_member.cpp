/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_non_member.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 23:13:38 by maolivei          #+#    #+#             */
/*   Updated: 2023/02/18 23:28:21 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.hpp"

TEST_CASE("test map operator== equal maps returns true")
{
    ft::map<char, std::string> ft(base_ft_map);

    CHECK((ft == base_ft_map) == true);
}

TEST_CASE("test map operator== different maps returns false")
{
    ft::map<char, std::string> ft;

    CHECK((ft == base_ft_map) == false);
}

TEST_CASE("test map operator!= equal maps returns false")
{
    ft::map<char, std::string> ft(base_ft_map);

    CHECK((ft != base_ft_map) == false);
}

TEST_CASE("test map operator!= different maps returns true")
{
    ft::map<char, std::string> ft;

    CHECK((ft != base_ft_map) == true);
}

TEST_CASE("test map operator> equal maps returns false")
{
    ft::map<char, std::string> ft(base_ft_map);

    CHECK((ft > base_ft_map) == false);
}

TEST_CASE("test map operator> different maps returns true when lhs is greater")
{
    ft::map<char, std::string> ft;

    CHECK((base_ft_map > ft) == true);
}

TEST_CASE("test map operator> different maps returns false when lhs is lesser")
{
    ft::map<char, std::string> ft;

    CHECK((ft > base_ft_map) == false);
}

TEST_CASE("test map operator< equal maps returns false")
{
    ft::map<char, std::string> ft(base_ft_map);

    CHECK((ft < base_ft_map) == false);
}

TEST_CASE("test map operator< different maps returns false when lhs is greater")
{
    ft::map<char, std::string> ft;

    CHECK((base_ft_map < ft) == false);
}

TEST_CASE("test map operator< different maps returns true when lhs is lesser")
{
    ft::map<char, std::string> ft;

    CHECK((ft < base_ft_map) == true);
}

TEST_CASE("test map operator>= equal maps returns true")
{
    ft::map<char, std::string> ft(base_ft_map);

    CHECK((ft >= base_ft_map) == true);
}

TEST_CASE("test map operator>= different maps returns true when lhs is greater")
{
    ft::map<char, std::string> ft;

    CHECK((base_ft_map >= ft) == true);
}

TEST_CASE("test map operator>= different maps returns false when lhs is lesser")
{
    ft::map<char, std::string> ft;

    CHECK((ft >= base_ft_map) == false);
}

TEST_CASE("test map operator<= equal maps returns true")
{
    ft::map<char, std::string> ft(base_ft_map);

    CHECK((ft <= base_ft_map) == true);
}

TEST_CASE("test map operator<= different maps returns false when lhs is greater")
{
    ft::map<char, std::string> ft;

    CHECK((base_ft_map <= ft) == false);
}

TEST_CASE("test map operator<= different maps returns true when lhs is lesser")
{
    ft::map<char, std::string> ft;

    CHECK((ft <= base_ft_map) == true);
}

TEST_CASE("test map swap() non-member properly swaps between maps of same size with different values")
{
    std::map<char, std::string> std1(base_std_map);
    ft::map<char, std::string>  ft1(base_ft_map);

    std::map<char, std::string> std2 = populate(std2);
    ft::map<char, std::string>  ft2  = populate(ft2);

    std1.swap(std2);
    ft1.swap(ft2);

    compare_maps(ft1, std1);
}

TEST_CASE("test map swap() non-member properly swaps between maps of different size")
{
    std::map<char, std::string> std1(base_std_map);
    ft::map<char, std::string>  ft1(base_ft_map);

    std::map<char, std::string> std2;
    ft::map<char, std::string>  ft2;

    std2.insert(std::make_pair('X', "X"));
    std2.insert(std::make_pair('Y', "Y"));
    std2.insert(std::make_pair('Z', "Z"));

    ft2.insert(ft::make_pair('X', "X"));
    ft2.insert(ft::make_pair('Y', "Y"));
    ft2.insert(ft::make_pair('Z', "Z"));

    std::swap(std1, std2);
    ft::swap(ft1, ft2);

    compare_maps(ft1, std1);
}

TEST_CASE("test map swap() non-member properly swaps between populated map and empty map")
{
    std::map<char, std::string> std1(base_std_map);
    ft::map<char, std::string>  ft1(base_ft_map);

    std::map<char, std::string> std2;
    ft::map<char, std::string>  ft2;

    std::swap(std1, std2);
    ft::swap(ft1, ft2);

    compare_maps(ft1, std1);
}

TEST_CASE("test map swap() non-member assert swap does a deep swap")
{
    std::map<char, std::string> std1(base_std_map);
    ft::map<char, std::string>  ft1(base_ft_map);

    std::map<char, std::string> std2;
    ft::map<char, std::string>  ft2;

    std2.insert(std::make_pair('X', "X"));
    std2.insert(std::make_pair('Y', "Y"));
    std2.insert(std::make_pair('Z', "Z"));

    ft2.insert(ft::make_pair('X', "X"));
    ft2.insert(ft::make_pair('Y', "Y"));
    ft2.insert(ft::make_pair('Z', "Z"));

    std::swap(std1, std2);
    std1.insert(base_std_map.begin(), base_std_map.end());

    ft::swap(ft1, ft2);
    ft1.insert(base_ft_map.begin(), base_ft_map.end());

    CHECK_FALSE(ft1.size() == ft2.size());

    compare_maps(ft1, std1);
}
