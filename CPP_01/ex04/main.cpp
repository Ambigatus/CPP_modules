/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:01:37 by ddzuba            #+#    #+#             */
/*   Updated: 2023/05/30 16:06:01 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"
#include <fstream>

int main(int argc, char **argv)
{
	if (argc != 4) // check the number of args
	{
		std::cout << "\033[31mError: \033[00m" << "Wrong number of arguments" << std::endl;
		return 1;
	}

	std::ifstream in(argv[1]);  // open the file for reading
	if (!in.is_open())
	{
		std::cout << "\033[31mError: \033[00m"  << "File not found" << std::endl;
		return 1;
	}

	std::string line;
	std::getline(in, line, '\0');	// read the file and place it to line
	in.close();						// close the file

	Replace place;					// creating of object
	std::string line_replace;
	line_replace = place.my_replace(line, argv[2], argv[3]);
	// We cant merge char with char, so we make first element as string
	std::string fileout = std::string(argv[1]) + "." + "replace"; // Creating a name for our file

	std::ofstream out; 				// creating a file descriptor
	out.open(fileout);				// opening the file for writing
	out << line_replace;
	out.close();
	return 0;
}
