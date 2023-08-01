/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:55:36 by hboichuk          #+#    #+#             */
/*   Updated: 2023/08/01 16:14:36 by hboichuk         ###   ########.fr       */
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
#include "MutantStack.tpp"


class MutantStack
{
	private:
		// unsigned int _n;
		// //vector container is the same as dynamic arrays
		// std::vector<int>  _data;
		
		MutantStack(void);
	
	public:
		MutantStack(unsigned int);
		~MutantStack();
		MutantStack(Span const &copy);
		MutantStack &operator=(Span const &copy);

		//for working with our numbers
		// int & operator[] (unsigned int index);

	//functions for span
		// void				addNumber(unsigned int i);
		// void				addManyNumbers(unsigned int range);
		// unsigned int		shortestSpan(void);
		// unsigned int		longestSpan(void);
	
};


#endif