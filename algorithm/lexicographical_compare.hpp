/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:02:59 by maolivei          #+#    #+#             */
/*   Updated: 2023/01/25 12:12:41 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEXICOGRAPHICAL_COMPARE_HPP
#define FT_LEXICOGRAPHICAL_COMPARE_HPP

namespace ft {

template <typename Iter1, typename Iter2>
bool lexicographical_compare(Iter1 first1, Iter1 last1, Iter2 first2, Iter2 last2)
{
    while (first1 != last1) {
        if (first2 == last2 || *first2 < *first1)
            return (false);
        else if (*first1 < *first2)
            return (true);
        ++first1;
        ++first2;
    }
    return (first2 != last2);
}

template <typename Iter1, typename Iter2, typename Compare>
bool lexicographical_compare(Iter1 first1, Iter1 last1, Iter2 first2, Iter2 last2, Compare comp)
{
    while (first1 != last1) {
        if (first2 == last2 || comp(*first2, *first1))
            return (false);
        else if (comp(*first1, *first2))
            return (true);
        ++first1;
        ++first2;
    }
    return (first2 != last2);
}

} /* namespace ft */

#endif /* FT_LEXICOGRAPHICAL_COMPARE_HPP */
