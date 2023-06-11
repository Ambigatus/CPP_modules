/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:09:49 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/11 18:18:18 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void )
{
	// ClapTrap Bro("BroBot");
	// ClapTrap Furry("FurryBot");
	// int i = 0;
	// while (i < 10)
	// {
	// Bro.attack("FurryBot");
	// Furry.beRepaired(1);
	// i++;
	// } 

	// std::cout << B_GREEN << "-----------------------------------" << DEFAULT << std::endl << std::endl;
	// ScavTrap Yao("Yao Min");
	// ScavTrap Poker("Poker Face");
	// int o = 0;
	// while (o < 10)
	// {
	// Yao.attack("Poker Face");
	// Poker.takeDamage(5);
	// Poker.beRepaired(1);
	// Yao.guardGate();
	// Poker.guardGate();
	// o++;
	// } 

	std::cout << B_GREEN << "-----------------------------------" << DEFAULT << std::endl << std::endl;
	FragTrap Billy("Billy Herrington");
	FragTrap Van("Van Darkholme");
	int p = 0;
	while (p < 10)
	{
		Billy.attack("Van Darkholme");
		Van.takeDamage(2);
		Van.beRepaired(5);
		Van.attack("Billy Herrington");
		Billy.takeDamage(21);
		Billy.beRepaired(3);
		Billy.highFivesGuys();
		Van.highFivesGuys();
		p++;
	}
	return 0;
}