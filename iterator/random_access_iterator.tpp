/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.tpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:57:01 by maolivei          #+#    #+#             */
/*   Updated: 2023/01/24 21:09:42 by maolivei         ###   ########.fr       */
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
random_access_iterator<T>::random_access_iterator(iterator_type x) : _ptr(x)
{
}

template <typename T>
random_access_iterator<T>::random_access_iterator(random_access_iterator<T> const &src) : _ptr(src._ptr)
{
}

template <typename T>
random_access_iterator<T>::~random_access_iterator(void)
{
}

template <typename T>
random_access_iterator<T> &random_access_iterator<T>::operator=(random_access_iterator<T> const &src)
{
    _ptr = src._ptr;
    return (*this);
}

template <typename T>
random_access_iterator<T> &random_access_iterator<T>::operator++(void)
{
    ++_ptr;
    return (*this);
}

template <typename T>
random_access_iterator<T> random_access_iterator<T>::operator++(int)
{
    random_access_iterator tmp(*this);
    _ptr++;
    return (tmp);
}

template <typename T>
random_access_iterator<T> &random_access_iterator<T>::operator+=(difference_type n)
{
    _ptr += n;
    return (*this);
}

template <typename T>
random_access_iterator<T> random_access_iterator<T>::operator+(difference_type n) const
{
    return (random_access_iterator(_ptr + n));
}

template <typename T>
random_access_iterator<T> &random_access_iterator<T>::operator--(void)
{
    --_ptr;
    return (*this);
}

template <typename T>
random_access_iterator<T> random_access_iterator<T>::operator--(int)
{
    random_access_iterator tmp(*this);
    _ptr--;
    return (tmp);
}

template <typename T>
random_access_iterator<T> &random_access_iterator<T>::operator-=(difference_type n)
{
    _ptr -= n;
    return (*this);
}

template <typename T>
random_access_iterator<T> random_access_iterator<T>::operator-(difference_type n) const
{
    return (random_access_iterator(_ptr - n));
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
