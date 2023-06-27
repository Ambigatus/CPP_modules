/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 21:53:47 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/27 11:15:18 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
    _type = "ice";
    // std::cout << "* Ice: materia is created *" << std::endl;
}

Ice::Ice( Ice const & src ) : AMateria(src)
{
    *this = src;
    // std::cout << "* Ice: materia is copied *" << std::endl;
}

Ice     &Ice::operator=( const Ice& rhs ) 
{
    if (this != &rhs)
    {
        this->_type = rhs._type;
    }
    return *this;
}

Ice::~Ice()
{
    // std::cout << "* Ice: ice is destroyed *" << std::endl;
}

AMateria    *Ice::clone() const
{
    AMateria    *clone;

    clone = new Ice(*this);
    return (clone);
}

void    Ice::use( ICharacter &target )
{
    std::cout << " * shoots an ice bolt at " << target.getName() << std::endl;
}
