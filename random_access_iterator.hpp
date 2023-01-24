/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:46:39 by maolivei          #+#    #+#             */
/*   Updated: 2023/01/24 17:54:20 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RANDOM_ACCESS_ITERATOR_HPP
#define FT_RANDOM_ACCESS_ITERATOR_HPP

#include "iterator.hpp"

namespace ft {

template <typename Iterator>
class random_access_iterator : public iterator<std::random_access_iterator_tag, Iterator> {
    private:
        typedef random_access_iterator rai;

        Iterator _ptr;

    public:
        typedef Iterator                                              iterator_type;
        typedef typename iterator_traits<Iterator>::value_type        value_type;
        typedef typename iterator_traits<Iterator>::pointer           pointer;
        typedef typename iterator_traits<Iterator>::reference         reference;
        typedef typename iterator_traits<Iterator>::difference_type   difference_type;
        typedef typename iterator_traits<Iterator>::iterator_category iterator_category;

        random_access_iterator(void);
        random_access_iterator(rai const &src);
        ~random_access_iterator(void);
        random_access_iterator &operator=(rai const &src);

        bool operator==(rai const &rhs) const;
        bool operator!=(rai const &rhs) const;
        bool operator>=(rai const &rhs) const;
        bool operator<=(rai const &rhs) const;
        bool operator>(rai const &rhs) const;
        bool operator<(rai const &rhs) const;

        random_access_iterator operator++(int); /* postfixed */
        random_access_iterator operator--(int); /* postfixed */

        random_access_iterator &operator++(void); /* prefixed */
        random_access_iterator &operator--(void); /* prefixed */

        random_access_iterator operator+(difference_type n) const;
        random_access_iterator operator-(difference_type n) const;

        random_access_iterator &operator+=(difference_type n);
        random_access_iterator &operator-=(difference_type n);

        pointer   operator->(void) const;
        reference operator*(void) const;

        reference operator[](difference_type n) const;

        iterator_type base(void) const;
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
bool operator>=(random_access_iterator<L> const &rhs, random_access_iterator<R> const &lhs)
{
    return (rhs.base() >= lhs.base());
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
bool operator<(random_access_iterator<L> const &rhs, random_access_iterator<R> const &lhs)
{
    return (rhs.base() < lhs.base());
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

}

#include "random_access_iterator.tpp"

#endif /* FT_RANDOM_ACCESS_ITERATOR_HPP */
