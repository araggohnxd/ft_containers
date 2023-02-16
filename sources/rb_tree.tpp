/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree.tpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 22:37:23 by maolivei          #+#    #+#             */
/*   Updated: 2023/02/16 19:09:17 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RB_TREE_TPP
#define FT_RB_TREE_TPP

namespace ft {

template <RB_TREE_TEMPLATE>
RB_TREE_CLASS::rb_tree(key_compare const &comp, allocator_type const &alloc) :
    _NIL(NULL),
    _root(NULL),
    _size(0),
    _key_compare(comp),
    _allocator(alloc)
{
    _NIL = _allocator.allocate(1);
    _allocator.construct(_NIL, node(value_type(), _root, _NIL, _NIL, _NIL, _NIL, black));
    _root = _NIL;
}

template <RB_TREE_TEMPLATE>
RB_TREE_CLASS::~rb_tree(void)
{
    if (_root && _root != _NIL)
        _destroy_tree(_root);
    if (_NIL) {
        _allocator.destroy(_NIL);
        _allocator.deallocate(_NIL, 1);
    }
}

template <RB_TREE_TEMPLATE>
typename RB_TREE_CLASS::node_pointer RB_TREE_CLASS::insert_node(value_type const &value)
{
    node_pointer z = _create_node(value);
    node_pointer y = _NIL;
    node_pointer x = _root;

    while (x && x != _NIL) {
        y = x;
        if (_key_compare(KeyOfValue()(z->value), KeyOfValue()(x->value)))
            x = x->left;
        else
            x = x->right;
    }
    z->parent = y;
    if (!y || y == _NIL)
        _root = z;
    else if (_key_compare(KeyOfValue()(z->value), KeyOfValue()(y->value)))
        y->left = z;
    else
        y->right = z;
    ++_size;
    _NIL->root = _root;
    _insert_fixup(z);
    return (z);
}

template <RB_TREE_TEMPLATE>
void RB_TREE_CLASS::delete_node(key_type const &key)
{
    node_pointer    z                = search(key);
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
        } else
            x->parent = y;         // in case x is NIL
        _transplant(z, y);         //  replace z by its successor y
        y->left         = z->left; //  and give z’s left child to y,
        y->left->parent = y;       //  which had no left child
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
typename RB_TREE_CLASS::node_pointer RB_TREE_CLASS::search(key_type const &key)
{
    return (_search(_root, key));
}

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

template <RB_TREE_TEMPLATE>
typename RB_TREE_CLASS::node_pointer RB_TREE_CLASS::_search(node_pointer node, key_type const &key)
{
    if (!node || node == _NIL || KeyOfValue()(node->value) == key)
        return (node);
    if (_key_compare(key, KeyOfValue()(node->value)))
        return (_search(node->left, key));
    return (_search(node->right, key));
}

template <RB_TREE_TEMPLATE>
typename RB_TREE_CLASS::node_pointer RB_TREE_CLASS::_create_node(value_type const &value)
{
    node_pointer new_node = _allocator.allocate(1);

    _allocator.construct(new_node, node(value, _root, _NIL, _NIL, _NIL, _NIL, red));
    return (new_node);
}

template <RB_TREE_TEMPLATE>
void RB_TREE_CLASS::_destroy_tree(node_pointer node)
{
    if (!node || node == _NIL)
        return;
    _destroy_tree(node->right);
    _destroy_tree(node->left);
    _allocator.destroy(node);
    _allocator.deallocate(node, 1);
    --_size;
}

template <RB_TREE_TEMPLATE>
void RB_TREE_CLASS::_insert_fixup(node_pointer z)
{
    while (z->parent && z->parent->color == red) {
        if (z->parent->parent && z->parent == z->parent->parent->left)
            _insert_fixup_left_child(z);
        else if (z->parent->parent && z->parent == z->parent->parent->right)
            _insert_fixup_right_child(z);
        if (z == _root)
            break;
    }
    _root->color = black;
}

template <RB_TREE_TEMPLATE>
void RB_TREE_CLASS::_insert_fixup_left_child(node_pointer z)
{
    node_pointer y = z->parent->parent->right;

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
}

template <RB_TREE_TEMPLATE>
void RB_TREE_CLASS::_insert_fixup_right_child(node_pointer z)
{
    node_pointer y = z->parent->parent->left;

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
typename RB_TREE_CLASS::node_pointer RB_TREE_CLASS::root(void) const
{
    return (_root);
}

template <RB_TREE_TEMPLATE>
typename RB_TREE_CLASS::node_pointer RB_TREE_CLASS::nil(void) const
{
    return (_NIL);
}

template <RB_TREE_TEMPLATE>
typename RB_TREE_CLASS::size_type RB_TREE_CLASS::size(void) const
{
    return (_size);
}

} /* namespace ft */

#endif /* FT_RB_TREE_TPP */
