/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack_performance.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 10:04:08 by maolivei          #+#    #+#             */
/*   Updated: 2023/02/21 21:26:17 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.hpp"

TEST_CASE("test stack performance")
{
    double start, end, elapsed_time;

    SUBCASE("test int stack push performance")
    {
        ft::stack<int, ft::vector<int> > stk;

        start = (double)clock() / CLOCKS_PER_SEC;

        for (int i = 0; i < ITERATIONS; ++i)
            stk.push(i);

        end          = (double)clock() / CLOCKS_PER_SEC;
        elapsed_time = end - start;
        std::cout << TIME_PRINT << "int stack push: " GREEN << elapsed_time << RESET << '\n';
    }
    SUBCASE("test int stack pop performance")
    {
        ft::vector<int>                  base(ITERATIONS, 42);
        ft::stack<int, ft::vector<int> > stk(base);

        start = (double)clock() / CLOCKS_PER_SEC;

        for (int i = 0; i < ITERATIONS; ++i)
            stk.pop();

        end          = (double)clock() / CLOCKS_PER_SEC;
        elapsed_time = end - start;
        std::cout << TIME_PRINT << "int stack pop: " GREEN << elapsed_time << RESET << '\n';
    }
    SUBCASE("test string stack push performance")
    {
        ft::stack<std::string, ft::vector<std::string> > stk;

        start = (double)clock() / CLOCKS_PER_SEC;

        for (int i = 0; i < ITERATIONS; ++i)
            stk.push("foo");

        end          = (double)clock() / CLOCKS_PER_SEC;
        elapsed_time = end - start;
        std::cout << TIME_PRINT << "string stack push: " GREEN << elapsed_time << RESET << '\n';
    }
    SUBCASE("test string stack pop performance")
    {
        ft::vector<std::string>                          base(ITERATIONS, "foo");
        ft::stack<std::string, ft::vector<std::string> > stk(base);

        start = (double)clock() / CLOCKS_PER_SEC;

        for (int i = 0; i < ITERATIONS; ++i)
            stk.pop();

        end          = (double)clock() / CLOCKS_PER_SEC;
        elapsed_time = end - start;
        std::cout << TIME_PRINT << "string stack pop: " GREEN << elapsed_time << RESET << '\n'
                  << std::endl;
    }
}
