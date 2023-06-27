/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:53:32 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/26 18:13:48 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{

    private:
        Brain   *_brain;
    
    public:
        Dog( void );
        virtual ~Dog( void );
        Dog(Dog const &copy);
        Dog &operator=(Dog const &copy);

    virtual void            makeSound( void ) const;
    void                    setIdea(int index, std::string idea);
    std::string             getIdea(int index) const;
};

#endif