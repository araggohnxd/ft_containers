/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_iterators.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:15:08 by maolivei          #+#    #+#             */
/*   Updated: 2023/02/17 23:56:50 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.hpp"

SCENARIO("test map iterators")
{
    GIVEN("lorenipsum maps as base")
    {
        std::map<char, std::string> base_std;
        ft::map<char, std::string>  base_ft;

        build_lorenipsum_map(base_std);
        build_lorenipsum_map(base_ft);

        REQUIRE(base_std.size() == base_ft.size());
        REQUIRE(base_std.empty() == base_ft.empty());

        WHEN("iterating through base maps with iterator")
        {
            std::map<char, std::string>::iterator it_std = base_std.begin();
            ft::map<char, std::string>::iterator  it_ft  = base_ft.begin();

            THEN("all iterations should be equal in both maps")
            {
                for (; it_std != base_std.end(); ++it_std, ++it_ft) {
                    CHECK(it_std->first == it_ft->first);
                    CHECK(it_std->second == it_ft->second);
                }
            }
        }

        WHEN("iterating through base maps with const iterator")
        {
            std::map<char, std::string>::const_iterator it_std = base_std.begin();
            ft::map<char, std::string>::const_iterator  it_ft  = base_ft.begin();

            THEN("all iterations should be equal in both maps")
            {
                for (; it_std != base_std.end(); ++it_std, ++it_ft) {
                    CHECK(it_std->first == it_ft->first);
                    CHECK(it_std->second == it_ft->second);
                }
            }
        }

        WHEN("iterating through base maps with reverse iterator")
        {
            std::map<char, std::string>::reverse_iterator it_std = base_std.rbegin();
            ft::map<char, std::string>::reverse_iterator  it_ft  = base_ft.rbegin();

            THEN("all iterations should be equal in both maps")
            {
                for (; it_std != base_std.rend(); ++it_std, ++it_ft) {
                    CHECK(it_std->first == it_ft->first);
                    CHECK(it_std->second == it_ft->second);
                }
            }
        }

        WHEN("iterating through base maps with const reverse iterator")
        {
            std::map<char, std::string>::const_reverse_iterator it_std = base_std.rbegin();
            ft::map<char, std::string>::const_reverse_iterator  it_ft  = base_ft.rbegin();

            THEN("all iterations should be equal in both maps")
            {
                for (; it_std != base_std.rend(); ++it_std, ++it_ft) {
                    CHECK(it_std->first == it_ft->first);
                    CHECK(it_std->second == it_ft->second);
                }
            }
        }

        WHEN("calling map begin() iterator function")
        {
            ft::map<char, std::string>::iterator it_ft = base_ft.begin();

            THEN("value inside iterator should be equal to 'E'")
            {
                CHECK(it_ft->first == 'E');
                CHECK(it_ft->second == "E");
            }
        }

        WHEN("calling map begin() iterator function and incrementing once")
        {
            ft::map<char, std::string>::iterator it_ft = base_ft.begin();
            ++it_ft;

            THEN("value inside iterator should be equal to 'I'")
            {
                CHECK(it_ft->first == 'I');
                CHECK(it_ft->second == "I");
            }
        }

        WHEN("calling map end() iterator function and decrementing once")
        {
            ft::map<char, std::string>::iterator it_ft = base_ft.end();
            --it_ft;

            THEN("value inside iterator should be equal to 'U'")
            {
                CHECK(it_ft->first == 'U');
                CHECK(it_ft->second == "U");
            }
        }

        WHEN("calling map end() iterator function and incrementing once")
        {
            ft::map<char, std::string>::iterator it_ft = base_ft.end();
            ++it_ft;

            THEN("value inside iterator should be equal to 'U'")
            {
                CHECK(it_ft->first == 'U');
                CHECK(it_ft->second == "U");
            }
        }

        WHEN("calling map rbegin() iterator function")
        {
            ft::map<char, std::string>::reverse_iterator it_ft = base_ft.rbegin();

            THEN("value inside iterator should be equal to 'U'")
            {
                CHECK(it_ft->first == 'U');
                CHECK(it_ft->second == "U");
            }
        }

        WHEN("calling map rbegin() iterator function and decrementing once")
        {
            ft::map<char, std::string>::reverse_iterator it_ft = base_ft.rbegin();
            --it_ft;

            THEN("value inside iterator should be equal to 'S'")
            {
                CHECK(it_ft->first == 'S');
                CHECK(it_ft->second == "S");
            }
        }

        WHEN("calling map rbegin() iterator function and incrementing once")
        {
            ft::map<char, std::string>::reverse_iterator it_ft = base_ft.rbegin();
            ++it_ft;

            THEN("value inside iterator should be equal to 'S'")
            {
                CHECK(it_ft->first == 'S');
                CHECK(it_ft->second == "S");
            }
        }

        WHEN("calling map rend() iterator function and decrementing once")
        {
            ft::map<char, std::string>::reverse_iterator it_ft = base_ft.rend();
            --it_ft;

            THEN("value inside iterator should be equal to 'E'")
            {
                CHECK(it_ft->first == 'E');
                CHECK(it_ft->second == "E");
            }
        }

        WHEN("calling map rend() iterator function and incrementing once")
        {
            ft::map<char, std::string>::reverse_iterator it_ft = base_ft.rend();
            ++it_ft;

            THEN("value inside iterator should be equal to 'U'")
            {
                CHECK(it_ft->first == 'U');
                CHECK(it_ft->second == "U");
            }
        }

        WHEN("iterating through base map with iterator and calculating its size")
        {
            ft::map<char, std::string>::iterator it_ft    = base_ft.begin();
            size_t                                       map_size = 0;

            THEN("final size should equal map's true size")
            {
                for (; it_ft != base_ft.end(); ++it_ft)
                    ++map_size;
                CHECK(map_size == base_ft.size());
            }
        }

        WHEN("iterating through base map with reverse iterator and calculating its size")
        {
            ft::map<char, std::string>::reverse_iterator it_ft    = base_ft.rbegin();
            size_t                                       map_size = 0;

            THEN("final size should equal map's true size")
            {
                for (; it_ft != base_ft.rend(); ++it_ft)
                    ++map_size;
                CHECK(map_size == base_ft.size());
            }
        }
    }
}
