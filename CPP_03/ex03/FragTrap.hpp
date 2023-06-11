/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:41:39 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/11 19:34:04 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include <string.h>
#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
	public:
		FragTrap(); // constructor
		FragTrap(std::string name); // name setting
		~FragTrap(); //deconstructor
		FragTrap(FragTrap const &copy); //copy constructor
		FragTrap &operator=(FragTrap const &copy); //assignment operator overload

		void highFivesGuys(void);
};

#endif