/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.tpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:57:01 by maolivei          #+#    #+#             */
/*   Updated: 2023/01/24 21:09:53 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_REVERSE_ITERATOR_TPP
#define FT_REVERSE_ITERATOR_TPP

#include "reverse_iterator.hpp"

namespace ft {

template <typename T>
reverse_iterator<T>::reverse_iterator(void) : _ptr(NULL)
{
}

template <typename T>
reverse_iterator<T>::reverse_iterator(iterator_type x) : _ptr(x)
{
}

template <typename T>
reverse_iterator<T>::reverse_iterator(reverse_iterator<T> const &src) : _ptr(src._ptr)
{
}

template <typename T>
reverse_iterator<T>::~reverse_iterator(void)
{
}

template <typename T>
reverse_iterator<T> &reverse_iterator<T>::operator=(reverse_iterator<T> const &src)
{
    _ptr = src._ptr;
    return (*this);
}

template <typename T>
reverse_iterator<T> &reverse_iterator<T>::operator++(void)
{
    --_ptr;
    return (*this);
}

template <typename T>
reverse_iterator<T> reverse_iterator<T>::operator++(int)
{
    reverse_iterator tmp(*this);
    _ptr--;
    return (tmp);
}

template <typename T>
reverse_iterator<T> &reverse_iterator<T>::operator+=(difference_type n)
{
    _ptr -= n;
    return (*this);
}

template <typename T>
reverse_iterator<T> reverse_iterator<T>::operator+(difference_type n) const
{
    return (reverse_iterator(_ptr - n));
}

template <typename T>
reverse_iterator<T> &reverse_iterator<T>::operator--(void)
{
    ++_ptr;
    return (*this);
}

template <typename T>
reverse_iterator<T> reverse_iterator<T>::operator--(int)
{
    reverse_iterator tmp(*this);
    _ptr++;
    return (tmp);
}

template <typename T>
reverse_iterator<T> &reverse_iterator<T>::operator-=(difference_type n)
{
    _ptr += n;
    return (*this);
}

template <typename T>
reverse_iterator<T> reverse_iterator<T>::operator-(difference_type n) const
{
    return (reverse_iterator(_ptr + n));
}

template <typename T>
reverse_iterator<T>::reference reverse_iterator<T>::operator*(void) const
{
    return (*--_ptr);
}

template <typename T>
reverse_iterator<T>::pointer reverse_iterator<T>::operator->(void) const
{
    return (--_ptr);
}

template <typename T>
reverse_iterator<T>::reference reverse_iterator<T>::operator[](difference_type n) const
{
    return (_ptr[-n - 1]);
}

template <typename T>
reverse_iterator<T>::iterator_type reverse_iterator<T>::base(void) const
{
    return (_ptr);
}

} /* namespace ft */

#endif /* FT_REVERSE_ITERATOR_TPP */
