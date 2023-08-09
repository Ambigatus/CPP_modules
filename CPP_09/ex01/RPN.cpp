/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:26:51 by ddzuba            #+#    #+#             */
/*   Updated: 2023/08/09 15:45:21 by ddzuba           ###   ########.fr       */
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

bool	RPN::_isOperatorNext(STR element)
{
	return (element == "+" ||
			element == "-" ||
			element == "/" ||
			element == "*");
}

bool	RPN::_isOperationPosibble(STR element)
{
	if (_numbers.size() >= 2)
		return true;
	if (element == "+")
		COUT << B_RED << ERR_SUM << DEFAULT << ENDL;
	if (element == "-")
		COUT << B_RED << ERR_SUBS << DEFAULT << ENDL;
	if (element == "*")
		COUT << B_RED << ERR_MULT << DEFAULT << ENDL;
	if (element == "/")
		COUT << B_RED << ERR_DIV << DEFAULT << ENDL;
	return false;
}

void	RPN::_performOperations(STR element)
{
	int	operand;
	int	output;

	operand = _numbers.top();
	_numbers.pop();
	if (element == "+")
		output = _numbers.top() + operand;
	if (element == "-")
		output = _numbers.top() - operand;
	if (element == "*")
		output = _numbers.top() * operand;
	if (element == "/")
	{		
		if (operand == 0)
		{
			COUT << B_RED << ERR_ZERO << DEFAULT << ENDL;
			exit(-1);
		}
		output = _numbers.top() / operand;
	}
	_numbers.pop();
	_numbers.push(output);
}

int		RPN::_extractNextNumber(STR element)
{
	int	num;

	std::istringstream iss(element);
	if (!(iss >> num))
	{
		COUT << B_RED << ERR_INPUT << DEFAULT << ENDL;
		exit(-1);
	}
	return num;
}

bool	RPN::_isNumberValid(int num)
{
	if (num > 9 || num < -9)
	{
		COUT << B_RED << ERR_NUMBER << DEFAULT << ENDL;
		return false;
	}
	return true;
}

void	RPN::_displayResult()
{
	if (_numbers.size() == 1)
		COUT << _numbers.top() << ENDL;
	else
	{
		COUT << B_RED << ERR_OPERATORS << DEFAULT << ENDL;
		exit(-1);
	}
}

RPN::RPN() {}

RPN::~RPN() {}

void	RPN::calculate(char input[])
{
	_splitInput(input);
	_processElements();
	_displayResult();
}
