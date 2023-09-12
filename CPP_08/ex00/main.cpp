/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:03:55 by hboichuk          #+#    #+#             */
/*   Updated: 2023/09/12 18:06:09 by hboichuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(int argc, char **argv)
{
	std::vector<int> vector;
	std::list<int> list;
	
	//checkers for errors
	if (argc != 2)
	{
		std::cout << "You need a number!" << std::endl;
		return EXIT_FAILURE;
	}

	for(int i = 0, n = strlen(argv[1]); i < n; i++)
	{
    	if(!isdigit(argv[1][i]))
		{
			std::cout << "You need a number!" << std::endl;
			return EXIT_FAILURE;
		}
	}
	
	//first test 
	for (int i = 0;i < 10; i++)
		vector.push_back(i);

	//second test
	for (int y = 0;y < 10; y++)
		list.push_back(y);
	
	easyfind(vector, std::atoi( argv[1]));
	easyfind(list, std::atoi( argv[1]));
	return EXIT_SUCCESS;
}