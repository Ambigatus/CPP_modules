/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:42:30 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/08 10:59:07 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Called default constructor" << std::endl << std::endl;
	_name = "name";
	_health = 10;
	_energy = 10;
	_attack = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Called ClapTrap constructor" << std::endl << std::endl;
	_name = name;
	_health = 10;
	_energy = 10;
	_attack = 0;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Called destructor" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &copy)
{
	*this = copy;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &copy)
{
	if (this == &copy)
		return *this;
	this->_name = copy._name;
	this->_health = copy._health;
	this->_energy = copy._energy;
	this->_attack = copy._attack;
	return *this;
}

void ClapTrap::attack(const std::string &target)
{
	if (_health <= 0)
	{
		return;
	}
	_energy--;
	if (_energy)
	{
		std::cout << "⚔️ ClapTrap " << _name << " attacks " << target << ", causing " << _attack
				  << " points of physical damage!💥" << std::endl;
		std::cout << "🤖" << _name << " has only " << _energy << " ⚡energy left" << std::endl
				  << std::endl;
		if (_energy < 4)
			std::cout << B_RED << "⚠️WARNING! " << DEFAULT << _name << " has only " << _energy
					  << " energy left!" << std::endl
					  << std::endl;
		sleep(1);
	}
	else
		std::cout << "⛔ No energy points. Turning off..." << std::endl
				  << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_health <= 0)
	{
		std::cout << "ClapTrap 🤖" << _name << " laying dead on the floor 💀" << std::endl << std::endl;
		return;
	}
	_health -= amount;
	if (_health > 0)
	{
		std::cout << "🛡️ ClapTrap 🤖 " << _name << " take emotional damage 💥 " << amount << ", current health is "
			  << _health << " ❤️ " << std::endl << std::endl;
		if (_health < 4)
			std::cout << B_RED << "⚠️WARNING! " << DEFAULT << _name << " has only " << _health
					  << " hitpoints left!" << std::endl
					  << std::endl;
		sleep(1);
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_health <= 0)
	{
		std::cout << "🤖Bot " << _name << " was destroyed!" << std::endl << std::endl;
		return;
	}
	_energy--;
	_health += amount;
	if (_energy)
	{
		std::cout << "🛠️ ClapTrap " << _name << " repair himself by " << amount
				  << " hit points, current health is " << _health << " ❤️ " << std::endl;
		std::cout << "🤖" << _name << " has only " << _energy << " ⚡energy left" << std::endl
				  << std::endl;
		if (_energy < 4)
			std::cout << B_RED << "⚠️WARNING! " << DEFAULT << _name << " has only " << _energy
					  << " energy left!" << std::endl
					  << std::endl;
		sleep(1);
	}
	else
		std::cout << "⛔ No energy points. Turning off..." << std::endl
				  << std::endl;
		return;
}
