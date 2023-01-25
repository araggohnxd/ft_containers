/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:38:23 by maolivei          #+#    #+#             */
/*   Updated: 2023/01/24 21:09:40 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RANDOM_ACCESS_ITERATOR_HPP
#define FT_RANDOM_ACCESS_ITERATOR_HPP

#include "iterator_base.hpp"
#include "iterator_traits.hpp"

namespace ft {

template <typename Iterator>
class random_access_iterator : public ft::iterator<typename ft::iterator_traits<Iterator>::iterator_category,
                                                   typename ft::iterator_traits<Iterator>::value_type,
                                                   typename ft::iterator_traits<Iterator>::difference_type,
                                                   typename ft::iterator_traits<Iterator>::pointer,
                                                   typename ft::iterator_traits<Iterator>::reference> {
    public:
        typedef Iterator                                              iterator_type;
        typedef typename iterator_traits<Iterator>::value_type        value_type;
        typedef typename iterator_traits<Iterator>::pointer           pointer;
        typedef typename iterator_traits<Iterator>::reference         reference;
        typedef typename iterator_traits<Iterator>::difference_type   difference_type;
        typedef typename iterator_traits<Iterator>::iterator_category iterator_category;

        random_access_iterator(void);
        explicit random_access_iterator(iterator_type x);
        random_access_iterator(random_access_iterator const &src);
        ~random_access_iterator(void);
        random_access_iterator &operator=(random_access_iterator const &src);

        random_access_iterator &operator++(void); /* prefixed */
        random_access_iterator  operator++(int);  /* postfixed */
        random_access_iterator &operator+=(difference_type n);
        random_access_iterator  operator+(difference_type n) const;

        random_access_iterator &operator--(void); /* prefixed */
        random_access_iterator  operator--(int);  /* postfixed */
        random_access_iterator &operator-=(difference_type n);
        random_access_iterator  operator-(difference_type n) const;

        reference operator*(void) const;
        pointer   operator->(void) const;

        reference operator[](difference_type n) const;

        iterator_type base(void) const;

    private:
        Iterator _ptr;
};

template <typename L, typename R>
bool operator==(random_access_iterator<L> const &rhs, random_access_iterator<R> const &lhs)
{
    return (rhs.base() == lhs.base());
}

template <typename L, typename R>
bool operator!=(random_access_iterator<L> const &rhs, random_access_iterator<R> const &lhs)
{
    return (rhs.base() != lhs.base());
}

template <typename L, typename R>
bool operator<(random_access_iterator<L> const &rhs, random_access_iterator<R> const &lhs)
{
    return (rhs.base() < lhs.base());
}

template <typename L, typename R>
bool operator<=(random_access_iterator<L> const &rhs, random_access_iterator<R> const &lhs)
{
    return (rhs.base() <= lhs.base());
}

template <typename L, typename R>
bool operator>(random_access_iterator<L> const &rhs, random_access_iterator<R> const &lhs)
{
    return (rhs.base() > lhs.base());
}

template <typename L, typename R>
bool operator>=(random_access_iterator<L> const &rhs, random_access_iterator<R> const &lhs)
{
    return (rhs.base() >= lhs.base());
}

template <typename L, typename R>
typename random_access_iterator<L>::difference_type operator+(random_access_iterator<L> const &rhs,
                                                              random_access_iterator<R> const &lhs)
{
    return (rhs.base() + lhs.base());
}

template <typename L, typename R>
typename random_access_iterator<L>::difference_type operator-(random_access_iterator<L> const &rhs,
                                                              random_access_iterator<R> const &lhs)
{
    return (rhs.base() - lhs.base());
}

} /* namespace ft */

#include "random_access_iterator.tpp"

#endif /* FT_RANDOM_ACCESS_ITERATOR_HPP */
