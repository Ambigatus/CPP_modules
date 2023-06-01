/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 10:33:49 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/01 10:36:52 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include <string.h>
#include "Weapon.hpp"

class HumanB
{
		private:
			HumanB();
			std::string _name;
			Weapon *_weapon;

		public:
			HumanB(std::string const &name);
			~HumanB();

		void attack();
			void setWeapon(Weapon &weapon);

};

#endif
