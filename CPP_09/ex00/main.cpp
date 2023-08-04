/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:03:55 by hboichuk          #+#    #+#             */
/*   Updated: 2023/08/04 20:35:18 by hboichuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{	
	if (argc != 2) 
	{
		std::cerr << "You need 2 arguments!" << std::endl;
		return EXIT_FAILURE;
	}
	
	std::string _file = argv[1];

	//checkers
	checkFile();
	
	
	return EXIT_SUCCESS;
}