/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:26:15 by hboichuk          #+#    #+#             */
/*   Updated: 2023/07/31 14:14:47 by hboichuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <exception> //kinds - https://cplusplus.com/reference/exception/exception/
#include <vector>
#include <list>
#include <cmath>
#include <numeric>


class Span
{
	private:
		unsigned int _n;
		//vector container is the same as dynamic arrays
		std::vector<int>  _data;
		
		Span(void);
	
	public:
		Span(unsigned int);
		~Span();
		Span(Span const &copy);
		Span &operator=(Span const &copy);

		//for working with our numbers
		int & operator[] (unsigned int index);

	//functions for span
		void				addNumber(unsigned int i);
		unsigned int		shortestSpan(void);
		unsigned int		longestSpan(void);
	
};


#endif