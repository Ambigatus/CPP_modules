/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:26:41 by ddzuba            #+#    #+#             */
/*   Updated: 2023/09/19 16:44:13 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "Utils.hpp"

PmergeMe::PmergeMe(PmergeMe &copy)
{
	*this = copy;
}

PmergeMe	&PmergeMe::operator=(PmergeMe &copy)
{
	_arraySize = copy._arraySize;
	if (_arraySize > 0)
	{
		delete[] _arrayNumbers;
		_arrayNumbers = new int[_arraySize];
		for (int i = 0; i < _arraySize; i++)
			_arrayNumbers[i] = copy._arrayNumbers[i];
	}
	
	if (!_set_Numbers.empty())
	{
		_set_Numbers.clear();
		SET<int>::const_iterator setIt;
		for (setIt = copy._set_Numbers.begin(); setIt != copy._set_Numbers.end(); ++setIt)
			_set_Numbers.insert(*setIt);
	}
	
	if (!_listNumbers.empty())
	{
		_listNumbers.clear();
		LIST<int>::const_iterator listIt;
		for (listIt = copy._listNumbers.begin(); listIt != copy._listNumbers.end(); ++listIt)
			_listNumbers.push_back(*listIt);
	}

	if (!_dequeNumbers.empty())
	{
		DEQUE<int>::const_iterator dequeIt;
		for (dequeIt = copy._dequeNumbers.begin(); dequeIt != copy._dequeNumbers.end(); ++dequeIt)
			_dequeNumbers.push_back(*dequeIt);
	}
	return *this;
}
