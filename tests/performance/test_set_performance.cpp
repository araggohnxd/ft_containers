/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set_performance.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:41:52 by maolivei          #+#    #+#             */
/*   Updated: 2023/02/22 20:03:28 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.hpp"

TEST_CASE("test set performance")
{
    double start, end, elapsed_time;

    SUBCASE("test int set insert single performance")
    {
        ft::set<int> set;

        start = (double)clock() / CLOCKS_PER_SEC;

        for (int i = 0; i < ITERATIONS / 5; ++i)
            set.insert(i);

        end          = (double)clock() / CLOCKS_PER_SEC;
        elapsed_time = end - start;
        std::cout << TIME_PRINT << "int set insert single: " GREEN << elapsed_time << RESET << '\n';
    }
    SUBCASE("test int set insert hint performance")
    {
        ft::set<int> set;

        start = (double)clock() / CLOCKS_PER_SEC;

        for (int i = 0; i < ITERATIONS / 5; ++i)
            set.insert(set.find(i - 1), i);

        end          = (double)clock() / CLOCKS_PER_SEC;
        elapsed_time = end - start;
        std::cout << TIME_PRINT << "int set insert hint: " GREEN << elapsed_time << RESET << '\n';
    }
    SUBCASE("test int set insert range performance")
    {
        ft::set<int> base;
        ft::set<int> set;
        for (int i = 0; i < ITERATIONS / 5; ++i)
            base.insert(i);

        start = (double)clock() / CLOCKS_PER_SEC;

        set.insert(base.begin(), base.end());

        end          = (double)clock() / CLOCKS_PER_SEC;
        elapsed_time = end - start;
        std::cout << TIME_PRINT << "int set insert range: " GREEN << elapsed_time << RESET << '\n';
    }
    SUBCASE("test int set erase single performance")
    {
        ft::set<int> set;
        for (int i = 0; i < ITERATIONS / 5; ++i)
            set.insert(i);

        start = (double)clock() / CLOCKS_PER_SEC;

        for (int i = 0; i < ITERATIONS / 5; ++i)
            set.erase(set.begin());

        end          = (double)clock() / CLOCKS_PER_SEC;
        elapsed_time = end - start;
        std::cout << TIME_PRINT << "int set erase single: " GREEN << elapsed_time << RESET << '\n';
    }
    SUBCASE("test int set erase key performance")
    {
        ft::set<int> set;
        for (int i = 0; i < ITERATIONS / 5; ++i)
            set.insert(i);

        start = (double)clock() / CLOCKS_PER_SEC;

        for (int i = 0; i < ITERATIONS / 5; ++i)
            set.erase(i);

        end          = (double)clock() / CLOCKS_PER_SEC;
        elapsed_time = end - start;
        std::cout << TIME_PRINT << "int set erase key: " GREEN << elapsed_time << RESET << '\n';
    }
    SUBCASE("test int set erase range performance")
    {
        ft::set<int> set;
        for (int i = 0; i < ITERATIONS / 5; ++i)
            set.insert(i);

        start = (double)clock() / CLOCKS_PER_SEC;

        set.erase(set.begin(), set.end());

        end          = (double)clock() / CLOCKS_PER_SEC;
        elapsed_time = end - start;
        std::cout << TIME_PRINT << "int set erase range: " GREEN << elapsed_time << RESET << '\n';
    }
    SUBCASE("test int set clear performance")
    {
        ft::set<int> set;
        for (int i = 0; i < ITERATIONS / 5; ++i)
            set.insert(i);

        start = (double)clock() / CLOCKS_PER_SEC;

        set.clear();

        end          = (double)clock() / CLOCKS_PER_SEC;
        elapsed_time = end - start;
        std::cout << TIME_PRINT << "int set clear: " GREEN << elapsed_time << RESET << '\n';
    }
    SUBCASE("test int set find performance")
    {
        ft::set<int> set;
        for (int i = 0; i < ITERATIONS / 5; ++i)
            set.insert(i);

        start = (double)clock() / CLOCKS_PER_SEC;

        set.find(ITERATIONS / 5 / 2);

        end          = (double)clock() / CLOCKS_PER_SEC;
        elapsed_time = end - start;
        std::cout << TIME_PRINT << "int set find: " GREEN << elapsed_time << RESET << '\n';
    }
    SUBCASE("test int set lower_bound performance")
    {
        ft::set<int> set;
        for (int i = 0; i < ITERATIONS / 5; ++i)
            set.insert(i);

        start = (double)clock() / CLOCKS_PER_SEC;

        set.lower_bound(ITERATIONS / 5 / 2);

        end          = (double)clock() / CLOCKS_PER_SEC;
        elapsed_time = end - start;
        std::cout << TIME_PRINT << "int set lower_bound: " GREEN << elapsed_time << RESET << '\n';
    }
    SUBCASE("test int set upper_bound performance")
    {
        ft::set<int> set;
        for (int i = 0; i < ITERATIONS / 5; ++i)
            set.insert(i);

        start = (double)clock() / CLOCKS_PER_SEC;

        set.upper_bound(ITERATIONS / 5 / 2);

        end          = (double)clock() / CLOCKS_PER_SEC;
        elapsed_time = end - start;
        std::cout << TIME_PRINT << "int set upper_bound: " GREEN << elapsed_time << RESET << '\n';
    }
    SUBCASE("test int set equal_range performance")
    {
        ft::set<int> set;
        for (int i = 0; i < ITERATIONS / 5; ++i)
            set.insert(i);

        start = (double)clock() / CLOCKS_PER_SEC;

        set.equal_range(ITERATIONS / 5 / 2);

        end          = (double)clock() / CLOCKS_PER_SEC;
        elapsed_time = end - start;
        std::cout << TIME_PRINT << "int set equal_range: " GREEN << elapsed_time << RESET << '\n'
                  << std::endl;
    }
}
