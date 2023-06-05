/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 19:06:40 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/04 17:02:24 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
// #include <limits>
#include <iostream>

int main(void) {
    PhoneBook book;
    std::string input = "";
    book.welcome();
    while (input.compare("EXIT")) 
	{
        if (input.compare("ADD") == 0)
            book.addContact();
        else if (input.compare("SEARCH") == 0) {
            book.printContacts();
            book.search();
        }
        std::cout << "> " << std::flush;
        std::cin >> input;
    }
    return 0;
}