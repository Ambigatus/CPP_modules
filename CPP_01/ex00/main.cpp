/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:45:42 by ddzuba            #+#    #+#             */
/*   Updated: 2023/05/26 18:47:31 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie zombie1;

	randomChump( "Georgiy" );

	Zombie *zombie2;
	zombie2 = newZombie( "Yurii" );
	delete zombie2;

	return 0;
}
