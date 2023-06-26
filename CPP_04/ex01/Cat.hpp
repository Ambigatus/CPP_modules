/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 21:26:11 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/26 18:18:13 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{

	private:
    	Brain   *_brain;
	
	public:
		Cat();
		Cat(Cat const &copy);
		Cat &operator=(Cat const &copy);
		virtual ~Cat();

		// virtual void makeSound() const;
		virtual void 			makeSound() const;
		void            		setIdea(int index, std::string idea);
    	std::string     		getIdea(int index) const;
};

#endif
