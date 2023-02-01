/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.tpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:57:01 by maolivei          #+#    #+#             */
/*   Updated: 2023/01/30 12:41:10 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RANDOM_ACCESS_ITERATOR_TPP
#define FT_RANDOM_ACCESS_ITERATOR_TPP

#include "random_access_iterator.hpp"

namespace ft {

template <typename Iterator>
random_access_iterator<Iterator>::random_access_iterator(void) : _ptr(NULL)
{
}

template <typename Iterator>
random_access_iterator<Iterator>::random_access_iterator(iterator_type const &x) : _ptr(x)
{
}

template <typename Iterator>
random_access_iterator<Iterator>::random_access_iterator(random_access_iterator const &src) :
    _ptr(src._ptr)
{
}

template <typename Iterator>
template <typename T>
random_access_iterator<Iterator>::random_access_iterator(random_access_iterator<T> const &src) :
    _ptr(src.base())
{
}

template <typename Iterator>
random_access_iterator<Iterator>::~random_access_iterator(void)
{
}

template <typename Iterator>
random_access_iterator<Iterator> &
random_access_iterator<Iterator>::operator=(random_access_iterator<Iterator> const &src)
{
    _ptr = src._ptr;
    return (*this);
}

template <typename Iterator>
random_access_iterator<Iterator> &random_access_iterator<Iterator>::operator++(void)
{
    ++_ptr;
    return (*this);
}

template <typename Iterator>
random_access_iterator<Iterator> random_access_iterator<Iterator>::operator++(int)
{
    random_access_iterator tmp(*this);
    _ptr++;
    return (tmp);
}

template <typename Iterator>
random_access_iterator<Iterator> &random_access_iterator<Iterator>::operator+=(difference_type n)
{
    _ptr += n;
    return (*this);
}

template <typename Iterator>
random_access_iterator<Iterator>
random_access_iterator<Iterator>::operator+(difference_type n) const
{
    return (random_access_iterator(_ptr + n));
}

template <typename Iterator>
random_access_iterator<Iterator> &random_access_iterator<Iterator>::operator--(void)
{
    --_ptr;
    return (*this);
}

template <typename Iterator>
random_access_iterator<Iterator> random_access_iterator<Iterator>::operator--(int)
{
    random_access_iterator tmp(*this);
    _ptr--;
    return (tmp);
}

template <typename Iterator>
random_access_iterator<Iterator> &random_access_iterator<Iterator>::operator-=(difference_type n)
{
    _ptr -= n;
    return (*this);
}

template <typename Iterator>
random_access_iterator<Iterator>
random_access_iterator<Iterator>::operator-(difference_type n) const
{
    return (random_access_iterator(_ptr - n));
}

template <typename Iterator>
typename random_access_iterator<Iterator>::reference
random_access_iterator<Iterator>::operator*(void) const
{
    return (*_ptr);
}

template <typename Iterator>
typename random_access_iterator<Iterator>::pointer
random_access_iterator<Iterator>::operator->(void) const
{
    return (_ptr);
}

template <typename Iterator>
typename random_access_iterator<Iterator>::reference
random_access_iterator<Iterator>::operator[](difference_type n) const
{
    return (_ptr[n]);
}

template <typename Iterator>
typename random_access_iterator<Iterator>::iterator_type
random_access_iterator<Iterator>::base(void) const
{
    return (_ptr);
}

} /* namespace ft */

#endif /* FT_RANDOM_ACCESS_ITERATOR_TPP */
