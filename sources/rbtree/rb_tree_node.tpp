/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree_node.tpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:44:11 by maolivei          #+#    #+#             */
/*   Updated: 2023/02/14 19:54:19 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RB_TREE_NODE_TPP
#define FT_RB_TREE_NODE_TPP

#include "rb_tree_node.hpp"

namespace ft {

template <typename T>
rb_tree_node<T>::rb_tree_node(void) :
    value(T()),
    root(NULL),
    nil(NULL),
    parent(NULL),
    right(NULL),
    left(NULL),
    color(black)
{
}

template <typename T>
rb_tree_node<T>::rb_tree_node(value_type const &value,
                              node_pointer      root,
                              node_pointer      nil,
                              node_pointer      parent,
                              node_pointer      right,
                              node_pointer      left,
                              color_type        color) :
    value(value),
    root(root),
    nil(nil),
    parent(parent),
    right(right),
    left(left),
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

template <typename T>
typename rb_tree_node<T>::node_pointer rb_tree_node<T>::successor(node_pointer x)
{
    node_pointer y;

    if (x == x->nil)
        return (maximum(x->nil->root));
    if (x->right != x->nil)
        return (minimum(x->right));
    y = x->parent;
    while (y != y->nil && x == y->right) {
        x = y;
        y = y->parent;
    }
    return (y);
}

template <typename T>
typename rb_tree_node<T>::const_node_pointer rb_tree_node<T>::successor(const_node_pointer x)
{
    node_pointer y;

    if (x == x->nil)
        return (maximum(x->nil->root));
    if (x->right != x->nil)
        return (minimum(x->right));
    y = x->parent;
    while (y != y->nil && x == y->right) {
        x = y;
        y = y->parent;
    }
    return (y);
}

template <typename T>
typename rb_tree_node<T>::node_pointer rb_tree_node<T>::predecessor(node_pointer x)
{
    node_pointer y;

    if (x == x->nil)
        return (maximum(x->nil->root));
    if (x->left != x->nil)
        return (maximum(x->left));
    y = x->parent;
    while (y != y->nil && x == y->left) {
        x = y;
        y = y->parent;
    }
    return (y);
}

template <typename T>
typename rb_tree_node<T>::const_node_pointer rb_tree_node<T>::predecessor(const_node_pointer x)
{
    node_pointer y;

    if (x == x->nil)
        return (maximum(x->nil->root));
    if (x->left != x->nil)
        return (maximum(x->left));
    y = x->parent;
    while (y != y->nil && x == y->left) {
        x = y;
        y = y->parent;
    }
    return (y);
}

} /* namespace ft */

#endif /* FT_RB_TREE_NODE_TPP */
