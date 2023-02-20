/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:07:09 by maolivei          #+#    #+#             */
/*   Updated: 2023/02/15 21:18:31 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RB_TREE_ITERATOR_HPP
#define FT_RB_TREE_ITERATOR_HPP

#include "iterator.hpp"
#include "rb_tree_node.hpp"

namespace ft {

template <typename Iterator>
class rb_tree_iterator : public iterator<std::bidirectional_iterator_tag, Iterator> {
    public:
        typedef Iterator                                            iterator_type;
        typedef typename iterator_traits<Iterator>::value_type      value_type;
        typedef typename iterator_traits<Iterator>::pointer         pointer;
        typedef typename iterator_traits<Iterator>::reference       reference;
        typedef typename iterator_traits<Iterator>::difference_type difference_type;
        typedef std::bidirectional_iterator_tag                     iterator_category;
        typedef rb_tree_node<value_type>                            node;
        typedef node                                               *node_pointer;

        rb_tree_iterator(void);
        explicit rb_tree_iterator(iterator_type const &value);
        explicit rb_tree_iterator(node_pointer ptr);
        rb_tree_iterator(rb_tree_iterator const &src);
        template <typename T> rb_tree_iterator(rb_tree_iterator<T> const &src);
        ~rb_tree_iterator(void);
        rb_tree_iterator &operator=(rb_tree_iterator const &src);

        rb_tree_iterator &operator++(void); // prefixed
        rb_tree_iterator  operator++(int);  // postfixed

        rb_tree_iterator &operator--(void); // prefixed
        rb_tree_iterator  operator--(int);  // postfixed

        reference operator*(void) const;
        pointer   operator->(void) const;

        node_pointer base(void) const;

    private:
        node_pointer _node;
};

template <typename L, typename R>
inline bool operator==(rb_tree_iterator<L> const &lhs, rb_tree_iterator<R> const &rhs)
{
    return (lhs.base() == rhs.base());
}

template <typename L, typename R>
inline bool operator!=(rb_tree_iterator<L> const &lhs, rb_tree_iterator<R> const &rhs)
{
    return (lhs.base() != rhs.base());
}

} /* namespace ft */

#include "rb_tree_iterator.tpp"

#endif /* FT_RB_TREE_ITERATOR_HPP */
