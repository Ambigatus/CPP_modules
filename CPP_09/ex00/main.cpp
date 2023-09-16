/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:03:55 by hboichuk          #+#    #+#             */
/*   Updated: 2023/09/16 16:49:48 by hboichuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{	
	if (argc != 2) 
	{
		std::cerr << "Error: could not open file." << std::endl;
		return EXIT_FAILURE;
	}
	
	std::string _file = argv[1];

	//checkers
	// checkFile();
	startExchange(_file);
	
	
	return EXIT_SUCCESS;
}