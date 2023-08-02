/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:48:07 by ddzuba            #+#    #+#             */
/*   Updated: 2023/08/02 14:48:09 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<typename T>
Array<T>::Array() : _size(0), _values(new T[0]){}

template<typename T>
Array<T>::Array(unsigned int size) : _size(size), _values(new T[size]){}

template<typename T>
Array<T>::Array(Array const &copy) : _size(0), _values(new T[0])
{
	*this = copy;
}

template<typename T>
Array<T> &Array<T>::operator=(Array<T> const &copy)
{
	_size = copy.size();
	if (_values)
		delete [] _values;
	_values = new T[copy.size()];
	for (size_t i = 0; i < _size; i++)
		_values[i] = copy[i];
	return *this;
}

template<typename T>
Array<T>::~Array()
{
	delete [] _values;
}

template<typename T>
T &Array<T>::operator[](size_t index) const
{
	if (index < _size)
		return _values[index];
	else
		throw OutOfBoundsExeption();
}

template<typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

template<typename T>
const char	*Array<T>::OutOfBoundsExeption::what() const throw()
{
	return "Exception: Index is out of bounds";
}
