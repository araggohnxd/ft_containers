/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree_node.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:31:00 by maolivei          #+#    #+#             */
/*   Updated: 2023/02/08 22:36:12 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RB_TREE_NODE_HPP
#define FT_RB_TREE_NODE_HPP

#include <cstddef>

namespace ft {

enum rb_tree_color { black, red };

template <typename T>
struct rb_tree_node {
        typedef T                  value_type;
        typedef rb_tree_node<T>    node;
        typedef node              *node_pointer;
        typedef node const        *const_node_pointer;
        typedef enum rb_tree_color color_type;

        explicit rb_tree_node(void);
        explicit rb_tree_node(value_type const &value,
                              node_pointer      root,
                              node_pointer      nil,
                              node_pointer      parent = NULL,
                              node_pointer      right  = NULL,
                              node_pointer      left   = NULL,
                              color_type        color  = black);

        static node_pointer       maximum(node_pointer x);
        static const_node_pointer maximum(const_node_pointer x);
        static node_pointer       minimum(node_pointer x);
        static const_node_pointer minimum(const_node_pointer x);
        static node_pointer       successor(node_pointer x);
        static const_node_pointer successor(const_node_pointer x);
        static node_pointer       predecessor(node_pointer x);
        static const_node_pointer predecessor(const_node_pointer x);

        value_type   value;
        node_pointer root;
        node_pointer nil;
        node_pointer parent;
        node_pointer right;
        node_pointer left;
        color_type   color;
};

} /* namespace ft */

#include "rb_tree_node.tpp"

#endif /* FT_RB_TREE_NODE_HPP */
