/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack_modifiers.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:48:27 by maolivei          #+#    #+#             */
/*   Updated: 2023/02/19 20:02:03 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.hpp"

TEST_CASE("test stack push() successfully adds 1 to 3 with default underlying container")
{
    ft::stack<int>  ft;
    std::stack<int> std;

    std.push(1);
    ft.push(1);

    CHECK(ft.top() == std.top());
    CHECK(ft.top() == 1);

    std.push(2);
    ft.push(2);

    CHECK(ft.top() == std.top());
    CHECK(ft.top() == 2);

    std.push(3);
    ft.push(3);

    CHECK(ft.top() == std.top());
    CHECK(ft.top() == 3);
}

TEST_CASE("test stack push() successfully adds 1 to 3 with std::vector underlying container")
{
    ft::stack<int, std::vector<int> >  ft;
    std::stack<int, std::vector<int> > std;

    std.push(1);
    ft.push(1);

    CHECK(ft.top() == std.top());
    CHECK(ft.top() == 1);

    std.push(2);
    ft.push(2);

    CHECK(ft.top() == std.top());
    CHECK(ft.top() == 2);

    std.push(3);
    ft.push(3);

    CHECK(ft.top() == std.top());
    CHECK(ft.top() == 3);
}

TEST_CASE("test stack push() successfully adds 1 to 3 with std::deque underlying container")
{
    ft::stack<int, std::deque<int> >  ft;
    std::stack<int, std::deque<int> > std;

    std.push(1);
    ft.push(1);

    CHECK(ft.top() == std.top());
    CHECK(ft.top() == 1);

    std.push(2);
    ft.push(2);

    CHECK(ft.top() == std.top());
    CHECK(ft.top() == 2);

    std.push(3);
    ft.push(3);

    CHECK(ft.top() == std.top());
    CHECK(ft.top() == 3);
}

TEST_CASE("test stack push() increases size by 1 with default underlying container")
{
    ft::stack<int>  ft;
    std::stack<int> std;

    std.push(42);
    ft.push(42);

    CHECK(ft.size() == std.size());
    CHECK(ft.size() == 1);
}

TEST_CASE("test stack push() increases size by 1 with std::vector underlying container")
{
    ft::stack<int, std::vector<int> >  ft;
    std::stack<int, std::vector<int> > std;

    std.push(42);
    ft.push(42);

    CHECK(ft.size() == std.size());
    CHECK(ft.size() == 1);
}

TEST_CASE("test stack push() increases size by 1 with std::deque underlying container")
{
    ft::stack<int, std::deque<int> >  ft;
    std::stack<int, std::deque<int> > std;

    std.push(42);
    ft.push(42);

    CHECK(ft.size() == std.size());
    CHECK(ft.size() == 1);
}

TEST_CASE("test stack pop() sucessfully pops 3 to 1 with default underlying container")
{
    ft::stack<int>  ft;
    std::stack<int> std;

    for (int i = 0; i < 4; ++i) {
        std.push(i);
        ft.push(i);
    }

    std.pop();
    ft.pop();

    CHECK(ft.top() == std.top());
    CHECK(ft.top() == 2);

    std.pop();
    ft.pop();

    CHECK(ft.top() == std.top());
    CHECK(ft.top() == 1);

    std.pop();
    ft.pop();

    CHECK(ft.top() == std.top());
    CHECK(ft.top() == 0);
}

TEST_CASE("test stack pop() sucessfully pops 3 to 1 with std::vector underlying container")
{
    ft::stack<int, std::vector<int> >  ft;
    std::stack<int, std::vector<int> > std;

    for (int i = 0; i < 4; ++i) {
        std.push(i);
        ft.push(i);
    }

    std.pop();
    ft.pop();

    CHECK(ft.top() == std.top());
    CHECK(ft.top() == 2);

    std.pop();
    ft.pop();

    CHECK(ft.top() == std.top());
    CHECK(ft.top() == 1);

    std.pop();
    ft.pop();

    CHECK(ft.top() == std.top());
    CHECK(ft.top() == 0);
}

TEST_CASE("test stack pop() sucessfully pops 3 to 1 with std::deque underlying container")
{
    ft::stack<int, std::deque<int> >  ft;
    std::stack<int, std::deque<int> > std;

    for (int i = 0; i < 4; ++i) {
        std.push(i);
        ft.push(i);
    }

    std.pop();
    ft.pop();

    CHECK(ft.top() == std.top());
    CHECK(ft.top() == 2);

    std.pop();
    ft.pop();

    CHECK(ft.top() == std.top());
    CHECK(ft.top() == 1);

    std.pop();
    ft.pop();

    CHECK(ft.top() == std.top());
    CHECK(ft.top() == 0);
}

TEST_CASE("test stack pop() decreases size by 1 with default underlying container")
{
    ft::stack<int>  ft;
    std::stack<int> std;

    std.push(42);
    ft.push(42);

    std.pop();
    ft.pop();

    CHECK(ft.size() == std.size());
    CHECK(ft.size() == 0);
}

TEST_CASE("test stack pop() decreases size by 1 with std::vector underlying container")
{
    ft::stack<int, std::vector<int> >  ft;
    std::stack<int, std::vector<int> > std;

    std.push(42);
    ft.push(42);

    std.pop();
    ft.pop();

    CHECK(ft.size() == std.size());
    CHECK(ft.size() == 0);
}

TEST_CASE("test stack pop() decreases size by 1 with std::deque underlying container")
{
    ft::stack<int, std::deque<int> >  ft;
    std::stack<int, std::deque<int> > std;

    std.push(42);
    ft.push(42);

    std.pop();
    ft.pop();

    CHECK(ft.size() == std.size());
    CHECK(ft.size() == 0);
}

TEST_CASE("test stack pop() empties stack if pop all items with default underlying container")
{
    ft::stack<int>  ft;
    std::stack<int> std;

    for (int i = 0; i < 10; ++i) {
        std.push(i);
        ft.push(i);
    }

    for (int i = 0; i < 10; ++i) {
        std.pop();
        ft.pop();
    }

    CHECK(ft.size() == std.size());
    CHECK(ft.empty() == std.empty());
    CHECK(ft.size() == 0);
    CHECK(ft.empty() == true);
}

TEST_CASE("test stack pop() empties stack if pop all items with std::vector underlying container")
{
    ft::stack<int, std::vector<int> >  ft;
    std::stack<int, std::vector<int> > std;

    for (int i = 0; i < 10; ++i) {
        std.push(i);
        ft.push(i);
    }

    for (int i = 0; i < 10; ++i) {
        std.pop();
        ft.pop();
    }

    CHECK(ft.size() == std.size());
    CHECK(ft.empty() == std.empty());
    CHECK(ft.size() == 0);
    CHECK(ft.empty() == true);
}

TEST_CASE("test stack pop() empties stack if pop all items with std::deque underlying container")
{
    ft::stack<int, std::deque<int> >  ft;
    std::stack<int, std::deque<int> > std;

    for (int i = 0; i < 10; ++i) {
        std.push(i);
        ft.push(i);
    }

    for (int i = 0; i < 10; ++i) {
        std.pop();
        ft.pop();
    }

    CHECK(ft.size() == std.size());
    CHECK(ft.empty() == std.empty());
    CHECK(ft.size() == 0);
    CHECK(ft.empty() == true);
}
