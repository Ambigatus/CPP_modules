/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 21:53:28 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/27 11:08:51 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure( void )
{
    _type = "cure";
    // std::cout << "* Cure: materia is created *" << std::endl;
}

Cure::Cure(Cure const &copy) : AMateria(copy)
{
    *this = copy;
    // std::cout << "* Cure: materia is copied *" << std::endl;
}

Cure    &Cure::operator=( const Cure &copy ) 
{
    if (this != &copy)
    {
        this->_type = copy._type;
    }
    return *this;
}

Cure::~Cure()
{
    // std::cout << "* Ice: cure is destroyed *" << std::endl;
}

AMateria *Cure::clone() const
{
    AMateria *clone;

    clone = new Cure(*this);
    return (clone);
}

void    Cure::use( ICharacter& target )
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
