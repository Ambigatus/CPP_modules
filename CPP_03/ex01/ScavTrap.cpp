/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 10:38:26 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/27 21:13:03 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap()
{
	_name = "Nameless";
	_health = 100;
	_energy = 50;
	_attack = 20;
	std::cout << "A nameless ScavTrap has been assembled." << std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_name = name;
	_health = 100;
	_energy = 50;
	_attack = 20;
	std::cout << "Called ScavTrap constructor" << std::endl << std::endl;
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

void ScavTrap::attack(const std::string &target)
{
	if (_health <= 0)
	{
		return;
	}
	if (_energy > 0)
	{
		_energy--;
		std::cout << "⚔️ Mechanical Warrior 🤖" << _name << " strikes " << target << ", dealing " << _attack
				  << " points of chemical damage!💥" << std::endl;
		std::cout << "🤖" << _name << " has only " << _energy << " ⚡energy left" << std::endl
				  << std::endl;
		if (_energy < 4)
			std::cout << B_RED << "⚠️WARNING! " << DEFAULT << _name << " has only " << _energy
					  << " energy left!" << std::endl
					  << std::endl;
		if (_energy == 0)
		{
			std::cout << "⛔ No energy points. Turning off..." << std::endl
				  << std::endl;
			return ;
		}
	}
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