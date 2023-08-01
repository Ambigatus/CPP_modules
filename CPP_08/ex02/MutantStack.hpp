/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:55:36 by hboichuk          #+#    #+#             */
/*   Updated: 2023/08/01 16:49:02 by hboichuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <exception> //kinds - https://cplusplus.com/reference/exception/exception/
#include <vector>
#include <list>
#include <cmath>
#include <numeric>
# include <stack>


template <typename T>

class MutantStack: public std::stack<T> 
{
	private:
	
	public:
		MutantStack(void);
		~MutantStack();
		MutantStack(MutantStack const &copy);
		MutantStack &operator=(MutantStack const &copy);

		typedef typename std::stack<T>::container_type::iterator iterator;
    	iterator begin();
    	iterator end();
	
};

#include "MutantStack.tpp"

#endif