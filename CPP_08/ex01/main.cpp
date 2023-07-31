/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:03:55 by hboichuk          #+#    #+#             */
/*   Updated: 2023/07/31 14:16:26 by hboichuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main(void)
{
	//simple test
	// Span sp = Span(5);
	// sp.addNumber(6);
	// sp.addNumber(3);
	// sp.addNumber(17);
	// sp.addNumber(9);
	// sp.addNumber(11);
	// // sp.addNumber(12);//Data is full

	// //where are my numbers
	// for (int i = 0; i < 5; i++)
    //     std::cout << sp[i] << std::endl;
		
	// std::cout << "Here spans:" << std::endl;
	// std::cout << sp.shortestSpan() << std::endl;
	// std::cout << sp.longestSpan() << std::endl;

	// *********

	//hard test with variative value
	// int amount = 5; //choose how many nums
	// Span hard = Span(amount); 
	// srand(time(NULL));
	// for (int y = 0; y <	amount; y++) 
	// {
	// 	int num = std::rand() % 10;
	// 	std::cout << num << std::endl;
	// 	hard.addNumber(num);
	// }
	// std::cout << "Here spans:" << std::endl;
	// std::cout << hard.shortestSpan() << std::endl;
	// std::cout << hard.longestSpan() << std::endl;


	return EXIT_SUCCESS;
	
}