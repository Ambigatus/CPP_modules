/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:09:49 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/11 17:57:12 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void )
{
	// ClapTrap Bro("BroBot");
	// ClapTrap Furry("FurryBot");
	// int i = 0;
	// while (i < 10)
	// {
	// Bro.attack("FurryBot");
	// Furry.takeDamage(5);
	// Furry.beRepaired(1);
	// i++;
	// } 

	std::cout << B_GREEN << "-----------------------------------" << DEFAULT << std::endl << std::endl;
	ScavTrap Yao("Yao Min");
	ScavTrap Poker("Poker Face");
	int o = 0;
	while (o < 10)
	{
	Yao.attack("Poker Face");
	Poker.takeDamage(23);
	Poker.beRepaired(10);
	Yao.guardGate();
	Poker.guardGate();
	o++;
	} 

	return 0;
}