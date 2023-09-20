/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:26:41 by ddzuba            #+#    #+#             */
/*   Updated: 2023/09/20 18:04:08 by ddzuba           ###   ########.fr       */
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
	/* If _arraySize is greater than 0, the existing _arrayNumbers array is deleted using delete[]. 
	This is done to release any previously allocated memory.*/
	if (_arraySize > 0)
	{
		delete[] _arrayNumbers;
		_arrayNumbers = new int[_arraySize];
		for (int i = 0; i < _arraySize; i++)
			_arrayNumbers[i] = copy._arrayNumbers[i];
	}
	/* A loop copies the values from copy._arrayNumbers to _arrayNumbers element by element.
	If _set_Numbers is not empty, it is cleared using the clear() function.
	A loop iterates through copy._set_Numbers, and each element is inserted into _set_Numbers. 
	This effectively copies the contents of the set.*/
	if (!_set_Numbers.empty())
	{
		_set_Numbers.clear();
		SET<int>::const_iterator setIt;
		for (setIt = copy._set_Numbers.begin(); setIt != copy._set_Numbers.end(); ++setIt)
			_set_Numbers.insert(*setIt);
	}
	/* Similarly, if _listNumbers is not empty, it is cleared, and then a loop copies elements
	from copy._listNumbers to _listNumbers.*/
	if (!_listNumbers.empty())
	{
		_listNumbers.clear();
		LIST<int>::const_iterator listIt;
		for (listIt = copy._listNumbers.begin(); listIt != copy._listNumbers.end(); ++listIt)
			_listNumbers.push_back(*listIt);
	}
	/* Finally, if _dequeNumbers is not empty, a loop copies elements from copy._dequeNumbers to _dequeNumbers.*/
	if (!_dequeNumbers.empty())
	{
		DEQUE<int>::const_iterator dequeIt;
		for (dequeIt = copy._dequeNumbers.begin(); dequeIt != copy._dequeNumbers.end(); ++dequeIt)
			_dequeNumbers.push_back(*dequeIt);
	}
	return *this;
}

/* It's a templated function, meaning it can work with different types of containers and iterators,
making it more flexible and reusable.

Overall, this function is an implementation of a hybrid sorting algorithm that leverages the efficiency
of insertion sort for small sublists and merge sort for larger sublists.*/
template <typename Container, typename Iterator>
void	PmergeMe::_mergeInsertSort(Container& cont, Iterator low, Iterator high)
{
	if (low != high)
	{
		if (DIST(low, high) <= 4)
		{
			for (Iterator i = low; i != high; ++i)
			{
				typename Container::value_type key = *i;
				Iterator o = i;
				while (o != low && *std::prev(o) > key)
				{
					*o = *std::prev(o);
					--o;
				}
				*o = key;
			}
		}
		else
		{
			Iterator mid = low;  // divide the container on two parts
			std::advance(mid, DIST(low, high) / 2);
			_mergeInsertSort(cont, low, mid); //sort our parts recursively
			_mergeInsertSort(cont, mid, high);
			_merge(cont, low, mid, high); //merge our parts
		}
	}
}

template <typename Container, typename Iterator>
void	PmergeMe::_merge(Container& cont, Iterator low, Iterator mid, Iterator high)
{
	Container	buff;
	Iterator	i = low;
	Iterator	o = mid;
/* Here we connected our sorted subcontainers to temporary buffer */
	while (i != mid && o != high)
	{
		if (*i <= *o)
		{
			buff.push_back(*i);
			++i;
		}
		else
		{
			buff.push_back(*o);
			++o;
		}
	}
/* Here we copied remaining elements from the first container */
	while (i != mid)
	{
		buff.push_back(*i);
		++i;
	}
/* Here we copied remaining elements from the second container */
	while (o != high)
	{
		buff.push_back(*o);
		++o;
	}
/* At the end, we copy merged elements to the original container */
	Iterator	iter = low;
	for (typename Container::iterator tempIter = buff.begin(); tempIter != buff.end(); ++tempIter, ++iter)
		*iter = *tempIter;
}

void	PmergeMe::_exitProgram()
{
	delete[] _arrayNumbers;
	exit(-1);
}

int	PmergeMe::_assignNumber(STR element)
{
	int num;

	std::istringstream	iss(element);
	if (!(iss >> num))
	{
		COUT << B_RED << ERR_POSITIVE << DEFAULT << ENDL;
		_exitProgram();
	}
	return num;
}

bool	PmergeMe::_isNumberPositive(int num)
{
	if (num <= 0)
	{
		COUT << B_RED << ERR_POSITIVE << DEFAULT << ENDL;
		return false;
	}
	return true;
}

bool	PmergeMe::_searchDuplicates()
{
	for (int i = 0; i < (_arraySize - 1); i++)
	{
		for (int o = (i + 1); o < (_arraySize); o++)
		{
			if (_arrayNumbers[i] == _arrayNumbers[o])
			{
				COUT << B_RED << ERR_DUPLICATE << DEFAULT << ENDL;
				return true;
			}
		}
	}
	return false;
}

