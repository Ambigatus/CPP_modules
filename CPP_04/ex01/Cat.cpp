/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:35:10 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/26 18:47:55 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal()
{
	_type = "type Cat";
	std::cout << "Cat: Default constructor called" << std::endl;
    _brain = new Brain();
    return ;
}

Cat::~Cat()
{
    delete _brain;
	std::cout << "Cat: Destructor called" << std::endl;
    return ;
}

Cat::Cat(Cat const &copy): Animal(copy) 
{
    _brain = new Brain();
	*this = copy;
	std::cout << "Cat: Copy constructor called" << std::endl;
    return ;
}

Cat &Cat::operator=(Cat const &copy)
{
	std::cout << "Cat: operator= called" << std::endl;
	if(this == &copy)
		return *this;
	this->_type = copy._type;
    *_brain = *copy._brain;
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << "Cat: Meow" << std::endl;
    return ;
}

void    Cat::setIdea(int index, std::string idea)
{
    if (index < 0 || index >= 100)
    {
        std::cout << "That idea cannot be stored there." << std::endl;
        return ;
    }
    else
        _brain->setIdea(index, idea);
    return ;
}

std::string Cat::getIdea(int index) const
{
    if (index < 0 || index >= 100)
    {
        std::cout << "No thoughts there." << std::endl;
        return (NULL);
    }
    else
        return (_brain->getIdea(index));
}