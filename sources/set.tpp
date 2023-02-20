/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.tpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:48:46 by maolivei          #+#    #+#             */
/*   Updated: 2023/02/20 11:13:36 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SET_TPP
#define FT_SET_TPP

#include "set.hpp"

namespace ft {

/************************** CONSTRUCTORS, DESTRUCTOR AND ASSIGN OPERATOR **************************/

template <SET_TEMPLATE>
SET_CLASS::set(key_compare const &comp, allocator_type const &alloc) : _tree(tree_type(comp, alloc))
{
}

template <SET_TEMPLATE>
template <typename Iterator>
SET_CLASS::set(Iterator              first,
               Iterator              last,
               key_compare const    &comp,
               allocator_type const &alloc) :
    _tree(tree_type(comp, alloc))
{
    insert(first, last);
}

template <SET_TEMPLATE>
SET_CLASS::set(set const &src) : _tree(tree_type(src._tree))
{
}

template <SET_TEMPLATE>
SET_CLASS &SET_CLASS::operator=(set const &src)
{
    if (this == &src)
        return (*this);
    _tree = src._tree;
    return (*this);
}

template <SET_TEMPLATE>
SET_CLASS::~set(void)
{
    clear();
}

/******************************************** ITERATORS *******************************************/

template <SET_TEMPLATE>
typename SET_CLASS::iterator SET_CLASS::begin(void)
{
    return (_tree.begin());
}

template <SET_TEMPLATE>
typename SET_CLASS::const_iterator SET_CLASS::begin(void) const
{
    return (_tree.begin());
}

template <SET_TEMPLATE>
typename SET_CLASS::iterator SET_CLASS::end(void)
{
    return (_tree.end());
}

template <SET_TEMPLATE>
typename SET_CLASS::const_iterator SET_CLASS::end(void) const
{
    return (_tree.end());
}

template <SET_TEMPLATE>
typename SET_CLASS::reverse_iterator SET_CLASS::rbegin(void)
{
    return (_tree.rbegin());
}

template <SET_TEMPLATE>
typename SET_CLASS::const_reverse_iterator SET_CLASS::rbegin(void) const
{
    return (_tree.rbegin());
}

template <SET_TEMPLATE>
typename SET_CLASS::reverse_iterator SET_CLASS::rend(void)
{
    return (_tree.rend());
}

template <SET_TEMPLATE>
typename SET_CLASS::const_reverse_iterator SET_CLASS::rend(void) const
{
    return (_tree.rend());
}

/******************************************** CAPACITY ********************************************/

template <SET_TEMPLATE>
bool SET_CLASS::empty(void) const
{
    return (_tree.empty());
}

template <SET_TEMPLATE>
typename SET_CLASS::size_type SET_CLASS::size(void) const
{
    return (_tree.size());
}

template <SET_TEMPLATE>
typename SET_CLASS::size_type SET_CLASS::max_size(void) const
{
    return (_tree.max_size());
}

/******************************************** MODIFIERS *******************************************/

template <SET_TEMPLATE>
pair<typename SET_CLASS::iterator, bool> SET_CLASS::insert(value_type const &value)
{
    return (_tree.insert(value));
}

template <SET_TEMPLATE>
typename SET_CLASS::iterator SET_CLASS::insert(iterator position, value_type const &value)
{
    return (_tree.insert(position, value));
}

template <SET_TEMPLATE>
template <typename Iterator>
void SET_CLASS::insert(Iterator first, Iterator last)
{
    _tree.insert(first, last);
}

template <SET_TEMPLATE>
void SET_CLASS::erase(iterator position)
{
    _tree.erase(*position);
}

template <SET_TEMPLATE>
typename SET_CLASS::size_type SET_CLASS::erase(value_type const &value)
{
    if (find(value) == end())
        return (0);
    _tree.erase(value);
    return (1);
}

template <SET_TEMPLATE>
void SET_CLASS::erase(iterator first, iterator last)
{
    while (first != last)
        erase(first++);
}

template <SET_TEMPLATE>
void SET_CLASS::swap(set &src)
{
    _tree.swap(src._tree);
}

template <SET_TEMPLATE>
void SET_CLASS::clear(void)
{
    _tree.clear();
}

/******************************************** OBSERVERS *******************************************/

template <SET_TEMPLATE>
typename SET_CLASS::key_compare SET_CLASS::key_comp(void) const
{
    return (_tree.key_comp());
}

template <SET_TEMPLATE>
typename SET_CLASS::value_compare SET_CLASS::value_comp(void) const
{
    return (value_compare(_tree.key_comp()));
}

/**************************************** LOOKUP OPERATIONS ***************************************/

template <SET_TEMPLATE>
typename SET_CLASS::iterator SET_CLASS::find(value_type const &value)
{
    return (iterator(_tree.find(value)));
}

template <SET_TEMPLATE>
typename SET_CLASS::const_iterator SET_CLASS::find(value_type const &value) const
{
    return (const_iterator(_tree.find(value)));
}

template <SET_TEMPLATE>
typename SET_CLASS::size_type SET_CLASS::count(value_type const &value) const
{
    return (_tree.count(value));
}

template <SET_TEMPLATE>
typename SET_CLASS::iterator SET_CLASS::lower_bound(value_type const &value)
{
    return (_tree.lower_bound(value));
}

template <SET_TEMPLATE>
typename SET_CLASS::const_iterator SET_CLASS::lower_bound(value_type const &value) const
{
    return (_tree.lower_bound(value));
}

template <SET_TEMPLATE>
typename SET_CLASS::iterator SET_CLASS::upper_bound(value_type const &value)
{
    return (_tree.upper_bound(value));
}

template <SET_TEMPLATE>
typename SET_CLASS::const_iterator SET_CLASS::upper_bound(value_type const &value) const
{
    return (_tree.upper_bound(value));
}

template <SET_TEMPLATE>
pair<typename SET_CLASS::iterator, typename SET_CLASS::iterator>
SET_CLASS::equal_range(value_type const &value)
{
    return (_tree.equal_range(value));
}

template <SET_TEMPLATE>
pair<typename SET_CLASS::const_iterator, typename SET_CLASS::const_iterator>
SET_CLASS::equal_range(value_type const &value) const
{
    return (_tree.equal_range(value));
}

/******************************************** ALLOCATOR *******************************************/

template <SET_TEMPLATE>
typename SET_CLASS::allocator_type SET_CLASS::get_allocator(void) const
{
    return (_tree.get_allocator());
}

} /* namespace ft */

#endif /* FT_SET_TPP */
