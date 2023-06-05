/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 18:15:20 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/03 18:15:39 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv) 
{
	int	i;
	int y;
	
	i = 1;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else 
	{
		while (argv[i])
		{
			y = 0;
			while (argv[i][y])
			{
				std::cout << (char) toupper(argv[i][y]);
				y++;
			}
			if (i < argc - 1)
				std::cout << ' ';
			i++;
		}		
	}
	std::cout << std::endl;
	return (0);
}
