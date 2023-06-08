/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:09:49 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/07 18:22:51 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main( void )
{
	ClapTrap();
	ClapTrap Bro("BroBot");
	ClapTrap Furry("FurryBot");
	int i = 0;
	while (i < 10)
	{
	Bro.attack("FurryBot");
	Furry.takeDamage(5);
	Furry.beRepaired(1);
	i++;
	} 
	return 0;
}