/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:53:31 by maolivei          #+#    #+#             */
/*   Updated: 2023/01/31 13:29:32 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP

#include "algorithm.hpp"
#include "iterator.hpp"
#include "type_traits.hpp"
#include <memory>
#include <stdexcept>

namespace ft {

template <typename T, typename Alloc = std::allocator<T> >
class vector {
    public:
        typedef T                                         value_type;
        typedef Alloc                                     allocator_type;
        typedef std::size_t                               size_type;
        typedef std::ptrdiff_t                            difference_type;
        typedef typename allocator_type::reference        reference;
        typedef typename allocator_type::const_reference  const_reference;
        typedef typename allocator_type::pointer          pointer;
        typedef typename allocator_type::const_pointer    const_pointer;
        typedef ft::random_access_iterator<pointer>       iterator;
        typedef ft::random_access_iterator<const_pointer> const_iterator;
        typedef ft::reverse_iterator<iterator>            reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>      const_reverse_iterator;

        /* constructors, destructor and assign operator */

        vector(vector const &src);
        explicit vector(Alloc const &alloc = Alloc());
        explicit vector(size_type n, T const &value = T(), Alloc const &alloc = Alloc());

        template <typename Iter>
        vector(Iter         first,
               Iter         last,
               Alloc const &alloc                                            = Alloc(),
               typename ft::enable_if<!ft::is_integral<Iter>::value>::type * = NULL);

        ~vector(void);
        vector &operator=(vector const &src);

        /* member functions */

        void assign(size_type n, T const &value);

        template <typename Iter>
        void assign(Iter first,
                    Iter last,
                    typename ft::enable_if<!ft::is_integral<Iter>::value>::type * = NULL);

        allocator_type get_allocator(void) const;

        /* element access */

        reference       at(size_type pos);
        const_reference at(size_type pos) const;
        reference       operator[](size_type pos);
        const_reference operator[](size_type pos) const;
        reference       front(void);
        const_reference front(void) const;
        reference       back(void);
        const_reference back(void) const;
        pointer         data(void);
        const_pointer   data(void) const;

        /* iterators */

        iterator               begin(void);
        const_iterator         begin(void) const;
        iterator               end(void);
        const_iterator         end(void) const;
        reverse_iterator       rbegin(void);
        const_reverse_iterator rbegin(void) const;
        reverse_iterator       rend(void);
        const_reverse_iterator rend(void) const;

        /* capacity */

        bool      empty(void) const;
        size_type size(void) const;
        size_type max_size(void) const;
        size_type capacity(void) const;
        void      reserve(size_type new_cap);

        /* modifiers */

        void     clear(void);
        iterator insert(iterator pos, T const &value);
        void     insert(iterator pos, size_type n, T const &value);

        template <typename Iter>
        void insert(iterator pos,
                    Iter     first,
                    Iter     last,
                    typename ft::enable_if<!ft::is_integral<Iter>::value>::type * = NULL);

        iterator erase(iterator position);
        iterator erase(iterator first, iterator last);
        void     push_back(T const &value);
        void     pop_back(void);
        void     resize(size_type n, value_type value = value_type());
        void     swap(vector &src);

    protected:
        pointer        _data;
        size_type      _capacity;
        size_type      _size;
        allocator_type _allocator;
};

template <typename T, typename Alloc>
void swap(vector<T, Alloc> &lhs, vector<T, Alloc> &rhs)
{
    lhs.swap(rhs);
}

template <typename T, typename Alloc>
bool operator==(vector<T, Alloc> const &lhs, vector<T, Alloc> const &rhs)
{
    return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template <typename T, typename Alloc>
bool operator!=(vector<T, Alloc> const &lhs, vector<T, Alloc> const &rhs)
{
    return (!(lhs == rhs));
}

template <typename T, typename Alloc>
bool operator<(vector<T, Alloc> const &lhs, vector<T, Alloc> const &rhs)
{
    return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template <typename T, typename Alloc>
bool operator<=(vector<T, Alloc> const &lhs, vector<T, Alloc> const &rhs)
{
    return (lhs < rhs || lhs == rhs);
}

template <typename T, typename Alloc>
bool operator>(vector<T, Alloc> const &lhs, vector<T, Alloc> const &rhs)
{
    return (rhs < lhs);
}

template <typename T, typename Alloc>
bool operator>=(vector<T, Alloc> const &lhs, vector<T, Alloc> const &rhs)
{
    return (lhs > rhs || lhs == rhs);
}

} /* namespace ft */

#include "vector.tpp"

#endif /* FT_VECTOR_HPP */
