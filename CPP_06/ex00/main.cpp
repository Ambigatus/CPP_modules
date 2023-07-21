/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:03:55 by hboichuk          #+#    #+#             */
/*   Updated: 2023/07/21 16:30:26 by hboichuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

int	main(int argc, char **argv)
{
	if(argc != 2)
	{
		std::cout << "You need only one argument!" << std::endl;
		return EXIT_FAILURE;
	}

		Converter test;
	try
    {
        test.setStr( argv[1] );
        test.convert();

        std::cout << test;
    }
    catch( const std::exception& e ) 
	{
        std::cerr << "Error: " << e.what() << std::endl;
    }
	return EXIT_SUCCESS;
}