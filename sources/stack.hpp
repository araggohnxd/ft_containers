/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:00:48 by maolivei          #+#    #+#             */
/*   Updated: 2023/02/19 19:27:55 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_HPP
#define FT_STACK_HPP

#include "vector.hpp"

namespace ft {

template <typename T, typename Container = vector<T> >
class stack {
    public:
        typedef Container                           container_type;
        typedef typename Container::value_type      value_type;
        typedef typename Container::size_type       size_type;
        typedef typename Container::reference       reference;
        typedef typename Container::const_reference const_reference;

        /******************************* CONSTRUCTORS AND DESTRUCTOR ******************************/

        explicit stack(container_type const &container = container_type());
        ~stack(void);

        /**************************************** CAPACITY ****************************************/

        bool      empty(void) const;
        size_type size(void) const;

        /************************************* ELEMENT ACCESS *************************************/

        value_type       &top(void);
        value_type const &top(void) const;

        /**************************************** MODIFIERS ***************************************/

        void push(value_type const &value);
        void pop(void);

        /********************************** NON-MEMBER FUNCTIONS **********************************/

        template <typename _T, typename _Container>
        friend bool operator==(stack<_T, _Container> const &, stack<_T, _Container> const &);

        template <typename _T, typename _Container>
        friend bool operator<(stack<_T, _Container> const &, stack<_T, _Container> const &);

    protected:
        Container _container;
};

template <typename T, typename Container>
bool operator==(stack<T, Container> const &lhs, stack<T, Container> const &rhs)
{
    return (lhs._container == rhs._container);
}

template <typename T, typename Container>
bool operator!=(stack<T, Container> const &lhs, stack<T, Container> const &rhs)
{
    return (!(lhs == rhs));
}

template <typename T, typename Container>
bool operator<(stack<T, Container> const &lhs, stack<T, Container> const &rhs)
{
    return (lhs._container < rhs._container);
}

template <typename T, typename Container>
bool operator<=(stack<T, Container> const &lhs, stack<T, Container> const &rhs)
{
    return (!(rhs < lhs));
}

template <typename T, typename Container>
bool operator>(stack<T, Container> const &lhs, stack<T, Container> const &rhs)
{
    return (rhs < lhs);
}

template <typename T, typename Container>
bool operator>=(stack<T, Container> const &lhs, stack<T, Container> const &rhs)
{
    return (!(lhs < rhs));
}

} /* namespace ft */

#include "stack.tpp"

#endif /* FT_STACK_HPP */
