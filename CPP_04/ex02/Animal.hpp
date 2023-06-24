/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:27:22 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/24 20:37:16 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"

class Animal
{
	protected:
		std::string _type;

	public:
		Animal();
		// The virtual keyword indicates that the destructor can be overridden
		//  in derived classes. This is important when working with inheritance, 
		//  as it allows the correct destructor
		//  to be called when deleting an object through a pointer to the base class.
		virtual ~Animal();
		Animal(Animal const &copy);
		Animal &operator=(Animal const &copy);

		// The virtual keyword indicates that this function can be overridden in derived classes
		//Here the sequence = 0 is known as pure-specifier, and appears either immediately after 
		// the declarator or after the optional virt-specifier (override or final).
		// pure-specifier cannot appear in a member function definition or friend declaration.
		virtual void    makeSound( void ) const = 0;
		std::string getType() const;
};

#endif