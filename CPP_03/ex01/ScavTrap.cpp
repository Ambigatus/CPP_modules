/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 10:38:26 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/11 17:55:03 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "Called ScavTrap constructor" << std::endl << std::endl;
	_name = name;
	_health = 100;
	_energy = 50;
	_attack = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Called ScavTrap " << _name << " destructor" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &copy)
{
	*this = copy;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &copy)
{
	if (this == &copy)
		return *this;
	this->_name = copy._name;
	this->_health = copy._health;
	this->_energy = copy._energy;
	this->_attack = copy._attack;
	return *this;
}

void	ScavTrap::guardGate()
{
	if (_health > 0)
	{
	std::cout << B_YELLOW << "🤖 ScavTrap Bot " << _name << " going into Gate Keeper mode."
		<< DEFAULT << std::endl << std::endl;
	sleep(1);
	}
}