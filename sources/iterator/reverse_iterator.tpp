/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.tpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:57:01 by maolivei          #+#    #+#             */
/*   Updated: 2023/01/30 12:44:31 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_REVERSE_ITERATOR_TPP
#define FT_REVERSE_ITERATOR_TPP

#include "reverse_iterator.hpp"

namespace ft {

template <typename Iterator>
reverse_iterator<Iterator>::reverse_iterator(void) : _ptr(NULL)
{
}

template <typename Iterator>
reverse_iterator<Iterator>::reverse_iterator(iterator_type const &x) : _ptr(x)
{
}

template <typename Iterator>
reverse_iterator<Iterator>::reverse_iterator(reverse_iterator const &src) : _ptr(src._ptr)
{
}

template <typename Iterator>
template <typename T>
reverse_iterator<Iterator>::reverse_iterator(reverse_iterator<T> const &src) : _ptr(src.base())
{
}

template <typename Iterator>
reverse_iterator<Iterator>::~reverse_iterator(void)
{
}

template <typename Iterator>
reverse_iterator<Iterator> &
reverse_iterator<Iterator>::operator=(reverse_iterator<Iterator> const &src)
{
    _ptr = src._ptr;
    return (*this);
}

template <typename Iterator>
reverse_iterator<Iterator> &reverse_iterator<Iterator>::operator++(void)
{
    --_ptr;
    return (*this);
}

template <typename Iterator>
reverse_iterator<Iterator> reverse_iterator<Iterator>::operator++(int)
{
    reverse_iterator tmp(*this);
    _ptr--;
    return (tmp);
}

template <typename Iterator>
reverse_iterator<Iterator> &reverse_iterator<Iterator>::operator+=(difference_type n)
{
    _ptr -= n;
    return (*this);
}

template <typename Iterator>
reverse_iterator<Iterator> reverse_iterator<Iterator>::operator+(difference_type n) const
{
    return (reverse_iterator(_ptr - n));
}

template <typename Iterator>
reverse_iterator<Iterator> &reverse_iterator<Iterator>::operator--(void)
{
    ++_ptr;
    return (*this);
}

template <typename Iterator>
reverse_iterator<Iterator> reverse_iterator<Iterator>::operator--(int)
{
    reverse_iterator tmp(*this);
    _ptr++;
    return (tmp);
}

template <typename Iterator>
reverse_iterator<Iterator> &reverse_iterator<Iterator>::operator-=(difference_type n)
{
    _ptr += n;
    return (*this);
}

template <typename Iterator>
reverse_iterator<Iterator> reverse_iterator<Iterator>::operator-(difference_type n) const
{
    return (reverse_iterator(_ptr + n));
}

template <typename Iterator>
typename reverse_iterator<Iterator>::reference reverse_iterator<Iterator>::operator*(void) const
{
    return (*--_ptr);
}

template <typename Iterator>
typename reverse_iterator<Iterator>::pointer reverse_iterator<Iterator>::operator->(void) const
{
    return (--_ptr);
}

template <typename Iterator>
typename reverse_iterator<Iterator>::reference
reverse_iterator<Iterator>::operator[](difference_type n) const
{
    return (_ptr[-n - 1]);
}

template <typename Iterator>
typename reverse_iterator<Iterator>::iterator_type reverse_iterator<Iterator>::base(void) const
{
    return (_ptr);
}

} /* namespace ft */

#endif /* FT_REVERSE_ITERATOR_TPP */
