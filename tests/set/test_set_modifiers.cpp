/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set_modifiers.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 20:52:31 by maolivei          #+#    #+#             */
/*   Updated: 2023/02/20 12:02:14 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.hpp"

TEST_CASE("test set insert() successfully insert 'x'")
{
    std::set<char> std;
    ft::set<char>  ft;

    CHECK(std.find('X') == std.end());
    CHECK(ft.find('X') == ft.end());

    std.insert('X');
    ft.insert('X');

    CHECK(*(ft.find('X')) == *(std.find('X')));
    CHECK(*(ft.find('X')) == 'X');
}

TEST_CASE("test set insert() return pair second value is true when value doesn't exist")
{
    std::set<char> std;
    ft::set<char>  ft;

    std::pair<std::set<char>::iterator, bool> std_pair;
    ft::pair<ft::set<char>::iterator, bool>   ft_pair;

    std_pair = std.insert('X');
    ft_pair  = ft.insert('X');

    CHECK(*(ft_pair.first) == *(std_pair.first));
    CHECK(ft_pair.second == std_pair.second);
    CHECK(*(ft_pair.first) == 'X');
    CHECK(ft_pair.second == true);
}

TEST_CASE("test set insert() return pair second value is false when value exists")
{
    std::pair<std::set<char>::iterator, bool> std_pair;
    ft::pair<ft::set<char>::iterator, bool>   ft_pair;

    std_pair = base_std_set.insert('O');
    ft_pair  = base_ft_set.insert('O');

    CHECK(*(ft_pair.first) == *(std_pair.first));
    CHECK(ft_pair.second == std_pair.second);
    CHECK(*(ft_pair.first) == 'O');
    CHECK(ft_pair.second == false);
}

TEST_CASE("test set insert() increases map size by 1 when value doesn't exist")
{
    std::set<char> std;
    ft::set<char>  ft;

    std.insert('X');
    ft.insert('X');

    CHECK(ft.size() == std.size());
    CHECK(ft.size() == 1);
}

TEST_CASE("test set insert() doesn't increase map size when value already exist")
{
    std::set<char> std;
    ft::set<char>  ft;

    std.insert('X');
    ft.insert('X');

    std.insert('X');
    ft.insert('X');

    CHECK(ft.size() == std.size());
    CHECK(ft.size() == 1);
}

TEST_CASE("test set insert() hint succesfully insert 'x'")
{
    std::set<char> std;
    ft::set<char>  ft;

    CHECK(std.find('X') == std.end());
    CHECK(ft.find('X') == ft.end());

    std.insert(std.begin(), 'X');
    ft.insert(ft.begin(), 'X');

    CHECK(*(ft.find('X')) == *(std.find('X')));
    CHECK(*(ft.find('X')) == 'X');
}

TEST_CASE("test set insert() hint return iterator to inserted value if it doesn't exist")
{
    std::set<char> std;
    ft::set<char>  ft;

    std::set<char>::iterator std_it;
    ft::set<char>::iterator  ft_it;

    std_it = std.insert(std.begin(), 'X');
    ft_it  = ft.insert(ft.begin(), 'X');

    CHECK(*(ft_it) == *(std_it));
    CHECK(*(ft_it) == *(ft.find('X')));
    CHECK(*(ft_it) == 'X');
}

TEST_CASE("test set insert() hint return iterator to existing value if it exists")
{
    std::set<char> std;
    ft::set<char>  ft;

    std::set<char>::iterator std_it;
    ft::set<char>::iterator  ft_it;

    std.insert('X');
    ft.insert('X');

    std_it = std.insert(std.begin(), 'X');
    ft_it  = ft.insert(ft.begin(), 'X');

    CHECK(*(ft_it) == *(std_it));
    CHECK(*(ft_it) == *(ft.find('X')));
    CHECK(*(ft_it) == 'X');
    CHECK(ft_it == ft.begin());
    CHECK(ft.size() == 1); // size shouldn't change since value already existed
}

TEST_CASE("test set insert() hint increases map size by 1 when value doesn't exist")
{
    std::set<char> std;
    ft::set<char>  ft;

    std.insert(std.begin(), 'X');
    ft.insert(ft.begin(), 'X');

    CHECK(ft.size() == std.size());
    CHECK(ft.size() == 1);
}

TEST_CASE("test set insert() hint doesn't increase map size when value already exist")
{
    std::set<char> std;
    ft::set<char>  ft;

    std.insert('X');
    ft.insert('X');

    std.insert(std.begin(), 'X');
    ft.insert(ft.begin(), 'X');

    CHECK(ft.size() == std.size());
    CHECK(ft.size() == 1);
}

TEST_CASE("test set insert() range successfully insert 'lorenipsum' from base map")
{
    std::set<char> std;
    ft::set<char>  ft;

    std.insert(base_std_set.begin(), base_std_set.end());
    ft.insert(base_ft_set.begin(), base_ft_set.end());

    std::set<char>::iterator std_it     = std.begin();
    ft::set<char>::iterator  ft_it      = ft.begin();
    ft::set<char>::iterator  base_ft_it = base_ft_set.begin();

    for (; std_it != std.end(); ++std_it, ++ft_it, ++base_ft_it) {
        CHECK(*(std_it) == *(ft_it));
        CHECK(*(std_it) == *(ft_it));
        CHECK(*(base_ft_it) == *(ft_it));
        CHECK(*(base_ft_it) == *(ft_it));
    }
}

TEST_CASE("test set insert() range increases map size by 10 when inserting 'lorenipsum'")
{
    std::set<char> std;
    ft::set<char>  ft;

    std.insert(base_std_set.begin(), base_std_set.end());
    ft.insert(base_ft_set.begin(), base_ft_set.end());

    CHECK(ft.size() == std.size());
    CHECK(ft.size() == 10);
}

TEST_CASE("test set insert() range doesn't increase map size inserting existing values")
{
    std::set<char> std;
    ft::set<char>  ft;

    std.insert(base_std_set.begin(), base_std_set.end());
    ft.insert(base_ft_set.begin(), base_ft_set.end());

    std.insert(base_std_set.begin(), base_std_set.end());
    ft.insert(base_ft_set.begin(), base_ft_set.end());

    CHECK(ft.size() == std.size());
    CHECK(ft.size() == 10);
}

TEST_CASE("test set erase() iterator succesfully erases 'o'")
{
    ft::set<char> ft(base_ft_set);

    ft.erase(ft.begin());

    CHECK(ft.find('E') == ft.end());
}

TEST_CASE("test set erase() iterator decreases map size by 1 becoming 9 erasing from 'lorenipsum'")
{
    std::set<char> std(base_std_set);
    ft::set<char>  ft(base_ft_set);

    std.erase(std.begin());
    ft.erase(ft.begin());

    CHECK(ft.size() == std.size());
    CHECK(ft.size() == 9);
}

TEST_CASE("test set erase() iterator doesn't decrease map size if value doesn't exist")
{
    ft::set<char> ft(base_ft_set);

    ft.erase(ft.end());

    CHECK(ft.size() == 10);
}

TEST_CASE("test set erase() key succesfully erases 'o'")
{
    ft::set<char> ft(base_ft_set);

    ft.erase('O');

    CHECK(ft.find('O') == ft.end());
}

TEST_CASE("test set erase() key decreases map size by 1 becoming 9 erasing from 'lorenipsum'")
{
    std::set<char> std(base_std_set);
    ft::set<char>  ft(base_ft_set);

    std.erase('O');
    ft.erase('O');

    CHECK(ft.size() == std.size());
    CHECK(ft.size() == 9);
}

TEST_CASE("test set erase() key doesn't decrease map size if value doesn't exist")
{
    std::set<char> std(base_std_set);
    ft::set<char>  ft(base_ft_set);

    std.erase('X');
    ft.erase('X');

    CHECK(ft.size() == std.size());
    CHECK(ft.size() == 10);
}

TEST_CASE("test set erase() key returns 1 if erased value exists")
{
    std::set<char> std(base_std_set);
    ft::set<char>  ft(base_ft_set);

    size_t std_return = std.erase('O');
    size_t ft_return  = ft.erase('O');

    CHECK(ft_return == std_return);
    CHECK(ft_return == 1);
}

TEST_CASE("test set erase() key returns 0 if erased value doesn't exist")
{
    std::set<char> std(base_std_set);
    ft::set<char>  ft(base_ft_set);

    size_t std_return = std.erase('X');
    size_t ft_return  = ft.erase('X');

    CHECK(ft_return == std_return);
    CHECK(ft_return == 0);
}

TEST_CASE("test set erase() range succesfully erases 'eilmn' from 'lorenipsum'")
{
    ft::set<char> ft(base_ft_set);

    ft::set<char>::iterator ft_it = ft.begin();

    for (int i = 0; i < 5; ++ft_it, ++i)
        ;

    ft.erase(ft.begin(), ft_it);

    CHECK(ft.find('E') == ft.end());
    CHECK(ft.find('I') == ft.end());
    CHECK(ft.find('L') == ft.end());
    CHECK(ft.find('M') == ft.end());
    CHECK(ft.find('N') == ft.end());
}

TEST_CASE("test set erase() range decreases map size by 5 when erasing 'eilmn' from 'lorenipsum'")
{
    std::set<char> std(base_std_set);
    ft::set<char>  ft(base_ft_set);

    std::set<char>::iterator std_it = std.begin();
    ft::set<char>::iterator  ft_it  = ft.begin();

    for (int i = 0; i < 5; ++std_it, ++ft_it, ++i)
        ;

    std.erase(std.begin(), std_it);
    ft.erase(ft.begin(), ft_it);

    CHECK(ft.size() == std.size());
    CHECK(ft.size() == 5);
}

TEST_CASE("test set erase() range doesn't decrease map size when erasing empty range")
{
    std::set<char> std(base_std_set);
    ft::set<char>  ft(base_ft_set);

    std.erase(std.begin(), std.begin());
    ft.erase(ft.begin(), ft.begin());

    CHECK(ft.size() == std.size());
    CHECK(ft.size() == 10);
}

TEST_CASE("test set swap() properly swaps between maps of same size with different values")
{
    std::set<char> std1(base_std_set);
    ft::set<char>  ft1(base_ft_set);

    std::set<char> std2 = populate_set(std2);
    ft::set<char>  ft2  = populate_set(ft2);

    std1.swap(std2);
    ft1.swap(ft2);

    compare_sets(ft1, std1);
}

TEST_CASE("test set swap() properly swaps between maps of different size")
{
    std::set<char> std1(base_std_set);
    ft::set<char>  ft1(base_ft_set);

    std::set<char> std2;
    ft::set<char>  ft2;

    std2.insert('X');
    std2.insert('Y');
    std2.insert('Z');

    ft2.insert('X');
    ft2.insert('Y');
    ft2.insert('Z');

    std1.swap(std2);
    ft1.swap(ft2);

    compare_sets(ft1, std1);
}

TEST_CASE("test set swap() properly swaps between populated map and empty map")
{
    std::set<char> std1(base_std_set);
    ft::set<char>  ft1(base_ft_set);

    std::set<char> std2;
    ft::set<char>  ft2;

    std1.swap(std2);
    ft1.swap(ft2);

    compare_sets(ft1, std1);
}

TEST_CASE("test set swap() assert swap does a deep swap")
{
    std::set<char> std1(base_std_set);
    ft::set<char>  ft1(base_ft_set);

    std::set<char> std2;
    ft::set<char>  ft2;

    std2.insert('X');
    std2.insert('Y');
    std2.insert('Z');

    ft2.insert('X');
    ft2.insert('Y');
    ft2.insert('Z');

    std1.swap(std2);
    std1.insert(base_std_set.begin(), base_std_set.end());

    ft1.swap(ft2);
    ft1.insert(base_ft_set.begin(), base_ft_set.end());

    CHECK_FALSE(ft1.size() == ft2.size());

    compare_sets(ft1, std1);
}

TEST_CASE("test set clear() leaves map empty")
{
    std::set<char> std(base_std_set);
    ft::set<char>  ft(base_ft_set);

    std.clear();
    ft.clear();

    compare_sets(ft, std);

    CHECK(ft.size() == 0);
    CHECK(ft.empty() == true);
}

TEST_CASE("test set clear() empty map does nothing")
{
    std::set<char> std;
    ft::set<char>  ft;

    ft.clear();

    compare_sets(ft, std);

    CHECK(ft.size() == 0);
    CHECK(ft.empty() == true);
}
