/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:49:37 by ddzuba            #+#    #+#             */
/*   Updated: 2023/08/01 14:59:35 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template <typename T>
void	swap(T &x, T &y)
{
	T i = x;
	x = y;
	y = i;
}

template <typename T>
T &min(T &x, T &y)
{
	return (x < y ? x : y);
}

/* 
x > y: This is a condition that checks whether x is greater than y.
?: The ? symbol acts as the ternary operator, separating the condition from the two choices.
x: If the condition x > y is true (i.e., x is greater than y), then the value of the entire expression is x.
:: The : symbol separates the true and false choices.
y: If the condition x > y is false (i.e., x is not greater than y), then the value of the entire expression is y.*/

template <typename T>
T &max(T &x, T &y)
{
	return (x > y ? x : y);
}

#endif
