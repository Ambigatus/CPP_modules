/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:35:00 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/23 23:20:08 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog: Default constructor called" << std::endl;
	_type = "type Dog";
}

Dog::~Dog()
{
	std::cout << "Dog: Denstructor called" << std::endl;
}

Dog::Dog(Dog const &copy) : Animal(copy)
{
	std::cout << "Dog: Copy constructor called" << std::endl;
	this->_type = copy._type;
}

Dog &Dog::operator=(Dog const &copy)
{
	std::cout << "Dog: operator= called" << std::endl;
	if(this == &copy)
		return *this;
	this->_type = copy._type;
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "Dog: Gav" << std::endl;
}
