/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:57:52 by ddzuba            #+#    #+#             */
/*   Updated: 2023/05/26 18:31:30 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string.h>

class Zombie
{
	private:
			std::string _name;

	public:
			Zombie();
			Zombie(std::string name);
			~Zombie();
			
			void announce( void );
};

Zombie* newZombie( std::string name );
void	randomChump( std::string name );

#endif