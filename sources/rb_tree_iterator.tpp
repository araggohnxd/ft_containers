/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree_iterator.tpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:57:01 by maolivei          #+#    #+#             */
/*   Updated: 2023/02/15 21:18:36 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RB_TREE_ITERATOR_TPP
#define FT_RB_TREE_ITERATOR_TPP

#include "rb_tree_iterator.hpp"

namespace ft {

template <typename Iterator>
rb_tree_iterator<Iterator>::rb_tree_iterator(void) : _node(NULL)
{
}

template <typename Iterator>
rb_tree_iterator<Iterator>::rb_tree_iterator(iterator_type const &value) : _node(value)
{
}

template <typename Iterator>
rb_tree_iterator<Iterator>::rb_tree_iterator(node_pointer ptr) : _node(ptr)
{
}

template <typename Iterator>
rb_tree_iterator<Iterator>::rb_tree_iterator(rb_tree_iterator const &src) : _node(src._node)
{
}

template <typename Iterator>
template <typename T>
rb_tree_iterator<Iterator>::rb_tree_iterator(rb_tree_iterator<T> const &src) : _node(src.base())
{
}

template <typename Iterator>
rb_tree_iterator<Iterator>::~rb_tree_iterator(void)
{
}

template <typename Iterator>
rb_tree_iterator<Iterator> &
rb_tree_iterator<Iterator>::operator=(rb_tree_iterator<Iterator> const &src)
{
    _node = src._node;
    return (*this);
}

template <typename Iterator>
rb_tree_iterator<Iterator> &rb_tree_iterator<Iterator>::operator++(void)
{
    if (_node == _node->nil) {
        _node = node::maximum(_node->root);
        return (*this);
    }
    _node = node::successor(_node);
    return (*this);
}

template <typename Iterator>
rb_tree_iterator<Iterator> rb_tree_iterator<Iterator>::operator++(int)
{
    node_pointer tmp(_node);

    if (_node == _node->nil) {
        _node = node::maximum(_node->root);
        return (rb_tree_iterator(tmp));
    }
    _node = node::successor(_node);
    return (rb_tree_iterator(tmp));
}

template <typename Iterator>
rb_tree_iterator<Iterator> &rb_tree_iterator<Iterator>::operator--(void)
{
    if (_node == _node->nil) {
        _node = node::maximum(_node->root);
        return (*this);
    }
    _node = node::predecessor(_node);
    return (*this);
}

template <typename Iterator>
rb_tree_iterator<Iterator> rb_tree_iterator<Iterator>::operator--(int)
{
    node_pointer tmp(_node);

    if (_node == _node->nil) {
        _node = node::maximum(_node->root);
        return (rb_tree_iterator(tmp));
    }
    _node = node::predecessor(_node);
    return (rb_tree_iterator(tmp));
}

template <typename Iterator>
typename rb_tree_iterator<Iterator>::reference rb_tree_iterator<Iterator>::operator*(void) const
{
    return (_node->value);
}

template <typename Iterator>
typename rb_tree_iterator<Iterator>::pointer rb_tree_iterator<Iterator>::operator->(void) const
{
    return (&(operator*()));
}

template <typename Iterator>
typename rb_tree_iterator<Iterator>::node_pointer rb_tree_iterator<Iterator>::base(void) const
{
    return (_node);
}

} /* namespace ft */

#endif /* FT_RB_TREE_ITERATOR_TPP */
