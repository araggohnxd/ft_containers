/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack_non_member.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:06:12 by maolivei          #+#    #+#             */
/*   Updated: 2023/02/19 20:13:17 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.hpp"

static ft::vector<int> base_vec(10, 42);

static ft::stack<int> base_stack(base_vec);

TEST_CASE("test map operator== equal maps returns true")
{
    ft::stack<int> ft(base_vec);

    CHECK((ft == base_stack) == true);
}

TEST_CASE("test map operator== different maps returns false")
{
    ft::stack<int> ft;

    CHECK((ft == base_stack) == false);
}

TEST_CASE("test map operator!= equal maps returns false")
{
    ft::stack<int> ft(base_vec);

    CHECK((ft != base_stack) == false);
}

TEST_CASE("test map operator!= different maps returns true")
{
    ft::stack<int> ft;

    CHECK((ft != base_stack) == true);
}

TEST_CASE("test map operator> equal maps returns false")
{
    ft::stack<int> ft(base_vec);

    CHECK((ft > base_stack) == false);
}

TEST_CASE("test map operator> different maps returns true when lhs is greater")
{
    ft::stack<int> ft;

    CHECK((base_stack > ft) == true);
}

TEST_CASE("test map operator> different maps returns false when lhs is lesser")
{
    ft::stack<int> ft;

    CHECK((ft > base_stack) == false);
}

TEST_CASE("test map operator< equal maps returns false")
{
    ft::stack<int> ft(base_vec);

    CHECK((ft < base_stack) == false);
}

TEST_CASE("test map operator< different maps returns false when lhs is greater")
{
    ft::stack<int> ft;

    CHECK((base_stack < ft) == false);
}

TEST_CASE("test map operator< different maps returns true when lhs is lesser")
{
    ft::stack<int> ft;

    CHECK((ft < base_stack) == true);
}

TEST_CASE("test map operator>= equal maps returns true")
{
    ft::stack<int> ft(base_vec);

    CHECK((ft >= base_stack) == true);
}

TEST_CASE("test map operator>= different maps returns true when lhs is greater")
{
    ft::stack<int> ft;

    CHECK((base_stack >= ft) == true);
}

TEST_CASE("test map operator>= different maps returns false when lhs is lesser")
{
    ft::stack<int> ft;

    CHECK((ft >= base_stack) == false);
}

TEST_CASE("test map operator<= equal maps returns true")
{
    ft::stack<int> ft(base_vec);

    CHECK((ft <= base_stack) == true);
}

TEST_CASE("test map operator<= different maps returns false when lhs is greater")
{
    ft::stack<int> ft;

    CHECK((base_stack <= ft) == false);
}

TEST_CASE("test map operator<= different maps returns true when lhs is lesser")
{
    ft::stack<int> ft;

    CHECK((ft <= base_stack) == true);
}
