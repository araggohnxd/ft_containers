/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:00:48 by maolivei          #+#    #+#             */
/*   Updated: 2023/02/20 12:44:32 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SET_HPP
#define FT_SET_HPP

#include "rb_tree.hpp"

#define SET_TEMPLATE typename T, typename Compare, typename Alloc

#define SET_CLASS set<T, Compare, Alloc>

namespace ft {

template <typename T, typename Compare = std::less<T>, typename Alloc = std::allocator<T> >
class set {
    public:
        typedef T                               key_type;
        typedef T                               value_type;
        typedef Compare                         key_compare;
        typedef Compare                         value_compare;
        typedef typename Alloc::reference       reference;
        typedef typename Alloc::const_reference const_reference;
        typedef typename Alloc::pointer         pointer;
        typedef typename Alloc::const_pointer   const_pointer;

    private:
        template <typename P>
        struct _identity {
                T       operator()(P &x) const { return (x); }
                T const operator()(P const &x) const { return (x); }
        };

        typedef rb_tree<key_type, value_type, _identity<value_type>, key_compare, Alloc> tree_type;

    public:
        typedef typename tree_type::allocator_type         allocator_type;
        typedef typename tree_type::size_type              size_type;
        typedef typename tree_type::difference_type        difference_type;
        typedef typename tree_type::iterator               iterator;
        typedef typename tree_type::const_iterator         const_iterator;
        typedef typename tree_type::reverse_iterator       reverse_iterator;
        typedef typename tree_type::const_reverse_iterator const_reverse_iterator;

        /********************** CONSTRUCTORS, DESTRUCTOR AND ASSIGN OPERATOR **********************/

        explicit set(key_compare const    &comp  = key_compare(),
                     allocator_type const &alloc = allocator_type());
        template <class Iterator>
        set(Iterator              first,
            Iterator              last,
            key_compare const    &comp  = key_compare(),
            allocator_type const &alloc = allocator_type());
        set(set const &src);

        ~set(void);

        set &operator=(set const &src);

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

        void      erase(iterator position);
        size_type erase(value_type const &value);
        void      erase(iterator first, iterator last);
        void      swap(set &src);
        void      clear(void);

        /**************************************** OBSERVERS ***************************************/

        key_compare   key_comp(void) const;
        value_compare value_comp(void) const;

        /************************************ LOOKUP OPERATIONS ***********************************/

        iterator                             find(value_type const &value);
        const_iterator                       find(value_type const &value) const;
        size_type                            count(value_type const &value) const;
        iterator                             lower_bound(value_type const &value);
        const_iterator                       lower_bound(value_type const &value) const;
        iterator                             upper_bound(value_type const &value);
        const_iterator                       upper_bound(value_type const &value) const;
        pair<iterator, iterator>             equal_range(value_type const &value);
        pair<const_iterator, const_iterator> equal_range(value_type const &value) const;

        /**************************************** ALLOCATOR ***************************************/

        allocator_type get_allocator(void) const;

        /********************************** NON-MEMBER FUNCTIONS **********************************/

        template <typename T1, typename C1, typename A1>
        friend bool operator==(set<T1, C1, A1> const &, set<T1, C1, A1> const &);

        template <typename T1, typename C1, typename A1>
        friend bool operator<(set<T1, C1, A1> const &, set<T1, C1, A1> const &);

    private:
        tree_type _tree;
};

template <SET_TEMPLATE>
bool operator==(SET_CLASS const &lhs, SET_CLASS const &rhs)
{
    return (lhs._tree == rhs._tree);
}

template <SET_TEMPLATE>
bool operator!=(SET_CLASS const &lhs, SET_CLASS const &rhs)
{
    return (!(lhs == rhs));
}

template <SET_TEMPLATE>
bool operator<(SET_CLASS const &lhs, SET_CLASS const &rhs)
{
    return (lhs._tree < rhs._tree);
}

template <SET_TEMPLATE>
bool operator<=(SET_CLASS const &lhs, SET_CLASS const &rhs)
{
    return (!(rhs < lhs));
}

template <SET_TEMPLATE>
bool operator>(SET_CLASS const &lhs, SET_CLASS const &rhs)
{
    return (rhs < lhs);
}

template <SET_TEMPLATE>
bool operator>=(SET_CLASS const &lhs, SET_CLASS const &rhs)
{
    return (!(lhs < rhs));
}

} /* namespace ft */

#include "set.tpp"

#endif /* FT_SET_HPP */
