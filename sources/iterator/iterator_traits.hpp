/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 20:56:09 by maolivei          #+#    #+#             */
/*   Updated: 2023/01/24 21:09:38 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ITERATOR_TRAITS_HPP
#define FT_ITERATOR_TRAITS_HPP

#include <iterator>

namespace ft {

template <typename Iterator>
struct iterator_traits {
        typedef typename Iterator::value_type        value_type;
        typedef typename Iterator::pointer           pointer;
        typedef typename Iterator::reference         reference;
        typedef typename Iterator::difference_type   difference_type;
        typedef typename Iterator::iterator_category iterator_category;
};

template <typename T>
struct iterator_traits<T *> {
        typedef T                               value_type;
        typedef T                              *pointer;
        typedef T                              &reference;
        typedef std::ptrdiff_t                  difference_type;
        typedef std::random_access_iterator_tag iterator_category;
};

template <typename T>
struct iterator_traits<T const *> {
        typedef T                               value_type;
        typedef T const                        *pointer;
        typedef T const                        &reference;
        typedef std::ptrdiff_t                  difference_type;
        typedef std::random_access_iterator_tag iterator_category;
};

} /* namespace ft */

#endif /* FT_ITERATOR_TRAITS_HPP */
