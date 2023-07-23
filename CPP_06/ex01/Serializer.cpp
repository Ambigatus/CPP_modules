/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 12:53:01 by hboichuk          #+#    #+#             */
/*   Updated: 2023/07/23 13:21:23 by hboichuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() 
{
	std::cout << "Serializer: Default constructor called" << std::endl;
}

Serializer::Serializer(Serializer const &src) {
	std::cout << "Serializer: Default copy constructor called" << std::endl;
    (void)src;
    *this = src;
}

Serializer &Serializer::operator=(Serializer const &src) 
{
	std::cout << "Serializer: operator= called" << std::endl;
    (void)src;
    return (*this);
}

Serializer::~Serializer() 
{
	std::cout << "Serializer: Destructor called" << std::endl;
}

//methods
//shortly about reinterpret_cast operator -
// https://www.geeksforgeeks.org/reinterpret_cast-in-c-type-casting-operators/
uintptr_t   Serializer::serialize(Data *ptr) {
    uintptr_t   address = reinterpret_cast<uintptr_t>(ptr);
    return (address);
}

Data        *Serializer::deserialize(uintptr_t raw) {
    Data *tmp = reinterpret_cast<Data *>(raw);
    return (tmp);
}
