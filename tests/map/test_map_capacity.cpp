/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_capacity.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:29:34 by maolivei          #+#    #+#             */
/*   Updated: 2023/02/20 12:19:31 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.hpp"

TEST_CASE("test map size() with 'lorenipsum' values should have size 10")
{
    CHECK(base_ft_map.size() == base_std_map.size());
    CHECK(base_ft_map.size() == 10);
}

TEST_CASE("test map empty() with 'lorenipsum' values should not be empty")
{
    CHECK(base_ft_map.empty() == base_std_map.empty());
    CHECK(base_ft_map.empty() == false);
}

TEST_CASE("test map size() created empty should have size 0")
{
    CHECK(empty_ft_map.size() == empty_std_map.size());
    CHECK(empty_ft_map.size() == 0);
}

TEST_CASE("test map empty() created empty should be empty")
{
    CHECK(empty_ft_map.empty() == empty_std_map.empty());
    CHECK(empty_ft_map.empty() == true);
}
