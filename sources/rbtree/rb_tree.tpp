/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree.tpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 22:37:23 by maolivei          #+#    #+#             */
/*   Updated: 2023/03/02 19:27:27 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RB_TREE_TPP
#define FT_RB_TREE_TPP

#include "rb_tree.hpp"

namespace ft {

/************************** CONSTRUCTORS, DESTRUCTOR AND ASSIGN OPERATOR **************************/

template <RB_TREE_TEMPLATE>
RB_TREE_CLASS::rb_tree(key_compare const &comp, allocator_type const &alloc) :
    _NIL(NULL),
    _root(NULL),
    _size(0),
    _key_compare(comp),
    _allocator(alloc)
{
    _NIL  = _initialize_nil();
    _root = _NIL;
}

template <RB_TREE_TEMPLATE>
RB_TREE_CLASS::rb_tree(rb_tree const &src) :
    _NIL(NULL),
    _root(NULL),
    _size(0),
    _key_compare(src._key_compare),
    _allocator(src._allocator)
{
    _NIL  = _initialize_nil();
    _root = _NIL;
    _copy(src._root);
    _size = src._size;
}

template <RB_TREE_TEMPLATE>
RB_TREE_CLASS &RB_TREE_CLASS::operator=(rb_tree const &src)
{
    if (this == &src)
        return (*this);
    clear();
    _allocator.destroy(_NIL);
    _allocator.deallocate(_NIL, 1);
    _allocator = src._allocator;
    _NIL       = _initialize_nil();
    _root      = _NIL;
    _copy(src._root);
    _size        = src._size;
    _key_compare = src._key_compare;
    return (*this);
}

template <RB_TREE_TEMPLATE>
RB_TREE_CLASS::~rb_tree(void)
{
    clear();
    _allocator.destroy(_NIL);
    _allocator.deallocate(_NIL, 1);
}

/******************************************** ITERATORS *******************************************/

template <RB_TREE_TEMPLATE>
typename RB_TREE_CLASS::iterator RB_TREE_CLASS::begin(void)
{
    return (const_iterator(node::minimum(_root)));
}

template <RB_TREE_TEMPLATE>
typename RB_TREE_CLASS::const_iterator RB_TREE_CLASS::begin(void) const
{
    return (const_iterator(node::minimum(_root)));
}

template <RB_TREE_TEMPLATE>
typename RB_TREE_CLASS::iterator RB_TREE_CLASS::end(void)
{
    return (iterator(_NIL));
}

template <RB_TREE_TEMPLATE>
typename RB_TREE_CLASS::const_iterator RB_TREE_CLASS::end(void) const
{
    return (const_iterator(_NIL));
}

template <RB_TREE_TEMPLATE>
typename RB_TREE_CLASS::reverse_iterator RB_TREE_CLASS::rbegin(void)
{
    return (reverse_iterator(end()));
}

template <RB_TREE_TEMPLATE>
typename RB_TREE_CLASS::const_reverse_iterator RB_TREE_CLASS::rbegin(void) const
{
    return (const_reverse_iterator(end()));
}

template <RB_TREE_TEMPLATE>
typename RB_TREE_CLASS::reverse_iterator RB_TREE_CLASS::rend(void)
{
    return (reverse_iterator(begin()));
}

template <RB_TREE_TEMPLATE>
typename RB_TREE_CLASS::const_reverse_iterator RB_TREE_CLASS::rend(void) const
{
    return (const_reverse_iterator(begin()));
}

/******************************************** CAPACITY ********************************************/

template <RB_TREE_TEMPLATE>
bool RB_TREE_CLASS::empty(void) const
{
    return (!_size);
}

template <RB_TREE_TEMPLATE>
typename RB_TREE_CLASS::size_type RB_TREE_CLASS::size(void) const
{
    return (_size);
}

template <RB_TREE_TEMPLATE>
typename RB_TREE_CLASS::size_type RB_TREE_CLASS::max_size(void) const
{
    return (_allocator.max_size());
}

/******************************************** MODIFIERS *******************************************/

template <RB_TREE_TEMPLATE>
pair<typename RB_TREE_CLASS::iterator, bool> RB_TREE_CLASS::insert(value_type const &value)
{
    iterator it = find(KeyOfValue()(value));

    if (it != end())
        return (ft::make_pair(it, false));
    return (ft::make_pair(iterator(_insert_unique(value)), true));
}

