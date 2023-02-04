/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_element_access.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:48:39 by maolivei          #+#    #+#             */
/*   Updated: 2023/02/03 20:44:38 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.hpp"

TEST_CASE("test vector operator[] element reading in int vector")
{
    std::vector<int> std(10, 42);
    ft::vector<int>  ft(10, 42);

    for (size_t i = 0; i < 10; ++i)
        CHECK(ft[i] == std[i]);
}

TEST_CASE("test vector operator[] element writing in int vector")
{
    std::vector<int> std(10);
    ft::vector<int>  ft(10);

    for (size_t i = 0; i < 10; ++i) {
        ft[i]  = i;
        std[i] = i;
    }
    for (size_t i = 0; i < 10; ++i)
        CHECK(ft[i] == std[i]);
}

TEST_CASE("test vector operator[] element reading in string vector")
{
    std::vector<std::string> std(10, "foo");
    ft::vector<std::string>  ft(10, "foo");

    for (size_t i = 0; i < 10; ++i)
        CHECK(ft[i] == std[i]);
}

TEST_CASE("test vector operator[] element writing in string vector")
{
    char const *c[] = {"foo", "bar", "baz", "fizz", "buzz"};

    std::vector<std::string> std(5);
    ft::vector<std::string>  ft(5);

    for (size_t i = 0; i < 5; ++i) {
        ft[i]  = c[i];
        std[i] = c[i];
    }
    for (size_t i = 0; i < 5; ++i)
        CHECK(ft[i] == std[i]);
}

/* If the container size is greater than n, the function never throws exceptions.
 * Otherwise, the behavior is undefined. */
TEST_CASE("test vector operator[] try to access index -1 should not throw")
{
    ft::vector<int> ft(10, 42);

    CHECK_NOTHROW(ft[-1]);
}

/* If the container size is greater than n, the function never throws exceptions.
 * Otherwise, the behavior is undefined. */
TEST_CASE("test vector operator[] try to access index equal to current size should not throw")
{
    ft::vector<int> ft(10, 42);

    CHECK_NOTHROW(ft[ft.size()]);
}

TEST_CASE("test vector at() element reading in int vector")
{
    std::vector<int> std(10, 42);
    ft::vector<int>  ft(10, 42);

    for (size_t i = 0; i < 10; ++i)
        CHECK(ft.at(i) == std.at(i));
}

TEST_CASE("test vector at() element writing in int vector")
{
    std::vector<int> std(10);
    ft::vector<int>  ft(10);

    for (size_t i = 0; i < 10; ++i) {
        ft.at(i)  = i;
        std.at(i) = i;
    }
    for (size_t i = 0; i < 10; ++i)
        CHECK(ft[i] == std[i]);
}

TEST_CASE("test vector operator[] element reading in string vector")
{
    std::vector<std::string> std(10, "foo");
    ft::vector<std::string>  ft(10, "foo");

    for (size_t i = 0; i < 10; ++i)
        CHECK(ft.at(i) == std.at(i));
}

TEST_CASE("test vector operator[] element writing in string vector")
{
    char const *c[] = {"foo", "bar", "baz", "fizz", "buzz"};

    std::vector<std::string> std(5);
    ft::vector<std::string>  ft(5);

    for (size_t i = 0; i < 5; ++i) {
        ft.at(i)  = c[i];
        std.at(i) = c[i];
    }
    for (size_t i = 0; i < 5; ++i)
        CHECK(ft.at(i) == std.at(i));
}

/* It throws out_of_range if n is out of bounds. */
TEST_CASE("test vector at() try to access index -1 should throw")
{
    ft::vector<int> ft(10, 42);

    CHECK_THROWS_AS(ft.at(-1), std::out_of_range);
}

/* It throws out_of_range if n is out of bounds. */
TEST_CASE("test vector at() try to access index equal to current size should throw")
{
    ft::vector<int> ft(10, 42);

    CHECK_THROWS_AS(ft.at(ft.size()), std::out_of_range);
}

TEST_CASE("test vector front() equals first element using operator[] and at()")
{
    ft::vector<int> ft(10, 42);

    CHECK(ft.front() == ft[0]);
    CHECK(ft.front() == ft.at(0));
}

TEST_CASE("test vector front() element reading front of int vector")
{
    std::vector<int> std(10, 42);
    ft::vector<int>  ft(10, 42);

    CHECK(ft.front() == std.front());
}

TEST_CASE("test vector front() element writing front of int vector")
{
    std::vector<int> std(10, 42);
    ft::vector<int>  ft(10, 42);

    std.front() = 21;
    ft.front()  = 21;
    CHECK(ft.front() == std.front());
    CHECK(ft.front() == 21);
}

TEST_CASE("test vector front() element reading front of string vector")
{
    std::vector<std::string> std(10, "foo");
    ft::vector<std::string>  ft(10, "foo");

    CHECK(ft.front() == std.front());
}

TEST_CASE("test vector front() element writing front of string vector")
{
    std::vector<std::string> std(10, "foo");
    ft::vector<std::string>  ft(10, "foo");

    std.front() = "bar";
    ft.front()  = "bar";
    CHECK(ft.front() == std.front());
    CHECK(ft.front() == "bar");
}

TEST_CASE("test vector back() equals first element using operator[] and at()")
{
    ft::vector<int> ft(10, 42);

    CHECK(ft.back() == ft[ft.size() - 1]);
    CHECK(ft.back() == ft.at(ft.size() - 1));
}

TEST_CASE("test vector back() element reading back of int vector")
{
    std::vector<int> std(10, 42);
    ft::vector<int>  ft(10, 42);

    CHECK(ft.back() == std.back());
}

TEST_CASE("test vector back() element writing back of int vector")
{
    std::vector<int> std(10, 42);
    ft::vector<int>  ft(10, 42);

    std.back() = 21;
    ft.back()  = 21;
    CHECK(ft.back() == std.back());
    CHECK(ft.back() == 21);
}

TEST_CASE("test vector back() element reading back of string vector")
{
    std::vector<std::string> std(10, "foo");
    ft::vector<std::string>  ft(10, "foo");

    CHECK(ft.back() == std.back());
}

TEST_CASE("test vector back() element writing back of string vector")
{
    std::vector<std::string> std(10, "foo");
    ft::vector<std::string>  ft(10, "foo");

    std.back() = "bar";
    ft.back()  = "bar";
    CHECK(ft.back() == std.back());
    CHECK(ft.back() == "bar");
}

TEST_CASE("test vector data() element access reading and writing using int vector")
{
    ft::vector<int>  ft(5);
    std::vector<int> std(5);

    int *ptr_ft  = ft.data();
    int *ptr_std = std.data();

    *ptr_ft = 10;
    ++ptr_ft;
    *ptr_ft   = 20;
    ptr_ft[2] = 100;

    *ptr_std = 10;
    ++ptr_std;
    *ptr_std   = 20;
    ptr_std[2] = 100;

    for (size_t i = 0; i < 5; ++i)
        CHECK(ft[i] == std[i]);
}

TEST_CASE("test vector data() element access reading and writing using string vector")
{
    ft::vector<std::string>  ft(5);
    std::vector<std::string> std(5);

    std::string *ptr_ft  = ft.data();
    std::string *ptr_std = std.data();

    *ptr_ft = "foo";
    ++ptr_ft;
    *ptr_ft   = "bar";
    ptr_ft[2] = "baz";

    *ptr_std = "foo";
    ++ptr_std;
    *ptr_std   = "bar";
    ptr_std[2] = "baz";

    for (size_t i = 0; i < 5; ++i)
        CHECK(ft[i] == std[i]);
}
