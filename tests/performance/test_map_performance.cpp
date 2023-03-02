/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_performance.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:41:52 by maolivei          #+#    #+#             */
/*   Updated: 2023/03/02 19:18:58 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.hpp"

TEST_CASE("test map performance")
{
    double start, end, elapsed_time;

    ft::pair<int, int> p[ITERATIONS];

    for (int i = 0; i < ITERATIONS; ++i) {
        p[i].first = i;
        p[i].second = i;
    }

    SUBCASE("test int map insert single performance")
    {
        ft::map<int, int> map;

        start = (double)clock() / CLOCKS_PER_SEC;

        for (int i = 0; i < ITERATIONS; ++i)
            map.insert(p[i]);

        end          = (double)clock() / CLOCKS_PER_SEC;
        elapsed_time = end - start;
        std::cout << TIME_PRINT << "int map insert single: " GREEN << elapsed_time << RESET << '\n';
    }
    SUBCASE("test int map insert hint performance")
    {
        ft::map<int, int> map;

        start = (double)clock() / CLOCKS_PER_SEC;

        for (int i = 0; i < ITERATIONS; ++i)
            map.insert(map.find(i - 1), p[i]);

        end          = (double)clock() / CLOCKS_PER_SEC;
        elapsed_time = end - start;
        std::cout << TIME_PRINT << "int map insert hint: " GREEN << elapsed_time << RESET << '\n';
    }
    SUBCASE("test int map insert range performance")
    {
        ft::map<int, int> base;
        ft::map<int, int> map;
        for (int i = 0; i < ITERATIONS; ++i)
            base.insert(p[i]);

        start = (double)clock() / CLOCKS_PER_SEC;

        map.insert(base.begin(), base.end());

        end          = (double)clock() / CLOCKS_PER_SEC;
        elapsed_time = end - start;
        std::cout << TIME_PRINT << "int map insert range: " GREEN << elapsed_time << RESET << '\n';
    }
    SUBCASE("test int map erase single performance")
    {
        ft::map<int, int> map;
        for (int i = 0; i < ITERATIONS; ++i)
            map.insert(p[i]);

        start = (double)clock() / CLOCKS_PER_SEC;

        for (int i = 0; i < ITERATIONS; ++i)
            map.erase(map.begin());

        end          = (double)clock() / CLOCKS_PER_SEC;
        elapsed_time = end - start;
        std::cout << TIME_PRINT << "int map erase single: " GREEN << elapsed_time << RESET << '\n';
    }
    SUBCASE("test int map erase key performance")
    {
        ft::map<int, int> map;
        for (int i = 0; i < ITERATIONS; ++i)
            map.insert(p[i]);

        start = (double)clock() / CLOCKS_PER_SEC;

        for (int i = 0; i < ITERATIONS; ++i)
            map.erase(i);

        end          = (double)clock() / CLOCKS_PER_SEC;
        elapsed_time = end - start;
        std::cout << TIME_PRINT << "int map erase key: " GREEN << elapsed_time << RESET << '\n';
    }
    SUBCASE("test int map erase range performance")
    {
        ft::map<int, int> map;
        for (int i = 0; i < ITERATIONS; ++i)
            map.insert(p[i]);

        start = (double)clock() / CLOCKS_PER_SEC;

        map.erase(map.begin(), map.end());

        end          = (double)clock() / CLOCKS_PER_SEC;
        elapsed_time = end - start;
        std::cout << TIME_PRINT << "int map erase range: " GREEN << elapsed_time << RESET << '\n';
    }
    SUBCASE("test int map clear performance")
    {
        ft::map<int, int> map;
        for (int i = 0; i < ITERATIONS; ++i)
            map.insert(p[i]);

        start = (double)clock() / CLOCKS_PER_SEC;

        map.clear();

        end          = (double)clock() / CLOCKS_PER_SEC;
        elapsed_time = end - start;
        std::cout << TIME_PRINT << "int map clear: " GREEN << elapsed_time << RESET << '\n';
    }
    SUBCASE("test int map find performance")
    {
        ft::map<int, int> map;
        for (int i = 0; i < ITERATIONS; ++i)
            map.insert(p[i]);

        start = (double)clock() / CLOCKS_PER_SEC;

        map.find(ITERATIONS / 2);

        end          = (double)clock() / CLOCKS_PER_SEC;
        elapsed_time = end - start;
        std::cout << TIME_PRINT << "int map find: " GREEN << elapsed_time << RESET << '\n';
    }
    SUBCASE("test int map lower_bound performance")
    {
        ft::map<int, int> map;
        for (int i = 0; i < ITERATIONS; ++i)
            map.insert(p[i]);

        start = (double)clock() / CLOCKS_PER_SEC;

        map.lower_bound(ITERATIONS / 2);

        end          = (double)clock() / CLOCKS_PER_SEC;
        elapsed_time = end - start;
        std::cout << TIME_PRINT << "int map lower_bound: " GREEN << elapsed_time << RESET << '\n';
    }
    SUBCASE("test int map upper_bound performance")
    {
        ft::map<int, int> map;
        for (int i = 0; i < ITERATIONS; ++i)
            map.insert(p[i]);

        start = (double)clock() / CLOCKS_PER_SEC;

        map.upper_bound(ITERATIONS / 2);

        end          = (double)clock() / CLOCKS_PER_SEC;
        elapsed_time = end - start;
        std::cout << TIME_PRINT << "int map upper_bound: " GREEN << elapsed_time << RESET << '\n';
    }
    SUBCASE("test int map equal_range performance")
    {
        ft::map<int, int> map;
        for (int i = 0; i < ITERATIONS; ++i)
            map.insert(p[i]);

        start = (double)clock() / CLOCKS_PER_SEC;

        map.equal_range(ITERATIONS / 2);

        end          = (double)clock() / CLOCKS_PER_SEC;
        elapsed_time = end - start;
        std::cout << TIME_PRINT << "int map equal_range: " GREEN << elapsed_time << RESET << '\n'
                  << std::endl;
    }
}
