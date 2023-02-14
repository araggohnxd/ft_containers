/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree_node.tpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:44:11 by maolivei          #+#    #+#             */
/*   Updated: 2023/02/13 21:32:00 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RB_TREE_NODE_TPP
#define FT_RB_TREE_NODE_TPP

#include "rb_tree_node.hpp"

namespace ft {

template <typename T>
rb_tree_node<T>::rb_tree_node(void) :
    value(T()),
    parent(NULL),
    right(NULL),
    left(NULL),
    nil(NULL),
    color(black)
{
}

template <typename T>
rb_tree_node<T>::rb_tree_node(value_type const &value,
                              node_pointer      nil,
                              node_pointer      parent,
                              node_pointer      right,
                              node_pointer      left,
                              color_type        color) :
    value(value),
    parent(parent),
    right(right),
    left(left),
    nil(nil),
    color(color)
{
}

template <typename T>
typename rb_tree_node<T>::node_pointer rb_tree_node<T>::maximum(node_pointer x)
{
    while (x->right != x->nil)
        x = x->right;
    return (x);
}

template <typename T>
typename rb_tree_node<T>::const_node_pointer rb_tree_node<T>::maximum(const_node_pointer x)
{
    while (x->right != x->nil)
        x = x->right;
    return (x);
}

template <typename T>
typename rb_tree_node<T>::node_pointer rb_tree_node<T>::minimum(node_pointer x)
{
    while (x->left != x->nil)
        x = x->left;
    return (x);
}

template <typename T>
typename rb_tree_node<T>::const_node_pointer rb_tree_node<T>::minimum(const_node_pointer x)
{
    while (x->left != x->nil)
        x = x->left;
    return (x);
}

} /* namespace ft */

#endif /* FT_RB_TREE_NODE_TPP */
