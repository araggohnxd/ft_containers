/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_performance.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 10:04:08 by maolivei          #+#    #+#             */
/*   Updated: 2023/02/21 21:10:23 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.hpp"

double start, end, elapsed_time;

TEST_CASE("PERFORMANCE TESTS")
{
    SUBCASE("test int vector performance")
    {
        SUBCASE("test int vector assign range performance")
        {
            ft::vector<int> base(ITERATIONS, 42);
            ft::vector<int> vec;

            start = (double)clock() / CLOCKS_PER_SEC;

            vec.assign(base.begin(), base.end());

            end          = (double)clock() / CLOCKS_PER_SEC;
            elapsed_time = end - start;
            std::cout << TIME_PRINT << "int vector assign range: " GREEN << elapsed_time << RESET
                      << '\n';
        }
        SUBCASE("test int vector assign fill performance")
        {
            ft::vector<int> vec;

            start = (double)clock() / CLOCKS_PER_SEC;

            vec.assign(ITERATIONS, 42);

            end          = (double)clock() / CLOCKS_PER_SEC;
            elapsed_time = end - start;
            std::cout << TIME_PRINT << "int vector assign fill: " GREEN << elapsed_time << RESET
                      << '\n';
        }
        SUBCASE("test int vector push back performance")
        {
            ft::vector<int> vec;

            start = (double)clock() / CLOCKS_PER_SEC;

            for (int i = 0; i < ITERATIONS; ++i)
                vec.push_back(i);

            end          = (double)clock() / CLOCKS_PER_SEC;
            elapsed_time = end - start;
            std::cout << TIME_PRINT << "int vector push back: " GREEN << elapsed_time << RESET
                      << '\n';
        }
        SUBCASE("test int vector pop back performance")
        {
            ft::vector<int> vec(ITERATIONS);

            start = (double)clock() / CLOCKS_PER_SEC;

            for (int i = 0; i < ITERATIONS; ++i)
                vec.pop_back();

            end          = (double)clock() / CLOCKS_PER_SEC;
            elapsed_time = end - start;
            std::cout << TIME_PRINT << "int vector pop back: " GREEN << elapsed_time << RESET
                      << '\n';
        }
        SUBCASE("test int vector single insert performance")
        {
            ft::vector<int> vec;

            start = (double)clock() / CLOCKS_PER_SEC;

            for (int i = 0; i < ITERATIONS; ++i)
                vec.insert(vec.begin(), i);

            end          = (double)clock() / CLOCKS_PER_SEC;
            elapsed_time = end - start;
            std::cout << TIME_PRINT << "int vector single insert: " GREEN << elapsed_time << RESET
                      << '\n';
        }
        SUBCASE("test int vector fill insert performance")
        {
            ft::vector<int> vec;

            start = (double)clock() / CLOCKS_PER_SEC;

            for (int i = 0; i < ITERATIONS; ++i)
                vec.insert(vec.begin(), 10, i);

            end          = (double)clock() / CLOCKS_PER_SEC;
            elapsed_time = end - start;
            std::cout << TIME_PRINT << "int vector fill insert: " GREEN << elapsed_time << RESET
                      << '\n';
        }
        SUBCASE("test int vector range insert performance")
        {
            ft::vector<int> base(10, 42);
            ft::vector<int> vec;

            start = (double)clock() / CLOCKS_PER_SEC;

            for (int i = 0; i < ITERATIONS; ++i)
                vec.insert(vec.begin(), base.begin(), base.end());

            end          = (double)clock() / CLOCKS_PER_SEC;
            elapsed_time = end - start;
            std::cout << TIME_PRINT << "int vector range insert: " GREEN << elapsed_time << RESET
                      << '\n';
        }
        SUBCASE("test int vector single erase performance")
        {
            ft::vector<int> vec(ITERATIONS);

            start = (double)clock() / CLOCKS_PER_SEC;

            for (int i = 0; i < ITERATIONS; ++i)
                vec.erase(vec.begin());

            end          = (double)clock() / CLOCKS_PER_SEC;
            elapsed_time = end - start;
            std::cout << TIME_PRINT << "int vector single erase: " GREEN << elapsed_time << RESET
                      << '\n';
        }
        SUBCASE("test int vector range erase performance")
        {
            ft::vector<int> vec(ITERATIONS);

            start = (double)clock() / CLOCKS_PER_SEC;

            vec.erase(vec.begin(), vec.end());

            end          = (double)clock() / CLOCKS_PER_SEC;
            elapsed_time = end - start;
            std::cout << TIME_PRINT << "int vector range erase: " GREEN << elapsed_time << RESET
                      << '\n';
        }

        SUBCASE("test string vector assign range performance")
        {
            ft::vector<std::string> base(ITERATIONS / 10, "foo");
            ft::vector<std::string> vec;

            start = (double)clock() / CLOCKS_PER_SEC;

            vec.assign(base.begin(), base.end());

            end          = (double)clock() / CLOCKS_PER_SEC;
            elapsed_time = end - start;
            std::cout << TIME_PRINT << "string vector assign range: " GREEN << elapsed_time << RESET
                      << '\n';
        }
        SUBCASE("test string vector assign fill performance")
        {
            ft::vector<std::string> vec;

            start = (double)clock() / CLOCKS_PER_SEC;

            vec.assign(ITERATIONS / 10, "foo");

            end          = (double)clock() / CLOCKS_PER_SEC;
            elapsed_time = end - start;
            std::cout << TIME_PRINT << "string vector assign fill: " GREEN << elapsed_time << RESET
                      << '\n';
        }
        SUBCASE("test string vector push back performance")
        {
            ft::vector<std::string> vec;

            start = (double)clock() / CLOCKS_PER_SEC;

            for (int i = 0; i < ITERATIONS / 10; ++i)
                vec.push_back("foo");

            end          = (double)clock() / CLOCKS_PER_SEC;
            elapsed_time = end - start;
            std::cout << TIME_PRINT << "string vector push back: " GREEN << elapsed_time << RESET
                      << '\n';
        }
        SUBCASE("test string vector pop back performance")
        {
            ft::vector<std::string> vec(ITERATIONS / 10);

            start = (double)clock() / CLOCKS_PER_SEC;

            for (int i = 0; i < ITERATIONS / 10; ++i)
                vec.pop_back();

            end          = (double)clock() / CLOCKS_PER_SEC;
            elapsed_time = end - start;
            std::cout << TIME_PRINT << "string vector pop back: " GREEN << elapsed_time << RESET
                      << '\n';
        }
        SUBCASE("test string vector single insert performance")
        {
            ft::vector<std::string> vec;

            start = (double)clock() / CLOCKS_PER_SEC;

            for (int i = 0; i < ITERATIONS / 10; ++i)
                vec.insert(vec.begin(), "foo");

            end          = (double)clock() / CLOCKS_PER_SEC;
            elapsed_time = end - start;
            std::cout << TIME_PRINT << "string vector single insert: " GREEN << elapsed_time << RESET
                      << '\n';
        }
        SUBCASE("test string vector fill insert performance")
        {
            ft::vector<std::string> vec;

            start = (double)clock() / CLOCKS_PER_SEC;

            for (int i = 0; i < ITERATIONS / 10; ++i)
                vec.insert(vec.begin(), 10, "foo");

            end          = (double)clock() / CLOCKS_PER_SEC;
            elapsed_time = end - start;
            std::cout << TIME_PRINT << "string vector fill insert: " GREEN << elapsed_time << RESET
                      << '\n';
        }
        SUBCASE("test string vector range insert performance")
        {
            ft::vector<std::string> base(10, "foo");
            ft::vector<std::string> vec;

            start = (double)clock() / CLOCKS_PER_SEC;

            for (int i = 0; i < ITERATIONS / 10; ++i)
                vec.insert(vec.begin(), base.begin(), base.end());

            end          = (double)clock() / CLOCKS_PER_SEC;
            elapsed_time = end - start;
            std::cout << TIME_PRINT << "string vector range insert: " GREEN << elapsed_time << RESET
                      << '\n';
        }
        SUBCASE("test string vector single erase performance")
        {
            ft::vector<std::string> vec(ITERATIONS / 10);

            start = (double)clock() / CLOCKS_PER_SEC;

            for (int i = 0; i < ITERATIONS / 10; ++i)
                vec.erase(vec.begin());

            end          = (double)clock() / CLOCKS_PER_SEC;
            elapsed_time = end - start;
            std::cout << TIME_PRINT << "string vector single erase: " GREEN << elapsed_time << RESET
                      << '\n';
        }
        SUBCASE("test string vector range erase performance")
        {
            ft::vector<std::string> vec(ITERATIONS / 10);

            start = (double)clock() / CLOCKS_PER_SEC;

            vec.erase(vec.begin(), vec.end());

            end          = (double)clock() / CLOCKS_PER_SEC;
            elapsed_time = end - start;
            std::cout << TIME_PRINT << "string vector range erase: " GREEN << elapsed_time << RESET
                      << '\n';
        }
    }
}
