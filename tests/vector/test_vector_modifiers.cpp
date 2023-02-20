/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_modifiers.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:08:52 by maolivei          #+#    #+#             */
/*   Updated: 2023/02/20 13:37:33 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.hpp"

TEST_CASE("test vector assign() non-templated with 10 items in int vector")
{
    std::vector<int> std(10, 42);
    ft::vector<int>  ft(10, 42);

    std.assign(10, 21);
    ft.assign(10, 21);

    compare_vectors(ft, std);
}

TEST_CASE("test vector assign() non-templated with 10 items in string vector")
{
    std::vector<std::string> std(10, "foo");
    ft::vector<std::string>  ft(10, "foo");

    std.assign(10, "bar");
    ft.assign(10, "bar");

    compare_vectors(ft, std);
}

TEST_CASE("test vector assign() templated with int array")
{
    int const    n[]      = {2, 3, 5, 7, 11, 13, 17};
    const size_t n_length = sizeof(n) / sizeof(n[0]);

    std::vector<int> std(10, 42);
    ft::vector<int>  ft(10, 42);

    std.assign(n, (n + n_length));
    ft.assign(n, (n + n_length));

    compare_vectors(ft, std);
}

TEST_CASE("test vector assign() templated from int vector")
{
    std::vector<int> base(10, 21);

    std::vector<int> std(10, 42);
    ft::vector<int>  ft(10, 42);

    std.assign(base.begin(), base.end());
    ft.assign(base.begin(), base.end());

    compare_vectors(ft, std);
}

TEST_CASE("test vector assign() templated with string array")
{
    std::string const n[]      = {"foo", "bar", "baz", "fizz", "buzz"};
    const size_t      n_length = sizeof(n) / sizeof(n[0]);

    std::vector<std::string> std(10, "foo");
    ft::vector<std::string>  ft(10, "foo");

    std.assign(n, (n + n_length));
    ft.assign(n, (n + n_length));

    compare_vectors(ft, std);
}

TEST_CASE("test vector assign() templated from string vector")
{
    std::vector<std::string> base(10, "bar");

    std::vector<std::string> std(10, "foo");
    ft::vector<std::string>  ft(10, "foo");

    std.assign(base.begin(), base.end());
    ft.assign(base.begin(), base.end());

    compare_vectors(ft, std);
}

TEST_CASE("test vector assign() templated from string object")
{
    std::string base("foo bar baz fizz buzz");

    std::vector<char> std(10, 42);
    ft::vector<char>  ft(10, 42);

    std.assign(base.begin(), base.end());
    ft.assign(base.begin(), base.end());

    compare_vectors(ft, std);
}

TEST_CASE("test vector assign() max size elements should throw bad_alloc")
{
    ft::vector<int> ft(10, 42);

    CHECK_THROWS_AS(ft.assign(ft.max_size(), 21), std::bad_alloc);
}

TEST_CASE("test vector assign() more than max size elements should throw length_error")
{
    ft::vector<int> ft(10, 42);

    CHECK_THROWS_AS(ft.assign(ft.max_size() + 1, 21), std::length_error);
}

TEST_CASE("test vector assign() try to assign -1 should throw length_error")
{
    ft::vector<int> ft(10, 42);

    CHECK_THROWS_AS(ft.assign(-1, 21), std::length_error);
}

TEST_CASE("test vector assign() non-template size and capacity are increased properly after assign")
{
    std::vector<int> std(10, 42);
    ft::vector<int>  ft(10, 42);

    CHECK(ft.size() == std.size());
    CHECK(ft.capacity() == std.capacity());
    std.assign(42, 21);
    ft.assign(42, 21);
    CHECK(ft.size() == std.size());
    CHECK(ft.capacity() == std.capacity());
    std.assign(21, 42);
    ft.assign(21, 42);
    CHECK(ft.size() == std.size());
    CHECK(ft.capacity() == std.capacity());
}

TEST_CASE("test vector assign() template size and capacity are increased properly after assign")
{
    std::vector<int> base1(42, 21);
    std::vector<int> base2(21, 42);

    std::vector<int> std(10, 42);
    ft::vector<int>  ft(10, 42);

    CHECK(ft.size() == std.size());
    CHECK(ft.capacity() == std.capacity());
    std.assign(base1.begin(), base1.end());
    ft.assign(base1.begin(), base1.end());
    CHECK(ft.size() == std.size());
    CHECK(ft.capacity() == std.capacity());
    std.assign(base2.begin(), base2.end());
    ft.assign(base2.begin(), base2.end());
    CHECK(ft.size() == std.size());
    CHECK(ft.capacity() == std.capacity());
}

TEST_CASE("test vector push_back() push 10 new items to int vector")
{
    std::vector<int> std(10, 42);
    ft::vector<int>  ft(10, 42);

    for (size_t i = 0; i < 10; ++i) {
        std.push_back(i);
        ft.push_back(i);
    }

    compare_vectors(ft, std);
}

TEST_CASE("test vector push_back() push 10 new items to string vector")
{
    std::string const n[]      = {"foo", "bar", "baz", "fizz", "buzz"};
    const size_t      n_length = sizeof(n) / sizeof(n[0]);

    std::vector<std::string> std(10, "foo");
    ft::vector<std::string>  ft(10, "foo");

    for (size_t i = 0; i < 10; ++i) {
        std.push_back(n[i % n_length]);
        ft.push_back(n[i % n_length]);
    }

    compare_vectors(ft, std);
}

TEST_CASE("test vector push_back() push 1000 new items to int vector")
{
    std::vector<int> std(10, 42);
    ft::vector<int>  ft(10, 42);

    for (size_t i = 0; i < 1000; ++i) {
        std.push_back(i);
        ft.push_back(i);
    }

    compare_vectors(ft, std);
}

TEST_CASE("test vector push_back() push 1000 new items to string vector")
{
    std::string const n[]      = {"foo", "bar", "baz", "fizz", "buzz"};
    const size_t      n_length = sizeof(n) / sizeof(n[0]);

    std::vector<std::string> std(10, "foo");
    ft::vector<std::string>  ft(10, "foo");

    for (size_t i = 0; i < 1000; ++i) {
        std.push_back(n[i % n_length]);
        ft.push_back(n[i % n_length]);
    }

    compare_vectors(ft, std);
}

TEST_CASE("test vector pop_back() pop 10 items from int vector")
{
    std::vector<int> std(100, 42);
    ft::vector<int>  ft(100, 42);

    for (size_t i = 0; i < 10; ++i) {
        std.pop_back();
        ft.pop_back();
    }

    compare_vectors(ft, std);
}

TEST_CASE("test vector pop_back() pop 1000 items from int vector")
{
    std::vector<int> std(10000, 42);
    ft::vector<int>  ft(10000, 42);

    for (size_t i = 0; i < 1000; ++i) {
        std.pop_back();
        ft.pop_back();
    }

    compare_vectors(ft, std);
}

TEST_CASE("test vector pop_back() pop 10 items from int vector of size 10 should make it empty")
{
    std::vector<int> std(10, 42);
    ft::vector<int>  ft(10, 42);

    for (size_t i = 0; i < 10; ++i) {
        std.pop_back();
        ft.pop_back();
    }

    compare_vectors(ft, std);
}

TEST_CASE("test vector pop_back() pop 10 items from string vector")
{
    std::vector<std::string> std(100, "foo");
    ft::vector<std::string>  ft(100, "foo");

    for (size_t i = 0; i < 10; ++i) {
        std.pop_back();
        ft.pop_back();
    }

    compare_vectors(ft, std);
}

TEST_CASE("test vector pop_back() pop 1000 items from string vector")
{
    std::vector<std::string> std(10000, "foo");
    ft::vector<std::string>  ft(10000, "foo");

    for (size_t i = 0; i < 1000; ++i) {
        std.pop_back();
        ft.pop_back();
    }

    compare_vectors(ft, std);
}

TEST_CASE("test vector pop_back() pop 10 items from string vector of size 10 should make it empty")
{
    std::vector<std::string> std(10, "foo");
    ft::vector<std::string>  ft(10, "foo");

    for (size_t i = 0; i < 10; ++i) {
        std.pop_back();
        ft.pop_back();
    }

    compare_vectors(ft, std);
}

TEST_CASE("test vector pop_back() pop from empty vector does nothing")
{
    std::vector<int> std;
    ft::vector<int>  ft;

    compare_vectors(ft, std);

    ft.pop_back();

    compare_vectors(ft, std);
}

TEST_CASE("test vector insert() single element at begin of int vector")
{
    std::vector<int> std(10, 42);
    ft::vector<int>  ft(10, 42);

    std.insert(std.begin(), 21);
    ft.insert(ft.begin(), 21);

    compare_vectors(ft, std);
}

TEST_CASE("test vector insert() single element at end of int vector")
{
    std::vector<int> std(10, 42);
    ft::vector<int>  ft(10, 42);

    std.insert(std.end(), 21);
    ft.insert(ft.end(), 21);

    compare_vectors(ft, std);
}

TEST_CASE("test vector insert() single element at middle of int vector")
{
    std::vector<int> std(10, 42);
    ft::vector<int>  ft(10, 42);

    std.insert((std.begin() + (std.size() / 2)), 21);
    ft.insert((ft.begin() + (ft.size() / 2)), 21);

    compare_vectors(ft, std);
}

TEST_CASE("test vector insert() multiple elements one at a time in int vector")
{
    std::vector<int> std(10, 42);
    ft::vector<int>  ft(10, 42);

    for (size_t i = 0; i < 10; ++i) {
        std.insert((std.begin() + i), i);
        ft.insert((ft.begin() + i), i);
    }

    compare_vectors(ft, std);
}

TEST_CASE("test vector insert() non-templated 10 items to begin of int vector")
{
    std::vector<int> std(10, 42);
    ft::vector<int>  ft(10, 42);

    std.insert(std.begin(), 10, 21);
    ft.insert(ft.begin(), 10, 21);

    compare_vectors(ft, std);
}

TEST_CASE("test vector insert() non-templated 10 items to end of int vector")
{
    std::vector<int> std(10, 42);
    ft::vector<int>  ft(10, 42);

    std.insert(std.end(), 10, 21);
    ft.insert(ft.end(), 10, 21);

    compare_vectors(ft, std);
}

TEST_CASE("test vector insert() non-templated 10 items to middle of int vector")
{
    std::vector<int> std(10, 42);
    ft::vector<int>  ft(10, 42);

    std.insert((std.begin() + (std.size() / 2)), 10, 21);
    ft.insert((ft.begin() + (ft.size() / 2)), 10, 21);

    compare_vectors(ft, std);
}

TEST_CASE("test vector insert() non-templated 10 items to begin of string vector")
{
    std::vector<std::string> std(10, "foo");
    ft::vector<std::string>  ft(10, "foo");

    std.insert(std.begin(), 10, "bar");
    ft.insert(ft.begin(), 10, "bar");

    compare_vectors(ft, std);
}

TEST_CASE("test vector insert() non-templated 10 items to end of string vector")
{
    std::vector<std::string> std(10, "foo");
    ft::vector<std::string>  ft(10, "foo");

    std.insert(std.end(), 10, "bar");
    ft.insert(ft.end(), 10, "bar");

    compare_vectors(ft, std);
}

TEST_CASE("test vector insert() non-templated 10 items to middle of string vector")
{
    std::vector<std::string> std(10, "foo");
    ft::vector<std::string>  ft(10, "foo");

    std.insert((std.begin() + (std.size() / 2)), 10, "bar");
    ft.insert((ft.begin() + (ft.size() / 2)), 10, "bar");

    compare_vectors(ft, std);
}

TEST_CASE("test vector insert() non-templated 0 items should do nothing")
{
    std::vector<int> std(10, 42);
    ft::vector<int>  ft(10, 42);

    compare_vectors(ft, std);

    ft.insert(ft.begin(), 0, 21);

    compare_vectors(ft, std);
}

TEST_CASE("test vector insert() templated add items to begin of int vector from int array")
{
    int const    n[]      = {2, 3, 5, 7, 11, 13, 17};
    const size_t n_length = sizeof(n) / sizeof(n[0]);

    std::vector<int> std(1, 42);
    ft::vector<int>  ft(1, 42);

    std.insert(std.begin(), n, (n + n_length));
    ft.insert(ft.begin(), n, (n + n_length));

    compare_vectors(ft, std);
}

TEST_CASE("test vector insert() templated add items to begin of int vector from int vector")
{
    std::vector<int> base(42, 21);

    std::vector<int> std(10, 42);
    ft::vector<int>  ft(10, 42);

    std.insert(std.begin(), base.begin(), base.end());
    ft.insert(ft.begin(), base.begin(), base.end());

    compare_vectors(ft, std);
}

TEST_CASE("test vector insert() templated add items to end of int vector from int array")
{
    int const    n[]      = {2, 3, 5, 7, 11, 13, 17};
    const size_t n_length = sizeof(n) / sizeof(n[0]);

    std::vector<int> std(10, 42);
    ft::vector<int>  ft(10, 42);

    std.insert(std.end(), n, (n + n_length));
    ft.insert(ft.end(), n, (n + n_length));

    compare_vectors(ft, std);
}

TEST_CASE("test vector insert() templated add items to end of int vector from int vector")
{
    std::vector<int> base(42, 21);

    std::vector<int> std(10, 42);
    ft::vector<int>  ft(10, 42);

    std.insert(std.end(), base.begin(), base.end());
    ft.insert(ft.end(), base.begin(), base.end());

    compare_vectors(ft, std);
}

TEST_CASE("test vector insert() templated add items to middle of int vector from int array")
{
    int const    n[]      = {2, 3, 5, 7, 11, 13, 17};
    const size_t n_length = sizeof(n) / sizeof(n[0]);

    std::vector<int> std(10, 42);
    ft::vector<int>  ft(10, 42);

    std.insert((std.begin() + (std.size() / 2)), n, (n + n_length));
    ft.insert((ft.begin() + (ft.size() / 2)), n, (n + n_length));

    compare_vectors(ft, std);
}

TEST_CASE("test vector insert() templated add items to middle of int vector from int vector")
{
    std::vector<int> base(42, 21);

    std::vector<int> std(10, 42);
    ft::vector<int>  ft(10, 42);

    std.insert((std.begin() + (std.size() / 2)), base.begin(), base.end());
    ft.insert((ft.begin() + (ft.size() / 2)), base.begin(), base.end());

    compare_vectors(ft, std);
}

TEST_CASE("test vector insert() templated add items to begin of string vector from string array")
{
    std::string const n[]      = {"foo", "bar", "baz", "fizz", "buzz"};
    const size_t      n_length = sizeof(n) / sizeof(n[0]);

    std::vector<std::string> std(1, "foo");
    ft::vector<std::string>  ft(1, "foo");

    std.insert(std.begin(), n, (n + n_length));
    ft.insert(ft.begin(), n, (n + n_length));

    compare_vectors(ft, std);
}

TEST_CASE("test vector insert() templated add items to begin of string vector from string vector")
{
    std::vector<std::string> base(42, "bar");

    std::vector<std::string> std(10, "foo");
    ft::vector<std::string>  ft(10, "foo");

    std.insert(std.begin(), base.begin(), base.end());
    ft.insert(ft.begin(), base.begin(), base.end());

    compare_vectors(ft, std);
}

TEST_CASE("test vector insert() templated add items to end of string vector from string array")
{
    std::string const n[]      = {"foo", "bar", "baz", "fizz", "buzz"};
    const size_t      n_length = sizeof(n) / sizeof(n[0]);

    std::vector<std::string> std(10, "foo");
    ft::vector<std::string>  ft(10, "foo");

    std.insert(std.end(), n, (n + n_length));
    ft.insert(ft.end(), n, (n + n_length));

    compare_vectors(ft, std);
}

TEST_CASE("test vector insert() templated add items to end of string vector from string vector")
{
    std::vector<std::string> base(42, "bar");

    std::vector<std::string> std(10, "foo");
    ft::vector<std::string>  ft(10, "foo");

    std.insert(std.end(), base.begin(), base.end());
    ft.insert(ft.end(), base.begin(), base.end());

    compare_vectors(ft, std);
}

TEST_CASE("test vector insert() templated add items to middle of string vector from string array")
{
    std::string const n[]      = {"foo", "bar", "baz", "fizz", "buzz"};
    const size_t      n_length = sizeof(n) / sizeof(n[0]);

    std::vector<std::string> std(10, "foo");
    ft::vector<std::string>  ft(10, "foo");

    std.insert((std.begin() + (std.size() / 2)), n, (n + n_length));
    ft.insert((ft.begin() + (ft.size() / 2)), n, (n + n_length));

    compare_vectors(ft, std);
}

TEST_CASE("test vector insert() templated add items to middle of string vector from string vector")
{
    std::vector<std::string> base(42, "bar");

    std::vector<std::string> std(10, "foo");
    ft::vector<std::string>  ft(10, "foo");

    std.insert((std.begin() + (std.size() / 2)), base.begin(), base.end());
    ft.insert((ft.begin() + (ft.size() / 2)), base.begin(), base.end());

    compare_vectors(ft, std);
}

TEST_CASE("test vector insert() templated add items to begin of string vector from string object")
{
    std::string base("foo bar baz fizz buzz");

    std::vector<char> std(10, 42);
    ft::vector<char>  ft(10, 42);

    std.insert(std.begin(), base.begin(), base.end());
    ft.insert(ft.begin(), base.begin(), base.end());

    compare_vectors(ft, std);
}

TEST_CASE("test vector insert() templated 0 items should do nothing")
{
    std::vector<int> base(42, 21);

    std::vector<int> std(10, 42);
    ft::vector<int>  ft(10, 42);

    compare_vectors(ft, std);

    ft.insert(ft.begin(), base.begin(), base.begin());

    compare_vectors(ft, std);
}

TEST_CASE("test vector insert() returns the correct iterator")
{
    std::vector<int> std(10);
    ft::vector<int>  ft(10);

    for (size_t i = 0; i < 10; ++i) {
        std.push_back(i);
        ft.push_back(i);
    }
    CHECK(*ft.insert(ft.begin(), 42) == *std.insert(std.begin(), 42));
    CHECK(*ft.insert(ft.end(), 21) == *std.insert(std.end(), 21));
    CHECK(*ft.insert(ft.begin() + 5, 123) == *std.insert(std.begin() + 5, 123));
}

TEST_CASE("test vector erase() single item from begin of int vector")
{
    std::vector<int> std(10, 42);
    ft::vector<int>  ft(10, 42);

    std.erase(std.begin());
    ft.erase(ft.begin());

    compare_vectors(ft, std);
}

TEST_CASE("test vector erase() single item from end of int vector")
{
    std::vector<int> std(10, 42);
    ft::vector<int>  ft(10, 42);

    std.erase(std.end() - 1);
    ft.erase(ft.end() - 1);

    compare_vectors(ft, std);
}

TEST_CASE("test vector erase() single item from middle of int vector")
{
    std::vector<int> std(10, 42);
    ft::vector<int>  ft(10, 42);

    std.erase(std.begin() + (std.size() / 2));
    ft.erase(ft.begin() + (ft.size() / 2));

    compare_vectors(ft, std);
}

TEST_CASE("test vector erase() range of items starting at begin of int vector")
{
    std::vector<int> std(10, 42);
    ft::vector<int>  ft(10, 42);

    std.erase(std.begin(), std.begin() + 5);
    ft.erase(ft.begin(), ft.begin() + 5);

    compare_vectors(ft, std);
}

TEST_CASE("test vector erase() range of items starting at middle of int vector")
{
    std::vector<int> std(10, 42);
    ft::vector<int>  ft(10, 42);

    std.erase(std.begin() + 5, std.end());
    ft.erase(ft.begin() + 5, ft.end());

    compare_vectors(ft, std);
}

TEST_CASE("test vector erase() single item from begin of int vector")
{
    std::vector<std::string> std(10, "foo");
    ft::vector<std::string>  ft(10, "foo");

    std.erase(std.begin());
    ft.erase(ft.begin());

    compare_vectors(ft, std);
}

TEST_CASE("test vector erase() single item from end of int vector")
{
    std::vector<std::string> std(10, "foo");
    ft::vector<std::string>  ft(10, "foo");

    std.erase(std.end() - 1);
    ft.erase(ft.end() - 1);

    compare_vectors(ft, std);
}

TEST_CASE("test vector erase() single item from middle of int vector")
{
    std::vector<std::string> std(10, "foo");
    ft::vector<std::string>  ft(10, "foo");

    std.erase(std.begin() + (std.size() / 2));
    ft.erase(ft.begin() + (ft.size() / 2));

    compare_vectors(ft, std);
}

TEST_CASE("test vector erase() range of items starting at begin of int vector")
{
    std::vector<std::string> std(10, "foo");
    ft::vector<std::string>  ft(10, "foo");

    std.erase(std.begin(), std.begin() + 5);
    ft.erase(ft.begin(), ft.begin() + 5);

    compare_vectors(ft, std);
}

TEST_CASE("test vector erase() range of items starting at middle of int vector")
{
    std::vector<std::string> std(10, "foo");
    ft::vector<std::string>  ft(10, "foo");

    std.erase(std.begin() + 5, std.end());
    ft.erase(ft.begin() + 5, ft.end());

    compare_vectors(ft, std);
}

TEST_CASE("test vector erase() empty range should do nothing")
{
    std::vector<int> std(10, 42);
    ft::vector<int>  ft(10, 42);

    ft.erase(ft.begin(), ft.begin());

    compare_vectors(ft, std);
}

TEST_CASE("test vector erase() empty vector should do nothing")
{
    std::vector<int> std;
    ft::vector<int>  ft;

    ft.erase(ft.begin(), ft.begin());

    compare_vectors(ft, std);
}

TEST_CASE("test vector erase() single element returns correct iterator")
{
    std::vector<int> std(42);
    ft::vector<int>  ft(42);

    for (size_t i = 0; i < 42; ++i) {
        std.push_back(i);
        ft.push_back(i);
    }
    CHECK(*ft.erase(ft.begin()) == *std.erase(std.begin()));
    CHECK(*ft.erase(ft.begin() + 5) == *std.erase(std.begin() + 5));
    CHECK(*ft.erase(ft.end() - 1) == *std.erase(std.end() - 1));
}

TEST_CASE("test vector erase() range of elements returns correct iterator")
{
    std::vector<int> std(42);
    ft::vector<int>  ft(42);

    for (size_t i = 0; i < 42; ++i) {
        std.push_back(i);
        ft.push_back(i);
    }
    CHECK(*ft.erase(ft.begin(), ft.begin() + 10) == *std.erase(std.begin(), std.begin() + 10));
    CHECK(*ft.erase(ft.begin() + 10, ft.end()) == *std.erase(std.begin() + 10, std.end()));
}

TEST_CASE("test vector erase() all elements should leave vector empty")
{
    std::vector<int> std(10, 42);
    ft::vector<int>  ft(10, 42);

    std.erase(std.begin(), std.end());
    ft.erase(ft.begin(), ft.end());

    compare_vectors(ft, std);
    CHECK(ft.size() == 0);
    CHECK(ft.empty() == true);
}

TEST_CASE("test vector swap() properly copies values from same size int vector")
{
    std::vector<int> base_std(10, 42);
    ft::vector<int>  base_ft(10, 42);

    std::vector<int> std(10, 21);
    ft::vector<int>  ft(10, 21);

    std.swap(base_std);
    ft.swap(base_ft);

    compare_vectors(ft, std);
}

TEST_CASE("test vector swap() properly copies values from bigger size int vector")
{
    std::vector<int> base_std(100, 42);
    ft::vector<int>  base_ft(100, 42);

    std::vector<int> std(10, 21);
    ft::vector<int>  ft(10, 21);

    std.swap(base_std);
    ft.swap(base_ft);

    compare_vectors(ft, std);
}

TEST_CASE("test vector swap() properly copies values from smaller size int vector")
{
    std::vector<int> base_std(1, 42);
    ft::vector<int>  base_ft(1, 42);

    std::vector<int> std(10, 21);
    ft::vector<int>  ft(10, 21);

    std.swap(base_std);
    ft.swap(base_ft);
    CHECK(ft.size() == std.size());
    CHECK(ft.capacity() == std.capacity());

    compare_vectors(ft, std);
}

TEST_CASE("test vector swap() properly copies values from same size string vector")
{
    std::vector<std::string> base_std(10, "foo");
    ft::vector<std::string>  base_ft(10, "foo");

    std::vector<std::string> std(10, "bar");
    ft::vector<std::string>  ft(10, "bar");

    std.swap(base_std);
    ft.swap(base_ft);
    CHECK(ft.size() == std.size());
    CHECK(ft.capacity() == std.capacity());

    compare_vectors(ft, std);
}

TEST_CASE("test vector swap() properly copies values from bigger size string vector")
{
    std::vector<std::string> base_std(100, "foo");
    ft::vector<std::string>  base_ft(100, "foo");

    std::vector<std::string> std(10, "bar");
    ft::vector<std::string>  ft(10, "bar");

    std.swap(base_std);
    ft.swap(base_ft);
    CHECK(ft.size() == std.size());
    CHECK(ft.capacity() == std.capacity());

    compare_vectors(ft, std);
}

TEST_CASE("test vector swap() properly copies values from smaller size string vector")
{
    std::vector<std::string> base_std(1, "foo");
    ft::vector<std::string>  base_ft(1, "foo");

    std::vector<std::string> std(10, "bar");
    ft::vector<std::string>  ft(10, "bar");

    std.swap(base_std);
    ft.swap(base_ft);
    CHECK(ft.size() == std.size());
    CHECK(ft.capacity() == std.capacity());

    compare_vectors(ft, std);
}

TEST_CASE("test vector swap() assert that swap creates a deep copy")
{
    std::vector<int> base_std(10, 42);
    ft::vector<int>  base_ft(10, 42);

    std::vector<int> std(10, 21);
    ft::vector<int>  ft(10, 21);

    std.swap(base_std);
    std.insert(std.begin() + 5, 10, 123);

    ft.swap(base_ft);
    ft.insert(ft.begin() + 5, 10, 123);

    CHECK_FALSE(std.size() == base_std.size());
    CHECK_FALSE(std.capacity() == base_std.capacity());
    CHECK_FALSE(std::equal(std.begin(), std.end(), base_std.begin()));
    CHECK_FALSE(std::equal(base_std.begin(), base_std.end(), std.begin()));

    CHECK_FALSE(ft.size() == base_ft.size());
    CHECK_FALSE(ft.capacity() == base_ft.capacity());
    CHECK_FALSE(std::equal(ft.begin(), ft.end(), base_ft.begin()));
    CHECK_FALSE(std::equal(base_ft.begin(), base_ft.end(), ft.begin()));
}

TEST_CASE("test vector clear() leaves the vector empty")
{
    std::vector<int> std(10, 42);
    ft::vector<int>  ft(10, 42);

    std.clear();
    ft.clear();

    compare_vectors(ft, std);
    CHECK(ft.size() == 0);
    CHECK(ft.empty() == true);
}

TEST_CASE("test vector clear() empty vector should do nothing")
{
    std::vector<int> std;
    ft::vector<int>  ft;

    ft.clear();

    compare_vectors(ft, std);
    CHECK(ft.size() == 0);
    CHECK(ft.empty() == true);
}
