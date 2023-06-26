/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:35:00 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/26 18:48:00 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	_type = "type Dog";
    std::cout << "Dog: Default constructor called" << std::endl;
    _brain = new Brain();
    return ;
}

Dog::~Dog()
{
    delete _brain;
	std::cout << "Dog: Destructor called" << std::endl;
    return ;
}

Dog::Dog(Dog const &copy) : Animal(copy)
{
    _brain = new Brain();
	*this = copy;
	std::cout << "Dog: Copy constructor called" << std::endl;
    return ;
}

Dog &Dog::operator=(Dog const &copy)
{
	if(this == &copy)
		return *this;
	this->_type = copy._type;
    *_brain = *copy._brain;
	std::cout << "Dog: operator= called" << std::endl;
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "Dog: Gav" << std::endl;
}

void    Dog::setIdea(int index, std::string idea)
{
    if (index < 0 || index >= 100)
    {
        std::cout << "That idea cannot be stored there." << std::endl;
        return ;
    }
    else
        _brain->setIdea(index, idea);
    return;
}

std::string Dog::getIdea(int index) const
{
    if (index < 0 || index >= 100)
    {
        std::cout << "No thoughts there." << std::endl;
        return (NULL);
    }
    else
        return (_brain->getIdea(index));
}
