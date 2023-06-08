/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:42:34 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/07 17:37:00 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# define DEFAULT "\033[0;39m"
# define B_RED "\033[1;31m"
# define B_BLUE "\033[1;94m"
# define B_YELLOW "\033[1;33m"
# define B_GREEN "\033[1;32m"
# define B_PINK "\033[1;35m"

#include <iostream>
#include <string.h>

class ClapTrap
{
	private:
		std::string	_name;
		int			_health;
		int			_energy;
		int			_attack;

	public:
		ClapTrap();
		ClapTrap(std::string name); //constructor
		~ClapTrap(); //deconstructor
		ClapTrap(ClapTrap const &copy); //copy constructor
		ClapTrap &operator=(ClapTrap const &copy); //assignment operator overload(read more about it)

	void attack(const std::string& target);
	void takeDamage(unsigned int ammount);
	void beRepaired(unsigned int ammount);	
};

#endif

/* The assignment operator overload is a special member function in C++ that allows objects
 of a class to be assigned the values of another object of the same class. It is often referred
 to as the copy assignment operator.

In the code you provided, the assignment operator overload is declared as follows:


ClapTrap &operator=(ClapTrap const &copy);

The operator= is the assignment operator, and it is overloaded for the ClapTrap class.
The ClapTrap const &copy parameter represents a constant reference to another ClapTrap object 
from which values will be copied.

When you assign one object of the ClapTrap class to another object using the assignment operator
(=), the assignment operator overload is called to perform the assignment. It allows you to copy 
the values of the member variables from the source object (the object on the right-hand side of 
the assignment) to the target object (the object on the left-hand side of the assignment).

The assignment operator overload typically performs a member-wise assignment, where each member 
variable of the source object is copied to the corresponding member variable of the target object. 
It ensures that both objects end up with the same values for their member variables.

For example, given two ClapTrap objects claptrap1 and claptrap2, you can assign the values of 
claptrap1 to claptrap2 using the assignment operator overload as follows:


claptrap2 = claptrap1;

After this assignment, claptrap2 will have the same values for its member variables as claptrap1.

It's important to note that if the assignment operator overload is not explicitly defined for a 
class, the compiler generates a default assignment operator, which performs a member-wise assignment. 
However, if the class contains dynamically allocated resources or non-pointer members with complex 
behaviors, a custom assignment operator overload may need to be implemented to ensure proper copying 
and handling of the resources.  */