/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_base.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 20:56:09 by maolivei          #+#    #+#             */
/*   Updated: 2023/01/24 21:09:33 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ITERATOR_BASE_HPP
#define FT_ITERATOR_BASE_HPP

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

} /* namespace ft */

#endif /* FT_ITERATOR_BASE_HPP */
