/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 18:31:46 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/11 19:31:59 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name)
{
	_name = name;
	ClapTrap::_name = _name + "_clap_name";
	_health = FragTrap::_health;
	_energy = ScavTrap::_energy;
	_attack = FragTrap::_attack;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Called DiamondTrap " << _name << " destructor" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &copy)
{
	*this = copy;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &copy)
{
	if (this == &copy)
		return *this;
	this->_name = copy._name;
	this->_health = copy._health;
	this->_energy = copy._energy;
	this->_attack = copy._attack;
	return *this;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << B_GREEN << _name << " shouts: I am not who I say I am! In fact, my name is " 
		<< ClapTrap::_name << DEFAULT << std::endl;
	return ;
}
