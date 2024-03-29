/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:40:30 by ddzuba            #+#    #+#             */
/*   Updated: 2023/08/02 15:01:30 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main() {
    std::string partition(50, '-');

    std::cout << partition << std::endl;
    std::cout << "// EMPTY ARRAY TESTS //" << std::endl;
    std::cout << partition << std::endl;
    {
        std::cout << "Integers:" << std::endl;
        Array<int>	array1(5);
        std::cout << "array1 size: " << array1.size() << std::endl;
        for (int i = 0; i < 5; i++)
            std::cout << "array1 element[" << i << "]: " << array1[i] << std::endl;
        std::cout << partition << std::endl;

        std::cout << "Char:" << std::endl;
        Array<char>	array2(5);
        std::cout << "array2 size: " << array2.size() << std::endl;
        for (int i = 0; i < 5; i++)
            std::cout << "array1 element[" << i << "]: " << array2[i] << std::endl;
    }
    std::cout << partition << std::endl;
    std::cout << "// INT TEST //" << std::endl;
    std::cout << partition << std::endl;
    {
        Array<int>	array1(5);
        for (int i = 0; i < 5; i++)
            array1[i] = i;

        std::cout << "Base Array:" << std::endl;
        for (int i = 0; i < 5; i++)
            std::cout << "array1 element[" << i << "]: " << array1[i] << std::endl;
    }
    std::cout << partition << std::endl;
    std::cout << "// CHAR TEST //" << std::endl;
    std::cout << partition << std::endl;
    {
        Array<char>	array1(3);
        array1[0] = 'a';
        array1[1] = 'b';
        array1[2] = 'c';
        for (int i = 0; i < 3; i++)
            std::cout << "array1 element[" << i << "]: " << array1[i] << std::endl;
    }
    std::cout << partition << std::endl;
    std::cout << "// COPY TEST //" << std::endl;
    std::cout << partition << std::endl;
    {
        Array<int>	array1(5);
        for (int i = 0; i < 5; i++)
            array1[i] = i;

        Array<int>	array2;
        array2 = array1;
        for (int i = 0; i < 5; i++)
            array2[i] *= 2;

        std::cout << "Base Array:" << std::endl;
        for (int i = 0; i < 5; i++)
            std::cout << "array1 element[" << i << "]: " << array1[i] << std::endl;
        std::cout << partition << std::endl;
        std::cout << "Modified Copy Array:" << std::endl;
        for (int i = 0; i < 5; i++)
            std::cout << "array2 element[" << i << "]: " << array2[i] << std::endl;
    }
    std::cout << partition << std::endl;
    std::cout << "// OUT OF BOUNDS TEST //" << std::endl;
    std::cout << partition << std::endl;
    {
        Array<int>	array1(5);
        for (int i = 0; i < 5; i++)
            array1[i] = i;
        try
        {
            array1[5];
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << partition << std::endl;

    return (0);
}