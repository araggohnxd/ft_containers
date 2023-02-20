/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_modifiers.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 20:52:31 by maolivei          #+#    #+#             */
/*   Updated: 2023/02/20 12:19:42 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.hpp"

TEST_CASE("test map insert() successfully insert 'x'")
{
    std::map<char, std::string> std;
    ft::map<char, std::string>  ft;

    CHECK(std.find('X') == std.end());
    CHECK(ft.find('X') == ft.end());

    std.insert(std::make_pair('X', "X"));
    ft.insert(ft::make_pair('X', "X"));

    CHECK(ft.find('X')->second == std.find('X')->second);
    CHECK(ft.find('X')->second == "X");
}

TEST_CASE("test map insert() return pair second value is true when value doesn't exist")
{
    std::map<char, std::string> std;
    ft::map<char, std::string>  ft;

    std::pair<std::map<char, std::string>::iterator, bool> std_pair;
    ft::pair<ft::map<char, std::string>::iterator, bool>   ft_pair;

    std_pair = std.insert(std::make_pair('X', "X"));
    ft_pair  = ft.insert(ft::make_pair('X', "X"));

    CHECK(ft_pair.first->second == std_pair.first->second);
    CHECK(ft_pair.second == std_pair.second);
    CHECK(ft_pair.first->second == "X");
    CHECK(ft_pair.second == true);
}

TEST_CASE("test map insert() return pair second value is false when value exists")
{
    std::pair<std::map<char, std::string>::iterator, bool> std_pair;
    ft::pair<ft::map<char, std::string>::iterator, bool>   ft_pair;

    std_pair = base_std_map.insert(std::make_pair('O', "O"));
    ft_pair  = base_ft_map.insert(ft::make_pair('O', "O"));

    CHECK(ft_pair.first->second == std_pair.first->second);
    CHECK(ft_pair.second == std_pair.second);
    CHECK(ft_pair.first->second == "O");
    CHECK(ft_pair.second == false);
}

TEST_CASE("test map insert() increases map size by 1 when value doesn't exist")
{
    std::map<char, std::string> std;
    ft::map<char, std::string>  ft;

    std.insert(std::make_pair('X', "X"));
    ft.insert(ft::make_pair('X', "X"));

    CHECK(ft.size() == std.size());
    CHECK(ft.size() == 1);
}

TEST_CASE("test map insert() doesn't increase map size when value already exist")
{
    std::map<char, std::string> std;
    ft::map<char, std::string>  ft;

    std.insert(std::make_pair('X', "X"));
    ft.insert(ft::make_pair('X', "X"));

    std.insert(std::make_pair('X', "X"));
    ft.insert(ft::make_pair('X', "X"));

    CHECK(ft.size() == std.size());
    CHECK(ft.size() == 1);
}

TEST_CASE("test map insert() hint succesfully insert 'x'")
{
    std::map<char, std::string> std;
    ft::map<char, std::string>  ft;

    CHECK(std.find('X') == std.end());
    CHECK(ft.find('X') == ft.end());

    std.insert(std.begin(), std::make_pair('X', "X"));
    ft.insert(ft.begin(), ft::make_pair('X', "X"));

    CHECK(ft.find('X')->second == std.find('X')->second);
    CHECK(ft.find('X')->second == "X");
}

TEST_CASE("test map insert() hint return iterator to inserted value if it doesn't exist")
{
    std::map<char, std::string> std;
    ft::map<char, std::string>  ft;

    std::map<char, std::string>::iterator std_it;
    ft::map<char, std::string>::iterator  ft_it;

    std_it = std.insert(std.begin(), std::make_pair('X', "X"));
    ft_it  = ft.insert(ft.begin(), ft::make_pair('X', "X"));

    CHECK(ft_it->second == std_it->second);
    CHECK(ft_it->second == ft.find('X')->second);
    CHECK(ft_it->second == "X");
}

TEST_CASE("test map insert() hint return iterator to existing value if it exists")
{
    std::map<char, std::string> std;
    ft::map<char, std::string>  ft;

    std::map<char, std::string>::iterator std_it;
    ft::map<char, std::string>::iterator  ft_it;

    std.insert(std::make_pair('X', "X"));
    ft.insert(ft::make_pair('X', "X"));

    std_it = std.insert(std.begin(), std::make_pair('X', "X"));
    ft_it  = ft.insert(ft.begin(), ft::make_pair('X', "X"));

    CHECK(ft_it->second == std_it->second);
    CHECK(ft_it->second == ft.find('X')->second);
    CHECK(ft_it->second == "X");
    CHECK(ft_it == ft.begin());
    CHECK(ft.size() == 1); // size shouldn't change since value already existed
}

TEST_CASE("test map insert() hint increases map size by 1 when value doesn't exist")
{
    std::map<char, std::string> std;
    ft::map<char, std::string>  ft;

    std.insert(std.begin(), std::make_pair('X', "X"));
    ft.insert(ft.begin(), ft::make_pair('X', "X"));

    CHECK(ft.size() == std.size());
    CHECK(ft.size() == 1);
}

TEST_CASE("test map insert() hint doesn't increase map size when value already exist")
{
    std::map<char, std::string> std;
    ft::map<char, std::string>  ft;

    std.insert(std::make_pair('X', "X"));
    ft.insert(ft::make_pair('X', "X"));

    std.insert(std.begin(), std::make_pair('X', "X"));
    ft.insert(ft.begin(), ft::make_pair('X', "X"));

    CHECK(ft.size() == std.size());
    CHECK(ft.size() == 1);
}

TEST_CASE("test map insert() range successfully insert 'lorenipsum' from base map")
{
    std::map<char, std::string> std;
    ft::map<char, std::string>  ft;

    std.insert(base_std_map.begin(), base_std_map.end());
    ft.insert(base_ft_map.begin(), base_ft_map.end());

    std::map<char, std::string>::iterator std_it     = std.begin();
    ft::map<char, std::string>::iterator  ft_it      = ft.begin();
    ft::map<char, std::string>::iterator  base_ft_it = base_ft_map.begin();

    for (; std_it != std.end(); ++std_it, ++ft_it, ++base_ft_it) {
        CHECK(std_it->first == ft_it->first);
        CHECK(std_it->second == ft_it->second);
        CHECK(base_ft_it->first == ft_it->first);
        CHECK(base_ft_it->second == ft_it->second);
    }
}

TEST_CASE("test map insert() range increases map size by 10 when inserting 'lorenipsum'")
{
    std::map<char, std::string> std;
    ft::map<char, std::string>  ft;

    std.insert(base_std_map.begin(), base_std_map.end());
    ft.insert(base_ft_map.begin(), base_ft_map.end());

    CHECK(ft.size() == std.size());
    CHECK(ft.size() == 10);
}

TEST_CASE("test map insert() range doesn't increase map size inserting existing values")
{
    std::map<char, std::string> std;
    ft::map<char, std::string>  ft;

    std.insert(base_std_map.begin(), base_std_map.end());
    ft.insert(base_ft_map.begin(), base_ft_map.end());

    std.insert(base_std_map.begin(), base_std_map.end());
    ft.insert(base_ft_map.begin(), base_ft_map.end());

    CHECK(ft.size() == std.size());
    CHECK(ft.size() == 10);
}

TEST_CASE("test map erase() iterator succesfully erases 'o'")
{
    ft::map<char, std::string> ft(base_ft_map);

    ft.erase(ft.begin());

    CHECK(ft.find('E') == ft.end());
}

TEST_CASE("test map erase() iterator decreases map size by 1 becoming 9 erasing from 'lorenipsum'")
{
    std::map<char, std::string> std(base_std_map);
    ft::map<char, std::string>  ft(base_ft_map);

    std.erase(std.begin());
    ft.erase(ft.begin());

    CHECK(ft.size() == std.size());
    CHECK(ft.size() == 9);
}

TEST_CASE("test map erase() iterator doesn't decrease map size if value doesn't exist")
{
    ft::map<char, std::string> ft(base_ft_map);

    ft.erase(ft.end());

    CHECK(ft.size() == 10);
}

TEST_CASE("test map erase() key succesfully erases 'o'")
{
    ft::map<char, std::string> ft(base_ft_map);

    ft.erase('O');

    CHECK(ft.find('O') == ft.end());
}

TEST_CASE("test map erase() key decreases map size by 1 becoming 9 erasing from 'lorenipsum'")
{
    std::map<char, std::string> std(base_std_map);
    ft::map<char, std::string>  ft(base_ft_map);

    std.erase('O');
    ft.erase('O');

    CHECK(ft.size() == std.size());
    CHECK(ft.size() == 9);
}

TEST_CASE("test map erase() key doesn't decrease map size if value doesn't exist")
{
    std::map<char, std::string> std(base_std_map);
    ft::map<char, std::string>  ft(base_ft_map);

    std.erase('X');
    ft.erase('X');

    CHECK(ft.size() == std.size());
    CHECK(ft.size() == 10);
}

TEST_CASE("test map erase() key returns 1 if erased value exists")
{
    std::map<char, std::string> std(base_std_map);
    ft::map<char, std::string>  ft(base_ft_map);

    size_t std_return = std.erase('O');
    size_t ft_return  = ft.erase('O');

    CHECK(ft_return == std_return);
    CHECK(ft_return == 1);
}

TEST_CASE("test map erase() key returns 0 if erased value doesn't exist")
{
    std::map<char, std::string> std(base_std_map);
    ft::map<char, std::string>  ft(base_ft_map);

    size_t std_return = std.erase('X');
    size_t ft_return  = ft.erase('X');

    CHECK(ft_return == std_return);
    CHECK(ft_return == 0);
}

TEST_CASE("test map erase() range succesfully erases 'eilmn' from 'lorenipsum'")
{
    ft::map<char, std::string> ft(base_ft_map);

    ft::map<char, std::string>::iterator ft_it = ft.begin();

    for (int i = 0; i < 5; ++ft_it, ++i)
        ;

    ft.erase(ft.begin(), ft_it);

    CHECK(ft.find('E') == ft.end());
    CHECK(ft.find('I') == ft.end());
    CHECK(ft.find('L') == ft.end());
    CHECK(ft.find('M') == ft.end());
    CHECK(ft.find('N') == ft.end());
}

TEST_CASE("test map erase() range decreases map size by 5 when erasing 'eilmn' from 'lorenipsum'")
{
    std::map<char, std::string> std(base_std_map);
    ft::map<char, std::string>  ft(base_ft_map);

    std::map<char, std::string>::iterator std_it = std.begin();
    ft::map<char, std::string>::iterator  ft_it  = ft.begin();

    for (int i = 0; i < 5; ++std_it, ++ft_it, ++i)
        ;

    std.erase(std.begin(), std_it);
    ft.erase(ft.begin(), ft_it);

    CHECK(ft.size() == std.size());
    CHECK(ft.size() == 5);
}

TEST_CASE("test map erase() range doesn't decrease map size when erasing empty range")
{
    std::map<char, std::string> std(base_std_map);
    ft::map<char, std::string>  ft(base_ft_map);

    std.erase(std.begin(), std.begin());
    ft.erase(ft.begin(), ft.begin());

    CHECK(ft.size() == std.size());
    CHECK(ft.size() == 10);
}

TEST_CASE("test map swap() properly swaps between maps of same size with different values")
{
    std::map<char, std::string> std1(base_std_map);
    ft::map<char, std::string>  ft1(base_ft_map);

    std::map<char, std::string> std2 = populate(std2);
    ft::map<char, std::string>  ft2  = populate(ft2);

    std1.swap(std2);
    ft1.swap(ft2);

    compare_maps(ft1, std1);
}

TEST_CASE("test map swap() properly swaps between maps of different size")
{
    std::map<char, std::string> std1(base_std_map);
    ft::map<char, std::string>  ft1(base_ft_map);

    std::map<char, std::string> std2;
    ft::map<char, std::string>  ft2;

    std2.insert(std::make_pair('X', "X"));
    std2.insert(std::make_pair('Y', "Y"));
    std2.insert(std::make_pair('Z', "Z"));

    ft2.insert(ft::make_pair('X', "X"));
    ft2.insert(ft::make_pair('Y', "Y"));
    ft2.insert(ft::make_pair('Z', "Z"));

    std1.swap(std2);
    ft1.swap(ft2);

    compare_maps(ft1, std1);
}

TEST_CASE("test map swap() properly swaps between populated map and empty map")
{
    std::map<char, std::string> std1(base_std_map);
    ft::map<char, std::string>  ft1(base_ft_map);

    std::map<char, std::string> std2;
    ft::map<char, std::string>  ft2;

    std1.swap(std2);
    ft1.swap(ft2);

    compare_maps(ft1, std1);
}

TEST_CASE("test map swap() assert swap does a deep swap")
{
    std::map<char, std::string> std1(base_std_map);
    ft::map<char, std::string>  ft1(base_ft_map);

    std::map<char, std::string> std2;
    ft::map<char, std::string>  ft2;

    std2.insert(std::make_pair('X', "X"));
    std2.insert(std::make_pair('Y', "Y"));
    std2.insert(std::make_pair('Z', "Z"));

    ft2.insert(ft::make_pair('X', "X"));
    ft2.insert(ft::make_pair('Y', "Y"));
    ft2.insert(ft::make_pair('Z', "Z"));

    std1.swap(std2);
    std1.insert(base_std_map.begin(), base_std_map.end());

    ft1.swap(ft2);
    ft1.insert(base_ft_map.begin(), base_ft_map.end());

    CHECK_FALSE(ft1.size() == ft2.size());

    compare_maps(ft1, std1);
}

TEST_CASE("test map clear() leaves map empty")
{
    std::map<char, std::string> std(base_std_map);
    ft::map<char, std::string>  ft(base_ft_map);

    std.clear();
    ft.clear();

    compare_maps(ft, std);

    CHECK(ft.size() == 0);
    CHECK(ft.empty() == true);
}

TEST_CASE("test map clear() empty map does nothing")
{
    std::map<char, std::string> std;
    ft::map<char, std::string>  ft;

    ft.clear();

    compare_maps(ft, std);

    CHECK(ft.size() == 0);
    CHECK(ft.empty() == true);
}

TEST_CASE("test map size() map with size 10 resizes to 11 when inserted new item")
{
    std::map<char, std::string> std(base_std_map);
    ft::map<char, std::string> ft(base_ft_map);

    CHECK(ft.size() == std.size());
    CHECK(ft.size() == 10);

    std.insert(std::make_pair('X', "X"));
    ft.insert(ft::make_pair('X', "X"));

    CHECK(ft.size() == std.size());
    CHECK(ft.size() == 11);
}

TEST_CASE("test map size() map with size 10 resizes to 9 when erased one item")
{
    std::map<char, std::string> std(base_std_map);
    ft::map<char, std::string> ft(base_ft_map);

    CHECK(ft.size() == std.size());
    CHECK(ft.size() == 10);

    std.erase('O');
    ft.erase('O');

    CHECK(ft.size() == std.size());
    CHECK(ft.size() == 9);
}