template <RB_TREE_TEMPLATE>
typename RB_TREE_CLASS::iterator RB_TREE_CLASS::insert(iterator position, value_type const &value)
{
    (void)position;
    return (insert(value).first);
}

template <RB_TREE_TEMPLATE>
template <typename Iterator>
void RB_TREE_CLASS::insert(Iterator first, Iterator last)
{
    while (first != last)
        insert(*first++);
}

template <RB_TREE_TEMPLATE>
void RB_TREE_CLASS::erase(key_type const &key)
{
    node_pointer    z                = _find(_root, key);
    node_pointer    y                = z;
    node_pointer    x                = NULL;
    node_color_type y_original_color = y->color;

    if (z == _NIL)
        return;
    if (z->left == _NIL) {
        x = z->right;
        _transplant(z, z->right); // replace z by its right child
    } else if (z->right == _NIL) {
        x = z->left;
        _transplant(z, z->left); // replace z by its left child
    } else {
        y                = node::minimum(z->right); // y is z’s successor
        y_original_color = y->color;
        x                = y->right;
        if (y != z->right) {             // is y farther down the tree?
            _transplant(y, y->right);    //  replace y by its right child
            y->right         = z->right; //  z’s right child becomes
            y->right->parent = y;        //  y’s right child
        } else {
            x->parent = y; // in case x is NIL
        }
        _transplant(z, y);         // replace z by its successor y
        y->left         = z->left; // and give z’s left child to y,
        y->left->parent = y;       // which had no left child
        y->color        = z->color;
    }
    _allocator.destroy(z);
    _allocator.deallocate(z, 1);
    --_size;
    _NIL->root = _root;
    if (y_original_color == black) // if any red-black violations occur,
        _delete_fixup(x);          // correct them
}

template <RB_TREE_TEMPLATE>
void RB_TREE_CLASS::swap(rb_tree &src)
{
    node_allocator tmp_alloc   = src._allocator;
    node_pointer   tmp_root    = src._root;
    node_pointer   tmp_nil     = src._NIL;
    size_type      tmp_size    = src._size;
    key_compare    tmp_compare = src._key_compare;

    src._allocator   = _allocator;
    src._root        = _root;
    src._NIL         = _NIL;
    src._size        = _size;
    src._key_compare = _key_compare;
    _allocator       = tmp_alloc;
    _root            = tmp_root;
    _NIL             = tmp_nil;
    _size            = tmp_size;
    _key_compare     = tmp_compare;
}

template <RB_TREE_TEMPLATE>
void RB_TREE_CLASS::clear(void)
{
    _destroy_tree(_root);
    _root = _NIL;
    _size = 0;
}

/******************************************** OBSERVERS *******************************************/

template <RB_TREE_TEMPLATE>
typename RB_TREE_CLASS::key_compare RB_TREE_CLASS::key_comp(void) const
{
    return (_key_compare);
}

template <RB_TREE_TEMPLATE>
typename RB_TREE_CLASS::node_pointer RB_TREE_CLASS::root(void) const
{
    return (_root);
}

template <RB_TREE_TEMPLATE>
typename RB_TREE_CLASS::node_pointer RB_TREE_CLASS::nil(void) const
{
    return (_NIL);
}

/**************************************** LOOKUP OPERATIONS ***************************************/

template <RB_TREE_TEMPLATE>
typename RB_TREE_CLASS::iterator RB_TREE_CLASS::find(key_type const &key)
{
    return (iterator(_find(_root, key)));
}

template <RB_TREE_TEMPLATE>
typename RB_TREE_CLASS::const_iterator RB_TREE_CLASS::find(key_type const &key) const
{
    return (const_iterator(_find(_root, key)));
}

template <RB_TREE_TEMPLATE>
typename RB_TREE_CLASS::size_type RB_TREE_CLASS::count(key_type const &key) const
{
    return (_find(_root, key) != _NIL);
}

template <RB_TREE_TEMPLATE>
typename RB_TREE_CLASS::iterator RB_TREE_CLASS::lower_bound(key_type const &key)
{
    node_pointer x = _root;
    node_pointer y = _NIL;

    while (x != _NIL) {
        if (!_key_compare(KeyOfValue()(x->value), key)) {
            y = x;
            x = x->left;
        } else
            x = x->right;
    }
    return (iterator(y));
}

