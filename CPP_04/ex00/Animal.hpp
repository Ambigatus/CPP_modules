/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:27:22 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/12 15:44:12 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

# define DEFAULT "\033[0;39m"
# define B_RED "\033[1;31m"
# define B_BLUE "\033[1;94m"
# define B_YELLOW "\033[1;33m"
# define B_GREEN "\033[1;32m"
# define B_PINK "\033[1;35m"
# define B_PURPURE "\033[1;35m"
# define B_TURQUOISE "\033[36;1m"

class Animal
{
	protected:
		std::string _type;

	public:
		Animal();
		virtual ~Animal();
		Animal(Animal const &copy);
		Animal &operator=(Animal const &copy);

		virtual void makeSound() const;
		std::string getType() const;
};

#endif