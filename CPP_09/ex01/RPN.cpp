/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:26:51 by ddzuba            #+#    #+#             */
/*   Updated: 2023/08/06 14:47:21 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(RPN &copy)
{
	*this = copy;
}

RPN &RPN::operator=(RPN &copy)
{
	while (!_numbers.empty())
		_numbers.pop();
	std::stack<int>	buffer;
	while (!copy._numbers.empty())
	{
		buffer.push(copy._numbers.top());
		copy._numbers.pop();
	}
	while (!buffer.empty())
	{
		_numbers.push(buffer.top());
		copy._numbers.push(buffer.top());
		buffer.pop();
	}
	return *this;
}

void	RPN::_splitInput(char *input)
{
	STR inputStr = static_cast<STR>(input);
	_elements = _split(inputStr, ' ');
}

std::vector<STR>	RPN::_split(const STR &str, char delimiter)
{
	std::vector<STR> tokens;
	std::istringstream iss(str);
	STR	token;

	while (std::getline(iss, token, delimiter))
		tokens.push_back(token);
	return tokens;
}

void	RPN::_processElements()
{
	int	num;
	std::vector<STR>::iterator it;
	for (it = _elements.begin(); it != _elements.end(); it++)
	{
		if (_isOperatorNext(*it))
		{
			if (_isOperationPosibble(*it))
			{
				_performOperations((*it));
				continue;
			}
			else
				exit(-1);
		}
		num = _extractNextNumber(*it);
		if (!_isNumberValid(num))
			exit(-1);
		_numbers.push(num);
	}
}