template <RB_TREE_TEMPLATE>
typename RB_TREE_CLASS::const_iterator RB_TREE_CLASS::lower_bound(key_type const &key) const
{
    node_pointer x = _root;
    node_pointer y = _NIL;

    while (x != _NIL) {
        if (!_key_compare(KeyOfValue()(x->value), key)) {
            y = x;
            x = x->left;
        } else
            x = x->right;
    }
    return (const_iterator(y));
}

template <RB_TREE_TEMPLATE>
typename RB_TREE_CLASS::iterator RB_TREE_CLASS::upper_bound(key_type const &key)
{
    node_pointer x = _root;
    node_pointer y = _NIL;

    while (x != _NIL) {
        if (_key_compare(key, KeyOfValue()(x->value))) {
            y = x;
            x = x->left;
        } else
            x = x->right;
    }
    return (iterator(y));
}

template <RB_TREE_TEMPLATE>
typename RB_TREE_CLASS::const_iterator RB_TREE_CLASS::upper_bound(key_type const &key) const
{
    node_pointer x = _root;
    node_pointer y = _NIL;

    while (x != _NIL) {
        if (_key_compare(key, KeyOfValue()(x->value))) {
            y = x;
            x = x->left;
        } else
            x = x->right;
    }
    return (const_iterator(y));
}

template <RB_TREE_TEMPLATE>
pair<typename RB_TREE_CLASS::iterator, typename RB_TREE_CLASS::iterator>
RB_TREE_CLASS::equal_range(key_type const &key)
{
    return (pair<iterator, iterator>(lower_bound(key), upper_bound(key)));
}

template <RB_TREE_TEMPLATE>
pair<typename RB_TREE_CLASS::const_iterator, typename RB_TREE_CLASS::const_iterator>
RB_TREE_CLASS::equal_range(key_type const &key) const
{
    return (pair<const_iterator, const_iterator>(lower_bound(key), upper_bound(key)));
}

/******************************************** ALLOCATOR *******************************************/

template <RB_TREE_TEMPLATE>
typename RB_TREE_CLASS::node_allocator RB_TREE_CLASS::get_allocator(void) const
{
    return (_allocator);
}

/***************************************** PRIVATE METHODS ****************************************/

template <RB_TREE_TEMPLATE>
typename RB_TREE_CLASS::node_pointer RB_TREE_CLASS::_find(node_pointer x, key_type const &key) const
{
    if (x == _NIL || KeyOfValue()(x->value) == key)
        return (x);
    if (_key_compare(key, KeyOfValue()(x->value)))
        return (_find(x->left, key));
    return (_find(x->right, key));
}

template <RB_TREE_TEMPLATE>
typename RB_TREE_CLASS::node_pointer RB_TREE_CLASS::_create_node(value_type const &value)
{
    node_pointer new_node = _allocator.allocate(1);

    if (!new_node)
        throw std::bad_alloc();
    _allocator.construct(new_node, node(value, _root, _NIL, _NIL, _NIL, _NIL, red));
    return (new_node);
}

template <RB_TREE_TEMPLATE>
typename RB_TREE_CLASS::node_pointer RB_TREE_CLASS::_initialize_nil(void)
{
    node_pointer nil = _allocator.allocate(1);

    if (!nil)
        throw std::bad_alloc();
    _allocator.construct(nil, node(value_type(), _root, nil, nil, nil, nil, black));
    return (nil);
}

template <RB_TREE_TEMPLATE>
void RB_TREE_CLASS::_destroy_tree(node_pointer node)
{
    if (node == _NIL)
        return;
    _destroy_tree(node->right);
    _destroy_tree(node->left);
    _allocator.destroy(node);
    _allocator.deallocate(node, 1);
}

template <RB_TREE_TEMPLATE>
typename RB_TREE_CLASS::node_pointer RB_TREE_CLASS::_insert_unique(value_type const &value)
{
    node_pointer z = _create_node(value); // node to be inserted
    node_pointer y = _NIL;                // y will be parent of z
    node_pointer x = _root;               // node being compared with z

    // descend until reaching the NIL sentinel
    while (x != _NIL) {
        y = x;
        if (_key_compare(KeyOfValue()(z->value), KeyOfValue()(x->value)))
            x = x->left;
        else
            x = x->right;
    }
    z->parent = y; // found location, insert z with parent y
    if (y == _NIL)
        _root = z; // tree was empty
    else if (_key_compare(KeyOfValue()(z->value), KeyOfValue()(y->value)))
        y->left = z;
    else
        y->right = z;
    ++_size;
    _NIL->root = _root;
    _insert_fixup(z); // correct any violations of red-black properties
    return (z);
}

