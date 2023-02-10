/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_functions.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 20:56:09 by maolivei          #+#    #+#             */
/*   Updated: 2023/02/10 20:14:41 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ITERATOR_FUNCTIONS_HPP
#define FT_ITERATOR_FUNCTIONS_HPP

#include "iterator_traits.hpp"

namespace ft {

template <typename Iter>
typename iterator_traits<Iter>::difference_type distance(Iter first, Iter last)
{
    typename iterator_traits<Iter>::difference_type _distance = 0;

    while (first++ != last)
        ++_distance;
    return (_distance);
}

} /* namespace ft */

#endif /* FT_ITERATOR_FUNCTIONS_HPP */
