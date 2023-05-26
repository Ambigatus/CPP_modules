/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:28:30 by ddzuba            #+#    #+#             */
/*   Updated: 2023/05/26 19:15:30 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/* This is the implementation of the default constructor Zombie::Zombie(). 
* Inside this constructor, _name is set to the value "Foo," and then the
* announce() method is called. */
Zombie::Zombie()
{

}

/* This is the implementation of the destructor Zombie::~Zombie(). Inside the
* destructor, a message is printed using the zombie's name _name, indicating
* that the zombie was destroyed.  */
Zombie::~Zombie()
{
	std::cout << _name << " was destroyed." << std::endl;
}

/* This is the implementation of the method Zombie::announce(). Inside this method,
* a message is printed using the zombie's name _name, indicating the zombie and its
* characteristics. In this case, the message "<name>: BraiiiiiiinnnzzzZ..."
* will be printed.*/
void Zombie::announce( void )
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
	_name = name;
}
