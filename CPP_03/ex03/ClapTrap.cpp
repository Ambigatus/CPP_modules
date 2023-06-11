/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:42:30 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/11 19:32:41 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Called default constructor" << std::endl << std::endl;
	_name = "DEFAULT";
	_health = 10;
	_energy = 10;
	_attack = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	_name = name;
	_health = 10;
	_energy = 10;
	_attack = 0;
	std::cout << "Called ClapTrap constructor for " << _name << std::endl << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Called ClapTrap " << _name << " destructor" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &copy)
{
	*this = copy;
	std::cout << "New ClapTrap " << _name << " assembled according to plans" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &copy)
{
	if (this == &copy)
		return *this;
	this->_name = copy._name;
	this->_health = copy._health;
	this->_energy = copy._energy;
	this->_attack = copy._attack;
	std::cout << "Transfer data to ClapTrap completed" << std::endl;
	return *this;
}

void ClapTrap::attack(const std::string &target)
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

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_health <= 0)
	{
		std::cout << "Mechanical Warrior 🤖" << _name << " laying dead on the floor 💀" << std::endl;
		std::cout << B_RED << "STOP HITTING THE DEAD BODY!" << DEFAULT << std::endl;
		return ;
	if (_health < 4)
			std::cout << B_RED << "⚠️WARNING! " << DEFAULT << _name << " has only " << _health
					  << " hitpoints left!" << std::endl
					  << std::endl;
	}
	if (_health > 0)
	{
		_health -= amount;
		std::cout << "🛡️ Mechanical Warrior 🤖 " << _name << " take emotional damage 💥 " << amount << ", current health is "
			  << _health << " ❤️ " << std::endl << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_health <= 0)
	{
		std::cout << B_BLUE << "🤖Mechanical Warrior " << _name << " was destroyed!" << DEFAULT << std::endl << std::endl;
		return ;
	}
	if (_energy >= 0)
	{
		_energy--;
		_health += amount;
		std::cout << "🛠️ Mechanical Warrior " << _name << " repair himself by " << amount
				  << " hit points, current health is " << _health << " ❤️ " << std::endl;
		std::cout << "🤖" << _name << " has only " << _energy << " ⚡energy left" << std::endl
				  << std::endl;
		if (_energy < 4)
			std::cout << B_RED << "⚠️WARNING! " << DEFAULT << _name << " has only " << _energy
					  << " energy left!" << std::endl
					  << std::endl;
	}
	else
	{
		std::cout << "⛔ No energy points. Turning off..." << std::endl
				  << std::endl;
		return;	
	}
}