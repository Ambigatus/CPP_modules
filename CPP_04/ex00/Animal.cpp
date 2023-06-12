/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:33:19 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/12 15:53:56 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << B_YELLOW << "Unknown Animal was born!" << DEFAULT << std::endl;
	_type = "unknown type";
}

Animal::~Animal()
{
	std::cout << B_RED << "Unknown Animal was died. RIP." << DEFAULT << std::endl;
}

Animal::Animal(Animal const &copy)
{
	std::cout << B_TURQUOISE << "New Animal was succefully cloned!" << DEFAULT << std::endl;
	this->_type = copy._type;
}

Animal &Animal::operator=(Animal const &copy)
{
	std::cout << B_GREEN << "New characteristics was succefully uploaded!" << DEFAULT << std::endl;
	if (this == &copy)
		return *this;
	this->_type = copy._type;
	return *this;
}

void Animal::makeSound() const
{
	std::cout << "Did you expect some words from Animal? Bruh..." << std::endl;
}

std::string Animal::getType() const
{
	return _type;
}