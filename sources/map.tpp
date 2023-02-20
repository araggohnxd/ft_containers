/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.tpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:48:46 by maolivei          #+#    #+#             */
/*   Updated: 2023/02/20 12:47:22 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_TPP
#define FT_MAP_TPP

#include "map.hpp"

namespace ft {

/************************** CONSTRUCTORS, DESTRUCTOR AND ASSIGN OPERATOR **************************/

template <MAP_TEMPLATE>
MAP_CLASS::map(key_compare const &comp, allocator_type const &alloc) : _tree(tree_type(comp, alloc))
{
}

template <MAP_TEMPLATE>
template <typename Iterator>
MAP_CLASS::map(Iterator              first,
               Iterator              last,
               key_compare const    &comp,
               allocator_type const &alloc) :
    _tree(tree_type(comp, alloc))
{
    insert(first, last);
}

template <MAP_TEMPLATE>
MAP_CLASS::map(map const &src) : _tree(tree_type(src._tree))
{
}

template <MAP_TEMPLATE>
MAP_CLASS &MAP_CLASS::operator=(map const &src)
{
    if (this == &src)
        return (*this);
    _tree = src._tree;
    return (*this);
}

template <MAP_TEMPLATE>
MAP_CLASS::~map(void)
{
    clear();
}

/******************************************** ITERATORS *******************************************/

template <MAP_TEMPLATE>
typename MAP_CLASS::iterator MAP_CLASS::begin(void)
{
    return (_tree.begin());
}

template <MAP_TEMPLATE>
typename MAP_CLASS::const_iterator MAP_CLASS::begin(void) const
{
    return (_tree.begin());
}

template <MAP_TEMPLATE>
typename MAP_CLASS::iterator MAP_CLASS::end(void)
{
    return (_tree.end());
}

template <MAP_TEMPLATE>
typename MAP_CLASS::const_iterator MAP_CLASS::end(void) const
{
    return (_tree.end());
}

template <MAP_TEMPLATE>
typename MAP_CLASS::reverse_iterator MAP_CLASS::rbegin(void)
{
    return (_tree.rbegin());
}

template <MAP_TEMPLATE>
typename MAP_CLASS::const_reverse_iterator MAP_CLASS::rbegin(void) const
{
    return (_tree.rbegin());
}

template <MAP_TEMPLATE>
typename MAP_CLASS::reverse_iterator MAP_CLASS::rend(void)
{
    return (_tree.rend());
}

template <MAP_TEMPLATE>
typename MAP_CLASS::const_reverse_iterator MAP_CLASS::rend(void) const
{
    return (_tree.rend());
}

/******************************************** CAPACITY ********************************************/

template <MAP_TEMPLATE>
bool MAP_CLASS::empty(void) const
{
    return (_tree.empty());
}

template <MAP_TEMPLATE>
typename MAP_CLASS::size_type MAP_CLASS::size(void) const
{
    return (_tree.size());
}

template <MAP_TEMPLATE>
typename MAP_CLASS::size_type MAP_CLASS::max_size(void) const
{
    return (_tree.max_size());
}

/***************************************** ELEMENT ACCESS *****************************************/

template <MAP_TEMPLATE>
typename MAP_CLASS::mapped_type &MAP_CLASS::operator[](key_type const &key)
{
    return ((insert(ft::make_pair(key, mapped_type())).first)->second);
}

template <MAP_TEMPLATE>
typename MAP_CLASS::mapped_type &MAP_CLASS::at(key_type const &key)
{
    iterator it = find(key);

    if (it == end())
        throw std::out_of_range("map::at()");
    return (it->second);
}

template <MAP_TEMPLATE>
typename MAP_CLASS::mapped_type const &MAP_CLASS::at(key_type const &key) const
{
    const_iterator it = find(key);

    if (it == end())
        throw std::out_of_range("map::at() const");
    return (it->second);
}

/******************************************** MODIFIERS *******************************************/

template <MAP_TEMPLATE>
pair<typename MAP_CLASS::iterator, bool> MAP_CLASS::insert(value_type const &value)
{
    return (_tree.insert(value));
}

template <MAP_TEMPLATE>
typename MAP_CLASS::iterator MAP_CLASS::insert(iterator position, value_type const &value)
{
    return (_tree.insert(position, value));
}

template <MAP_TEMPLATE>
template <typename Iterator>
void MAP_CLASS::insert(Iterator first, Iterator last)
{
    _tree.insert(first, last);
}

template <MAP_TEMPLATE>
void MAP_CLASS::erase(iterator position)
{
    _tree.erase(position->first);
}

template <MAP_TEMPLATE>
typename MAP_CLASS::size_type MAP_CLASS::erase(key_type const &key)
{
    if (find(key) == end())
        return (0);
    _tree.erase(key);
    return (1);
}

template <MAP_TEMPLATE>
void MAP_CLASS::erase(iterator first, iterator last)
{
    while (first != last)
        erase(first++);
}

template <MAP_TEMPLATE>
void MAP_CLASS::swap(map &src)
{
    _tree.swap(src._tree);
}

template <MAP_TEMPLATE>
void MAP_CLASS::clear(void)
{
    _tree.clear();
}

/******************************************** OBSERVERS *******************************************/

template <MAP_TEMPLATE>
typename MAP_CLASS::key_compare MAP_CLASS::key_comp(void) const
{
    return (_tree.key_comp());
}

template <MAP_TEMPLATE>
typename MAP_CLASS::value_compare MAP_CLASS::value_comp(void) const
{
    return (value_compare(_tree.key_comp()));
}

/**************************************** LOOKUP OPERATIONS ***************************************/

template <MAP_TEMPLATE>
typename MAP_CLASS::iterator MAP_CLASS::find(key_type const &key)
{
    return (iterator(_tree.find(key)));
}

template <MAP_TEMPLATE>
typename MAP_CLASS::const_iterator MAP_CLASS::find(key_type const &key) const
{
    return (const_iterator(_tree.find(key)));
}

template <MAP_TEMPLATE>
typename MAP_CLASS::size_type MAP_CLASS::count(key_type const &key) const
{
    return (_tree.count(key));
}

template <MAP_TEMPLATE>
typename MAP_CLASS::iterator MAP_CLASS::lower_bound(key_type const &key)
{
    return (_tree.lower_bound(key));
}

template <MAP_TEMPLATE>
typename MAP_CLASS::const_iterator MAP_CLASS::lower_bound(key_type const &key) const
{
    return (_tree.lower_bound(key));
}

template <MAP_TEMPLATE>
typename MAP_CLASS::iterator MAP_CLASS::upper_bound(key_type const &key)
{
    return (_tree.upper_bound(key));
}

template <MAP_TEMPLATE>
typename MAP_CLASS::const_iterator MAP_CLASS::upper_bound(key_type const &key) const
{
    return (_tree.upper_bound(key));
}

template <MAP_TEMPLATE>
pair<typename MAP_CLASS::iterator, typename MAP_CLASS::iterator>
MAP_CLASS::equal_range(key_type const &key)
{
    return (_tree.equal_range(key));
}

template <MAP_TEMPLATE>
pair<typename MAP_CLASS::const_iterator, typename MAP_CLASS::const_iterator>
MAP_CLASS::equal_range(key_type const &key) const
{
    return (_tree.equal_range(key));
}

/******************************************** ALLOCATOR *******************************************/

template <MAP_TEMPLATE>
typename MAP_CLASS::allocator_type MAP_CLASS::get_allocator(void) const
{
    return (_tree.get_allocator());
}

} /* namespace ft */

#endif /* FT_MAP_TPP */
