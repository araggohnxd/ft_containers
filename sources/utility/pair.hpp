/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:03:21 by maolivei          #+#    #+#             */
/*   Updated: 2023/01/25 13:06:37 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PAIR_HPP
#define FT_PAIR_HPP

namespace ft {

template <typename T1, typename T2>
struct pair {
        typedef T1 first_type;
        typedef T2 second_type;

        pair(void);
        template <typename U, typename V>
        pair(pair<U, V> const &src);
        pair(first_type const &x, second_type const &y);
        ~pair(void);
        pair &operator=(pair const &rhs);

        first_type  first;
        second_type second;
};

template <typename T1, typename T2>
pair<T1, T2> make_pair(T1 x, T2 y)
{
    return (pair<T1, T2>(x, y));
}

template <typename T1, typename T2>
bool operator==(pair<T1, T2> const &lhs, pair<T1, T2> const &rhs)
{
    return (lhs.first == rhs.first && lhs.second == rhs.second);
}

template <typename T1, typename T2>
bool operator!=(pair<T1, T2> const &lhs, pair<T1, T2> const &rhs)
{
    return (lhs.first != rhs.first && lhs.second != rhs.second);
}

template <typename T1, typename T2>
bool operator<(pair<T1, T2> const &lhs, pair<T1, T2> const &rhs)
{
    return (lhs.first < rhs.first && lhs.second < rhs.second);
}

template <typename T1, typename T2>
bool operator<=(pair<T1, T2> const &lhs, pair<T1, T2> const &rhs)
{
    return (lhs.first <= rhs.first && lhs.second <= rhs.second);
}

template <typename T1, typename T2>
bool operator>(pair<T1, T2> const &lhs, pair<T1, T2> const &rhs)
{
    return (lhs.first > rhs.first && lhs.second > rhs.second);
}

template <typename T1, typename T2>
bool operator>=(pair<T1, T2> const &lhs, pair<T1, T2> const &rhs)
{
    return (lhs.first >= rhs.first && lhs.second >= rhs.second);
}

} /* namespace ft */

#include "pair.tpp"

#endif /* FT_PAIR_HPP */
