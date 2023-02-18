/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_constructors.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:35:40 by maolivei          #+#    #+#             */
/*   Updated: 2023/02/17 23:31:03 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.hpp"

SCENARIO("test map constructors and assign operator")
{
    GIVEN("lorenipsum maps as base")
    {
        std::map<char, std::string> base_std;
        ft::map<char, std::string>  base_ft;

        build_lorenipsum_map(base_std);
        build_lorenipsum_map(base_ft);

        REQUIRE(base_std.size() == base_ft.size());
        REQUIRE(base_std.empty() == base_ft.empty());

        WHEN("calls map default constructor")
        {
            std::map<char, std::string> std;
            ft::map<char, std::string>  ft;

            THEN("both maps should be equal") { compare_maps(std, ft); }
        }

        WHEN("map range constructor with base map")
        {
            std::map<char, std::string> std(base_std.begin(), base_std.end());
            ft::map<char, std::string>  ft(base_ft.begin(), base_ft.end());

            THEN("both maps should be equal") { compare_maps(std, ft); }
        }

        WHEN("map copy constructor with base map")
        {
            std::map<char, std::string> std(base_std);
            ft::map<char, std::string>  ft(base_ft);

            THEN("both maps should be equal") { compare_maps(std, ft); }
        }

        WHEN("map assign operator with base map")
        {
            std::map<char, std::string> std;
            ft::map<char, std::string>  ft;

            std = base_std;
            ft  = base_ft;

            THEN("both maps should be equal") { compare_maps(std, ft); }
        }
    }
}

/* This test requires a specific constructor in map to be able to construct an object
 * through std::map iterators. This happens because ft::pair and std::pair are different
 * types, thus cannot be overloaded in the provided constructors */

// TEST_CASE("test map range constructor passing another map with values 'lorenipsum'")
// {
//     std::map<char, std::string> base;

//     build_lorenipsum_map(base);

//     std::map<char, std::string> std(base.begin(), base.end());
//     ft::map<char, std::string> ft(base.begin(), base.end());

//     compare_maps(std, ft);
// }