template <RB_TREE_TEMPLATE>
void RB_TREE_CLASS::_insert_fixup(node_pointer z)
{
    node_pointer y;

    while (z->parent->color == red) {
        // is z's parent a left child?
        if (z->parent == z->parent->parent->left) {
            y = z->parent->parent->right; // y is z's uncle
            // are z's parent and uncle both red?
            if (y->color == red) {
                z->parent->color         = black;
                y->color                 = black;
                z->parent->parent->color = red;
                z                        = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    _left_rotate(z);
                }
                z->parent->color         = black;
                z->parent->parent->color = red;
                _right_rotate(z->parent->parent);
            }
            // same as lines 446-460, but with 'right' and 'left' exchanged
        } else {
            y = z->parent->parent->left;
            if (y->color == red) {
                z->parent->color         = black;
                y->color                 = black;
                z->parent->parent->color = red;
                z                        = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    _right_rotate(z);
                }
                z->parent->color         = black;
                z->parent->parent->color = red;
                _left_rotate(z->parent->parent);
            }
        }
    }
    _root->color = black;
}

template <RB_TREE_TEMPLATE>
void RB_TREE_CLASS::_delete_fixup(node_pointer x)
{
    while (x != _root && x->color == black) {
        if (x == x->parent->left)
            _delete_fixup_left_child(x);
        else
            _delete_fixup_right_child(x);
    }
    x->color = black;
}

template <RB_TREE_TEMPLATE>
void RB_TREE_CLASS::_delete_fixup_left_child(node_pointer x)
{
    node_pointer w = x->parent->right; // w is x's sibling

    if (w->color == red) {
        w->color         = black;
        w->parent->color = red;
        _left_rotate(x->parent);
        w = x->parent->right;
    }
    if (w->left->color == black && w->right->color == black) {
        w->color = red;
        x        = x->parent;
    } else {
        if (w->right->color == black) {
            w->left->color = black;
            w->color       = red;
            _right_rotate(w);
            w = x->parent->right;
        }
        w->color         = x->parent->color;
        x->parent->color = black;
        w->right->color  = black;
        _left_rotate(x->parent);
        x = _root;
    }
}

template <RB_TREE_TEMPLATE>
void RB_TREE_CLASS::_delete_fixup_right_child(node_pointer x)
{
    node_pointer w = x->parent->left; // w is x's sibling

    if (w->color == red) {
        w->color         = black;
        w->parent->color = red;
        _right_rotate(x->parent);
        w = x->parent->left;
    }
    if (w->right->color == black && w->left->color == black) {
        w->color = red;
        x        = x->parent;
    } else {
        if (w->left->color == black) {
            w->right->color = black;
            w->color        = red;
            _left_rotate(w);
            w = x->parent->left;
        }
        w->color         = x->parent->color;
        x->parent->color = black;
        w->left->color   = black;
        _right_rotate(x->parent);
        x = _root;
    }
}

template <RB_TREE_TEMPLATE>
void RB_TREE_CLASS::_left_rotate(node_pointer x)
{
    node_pointer y = x->right;

    x->right = y->left;
    if (y->left != _NIL)
        y->left->parent = x;
    y->parent = x->parent;
    if (x == _root)
        _root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left   = x;
    x->parent = y;
}

template <RB_TREE_TEMPLATE>
void RB_TREE_CLASS::_right_rotate(node_pointer x)
{
    node_pointer y = x->left;

    x->left = y->right;
    if (y->right != _NIL)
        y->right->parent = x;
    y->parent = x->parent;
    if (x == _root)
        _root = y;
    else if (x == x->parent->right)
        x->parent->right = y;
    else
        x->parent->left = y;
    y->right  = x;
    x->parent = y;
}

template <RB_TREE_TEMPLATE>
void RB_TREE_CLASS::_transplant(node_pointer u, node_pointer v)
{
    if (u->parent == _NIL)
        _root = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;
    v->parent = u->parent;
}

template <RB_TREE_TEMPLATE>
void RB_TREE_CLASS::_copy(node_pointer x)
{
    if (x == x->nil)
        return;
    _insert_unique(x->value);
    _copy(x->left);
    _copy(x->right);
}

} /* namespace ft */

#endif /* FT_RB_TREE_TPP */
