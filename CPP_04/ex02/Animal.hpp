/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:27:22 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/27 20:39:07 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

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
		Animal(Animal const &copy);
		Animal &operator=(Animal const &copy);
		virtual ~Animal();

		// The virtual keyword indicates that this function can be overridden in derived classes
		virtual void makeSound() const = 0;
		std::string getType() const;
};

#endif