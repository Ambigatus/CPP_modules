/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:09:49 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/07 16:57:26 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main( void )
{
	ClapTrap Bro("BroBot");
	ClapTrap Furry("FurryBot");
	int i = 0;
	while (i < 10)
	{
	Bro.attack("FurryBot");
	Furry.takeDamage(0);
	Furry.beRepaired(1);
	i++;
	} 
	return 0;
}