/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:21:29 by ddzuba            #+#    #+#             */
/*   Updated: 2023/09/20 17:22:31 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 2) 
	{
        COUT << B_RED << ERR_ARGC << DEFAULT << ENDL;
        return (-1);
    }
    PmergeMe sorter;

    sorter.init(argc, argv);
    sorter.list();
    sorter.deque();
    sorter.set();
    return (0);
}