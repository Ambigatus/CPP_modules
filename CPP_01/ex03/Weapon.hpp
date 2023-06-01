/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 10:40:12 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/01 10:49:43 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string.h>

class Weapon
{
		private:
			Weapon();
			std::string _type;
			
		public:
			Weapon(std::string const &type);
			~Weapon();

		std::string const &getType() const;
		void setType(std::string const &type);

};

#endif