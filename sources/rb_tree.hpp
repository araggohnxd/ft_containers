/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 22:37:23 by maolivei          #+#    #+#             */
/*   Updated: 2023/02/09 19:12:28 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RB_TREE_HPP
#define FT_RB_TREE_HPP

#include "rb_tree.hpp"

#define RB_TREE_TEMPLATE                                                                           \
 typename Key, typename Value, typename KeyOfValue, typename Compare, typename Alloc

#define RB_TREE_CLASS rb_tree<Key, Value, KeyOfValue, Compare, Alloc>

#include "rb_tree_node.hpp"
#include <memory>

namespace ft {

template <typename Key,
          typename Value,
          typename KeyOfValue,
          typename Compare,
          typename Alloc = std::allocator<Value> >
class rb_tree {
    public:
        // TODO: see if all of these typedefs are necessary / being used
        typedef Value                                                 value_type;
        typedef Key                                                   key_type;
        typedef Compare                                               key_compare;
        typedef Alloc                                                 allocator_type;
        typedef value_type                                           &reference;
        typedef value_type const                                     &const_reference;
        typedef value_type                                           *pointer;
        typedef value_type const                                     *const_pointer;
        typedef std::size_t                                           size_type;
        typedef std::ptrdiff_t                                        difference_type;
        typedef rb_tree_node<Value>                                   node;
        typedef node                                                 *node_pointer;
        typedef node const                                           *const_node_pointer;
        typedef typename node::color_type                             node_color_type;
        typedef typename allocator_type::template rebind<node>::other node_allocator;

        explicit rb_tree(key_compare const    &comp  = key_compare(),
                         allocator_type const &alloc = allocator_type());
        ~rb_tree(void);

        node_pointer insert_node(value_type const &value);
        void         delete_node(key_type const &key);
        node_pointer search(key_type const &key);

        node_pointer root(void) const;
        node_pointer nil(void) const;
        size_type    size(void) const;

        node_pointer       maximum(node_pointer x);
        const_node_pointer maximum(const_node_pointer x);
        node_pointer       minimum(node_pointer x);
        const_node_pointer minimum(const_node_pointer x);
        node_pointer       successor(node_pointer x);
        const_node_pointer successor(const_node_pointer x);
        node_pointer       predecessor(node_pointer x);
        const_node_pointer predecessor(const_node_pointer x);


    private:
        node_pointer _search(node_pointer node, key_type const &key);
        node_pointer _create_node(value_type const &value);
        void         _destroy_tree(node_pointer node);
        void         _insert_fixup(node_pointer z);
        void         _insert_fixup_left_child(node_pointer z);
        void         _insert_fixup_right_child(node_pointer z);
        void         _delete_fixup(node_pointer x);
        void         _delete_fixup_left_child(node_pointer x);
        void         _delete_fixup_right_child(node_pointer x);
        void         _left_rotate(node_pointer x);
        void         _right_rotate(node_pointer x);
        void         _transplant(node_pointer u, node_pointer v);

        node_pointer   _NIL;
        node_pointer   _root;
        size_type      _size;
        key_compare    _key_compare;
        node_allocator _allocator;
};

} /* namespace ft */

#include "rb_tree.tpp"

#endif /* FT_RB_TREE_HPP */
