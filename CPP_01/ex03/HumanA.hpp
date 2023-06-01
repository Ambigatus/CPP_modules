/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:25:10 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/01 10:32:38 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include <string.h>
#include "Weapon.hpp"

class HumanA
{
		private:
			HumanA();
			std::string _name;
			Weapon *_weapon;
		public:
			HumanA(std::string const &name, Weapon &weapon);
			~HumanA();

		void attack();
};

#endif
