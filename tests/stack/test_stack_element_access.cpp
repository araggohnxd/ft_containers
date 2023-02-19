/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack_element_access.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:41:05 by maolivei          #+#    #+#             */
/*   Updated: 2023/02/19 19:48:06 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.hpp"

TEST_CASE("test stack top() push 1 to 10 should return 10 with default container")
{
    ft::stack<int>  ft;
    std::stack<int> std;

    for (int i = 0; i < 10; ++i) {
        std.push(i + 1);
        ft.push(i + 1);
    }

    CHECK(ft.top() == std.top());
    CHECK(ft.top() == 10);
}

TEST_CASE("test stack top() allows writing by updating element 10 to 42 with default container")
{
    ft::stack<int>  ft;
    std::stack<int> std;

    for (int i = 0; i < 10; ++i) {
        std.push(i + 1);
        ft.push(i + 1);
    }

    std.top() = 42;
    ft.top()  = 42;

    CHECK(ft.top() == std.top());
    CHECK(ft.top() == 42);
}

TEST_CASE("test stack top() push 1 to 10 should return 10 with std::vector")
{
    ft::stack<int, std::vector<int> >  ft;
    std::stack<int, std::vector<int> > std;

    for (int i = 0; i < 10; ++i) {
        std.push(i + 1);
        ft.push(i + 1);
    }

    CHECK(ft.top() == std.top());
    CHECK(ft.top() == 10);
}

TEST_CASE("test stack top() allows writing by updating element 10 to 42 with std::vector")
{
    ft::stack<int, std::vector<int> >  ft;
    std::stack<int, std::vector<int> > std;

    for (int i = 0; i < 10; ++i) {
        std.push(i + 1);
        ft.push(i + 1);
    }

    std.top() = 42;
    ft.top()  = 42;

    CHECK(ft.top() == std.top());
    CHECK(ft.top() == 42);
}

TEST_CASE("test stack top() push 1 to 10 should return 10 with std::deque")
{
    ft::stack<int, std::deque<int> >  ft;
    std::stack<int, std::deque<int> > std;

    for (int i = 0; i < 10; ++i) {
        std.push(i + 1);
        ft.push(i + 1);
    }

    CHECK(ft.top() == std.top());
    CHECK(ft.top() == 10);
}

TEST_CASE("test stack top() allows writing by updating element 10 to 42 with std::deque")
{
    ft::stack<int, std::deque<int> >  ft;
    std::stack<int, std::deque<int> > std;

    for (int i = 0; i < 10; ++i) {
        std.push(i + 1);
        ft.push(i + 1);
    }

    std.top() = 42;
    ft.top()  = 42;

    CHECK(ft.top() == std.top());
    CHECK(ft.top() == 42);
}
