/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack_constructor.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:29:39 by maolivei          #+#    #+#             */
/*   Updated: 2023/02/19 19:44:40 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.hpp"

TEST_CASE("test stack default constructor with default underlying container")
{
    ft::stack<int> ft;
    std::stack<int> std;

    CHECK(ft.size() == std.size());
    CHECK(ft.empty() == std.empty());
    CHECK(ft.size() == 0);
    CHECK(ft.empty() == true);
}

TEST_CASE("test stack default constructor with std::vector underlying container")
{
    ft::stack<int, std::vector<int> > ft;
    std::stack<int, std::vector<int> > std;

    CHECK(ft.size() == std.size());
    CHECK(ft.empty() == std.empty());
    CHECK(ft.size() == 0);
    CHECK(ft.empty() == true);
}

TEST_CASE("test stack default constructor with std::deque underlying container")
{
    ft::stack<int, std::deque<int> > ft;
    std::stack<int, std::deque<int> > std;

    CHECK(ft.size() == std.size());
    CHECK(ft.empty() == std.empty());
    CHECK(ft.size() == 0);
    CHECK(ft.empty() == true);
}
