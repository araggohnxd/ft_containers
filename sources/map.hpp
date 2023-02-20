/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:00:48 by maolivei          #+#    #+#             */
/*   Updated: 2023/02/20 12:29:31 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_HPP
#define FT_MAP_HPP

#include "rb_tree.hpp"

#define MAP_TEMPLATE typename Key, typename T, typename Compare, typename Alloc

#define MAP_CLASS map<Key, T, Compare, Alloc>

namespace ft {

template <typename Key,
          typename T,
          typename Compare = std::less<Key>,
          typename Alloc   = std::allocator<pair<const Key, T> > >
class map {
    public:
        typedef Key                               key_type;
        typedef T                                 mapped_type;
        typedef pair<const key_type, mapped_type> value_type;
        typedef Compare                           key_compare;
        typedef typename Alloc::reference         reference;
        typedef typename Alloc::const_reference   const_reference;
        typedef typename Alloc::pointer           pointer;
        typedef typename Alloc::const_pointer     const_pointer;

        class value_compare : public std::binary_function<value_type, value_type, bool> {
                friend class map<Key, T, Compare, Alloc>;

            protected:
                Compare comp;

                value_compare(Compare c) : comp(c) {}

            public:
                bool operator()(value_type const &x, value_type const &y) const
                {
                    return (comp(x.first, y.first));
                }
        };

    private:
        template <typename Pair>
        struct select1st {
                Key       operator()(Pair &x) const { return (x.first); }
                Key const operator()(Pair const &x) const { return (x.first); }
        };

        typedef rb_tree<key_type, value_type, select1st<value_type>, key_compare, Alloc> tree_type;

    public:
        typedef typename tree_type::allocator_type         allocator_type;
        typedef typename tree_type::size_type              size_type;
        typedef typename tree_type::difference_type        difference_type;
        typedef typename tree_type::iterator               iterator;
        typedef typename tree_type::const_iterator         const_iterator;
        typedef typename tree_type::reverse_iterator       reverse_iterator;
        typedef typename tree_type::const_reverse_iterator const_reverse_iterator;

        /********************** CONSTRUCTORS, DESTRUCTOR AND ASSIGN OPERATOR **********************/

        explicit map(key_compare const    &comp  = key_compare(),
                     allocator_type const &alloc = allocator_type());

        template <typename Iterator>
        map(Iterator              first,
            Iterator              last,
            key_compare const    &comp  = key_compare(),
            allocator_type const &alloc = allocator_type());

        map(map const &src);
        map &operator=(map const &src);
        ~map(void);

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

        /************************************* ELEMENT ACCESS *************************************/

        mapped_type       &operator[](key_type const &key);
        mapped_type       &at(key_type const &key);
        mapped_type const &at(key_type const &key) const;

        /**************************************** MODIFIERS ***************************************/

        pair<iterator, bool> insert(value_type const &value);
        iterator             insert(iterator position, value_type const &value);

        template <typename Iterator>
        void insert(Iterator first, Iterator last);

        void      erase(iterator position);
        size_type erase(key_type const &key);
        void      erase(iterator first, iterator last);
        void      swap(map &src);
        void      clear(void);

        /**************************************** OBSERVERS ***************************************/

        key_compare   key_comp(void) const;
        value_compare value_comp(void) const;

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

        allocator_type get_allocator(void) const;

        /********************************** NON-MEMBER FUNCTIONS **********************************/

        template <typename K1, typename T1, typename C1, typename A1>
        friend bool operator==(map<K1, T1, C1, A1> const &, map<K1, T1, C1, A1> const &);

        template <typename K1, typename T1, typename C1, typename A1>
        friend bool operator<(map<K1, T1, C1, A1> const &, map<K1, T1, C1, A1> const &);

    private:
        tree_type _tree;
};

template <MAP_TEMPLATE>
void swap(MAP_CLASS &lhs, MAP_CLASS &rhs)
{
    lhs.swap(rhs);
}

template <MAP_TEMPLATE>
bool operator==(MAP_CLASS const &lhs, MAP_CLASS const &rhs)
{
    return (lhs._tree == rhs._tree);
}

template <MAP_TEMPLATE>
bool operator!=(MAP_CLASS const &lhs, MAP_CLASS const &rhs)
{
    return (!(lhs == rhs));
}

template <MAP_TEMPLATE>
bool operator<(MAP_CLASS const &lhs, MAP_CLASS const &rhs)
{
    return (lhs._tree < rhs._tree);
}

template <MAP_TEMPLATE>
bool operator<=(MAP_CLASS const &lhs, MAP_CLASS const &rhs)
{
    return (!(rhs < lhs));
}

template <MAP_TEMPLATE>
bool operator>(MAP_CLASS const &lhs, MAP_CLASS const &rhs)
{
    return (rhs < lhs);
}

template <MAP_TEMPLATE>
bool operator>=(MAP_CLASS const &lhs, MAP_CLASS const &rhs)
{
    return (!(lhs < rhs));
}

} /* namespace ft */

#include "map.tpp"

#endif /* FT_MAP_HPP */
