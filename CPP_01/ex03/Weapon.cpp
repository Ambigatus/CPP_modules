/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 10:42:50 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/01 10:44:57 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string const &type)
{
	_type = type;
}

Weapon::~Weapon()
{
	
}

std::string const &Weapon::getType() const
{
	return _type;
}

void Weapon::setType(std::string const &type)
{
	_type = type;
}
