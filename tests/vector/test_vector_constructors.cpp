/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_constructors.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:20:32 by maolivei          #+#    #+#             */
/*   Updated: 2023/02/20 13:28:54 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.hpp"

TEST_CASE("test vector default constructor")
{
    std::vector<int> std;
    ft::vector<int>  ft;

    compare_vectors(ft, std);
}

TEST_CASE("test vector non-templated parametric constructor of type int with 10 items")
{
    std::vector<int> std(10, 42);
    ft::vector<int>  ft(10, 42);

    compare_vectors(ft, std);
}

TEST_CASE("test vector non-templated parametric constructor of type int with 10000 items")
{
    std::vector<int> std(10000, 42);
    ft::vector<int>  ft(10000, 42);

    compare_vectors(ft, std);
}

TEST_CASE("test vector non-templated parametric constructor of type string with 10 items")
{
    std::vector<std::string> std(10, "foo");
    ft::vector<std::string>  ft(10, "foo");

    compare_vectors(ft, std);
}

TEST_CASE("test vector non-templated parametric constructor of type string with 10000 items")
{
    std::vector<std::string> std(10000, "foo");
    ft::vector<std::string>  ft(10000, "foo");

    compare_vectors(ft, std);
}

TEST_CASE("test vector templated parametric constructor with an int array")
{
    int const    n[]      = {2, 3, 5, 7, 11, 13, 17};
    const size_t n_length = sizeof(n) / sizeof(n[0]);

    std::vector<int> std(n, (n + n_length));
    ft::vector<int>  ft(n, (n + n_length));

    compare_vectors(ft, std);
}

TEST_CASE("test vector templated parametric constructor from a int vector")
{
    std::vector<int> base(10, 42);

    std::vector<int> std(base.begin(), base.end());
    ft::vector<int>  ft(base.begin(), base.end());

    compare_vectors(ft, std);
}

TEST_CASE("test vector templated parametric constructor with an string array")
{
    std::string const n[]      = {"foo", "bar", "baz", "fizz", "buzz"};
    const size_t      n_length = sizeof(n) / sizeof(n[0]);

    std::vector<std::string> std(n, (n + n_length));
    ft::vector<std::string>  ft(n, (n + n_length));

    compare_vectors(ft, std);
}

TEST_CASE("test vector templated parametric constructor from a string vector")
{
    std::vector<std::string> base(10, "foo");

    std::vector<std::string> std(base.begin(), base.end());
    ft::vector<std::string>  ft(base.begin(), base.end());

    compare_vectors(ft, std);
}

TEST_CASE("test vector templated parametric constructor from a string object")
{
    std::string base("foo bar baz fizz buzz");

    std::vector<char> std(base.begin(), base.end());
    ft::vector<char>  ft(base.begin(), base.end());

    compare_vectors(ft, std);
}

TEST_CASE("test vector copy constructor from an int vector")
{
    ft::vector<int> ft(10, 42);
    ft::vector<int> copy(ft);

    compare_vectors(copy, ft);
}

TEST_CASE("test vector copy constructor from a string vector")
{
    ft::vector<std::string> ft(10, "foo");
    ft::vector<std::string> copy(ft);

    compare_vectors(copy, ft);
}

TEST_CASE("test vector copy assignment operator from an int vector")
{
    ft::vector<int> ft(10, 42);
    ft::vector<int> copy;

    copy = ft;
    compare_vectors(copy, ft);
}

TEST_CASE("test vector copy assignment operator from a string vector")
{
    ft::vector<std::string> ft(10, "foo");
    ft::vector<std::string> copy;

    copy = ft;
    compare_vectors(copy, ft);
}
