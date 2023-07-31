/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:14:03 by hboichuk          #+#    #+#             */
/*   Updated: 2023/07/31 14:16:41 by hboichuk         ###   ########.fr       */
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

//another variant
//bubble sort for span
// unsigned int	Span::shortestSpan(void)
// {
// 	if (_data.size() == 0 || _data.size() == 1)
// 		throw std::length_error("Not enough numbers!");

// 		std::vector<int>::iterator it = _data.begin();
//     std::vector<int>::iterator it2;

//     unsigned int min = abs(*it - *(it + 1));
//     for (it = _data.begin() ; it != _data.end(); it++)
//     {
//         for (it2 = it + 1; it2 != _data.end(); ++it2)
//         {
//             unsigned int k = abs(*it2 - *it);
//             if (k < min)
//                 min = k;
//         }
//     }
//     return (min);
// }

unsigned int	Span::shortestSpan(void)
{
	int shortest_span;

	std::sort(this->_data.begin(), this->_data.end());
	std::vector<int> diffs(this->_data.size() - 1); // "diffs" dynamic size array; this->_collection.size() returns the number of elements in the set container.
	std::adjacent_difference(this->_data.begin(), this->_data.end(), diffs.begin()); 
	shortest_span = *std::min_element(diffs.begin(), diffs.end());
	return (shortest_span);
}

unsigned int	Span::longestSpan(void)
{
	  if (_data.size() == 0 || _data.size() == 1)
        throw std::length_error("Not enough numbers!");
    std::vector<int>::iterator it;
    it = std::min_element(_data.begin(), _data.end());

    std::vector<int>::iterator it_max;
	//max element in vector
    it_max = std::max_element(_data.begin(), _data.end());

    return (*it_max - *it);
}