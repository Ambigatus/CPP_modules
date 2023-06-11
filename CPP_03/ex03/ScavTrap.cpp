/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 10:38:26 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/11 19:14:40 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	_name = "ScavTrap";
	_health = 100;
	_energy = 50;
	_attack = 20;
}

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
	std::cout << "Called ScavTrap destructor" << std::endl;
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
	std::cout << B_YELLOW << "🤖 ScavTrap Bot " << _name << " going into Gate Keeper mode."
		<< DEFAULT << std::endl << std::endl;
	sleep(1);
}

void ScavTrap::attack(const std::string& target)
{
	if (_health <= 0)
	{
		return ;
	}
	if (_energy > 0)
	{
		_energy--;
		std::cout << B_PINK << "######################### NEW ROUND STARTED #########################" << DEFAULT 
			<< std::endl << std::endl;
		std::cout << "⚔️ Mechanical Warrior 🤖" << _name << " attacks " << target 
			<< ", causing " << _attack << " points of physical damage!💥" << std::endl;
		std::cout << B_YELLOW << "🔰 Holly Molly, all physical damage was absorbed"
			<< " by the energy shield!" << DEFAULT << std::endl;
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