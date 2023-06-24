/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:02:15 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/24 17:17:46 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat: Default constructor called" << std::endl;
	_type = "type WrongCat";
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat: Denstructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy)
    : WrongAnimal(copy) 
{
	std::cout << "Cat: Copy constructor called" << std::endl;
	this->_type = copy._type;
}

WrongCat &WrongCat::operator=(WrongCat const &copy)
{
	std::cout << "WrongCat: operator= called" << std::endl;
	if(this == &copy)
		return *this;
	this->_type = copy._type;
	return *this;
}

void WrongCat::makeSound(void) const
{
	std::cout << "WrongCat: Brrrr" << std::endl;
}