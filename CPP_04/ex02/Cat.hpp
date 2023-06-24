/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 21:26:11 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/24 18:03:38 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat: public Animal
{

	private:
    Brain   *_brain;
	
	public:
		Cat();
		~Cat();
		Cat(Cat const &copy);
		Cat &operator=(Cat const &copy);

		// virtual void makeSound() const;
		void makeSound() const;
};

#endif
