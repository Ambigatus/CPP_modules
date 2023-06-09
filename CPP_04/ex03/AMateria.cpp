/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 21:05:51 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/27 10:33:47 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"


AMateria::AMateria( void ) : _type("Nothing")
{
    // std::cout << "* AMateria: materia is created *" << std::endl;
}

AMateria::AMateria( std::string const & type )  : _type(type)
{
    // std::cout << "AMateria " << this->_type << " created" << std::endl;
}

AMateria::AMateria( AMateria const & src )
{
    *this = src;
}

AMateria::~AMateria( void )
{
    // std::cout << "AMateria " << this->_type << " destroyed" << std::endl;
}

std::string const &AMateria::getType() const
{
    return this->_type;
}

AMateria &AMateria::operator=(AMateria const &copy)
{
    _type = copy._type;
    return (*this);
}

AMateria* AMateria::clone() const
{
    return (AMateria*)this;
}

void    AMateria::use( ICharacter &target )
{
    std::cout << "Nothing was used against " << target.getName()
        << ". As expected, without result." << std::endl;
}
