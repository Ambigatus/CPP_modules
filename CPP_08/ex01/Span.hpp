/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:26:15 by hboichuk          #+#    #+#             */
/*   Updated: 2023/09/13 15:25:20 by hboichuk         ###   ########.fr       */
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
		Span(unsigned int n);
		~Span();
		Span(Span const &copy);
		Span &operator=(Span const &copy);

		//for working with our numbers
		int & operator[] (unsigned int index);

	//functions for span
		void				addNumber(unsigned int i);
		void				addManyNumbers(unsigned int range);
		unsigned int		shortestSpan(void);
		unsigned int		longestSpan(void);

		//exception part
		class	SpanException : public std::exception {
    		private:
        		std::string _msg;
    		public:
        		SpanException(std::string msg): _msg(msg){};
        		virtual ~SpanException() throw (){};
        		virtual const char* what() const throw(){ return (_msg.c_str());};
    };
	
};


#endif