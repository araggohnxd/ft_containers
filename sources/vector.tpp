/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:01:01 by maolivei          #+#    #+#             */
/*   Updated: 2023/02/03 12:57:30 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_TPP
#define FT_VECTOR_TPP

#include "vector.hpp"
#include <iostream>

namespace ft {

template <typename T, typename Alloc>
vector<T, Alloc>::vector(vector const &src) :
    _data(NULL),
    _capacity(0),
    _size(0),
    _allocator(src._allocator)
{
    *this = src;
}

template <typename T, typename Alloc>
vector<T, Alloc>::vector(Alloc const &alloc) :
    _data(NULL),
    _capacity(0),
    _size(0),
    _allocator(alloc)
{
}

template <typename T, typename Alloc>
vector<T, Alloc>::vector(size_type n, T const &value, Alloc const &alloc) :
    _data(NULL),
    _capacity(n),
    _size(n),
    _allocator(alloc)
{
    if (_size > max_size())
        throw std::length_error("ft::vector ctor");
    _data = _allocator.allocate(_size);
    if (!_data)
        throw std::bad_alloc();
    for (size_type i = 0; i < _size; ++i)
        _allocator.construct((_data + i), value);
}

template <typename T, typename Alloc>
template <typename Iter>
vector<T, Alloc>::vector(Iter         first,
                         Iter         last,
                         Alloc const &alloc,
                         typename ft::enable_if<!ft::is_integral<Iter>::value>::type *) :
    _data(NULL),
    _capacity(ft::distance(first, last)),
    _size(ft::distance(first, last)),
    _allocator(alloc)
{
    if (_size > max_size())
        throw std::length_error("ft::vector ctor");
    _data = _allocator.allocate(_size);
    if (!_data)
        throw std::bad_alloc();
    for (size_type i = 0; i < _size; ++i)
        _allocator.construct((_data + i), *(first + i));
}

template <typename T, typename Alloc>
vector<T, Alloc>::~vector(void)
{
    clear();
    _allocator.deallocate(_data, _capacity);
}

template <typename T, typename Alloc>
vector<T, Alloc> &vector<T, Alloc>::operator=(vector const &src)
{
    if (this == &src)
        return (*this);
    clear();
    if (_capacity > 0)
        _allocator.deallocate(_data, _capacity);
    _allocator = src._allocator;
    _size      = src._size;
    _capacity  = src._capacity;
    _data      = _allocator.allocate(_capacity);
    if (!_data)
        throw std::bad_alloc();
    for (size_type i = 0; i < _size; ++i)
        _allocator.construct((_data + i), *(src._data + i));
    return (*this);
}

template <typename T, typename Alloc>
void vector<T, Alloc>::assign(size_type n, T const &value)
{
    if (n > max_size())
        throw std::length_error("ft::vector::assign()");
    clear();
    if (_capacity > 0)
        _allocator.deallocate(_data, _capacity);
    _capacity = n;
    _size     = n;
    _data     = _allocator.allocate(_size);
    if (!_data)
        throw std::bad_alloc();
    for (size_type i = 0; i < _size; ++i)
        _allocator.construct((_data + i), value);
}

template <typename T, typename Alloc>
template <typename Iter>
void vector<T, Alloc>::assign(Iter first,
                              Iter last,
                              typename ft::enable_if<!ft::is_integral<Iter>::value>::type *)
{

    difference_type distance = ft::distance(first, last);

    if (distance > max_size())
        throw std::length_error("ft::vector::assign()");
    clear();
    if (_capacity > 0)
        _allocator.deallocate(_data, _capacity);
    if (distance > _capacity)
        _capacity = distance;
    _size = distance;
    _data = _allocator.allocate(_size);
    if (!_data)
        throw std::bad_alloc();
    for (size_type i = 0; i < _size; ++i)
        _allocator.construct((_data + i), *(first + i));
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::allocator_type vector<T, Alloc>::get_allocator(void) const
{
    return (_allocator);
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::reference vector<T, Alloc>::at(size_type pos)
{
    if (pos >= _size)
        throw std::out_of_range("ft::vector::at()");
    return (*(begin() + pos));
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_reference vector<T, Alloc>::at(size_type pos) const
{
    if (pos >= _size)
        throw std::out_of_range("ft::vector::at() const");
    return (*(begin() + pos));
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::reference vector<T, Alloc>::operator[](size_type pos)
{
    if (pos >= _size)
        throw std::out_of_range("ft::vector::operator[]");
    return (*(begin() + pos));
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_reference vector<T, Alloc>::operator[](size_type pos) const
{
    if (pos >= _size)
        throw std::out_of_range("ft::vector::operator[] const");
    return (*(begin() + pos));
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::reference vector<T, Alloc>::front(void)
{
    return (*begin());
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_reference vector<T, Alloc>::front(void) const
{
    return (*begin());
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::reference vector<T, Alloc>::back(void)
{
    return (*(end() - 1));
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_reference vector<T, Alloc>::back(void) const
{
    return (*(end() - 1));
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::pointer vector<T, Alloc>::data(void)
{
    return (_data);
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_pointer vector<T, Alloc>::data(void) const
{
    return (_data);
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::begin(void)
{
    return (iterator(_data));
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_iterator vector<T, Alloc>::begin(void) const
{
    return (const_iterator(_data));
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::end(void)
{
    return (iterator(_data + _size));
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_iterator vector<T, Alloc>::end(void) const
{
    return (const_iterator(_data + _size));
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::reverse_iterator vector<T, Alloc>::rbegin(void)
{
    return (reverse_iterator(end()));
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_reverse_iterator vector<T, Alloc>::rbegin(void) const
{
    return (const_reverse_iterator(end()));
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::reverse_iterator vector<T, Alloc>::rend(void)
{
    return (reverse_iterator(begin()));
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_reverse_iterator vector<T, Alloc>::rend(void) const
{
    return (const_reverse_iterator(begin()));
}

template <typename T, typename Alloc>
bool vector<T, Alloc>::empty(void) const
{
    return (!_size);
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::size_type vector<T, Alloc>::size(void) const
{
    return (_size);
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::size_type vector<T, Alloc>::max_size(void) const
{
    return (_allocator.max_size());
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::size_type vector<T, Alloc>::capacity(void) const
{
    return (_capacity);
}

template <typename T, typename Alloc>
void vector<T, Alloc>::reserve(size_type new_cap)
{
    pointer   tmp;
    size_type i;

    if (new_cap <= _capacity)
        return;
    if (new_cap > max_size())
        throw std::length_error("ft::vector::reserve()");
    tmp = _allocator.allocate(new_cap);
    if (!tmp)
        throw std::bad_alloc();
    for (i = 0; i < _size; ++i)
        _allocator.construct((tmp + i), *(_data + i));
    clear();
    _allocator.deallocate(_data, _capacity);
    _data     = tmp;
    _size     = i;
    _capacity = new_cap;
}

template <typename T, typename Alloc>
void vector<T, Alloc>::clear(void)
{
    for (size_type i = 0; i < _size; ++i)
        _allocator.destroy(_data + i);
    _size = 0;
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::insert(iterator pos, T const &value)
{
    difference_type distance;

    if (pos < begin() || pos > end())
        throw std::out_of_range("ft::vector::insert()");
    distance = pos - begin();
    if (_size == _capacity)
        reserve(_size ? (_size * 2) : 1);
    for (difference_type i = _size; i > distance; --i) {
        _allocator.construct((_data + i), *(_data + i - 1));
        _allocator.destroy(_data + i - 1);
    }
    ++_size;
    _allocator.construct((_data + distance), value);
    return (iterator(_data + distance));
}

template <typename T, typename Alloc>
void vector<T, Alloc>::insert(iterator pos, size_type n, T const &value)
{
    difference_type distance;

    if (!n)
        return;
    if (pos < begin() || pos > end())
        throw std::out_of_range("ft::vector::insert()");
    distance = pos - begin();
    if ((_size + n) > _capacity)
        reserve(_size ? (_size * 2 + n) : n);
    for (difference_type i = _size; i > distance; --i) {
        _allocator.construct((_data + i + n - 1), *(_data + i - 1));
        _allocator.destroy(_data + i - 1);
    }
    _size += n;
    for (difference_type i = (distance + n - 1); n--; --i)
        _allocator.construct((_data + i), value);
}

template <typename T, typename Alloc>
template <typename Iter>
void vector<T, Alloc>::insert(iterator pos,
                              Iter     first,
                              Iter     last,
                              typename ft::enable_if<!ft::is_integral<Iter>::value>::type *)
{
    if (first > last)
        throw std::length_error("ft::vector::insert()");
    while (first != last) {
        pos = insert(pos, *first);
        ++pos;
        ++first;
    }
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::erase(iterator position)
{
    difference_type distance;

    if (position < begin() || position >= end())
        throw std::out_of_range("ft::vector::erase()");
    distance = position - begin();
    _allocator.destroy(_data + distance);
    for (difference_type i = distance; i < (_size - 1); ++i)
        _allocator.construct(_data + i, *(_data + i + 1));
    --_size;
    return (iterator(_data + distance));
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::erase(iterator first, iterator last)
{
    difference_type distance, n;

    if (first < begin() || first > end() || last < begin() || last > end())
        throw std::out_of_range("ft::vector::erase()");
    distance = first - begin();
    n        = last - first;
    for (size_type i = distance; i < (_size - n); ++i) {
        _allocator.construct(_data + i, *(_data + i + n));
        _allocator.destroy(_data + i + n);
    }
    _size -= n;
    return (iterator(_data + distance));
}

template <typename T, typename Alloc>
void vector<T, Alloc>::push_back(T const &value)
{
    if (_size == _capacity)
        reserve(_size ? (_size * 2) : 1);
    _allocator.construct((_data + _size), value);
    ++_size;
}

template <typename T, typename Alloc>
void vector<T, Alloc>::pop_back(void)
{
    if (!_size)
        return;
    _allocator.destroy(_data + (_size - 1));
    --_size;
}

template <typename T, typename Alloc>
void vector<T, Alloc>::resize(size_type n, value_type value)
{
    if (n < _size) {
        for (size_type i = n; i < _size; ++i)
            _allocator.destroy(_data + i);
    } else {
        if (n > _capacity)
            reserve(n);
        for (size_type i = _size; i < n; ++i)
            _allocator.construct((_data + i), value);
    }
    _size = n;
}

template <typename T, typename Alloc>
void vector<T, Alloc>::swap(vector &src)
{
    pointer   tmp_data     = src._data;
    size_type tmp_size     = src._size;
    size_type tmp_capacity = src._capacity;

    src._data     = _data;
    src._size     = _size;
    src._capacity = _capacity;
    _data         = tmp_data;
    _size         = tmp_size;
    _capacity     = tmp_capacity;
}

} /* namespace ft */

#endif /* FT_VECTOR_TPP */
