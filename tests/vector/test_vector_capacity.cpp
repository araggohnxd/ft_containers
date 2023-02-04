/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_capacity.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:22:48 by maolivei          #+#    #+#             */
/*   Updated: 2023/02/04 17:11:25 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.hpp"

TEST_CASE("test vector size int vector with 10 items")
{
    std::vector<int> std(10, 42);
    ft::vector<int>  ft(10, 42);

    CHECK(ft.size() == std.size());
}

TEST_CASE("test vector max size int vector with 10 items")
{
    std::vector<int> std(10, 42);
    ft::vector<int>  ft(10, 42);

    CHECK(ft.max_size() == std.max_size());
}

TEST_CASE("test vector resize check size before and after resizing with int")
{
    std::vector<int> std(10, 42);
    ft::vector<int>  ft(10, 42);

    CHECK(ft.size() == std.size());
    ft.resize(42, 21);
    std.resize(42, 21);
    CHECK(ft.size() == std.size());
}

TEST_CASE("test vector size string vector with 10 items")
{
    std::vector<std::string> std(10, "foo");
    ft::vector<std::string>  ft(10, "foo");

    CHECK(ft.size() == std.size());
}

TEST_CASE("test vector max size string vector with 10 items")
{
    std::vector<std::string> std(10, "foo");
    ft::vector<std::string>  ft(10, "foo");

    CHECK(ft.max_size() == std.max_size());
}

TEST_CASE("test vector resize check size before and after resizing with string")
{
    std::vector<std::string> std(10, "foo");
    ft::vector<std::string>  ft(10, "foo");

    CHECK(ft.size() == std.size());
    ft.resize(42, "bar");
    std.resize(42, "bar");
    CHECK(ft.size() == std.size());
}

TEST_CASE("test vector resize to a value equal to vector max size should throw")
{
    ft::vector<int> ft;

    CHECK_THROWS_AS(ft.resize(ft.max_size()), std::bad_alloc);
}

TEST_CASE("test vector resize check capacity doesn't change resizing to less than current capacity")
{
    std::vector<int> std(10, 42);
    ft::vector<int>  ft(10, 42);

    CHECK(ft.capacity() == std.capacity());
    CHECK(ft.capacity() == 10);
    ft.resize(1, 21);
    std.resize(1, 21);
    CHECK(ft.capacity() == std.capacity());
    CHECK(ft.capacity() == 10);
}

TEST_CASE("test vector capacity int vector with 10 items")
{
    std::vector<int> std(10, 42);
    ft::vector<int>  ft(10, 42);

    CHECK(ft.capacity() == std.capacity());
}

TEST_CASE("test vector resize check capacity before and after resizing with int")
{
    std::vector<int> std(10, 42);
    ft::vector<int>  ft(10, 42);

    CHECK(ft.capacity() == std.capacity());
    ft.resize(42, 21);
    std.resize(42, 21);
    CHECK(ft.capacity() == std.capacity());
}

TEST_CASE("test vector capacity string vector with 10 items")
{
    std::vector<std::string> std(10, "foo");
    ft::vector<std::string>  ft(10, "foo");

    CHECK(ft.capacity() == std.capacity());
}

TEST_CASE("test vector resize check capacity before and after resizing with string")
{
    std::vector<std::string> std(10, "foo");
    ft::vector<std::string>  ft(10, "foo");

    CHECK(ft.capacity() == std.capacity());
    ft.resize(42, "bar");
    std.resize(42, "bar");
    CHECK(ft.capacity() == std.capacity());
}

TEST_CASE("test vector created with default constructor is empty")
{
    std::vector<std::string> std;
    ft::vector<std::string>  ft;

    CHECK(ft.empty() == std.empty());
}

TEST_CASE("test vector created with default constructor is empty")
{
    std::vector<std::string> std;
    ft::vector<std::string>  ft;

    CHECK(ft.empty() == std.empty());
}

TEST_CASE("test vector created with fill constructor is not empty")
{
    std::vector<int> std(10, 42);
    ft::vector<int>  ft(10, 42);

    CHECK(ft.empty() == std.empty());
}

TEST_CASE("test vector created with default constructor is empty and it's size is zero")
{
    std::vector<std::string> std;
    ft::vector<std::string>  ft;

    CHECK(ft.empty() == std.empty());
    CHECK(ft.size() == std.size());
    CHECK(ft.size() == 0);
}

TEST_CASE("test vector created with default constructor is empty and it's capacity is zero")
{
    std::vector<std::string> std;
    ft::vector<std::string>  ft;

    CHECK(ft.empty() == std.empty());
    CHECK(ft.capacity() == std.capacity());
    CHECK(ft.capacity() == 0);
}

TEST_CASE("test vector reserve change empty vector capacity to 10")
{
    std::vector<std::string> std;
    ft::vector<std::string>  ft;

    CHECK(ft.empty() == std.empty());
    CHECK(ft.size() == std.size());
    CHECK(ft.capacity() == std.capacity());
    ft.reserve(10);
    std.reserve(10);
    CHECK(ft.empty() == std.empty());
    CHECK(ft.size() == std.size());
    CHECK(ft.capacity() == std.capacity());
}

TEST_CASE("test vector reserve check capacity doesn't change reserving less than current capacity")
{
    std::vector<int> std(10, 42);
    ft::vector<int>  ft(10, 42);

    CHECK(ft.capacity() == std.capacity());
    CHECK(ft.capacity() == 10);
    ft.reserve(1);
    std.reserve(1);
    CHECK(ft.capacity() == std.capacity());
    CHECK(ft.capacity() == 10);
}

TEST_CASE("test vector reserve a value equal to vector max size should throw")
{
    ft::vector<int> ft;

    CHECK_THROWS_AS(ft.reserve(ft.max_size()), std::bad_alloc);
}

TEST_CASE("test vector get_allocator() is the same as the standard one in int vector")
{
    std::vector<int> std(10, 42);
    ft::vector<int>  ft(10, 42);

    CHECK(std.get_allocator() == ft.get_allocator());
}

TEST_CASE("test vector get_allocator() is the same as the standard one in string vector")
{
    std::vector<std::string> std(10, "foo");
    ft::vector<std::string>  ft(10, "foo");

    CHECK(std.get_allocator() == ft.get_allocator());
}
