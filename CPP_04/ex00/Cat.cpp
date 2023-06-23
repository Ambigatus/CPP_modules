/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:35:10 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/23 21:47:49 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat: Default constructor called" << std::endl;
	_type = "type Cat";
}

Cat::~Cat()
{
	std::cout << "Cat: Denstructor called" << std::endl;
}

Cat::Cat(const Cat& copy)
    : Animal(copy) 
{
	std::cout << "Cat: Copy constructor called" << std::endl;
	this->_type = copy._type;
}

Cat &Cat::operator=(Cat const &copy)
{
	std::cout << "Cat: operator= called" << std::endl;
	if(this == &copy)
		return *this;
	this->_type = copy._type;
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "Cat: Meow" << std::endl;
}
