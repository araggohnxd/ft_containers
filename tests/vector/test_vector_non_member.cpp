/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_non_member.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:12:16 by maolivei          #+#    #+#             */
/*   Updated: 2023/02/04 17:37:10 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.hpp"

TEST_CASE("test vector operator== with int vector")
{
    ft::vector<int> vec1(10, 42);
    ft::vector<int> vec2(10, 42);

    CHECK(vec1 == vec2);
    vec1.push_back(123);
    vec2.push_back(123);
    CHECK(vec1 == vec2);
    vec1.assign(42, 21);
    vec2.assign(42, 21);
    CHECK(vec1 == vec2);
}

TEST_CASE("test vector operator!= with int vector same size but different elements")
{
    ft::vector<int> vec1(10, 42);
    ft::vector<int> vec2(10, 21);

    CHECK(vec1 != vec2);
    vec1.push_back(123);
    vec2.push_back(123);
    CHECK(vec1 != vec2);
    vec1.assign(42, 21);
    vec2.assign(42, 21);
    CHECK_FALSE(vec1 != vec2);
}

TEST_CASE("test vector operator!= with int vector same elements but different size")
{
    ft::vector<int> vec1(10, 42);
    ft::vector<int> vec2(100, 42);

    CHECK(vec1 != vec2);
    vec1.push_back(123);
    vec2.push_back(123);
    CHECK(vec1 != vec2);
    vec1.assign(42, 21);
    vec2.assign(42, 21);
    CHECK_FALSE(vec1 != vec2);
}

TEST_CASE("test vector operator< with int vector same size but different elements")
{
    ft::vector<int> vec1(10, 21);
    ft::vector<int> vec2(10, 42);
    ft::vector<int> vec3(10, 123);

    CHECK(vec1 < vec2);
    CHECK(vec2 < vec3);
    vec1.push_back(123);
    vec2.push_back(123);
    CHECK(vec1 < vec2);
    vec1.assign(42, 21);
    vec2.assign(42, 21);
    CHECK_FALSE(vec1 < vec2);
}

TEST_CASE("test vector operator< with int vector same size but different elements")
{
    ft::vector<int> vec1(1, 42);
    ft::vector<int> vec2(10, 42);
    ft::vector<int> vec3(100, 42);

    CHECK(vec1 < vec2);
    CHECK(vec2 < vec3);
    vec1.push_back(123);
    vec2.push_back(123);
    /* even though vec1 is smaller in size,
    the new pushed value makes it compare as greater than vec2 */
    CHECK_FALSE(vec1 < vec2);
    vec1.assign(42, 21);
    vec2.assign(42, 21);
    CHECK_FALSE(vec1 < vec2);
}

TEST_CASE("test vector operator<= with int vector same size but different elements")
{
    ft::vector<int> eqvec1(10, 21);
    ft::vector<int> vec1(10, 21);
    ft::vector<int> vec2(10, 42);
    ft::vector<int> vec3(10, 123);

    CHECK(vec1 <= eqvec1);
    CHECK(vec1 <= vec2);
    CHECK(vec2 <= vec3);
    vec1.push_back(123);
    vec2.push_back(123);
    CHECK(vec1 <= vec2);
    vec1.assign(42, 21);
    vec2.assign(42, 21);
    CHECK(vec1 <= vec2);
}

TEST_CASE("test vector operator<= with int vector same size but different elements")
{
    ft::vector<int> eqvec1(1, 42);
    ft::vector<int> vec1(1, 42);
    ft::vector<int> vec2(10, 42);
    ft::vector<int> vec3(100, 42);

    CHECK(vec1 <= eqvec1);
    CHECK(vec1 <= vec2);
    CHECK(vec2 <= vec3);
    vec1.push_back(123);
    vec2.push_back(123);
    /* even though vec1 is smaller in size,
    the new pushed value makes it compare as greater than vec2 */
    CHECK_FALSE(vec1 <= vec2);
    vec1.assign(42, 21);
    vec2.assign(42, 21);
    CHECK(vec1 <= vec2);
}

TEST_CASE("test vector operator> with int vector same size but different elements")
{
    ft::vector<int> vec1(10, 123);
    ft::vector<int> vec2(10, 42);
    ft::vector<int> vec3(10, 21);

    CHECK(vec1 > vec2);
    CHECK(vec2 > vec3);
    vec1.push_back(123);
    vec2.push_back(123);
    CHECK(vec1 > vec2);
    vec1.assign(42, 21);
    vec2.assign(42, 21);
    CHECK_FALSE(vec1 > vec2);
}

TEST_CASE("test vector operator> with int vector same size but different elements")
{
    ft::vector<int> vec1(100, 42);
    ft::vector<int> vec2(10, 42);
    ft::vector<int> vec3(1, 42);

    CHECK(vec1 > vec2);
    CHECK(vec2 > vec3);
    vec1.push_back(123);
    vec2.push_back(123);
    CHECK_FALSE(vec1 > vec2);
    vec1.assign(42, 21);
    vec2.assign(42, 21);
    CHECK_FALSE(vec1 > vec2);
}