void	PmergeMe::_showStartingArray()
{
	COUT << B_GREEN << "Unsorted list of elements: \t" << DEFAULT;
	for (int i = 0; i < (_arraySize); i++)
		COUT << B_PINK << _arrayNumbers[i] << " " << DEFAULT;
	COUT << "\n" << B_RED << LINE << "\n" << DEFAULT << ENDL;
}

double	PmergeMe::_sortingTime(STR container)
{
	clock_t	startTime;
	clock_t	endTime;

	if (container == "set")
	{
		startTime = clock();
		for (int i = 0; i < _arraySize; i++)
			_set_Numbers.insert(_arrayNumbers[i]);
		endTime = clock();
		return((double)(endTime - startTime) / CLOCKS_PER_SEC * 1e3);
	}
	else if (container == "list")
	{
		for (int i = 0; i < _arraySize; i++)
			_listNumbers.push_back(_arrayNumbers[i]);
		startTime = clock();
		_mergeInsertSort(_listNumbers, _listNumbers.begin(), _listNumbers.end());
		endTime = clock();
		return((double)(endTime - startTime) / CLOCKS_PER_SEC * 1e3);
	}
	else if (container == "deque")
	{
		for (int i = 0; i < _arraySize; i++)
			_dequeNumbers.push_back(_arrayNumbers[i]);
		startTime = clock();
		_mergeInsertSort(_dequeNumbers, _dequeNumbers.begin(), _dequeNumbers.end());
		endTime = clock();
		return((double)(endTime - startTime) / CLOCKS_PER_SEC * 1e3);
	}
	COUT << B_RED << ERR_NO_CONTAINER << DEFAULT << ENDL;
	_exitProgram();
	return -1;
}

void	PmergeMe::_showSortedArray(STR container)
{
	SET<int>::iterator	iter;
	COUT << B_YELLOW << "After sorting: \t" << DEFAULT;

	if (container == "set")
	{
		for (iter = _set_Numbers.begin(); iter != _set_Numbers.end(); iter++)
			COUT << B_GREEN << *iter << " " << DEFAULT;
	}
	else if (container == "list")
	{
		LIST<int>::iterator iterList;
		for (iterList = _listNumbers.begin(); iterList != _listNumbers.end(); iterList++)
			COUT << B_GREEN << *iterList << " " << DEFAULT;
	}
	else if (container == "deque")
	{
		DEQUE<int>::iterator	iterDeque;
		for (iterDeque = _dequeNumbers.begin(); iterDeque != _dequeNumbers.end(); iterDeque++)
			COUT << B_GREEN << *iterDeque << " " << DEFAULT;
	}
	COUT << ENDL;
}

void	PmergeMe::_showEndTime(STR container, double sortTime)
{
	if (container == "set")
	{
		COUT << B_TURQUOISE << "Working time with a range of " << _arraySize 
			<< " elements with " << U_GREEN <<  "std::set: " << B_BLUE 
			<< sortTime << " ms" << DEFAULT << ENDL;
	}
	else if (container == "list")
	{
		COUT << B_TURQUOISE << "Working time with a range of " << _arraySize 
			<< " elements with " << U_GREEN "std::list: " << B_BLUE << sortTime
			<< " ms" << DEFAULT << ENDL;
	}
	else if (container == "deque")
	{
		COUT << B_TURQUOISE << "Working time with a range of " << _arraySize 
			<< " elements with " << U_GREEN << "std::deque: " << B_BLUE << sortTime
			<< " ms" << DEFAULT << ENDL;
	}
}

PmergeMe::PmergeMe(){} // constructor

PmergeMe::~PmergeMe()
{
	delete[] _arrayNumbers;
}

void	PmergeMe::init(int argc, char *argv[])
{
	int	num;
	_arraySize = argc - 1;
	_arrayNumbers = new int[_arraySize];

	for (int i = 1; i < argc; i++)
	{
		num = _assignNumber(argv[i]);
		if (_isNumberPositive(num))
			_arrayNumbers[i - 1] = num;
		else
			_exitProgram();
	}
	_showStartingArray();
}

void	PmergeMe::set()
{
	double	sortTime;

	sortTime = _sortingTime("set");
	_showSortedArray("set");
	_showEndTime("set", sortTime);
	COUT << "\n" << B_RED << LINE << DEFAULT << "\n\n";
}

void	PmergeMe::list()
{
	double	sortTime;

	sortTime = _sortingTime("list");
	_showSortedArray("list");
	_showEndTime("list", sortTime);
	COUT << "\n" << B_RED << LINE << DEFAULT << "\n\n";
}

void	PmergeMe::deque()
{
	double	sortTime;

	sortTime = _sortingTime("deque");
	_showSortedArray("deque");
	_showEndTime("deque", sortTime);
	COUT << "\n" << B_RED << LINE << DEFAULT << "\n\n";
}
