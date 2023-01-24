/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.tpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:57:01 by maolivei          #+#    #+#             */
/*   Updated: 2023/01/24 18:35:22 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RANDOM_ACCESS_ITERATOR_TPP
#define FT_RANDOM_ACCESS_ITERATOR_TPP

#include "random_access_iterator.hpp"

namespace ft {

template <typename T>
random_access_iterator<T>::random_access_iterator(void) : _ptr(NULL)
{
}

template <typename T>
random_access_iterator<T>::random_access_iterator(rai const &src) : _ptr(src._ptr)
{
}

template <typename T>
random_access_iterator<T>::~random_access_iterator(void)
{
}

template <typename T>
random_access_iterator<T> &random_access_iterator<T>::operator=(rai const &src)
{
    _ptr = src._ptr;
    return (*this);
}

template <typename T>
bool random_access_iterator<T>::operator==(rai const &rhs) const
{
    return (_ptr == rhs._ptr);
}

template <typename T>
bool random_access_iterator<T>::operator!=(rai const &rhs) const
{
    return (_ptr != rhs._ptr);
}

template <typename T>
bool random_access_iterator<T>::operator>=(rai const &rhs) const
{
    return (_ptr >= rhs._ptr);
}

template <typename T>
bool random_access_iterator<T>::operator<=(rai const &rhs) const
{
    return (_ptr <= rhs._ptr);
}

template <typename T>
bool random_access_iterator<T>::operator>(rai const &rhs) const
{
    return (_ptr > rhs._ptr);
}

template <typename T>
bool random_access_iterator<T>::operator<(rai const &rhs) const
{
    return (_ptr < rhs._ptr);
}

template <typename T>
random_access_iterator<T> random_access_iterator<T>::operator+(difference_type n) const
{
    return (rai(_ptr + n));
}
template <typename T>
random_access_iterator<T> random_access_iterator<T>::operator-(difference_type n) const
{
    return (rai(_ptr - n));
}

template <typename T>
random_access_iterator<T> random_access_iterator<T>::operator++(int)
{
    rai tmp(*this);
    _ptr++;
    return (tmp);
}

template <typename T>
random_access_iterator<T> &random_access_iterator<T>::operator++(void)
{
    ++_ptr;
    return (*this);
}

template <typename T>
random_access_iterator<T> random_access_iterator<T>::operator--(int)
{
    rai tmp(*this);
    _ptr--;
    return (tmp);
}

template <typename T>
random_access_iterator<T> &random_access_iterator<T>::operator--(void)
{
    --_ptr;
    return (*this);
}

template <typename T>
random_access_iterator<T> &random_access_iterator<T>::operator+=(difference_type n)
{
    _ptr += n;
    return (*this);
}

template <typename T>
random_access_iterator<T> &random_access_iterator<T>::operator-=(difference_type n)
{
    _ptr -= n;
    return (*this);
}

template <typename T>
random_access_iterator<T>::reference random_access_iterator<T>::operator*(void) const
{
    return (*_ptr);
}

template <typename T>
random_access_iterator<T>::pointer random_access_iterator<T>::operator->(void) const
{
    return (_ptr);
}

template <typename T>
random_access_iterator<T>::reference random_access_iterator<T>::operator[](difference_type n) const
{
    return (_ptr[n]);
}

template <typename T>
random_access_iterator<T>::iterator_type random_access_iterator<T>::base(void) const
{
    return (_ptr);
}

} /* namespace ft */

#endif /* FT_RANDOM_ACCESS_ITERATOR_TPP */