TEST_CASE("test vector operator>= with int vector same size but different elements")
{
    ft::vector<int> eqvec1(10, 123);
    ft::vector<int> vec1(10, 123);
    ft::vector<int> vec2(10, 42);
    ft::vector<int> vec3(10, 21);

    CHECK(vec1 >= eqvec1);
    CHECK(vec1 >= vec2);
    CHECK(vec2 >= vec3);
    vec1.push_back(123);
    vec2.push_back(123);
    CHECK(vec1 >= vec2);
    vec1.assign(42, 21);
    vec2.assign(42, 21);
    CHECK(vec1 >= vec2);
}

TEST_CASE("test vector operator>= with int vector same size but different elements")
{
    ft::vector<int> eqvec1(100, 42);
    ft::vector<int> vec1(100, 42);
    ft::vector<int> vec2(10, 42);
    ft::vector<int> vec3(1, 42);

    CHECK(vec1 >= eqvec1);
    CHECK(vec1 >= vec2);
    CHECK(vec2 >= vec3);
    vec1.push_back(123);
    vec2.push_back(123);
    CHECK_FALSE(vec1 >= vec2);
    vec1.assign(42, 21);
    vec2.assign(42, 21);
    CHECK(vec1 >= vec2);
}

TEST_CASE("test vector swap() non-member properly copies values from same size int vector")
{
    std::vector<int> base_std(10, 42);
    ft::vector<int>  base_ft(10, 42);

    std::vector<int> std(10, 21);
    ft::vector<int>  ft(10, 21);

    std::swap(std, base_std);
    ft::swap(ft, base_ft);
    CHECK(ft.size() == std.size());
    CHECK(ft.capacity() == std.capacity());
    CHECK(std::equal(ft.begin(), ft.end(), std.begin()));
    CHECK(std::equal(std.begin(), std.end(), ft.begin()));
}

TEST_CASE("test vector swap() non-member properly copies values from bigger size int vector")
{
    std::vector<int> base_std(100, 42);
    ft::vector<int>  base_ft(100, 42);

    std::vector<int> std(10, 21);
    ft::vector<int>  ft(10, 21);

    std::swap(std, base_std);
    ft::swap(ft, base_ft);
    CHECK(ft.size() == std.size());
    CHECK(ft.capacity() == std.capacity());
    CHECK(std::equal(ft.begin(), ft.end(), std.begin()));
    CHECK(std::equal(std.begin(), std.end(), ft.begin()));
}

TEST_CASE("test vector swap() non-member properly copies values from smaller size int vector")
{
    std::vector<int> base_std(1, 42);
    ft::vector<int>  base_ft(1, 42);

    std::vector<int> std(10, 21);
    ft::vector<int>  ft(10, 21);

    std::swap(std, base_std);
    ft::swap(ft, base_ft);
    CHECK(ft.size() == std.size());
    CHECK(ft.capacity() == std.capacity());
    CHECK(std::equal(ft.begin(), ft.end(), std.begin()));
    CHECK(std::equal(std.begin(), std.end(), ft.begin()));
}

TEST_CASE("test vector swap() non-member properly copies values from same size string vector")
{
    std::vector<std::string> base_std(10, "foo");
    ft::vector<std::string>  base_ft(10, "foo");

    std::vector<std::string> std(10, "bar");
    ft::vector<std::string>  ft(10, "bar");

    std::swap(std, base_std);
    ft::swap(ft, base_ft);
    CHECK(ft.size() == std.size());
    CHECK(ft.capacity() == std.capacity());
    CHECK(std::equal(ft.begin(), ft.end(), std.begin()));
    CHECK(std::equal(std.begin(), std.end(), ft.begin()));
}

TEST_CASE("test vector swap() non-member properly copies values from bigger size string vector")
{
    std::vector<std::string> base_std(100, "foo");
    ft::vector<std::string>  base_ft(100, "foo");

    std::vector<std::string> std(10, "bar");
    ft::vector<std::string>  ft(10, "bar");

    std::swap(std, base_std);
    ft::swap(ft, base_ft);
    CHECK(ft.size() == std.size());
    CHECK(ft.capacity() == std.capacity());
    CHECK(std::equal(ft.begin(), ft.end(), std.begin()));
    CHECK(std::equal(std.begin(), std.end(), ft.begin()));
}

TEST_CASE("test vector swap() non-member properly copies values from smaller size string vector")
{
    std::vector<std::string> base_std(1, "foo");
    ft::vector<std::string>  base_ft(1, "foo");

    std::vector<std::string> std(10, "bar");
    ft::vector<std::string>  ft(10, "bar");

    std::swap(std, base_std);
    ft::swap(ft, base_ft);
    CHECK(ft.size() == std.size());
    CHECK(ft.capacity() == std.capacity());
    CHECK(std::equal(ft.begin(), ft.end(), std.begin()));
    CHECK(std::equal(std.begin(), std.end(), ft.begin()));
}

TEST_CASE("test vector swap() non-member assert that swap creates a deep copy")
{
    std::vector<int> base_std(10, 42);
    ft::vector<int>  base_ft(10, 42);

    std::vector<int> std(10, 21);
    ft::vector<int>  ft(10, 21);

    std::swap(std, base_std);
    std.insert(std.begin() + 5, 10, 123);

    ft::swap(ft, base_ft);
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
