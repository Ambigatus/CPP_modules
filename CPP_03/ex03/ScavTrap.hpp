/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 10:38:50 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/11 19:34:49 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# define DEFAULT "\033[0;39m"
# define B_RED "\033[1;31m"
# define B_BLUE "\033[1;94m"
# define B_YELLOW "\033[1;33m"
# define B_GREEN "\033[1;32m"
# define B_PINK "\033[1;35m"

#include <iostream>
#include <string.h>
#include "ClapTrap.hpp"
#include <unistd.h>

class ScavTrap: virtual public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		~ScavTrap();
		ScavTrap(ScavTrap const &copy);
		ScavTrap &operator=(ScavTrap const &copy);

		void guardGate();
		void attack(const std::string& target);
};

#endif