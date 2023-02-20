/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set_non_member.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 23:13:38 by maolivei          #+#    #+#             */
/*   Updated: 2023/02/20 11:50:59 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.hpp"

TEST_CASE("test set operator== equal maps returns true")
{
    ft::set<char> ft(base_ft_set);

    CHECK((ft == base_ft_set) == true);
}

TEST_CASE("test set operator== different maps returns false")
{
    ft::set<char> ft;

    CHECK((ft == base_ft_set) == false);
}

TEST_CASE("test set operator!= equal maps returns false")
{
    ft::set<char> ft(base_ft_set);

    CHECK((ft != base_ft_set) == false);
}

TEST_CASE("test set operator!= different maps returns true")
{
    ft::set<char> ft;

    CHECK((ft != base_ft_set) == true);
}

TEST_CASE("test set operator> equal maps returns false")
{
    ft::set<char> ft(base_ft_set);

    CHECK((ft > base_ft_set) == false);
}

TEST_CASE("test set operator> different maps returns true when lhs is greater")
{
    ft::set<char> ft;

    CHECK((base_ft_set > ft) == true);
}

TEST_CASE("test set operator> different maps returns false when lhs is lesser")
{
    ft::set<char> ft;

    CHECK((ft > base_ft_set) == false);
}

TEST_CASE("test set operator< equal maps returns false")
{
    ft::set<char> ft(base_ft_set);

    CHECK((ft < base_ft_set) == false);
}

TEST_CASE("test set operator< different maps returns false when lhs is greater")
{
    ft::set<char> ft;

    CHECK((base_ft_set < ft) == false);
}

TEST_CASE("test set operator< different maps returns true when lhs is lesser")
{
    ft::set<char> ft;

    CHECK((ft < base_ft_set) == true);
}

TEST_CASE("test set operator>= equal maps returns true")
{
    ft::set<char> ft(base_ft_set);

    CHECK((ft >= base_ft_set) == true);
}

TEST_CASE("test set operator>= different maps returns true when lhs is greater")
{
    ft::set<char> ft;

    CHECK((base_ft_set >= ft) == true);
}

TEST_CASE("test set operator>= different maps returns false when lhs is lesser")
{
    ft::set<char> ft;

    CHECK((ft >= base_ft_set) == false);
}

TEST_CASE("test set operator<= equal maps returns true")
{
    ft::set<char> ft(base_ft_set);

    CHECK((ft <= base_ft_set) == true);
}

TEST_CASE("test set operator<= different maps returns false when lhs is greater")
{
    ft::set<char> ft;

    CHECK((base_ft_set <= ft) == false);
}

TEST_CASE("test set operator<= different maps returns true when lhs is lesser")
{
    ft::set<char> ft;

    CHECK((ft <= base_ft_set) == true);
}
