/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 20:56:09 by maolivei          #+#    #+#             */
/*   Updated: 2023/01/24 16:23:14 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ITERATOR_HPP
#define FT_ITERATOR_HPP

#include <cstddef>

namespace ft {

template <typename Category,
          typename T,
          typename Distance  = std::ptrdiff_t,
          typename Pointer   = T *,
          typename Reference = T &>
struct iterator {
        typedef Category  iterator_category;
        typedef T         value_type;
        typedef Distance  difference_type;
        typedef Pointer   pointer;
        typedef Reference reference;
};

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

#endif /* FT_ITERATOR_HPP */
