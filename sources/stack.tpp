/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:48:46 by maolivei          #+#    #+#             */
/*   Updated: 2023/02/19 19:27:57 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_TPP
#define FT_STACK_TPP

#include "stack.hpp"

namespace ft {

/*********************************** CONSTRUCTORS AND DESTRUCTOR **********************************/

template <typename T, typename Container>
stack<T, Container>::stack(container_type const &container) : _container(container)
{
}

template <typename T, typename Container>
stack<T, Container>::~stack(void)
{
}

/******************************************** CAPACITY ********************************************/

template <typename T, typename Container>
bool stack<T, Container>::empty(void) const
{
    return (_container.empty());
}

template <typename T, typename Container>
typename stack<T, Container>::size_type stack<T, Container>::size(void) const
{
    return (_container.size());
}

/***************************************** ELEMENT ACCESS *****************************************/

template <typename T, typename Container>
typename stack<T, Container>::value_type &stack<T, Container>::top(void)
{
    return (_container.back());
}

template <typename T, typename Container>
typename stack<T, Container>::value_type const &stack<T, Container>::top(void) const
{
    return (_container.back());
}

/******************************************** MODIFIERS *******************************************/

template <typename T, typename Container>
void stack<T, Container>::push(value_type const &value)
{
    _container.push_back(value);
}

template <typename T, typename Container>
void stack<T, Container>::pop(void)
{
    _container.pop_back();
}

} /* namespace ft */

#endif /* FT_STACK_TPP */
