/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:15:32 by ddzuba            #+#    #+#             */
/*   Updated: 2023/08/01 15:15:34 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

int main() {
    std::string partition(30, '-');

    char		chars[5] = {'a', 'b', 'c', 'd', 'e'};
    int			ints[5] = {1, 2, 5, 7, 10};
    char*		charptrs[5];
    int*		intptrs[5];

    for (int i = 0; i < 5; i++)
    {
        charptrs[i] = &chars[i];
        intptrs[i] = &ints[i];
    }

    std::cout << partition << std::endl;
    std::cout << "// CHAR TEST //" << std::endl;
    std::cout << partition << std::endl;
    {
        iter(chars, 5, print);
        std::cout << partition << std::endl;

        iter(&charptrs, 5, print);
        iter(charptrs, 5, print);
    }
    std::cout << partition << std::endl;
    std::cout << "// INT TEST //" << std::endl;
    std::cout << partition << std::endl;
    {
        iter(ints, 5, print);
        std::cout << partition << std::endl;

        iter(ints, 5, square);
        iter(ints, 5, print);
        std::cout << partition << std::endl;

        iter(intptrs, 5, print);
    }
    std::cout << partition << std::endl;
    return (0);
}