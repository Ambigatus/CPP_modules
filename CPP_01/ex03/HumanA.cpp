/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:24:54 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/01 10:47:19 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string const &name, Weapon &weapon)
{
		_name = name;
		_weapon = &weapon;
}

HumanA::~HumanA()
{
	
}

void HumanA::attack()
{
	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}
