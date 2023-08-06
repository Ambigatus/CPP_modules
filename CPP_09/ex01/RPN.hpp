/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:54:51 by ddzuba            #+#    #+#             */
/*   Updated: 2023/08/06 14:46:41 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <vector>
# include <stack>
# include "Utils.hpp"

class RPN
{
	private:
		std::stack<int>				_numbers;
		std::vector<STR>			_elements;

	RPN(RPN &copy);
	RPN &operator=(RPN &copy);
	
	void	_splitInput(char input[]);
	std::vector<STR>	_split(const STR &str, char delimiter);
	void				_processElements();
	bool				_isOperatorNext(STR element);
	bool				_isOperationPosibble(STR element);
	void				_performOperations(STR element);
	int					_extractNextNumber(STR element);
	bool				_isNumberValid(int number);
	void				_displayResult();
	
	public:
		RPN();
		virtual ~RPN();

		void			calculate(char input[]);
};

#endif
