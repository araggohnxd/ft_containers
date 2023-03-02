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

#define RB_TREE_TEMPLATE                                                                           \
 typename Key, typename Value, typename KeyOfValue, typename Compare, typename Alloc

#define RB_TREE_CLASS rb_tree<Key, Value, KeyOfValue, Compare, Alloc>

#include "algorithm.hpp"
#include "iterator.hpp"
#include "rb_tree_node.hpp"
#include "utility.hpp"
#include <memory>
#include <stdexcept>

namespace ft {

template <typename Key,
          typename Value,
          typename KeyOfValue,
          typename Compare,
          typename Alloc = std::allocator<Value> >
class rb_tree {
    public:
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
        typedef rb_tree_iterator<pointer>                             iterator;
        typedef rb_tree_iterator<const_pointer>                       const_iterator;
        typedef ft::reverse_iterator<iterator>                        reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>                  const_reverse_iterator;

        /********************** CONSTRUCTORS, DESTRUCTOR AND ASSIGN OPERATOR **********************/

        explicit rb_tree(key_compare const    &comp  = key_compare(),
                         allocator_type const &alloc = allocator_type());
        rb_tree(rb_tree const &src);
        ~rb_tree(void);
        rb_tree &operator=(rb_tree const &src);

        /**************************************** ITERATORS ***************************************/

        iterator               begin(void);
        const_iterator         begin(void) const;
        iterator               end(void);
        const_iterator         end(void) const;
        reverse_iterator       rbegin(void);
        const_reverse_iterator rbegin(void) const;
        reverse_iterator       rend(void);
        const_reverse_iterator rend(void) const;

        /**************************************** CAPACITY ****************************************/

        bool      empty(void) const;
        size_type size(void) const;
        size_type max_size(void) const;

        /**************************************** MODIFIERS ***************************************/

        pair<iterator, bool> insert(value_type const &value);
        iterator             insert(iterator position, value_type const &value);

        template <typename Iterator>
        void insert(Iterator first, Iterator last);

        void erase(key_type const &key);
        void swap(rb_tree &src);
        void clear(void);

        /**************************************** OBSERVERS ***************************************/

        key_compare  key_comp(void) const;
        node_pointer root(void) const;
        node_pointer nil(void) const;

        /************************************ LOOKUP OPERATIONS ***********************************/

        iterator                             find(key_type const &key);
        const_iterator                       find(key_type const &key) const;
        size_type                            count(key_type const &key) const;
        iterator                             lower_bound(key_type const &key);
        const_iterator                       lower_bound(key_type const &key) const;
        iterator                             upper_bound(key_type const &key);
        const_iterator                       upper_bound(key_type const &key) const;
        pair<iterator, iterator>             equal_range(key_type const &key);
        pair<const_iterator, const_iterator> equal_range(key_type const &key) const;

        /**************************************** ALLOCATOR ***************************************/

        node_allocator get_allocator(void) const;

    private:
        node_pointer _find(node_pointer x, key_type const &key) const;
        node_pointer _create_node(value_type const &value);
        node_pointer _initialize_nil(void);
        node_pointer _insert_unique(value_type const &value);
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
        void         _copy(node_pointer x);

        node_pointer   _NIL;
        node_pointer   _root;
        size_type      _size;
        key_compare    _key_compare;
        node_allocator _allocator;
};

template <RB_TREE_TEMPLATE>
void swap(RB_TREE_CLASS &lhs, RB_TREE_CLASS &rhs)
{
    lhs.swap(rhs);
}

template <RB_TREE_TEMPLATE>
bool operator==(RB_TREE_CLASS const &lhs, RB_TREE_CLASS const &rhs)
{
    return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template <RB_TREE_TEMPLATE>
bool operator!=(RB_TREE_CLASS const &lhs, RB_TREE_CLASS const &rhs)
{
    return (!(lhs == rhs));
}

template <RB_TREE_TEMPLATE>
bool operator<(RB_TREE_CLASS const &lhs, RB_TREE_CLASS const &rhs)
{
    return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template <RB_TREE_TEMPLATE>
bool operator<=(RB_TREE_CLASS const &lhs, RB_TREE_CLASS const &rhs)
{
    return (!(rhs < lhs));
}

template <RB_TREE_TEMPLATE>
bool operator>(RB_TREE_CLASS const &lhs, RB_TREE_CLASS const &rhs)
{
    return (rhs < lhs);
}

template <RB_TREE_TEMPLATE>
bool operator>=(RB_TREE_CLASS const &lhs, RB_TREE_CLASS const &rhs)
{
    return (!(lhs < rhs));
}

} /* namespace ft */

#include "rb_tree.tpp"

#endif /* FT_RB_TREE_HPP */
