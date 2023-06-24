/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:10:53 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/24 18:04:56 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{

	private:
    Brain   *_brain;
	
	public:
		WrongCat();
		~WrongCat();
		WrongCat(WrongCat const &copy);
		WrongCat &operator=(WrongCat const &copy);

		// virtual void makeSound() const;
		void makeSound() const;
};

#endif
