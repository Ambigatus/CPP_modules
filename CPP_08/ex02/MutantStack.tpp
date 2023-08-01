/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:55:51 by hboichuk          #+#    #+#             */
/*   Updated: 2023/08/01 16:40:25 by hboichuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

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

template <typename T>
typename MutantStack<T>::iterator   MutantStack<T>::begin() {
    return (std::stack<T>::c.begin());
}

template <typename T>
typename MutantStack<T>::iterator   MutantStack<T>::end() {
    return (std::stack<T>::c.end());
}
