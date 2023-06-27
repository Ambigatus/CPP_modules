/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:33:19 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/26 18:47:14 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Unknown Animal")
{
	std::cout << "Animal: Default constructor called" << std::endl;
	return ;
}

Animal::~Animal()
{
	std::cout << "Animal: Destructor called" << std::endl;
	return ;
}

Animal::Animal(Animal const &copy)
{
	*this = copy;
	std::cout << "Animal: Copy constructor called" << std::endl;
}

Animal &Animal::operator=(Animal const &copy)
{
	std::cout << "Animal: operator= called" << std::endl;
	if(this == &copy)
		return *this;
	this->_type = copy._type;
	return *this;
}

void Animal::makeSound() const
{
	std::cout << "Animal can't talk" << std::endl;
	return ;
}

std::string Animal::getType() const
{
	return _type;
}
