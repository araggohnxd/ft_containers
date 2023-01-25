/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:24:50 by maolivei          #+#    #+#             */
/*   Updated: 2023/01/25 12:57:52 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENABLE_IF_HPP
#define FT_ENABLE_IF_HPP

namespace ft {

template <bool, typename>
struct enable_if {};

template <typename T>
struct enable_if<true, T> {
        typedef T type;
};

} /* namespace ft */

#endif /* FT_ENABLE_IF_HPP */
