/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:55:51 by hboichuk          #+#    #+#             */
/*   Updated: 2023/08/02 15:35:35 by hboichuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

//canonical part
template <typename T>
MutantStack<T>::MutantStack() {}

template <typename T>
MutantStack<T>::MutantStack(MutantStack<T> const &src) {*this = src;}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack<T> const &src) {
    std::stack<T>::operator=(src);
    return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack() {}

//end of canonical part
//point on element of beginning on stack
template <typename T>
typename MutantStack<T>::iterator   MutantStack<T>::begin() {
    return (std::stack<T>::c.begin());
}
//point on element of ending on stack
template <typename T>
typename MutantStack<T>::iterator   MutantStack<T>::end() {
    return (std::stack<T>::c.end());
}
