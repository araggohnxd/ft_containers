/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree.tpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 22:37:23 by maolivei          #+#    #+#             */
/*   Updated: 2023/02/12 16:33:29 by maolivei         ###   ########.fr       */
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
    _allocator.construct(_NIL, node());
    _root = _NIL;
}

template <RB_TREE_TEMPLATE>
RB_TREE_CLASS::~rb_tree(void)
{
    if (_root && _root != _NIL)
        _destroy_node(_root);
    if (_NIL)
        _allocator.deallocate(_NIL, 1);
}

template <RB_TREE_TEMPLATE>
typename RB_TREE_CLASS::node_pointer RB_TREE_CLASS::insert(value_type const &value)
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
    _insert_fixup(z);
    return (z);
}

template <RB_TREE_TEMPLATE>
typename RB_TREE_CLASS::node_pointer RB_TREE_CLASS::_create_node(value_type const &value)
{
    node_pointer new_node = _allocator.allocate(1);

    _allocator.construct(new_node, node(value, _root, _NIL, _NIL, _NIL, _NIL, red));
    return (new_node);
}

template <RB_TREE_TEMPLATE>
void RB_TREE_CLASS::_destroy_node(node_pointer node)
{
    if (!node || node == _NIL)
        return;
    _destroy_node(node->right);
    _destroy_node(node->left);
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
    _NIL->root = _root;
    ++_size;
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
typename RB_TREE_CLASS::node_pointer RB_TREE_CLASS::get_root(void) const
{
    return (_root);
}

template <RB_TREE_TEMPLATE>
typename RB_TREE_CLASS::node_pointer RB_TREE_CLASS::get_nil(void) const
{
    return (_NIL);
}

} /* namespace ft */

#endif /* FT_RB_TREE_TPP */
