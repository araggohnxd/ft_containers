/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_iterators.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:04:48 by maolivei          #+#    #+#             */
/*   Updated: 2023/02/03 19:07:08 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.hpp"

TEST_CASE("test vector iterator iterating through int vector and comparing values")
{
    std::vector<int> std(10, 42);
    ft::vector<int>  ft(10, 42);

    std::vector<int>::iterator stdit = std.begin();
    ft::vector<int>::iterator  ftit  = ft.begin();

    while (stdit != std.end() && ftit != ft.end())
        CHECK(*ftit++ == *stdit++);
}

TEST_CASE("test vector const iterator iterating through int vector and comparing values")
{
    std::vector<int> std(10, 42);
    ft::vector<int>  ft(10, 42);

    std::vector<int>::const_iterator stdit = std.begin();
    ft::vector<int>::const_iterator  ftit  = ft.begin();

    while (stdit != std.end() && ftit != ft.end())
        CHECK(*ftit++ == *stdit++);
}

TEST_CASE("test vector iterator begin function with int vector")
{
    std::vector<int> std(10, 42);
    ft::vector<int>  ft(10, 42);

    CHECK(*(ft.begin()) == *(std.begin()));
    *(ft.begin())  = 21;
    *(std.begin()) = 21;
    CHECK(*(ft.begin()) == *(std.begin()));
}

TEST_CASE("test vector const iterator begin function with int vector")
{
    std::vector<int> const std(10, 42);
    ft::vector<int> const  ft(10, 42);

    CHECK(*(ft.begin()) == *(std.begin()));
    // *(ft.begin())  = 21; expression must be a modifiable lvalue
}

TEST_CASE("test vector iterator end function")
{
    std::vector<int> std(10, 42);
    ft::vector<int>  ft(10, 42);

    CHECK(*(ft.end() - 1) == *(std.end() - 1));
    *(ft.end() - 1)  = 21;
    *(std.end() - 1) = 21;
    CHECK(*(ft.end() - 1) == *(std.end() - 1));
}

TEST_CASE("test vector const iterator end function")
{
    std::vector<int> const std(10, 42);
    ft::vector<int> const  ft(10, 42);

    CHECK(*(ft.end() - 1) == *(std.end() - 1));
    // *(ft.end() - 1)  = 21; expression must be a modifiable lvalue
}

TEST_CASE("test vector iterator iterations from begin to end equals the vector size")
{
    ft::vector<int> ft(10, 42);
    size_t          ft_vec_size = 0;

    for (ft::vector<int>::iterator it = ft.begin(); it != ft.end(); ++it)
        ++ft_vec_size;
    CHECK(ft_vec_size == ft.size());
}

TEST_CASE("test vector const iterator iterations from begin to end equals the vector size")
{
    ft::vector<int> ft(10, 42);
    size_t          ft_vec_size = 0;

    for (ft::vector<int>::const_iterator it = ft.begin(); it != ft.end(); ++it)
        ++ft_vec_size;
    CHECK(ft_vec_size == ft.size());
}

TEST_CASE("test vector reverse iterator iterating through int vector and comparing values")
{
    std::vector<int> std(10, 42);
    ft::vector<int>  ft(10, 42);

    std::vector<int>::reverse_iterator stdit = std.rbegin();
    ft::vector<int>::reverse_iterator  ftit  = ft.rbegin();

    while (stdit != std.rend() && ftit != ft.rend())
        CHECK(*ftit++ == *stdit++);
}

TEST_CASE("test vector const reverse iterator iterating through int vector and comparing values")
{
    std::vector<int> std(10, 42);
    ft::vector<int>  ft(10, 42);

    std::vector<int>::const_reverse_iterator stdit = std.rbegin();
    ft::vector<int>::const_reverse_iterator  ftit  = ft.rbegin();

    while (stdit != std.rend() && ftit != ft.rend())
        CHECK(*ftit++ == *stdit++);
}

TEST_CASE("test vector reverse iterator begin function with int vector")
{
    std::vector<int> std(10, 42);
    ft::vector<int>  ft(10, 42);

    CHECK(*(ft.rbegin()) == *(std.rbegin()));
    *(ft.rbegin())  = 21;
    *(std.rbegin()) = 21;
    CHECK(*(ft.rbegin()) == *(std.rbegin()));
}

TEST_CASE("test vector const reverse iterator begin function with int vector")
{
    std::vector<int> const std(10, 42);
    ft::vector<int> const  ft(10, 42);

    CHECK(*(ft.rbegin()) == *(std.rbegin()));
    // *(ft.rbegin())  = 21; expression must be a modifiable lvalue
}

TEST_CASE("test vector reverse iterator end function")
{
    std::vector<int> std(10, 42);
    ft::vector<int>  ft(10, 42);

    CHECK(*(ft.rend() - 1) == *(std.rend() - 1));
    *(ft.rend() - 1)  = 21;
    *(std.rend() - 1) = 21;
    CHECK(*(ft.rend() - 1) == *(std.rend() - 1));
}

TEST_CASE("test vector const reverse iterator end function")
{
    std::vector<int> const std(10, 42);
    ft::vector<int> const  ft(10, 42);

    CHECK(*(ft.rend() - 1) == *(std.rend() - 1));
    // *(ft.rend() - 1)  = 21; expression must be a modifiable lvalue
}

TEST_CASE("test vector reverse iterator iterations from begin to end equals the vector size")
{
    ft::vector<int> ft(10, 42);
    size_t          ft_vec_size = 0;

    for (ft::vector<int>::reverse_iterator it = ft.rbegin(); it != ft.rend(); ++it)
        ++ft_vec_size;
    CHECK(ft_vec_size == ft.size());
}

TEST_CASE("test vector const reverse iterator iterations from begin to end equals the vector size")
{
    ft::vector<int> ft(10, 42);
    size_t          ft_vec_size = 0;

    for (ft::vector<int>::const_reverse_iterator it = ft.rbegin(); it != ft.rend(); ++it)
        ++ft_vec_size;
    CHECK(ft_vec_size == ft.size());
}
