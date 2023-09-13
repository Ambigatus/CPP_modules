/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:03:55 by hboichuk          #+#    #+#             */
/*   Updated: 2023/09/13 17:40:48 by hboichuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main(void)
{
	//simple test from the subject
	std::cout << "\n\033[32m----- Simple Span -----\033[0m" << std::endl;
	Span sp = Span(5);
	try
    {
        sp.addNumber(5);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
       	sp.addNumber(12); // out of range case
    }
    catch (std::exception & ex)
    {
        std::cout << ex.what() << std::endl;
    }

    try
    {
        for (int i = 0; i < 5; ++i) // for showing our numbers
            std::cout << sp[i] << std::endl;
    }
    catch (std::exception & ex)
    {
        std::cout << ex.what() << std::endl;
    }

    std::cout << "Short Span: " << sp.shortestSpan() << std::endl;
    std::cout << "Long Span: " << sp.longestSpan() << std::endl;

	//hard test with variative value
	std::cout << "\n\033[32m----- Many numbers -----\033[0m" << std::endl;
	int amount;
	amount = 10100;
	std::vector<int> collection;
	Span hard = Span(amount);
	srand(1);
	for (int i = 0; i < amount; i++) // change here number
	{
	 	try
   	 	{
        	collection.push_back(rand() % amount);
   		}
    	catch (std::exception & ex)
    	{
        	std::cout << ex.what() << std::endl;
    	}
	}
	 try
    {
		hard.addManyNumbers(collection.begin(),collection.end());
        // for (int i = 0; i < amount; ++i) // for showing our numbers
        //     std::cout << hard[i] << " ";
    }
    catch (std::exception & ex)
    {
        std::cout << ex.what() << std::endl;
    }
	std::cout << std::endl;
	std::cout << "Short Span: " << hard.shortestSpan() << std::endl;
    std::cout << "Long Span: " << hard.longestSpan() << std::endl;

	// case with 1 or 0 numbers, should be an error, also cases with negative numbers
	std::cout << "\n\033[32m----- Error cases -----\033[0m" << std::endl;
    Span sp3 = Span(1);
	// sp3.addNumber(17);
    try {
        std::cout << "Short Span: " << sp3.shortestSpan() << std::endl;
    }
    catch (std::exception & ex)
    {
        std::cout << ex.what() << std::endl;
    }

    return (0);
	
}