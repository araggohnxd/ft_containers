/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:24:50 by maolivei          #+#    #+#             */
/*   Updated: 2023/01/25 12:59:14 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IS_INTEGRAL_HPP
#define FT_IS_INTEGRAL_HPP

#include "integral_constant.hpp"

namespace ft {

template <typename T>
struct is_integral : public false_type {};

template <>
struct is_integral<bool> : public true_type {};

template <>
struct is_integral<wchar_t> : public true_type {};

template <>
struct is_integral<signed char> : public true_type {};

template <>
struct is_integral<char> : public true_type {};

template <>
struct is_integral<short> : public true_type {};

template <>
struct is_integral<int> : public true_type {};

template <>
struct is_integral<long> : public true_type {};

template <>
struct is_integral<long long> : public true_type {};

template <>
struct is_integral<unsigned char> : public true_type {};

template <>
struct is_integral<unsigned short> : public true_type {};

template <>
struct is_integral<unsigned int> : public true_type {};

template <>
struct is_integral<unsigned long> : public true_type {};

template <>
struct is_integral<unsigned long long> : public true_type {};

} /* namespace ft */

#endif /* FT_IS_INTEGRAL_HPP */
