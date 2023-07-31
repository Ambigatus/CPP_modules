/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:14:03 by hboichuk          #+#    #+#             */
/*   Updated: 2023/07/31 12:21:21 by hboichuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

//ortodox part
Span::Span()
{
	std::cout << "Span: Default constructor called" << std::endl;
}

Span::Span( unsigned int n ) : _n( n ) 
{
	std::cout << "Span: Constructor for unsign. int called" << std::endl;
}

Span::Span(Span const &copy)
{
	std::cout << "Span: Copy constructor called" << std::endl;
	*this = copy;
}

Span &Span::operator=(Span const &copy)
{
	std::cout << "Span: operator= called" << std::endl;
	if ( this != &copy)
	{
		this->_n = copy._n;
		this->_data = copy._data;
	}
	return *this;
}

Span::~Span()
{
	std::cout << "Span: Destructor called" << std::endl;
}

//for seeing of our numbers 
int & Span::operator[] (unsigned int index)
{
    if (index >= _n || index < 0)
        throw std::out_of_range("Span::operator[]: out of range");
    return (this->_data[index]);
}

//functions
void	Span::addNumber(unsigned int i)
{
	if (_data.size() >= _n)
		throw std::out_of_range("Data is full");
	_data.push_back(i);
}