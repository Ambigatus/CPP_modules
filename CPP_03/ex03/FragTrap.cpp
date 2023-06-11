/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:41:36 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/11 19:14:19 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	_name = "FragTrap";
	_health = 100;
	_energy = 100;
	_attack = 30;
}

FragTrap::FragTrap(std::string name)
{
	std::cout << "Called FragTrap constructor" << std::endl << std::endl;
	_name = name;
	_health = 100;
	_energy = 100;
	_attack = 100;
}

FragTrap::~FragTrap()
{
	std::cout << "Called FragTrap " << _name << " destructor" << std::endl;
}

FragTrap::FragTrap(FragTrap const &copy)
{
	*this = copy;
}

FragTrap &FragTrap::operator=(FragTrap const &copy)
{
	if (this == &copy)
		return *this;
	this->_name = copy._name;
	this->_health = copy._health;
	this->_energy = copy._energy;
	this->_attack = copy._attack;
	return *this;
}

void FragTrap::highFivesGuys()
{
	if (_health > 0)
		std::cout << _name << " screaming: " << B_PINK << "High Fives, guys!!!" << DEFAULT << std::endl << std::endl; 
}
