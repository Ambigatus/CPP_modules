/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:24:17 by ddzuba            #+#    #+#             */
/*   Updated: 2023/09/19 16:45:58 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <deque>
# include <set>
# include <list>
# include <iostream>
# include <sstream>
# include "Utils.hpp"

class PmergeMe
{
	private:
		int					*_arrayNumbers;
		int					_arraySize;
		SET<int>			_set_Numbers;
		LIST<int>			_listNumbers;
		DEQUE<int>			_dequeNumbers;

		PmergeMe(PmergeMe &copy);
		PmergeMe	&operator=(PmergeMe &copy);
		
		template <typename Container, typename Iterator>
		void		_mergeInsertSort(Container& cont, Iterator low, Iterator high);
		template <typename Container, typename Iterator>
		void		_merge(Container& cont, Iterator low, Iterator mid, Iterator high);

		void		_exitProgram();
		int			_assignNumber(STR element);
		bool		_isNumberPositive(int number);
		bool		_searchDuplicates();
		void		_showStartingArray();
		double		_sortingTime(STR container);
		void		_showSortedArray(STR container);
		void		_showEndTime(STR container, double sortTime);

	public:
		PmergeMe();
		~PmergeMe();

		void	init(int argc, char **argv);
		void	set();
		void	list();
		void	deque();
};

#endif