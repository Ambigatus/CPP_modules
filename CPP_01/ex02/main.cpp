/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:58:45 by ddzuba            #+#    #+#             */
/*   Updated: 2023/05/29 18:19:42 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>

int	main()
{
	std::string	brain = "HI THIS IS BRAIN"; //string variable
	std::string	brain2 = "HI THIS IS BRAIN"; //string variable
	std::string	*stringPTR = &brain; //pointer
	std::string	&stringREF = brain; //address
	stringPTR	=	&brain2;

	//Print memory address
	std::cout << &brain <<std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;

	//Print variable
	std::cout << brain << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;

	// Just for testing
	std::cout << "---------------------" << std::endl;
	*stringPTR = "Some information";
	std::cout << brain2 << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << "---------------------" << std::endl;
	stringREF = "Another information";
	std::cout << brain << std::endl;
	std::cout << stringREF << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << &brain << std::endl;
	std::cout << &brain2 << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;
}
