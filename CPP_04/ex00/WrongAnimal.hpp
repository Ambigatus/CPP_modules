/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:07:42 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/24 17:24:21 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
	protected:
		std::string _type;

	public:
		WrongAnimal();
		// The virtual keyword indicates that the destructor can be overridden
		//  in derived classes. This is important when working with inheritance, 
		//  as it allows the correct destructor
		//  to be called when deleting an object through a pointer to the base class.
		virtual ~WrongAnimal();
		WrongAnimal(WrongAnimal const &copy);
		WrongAnimal &operator=(WrongAnimal const &copy);

		// The virtual keyword indicates that this function can be overridden in derived classes
		virtual void makeSound() const;
		std::string getType() const;
};

#endif