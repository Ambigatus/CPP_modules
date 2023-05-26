/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 19:07:21 by ddzuba            #+#    #+#             */
/*   Updated: 2023/05/26 19:16:24 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde( int N, std::string name )
{
	Zombie *arr = new Zombie[N];
	
	for (int i = 0; i < N; i++)
	{
		arr[i].setName(name);
		arr[i].announce();
	}
	
	return arr;
}
