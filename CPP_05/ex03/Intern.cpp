/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:02:26 by ddzuba            #+#    #+#             */
/*   Updated: 2023/07/31 14:26:45 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	this->arrForm[0] = "shrubbery creation";
	this->arrForm[1] = "robotomy request";
	this->arrForm[2] = "presidential pardon";

	this->func[0] = &Intern::newShrubbery;
	this->func[1] = &Intern::newRobotomy;
	this->func[2] = &Intern::newPresidential;
}

Intern::~Intern(){}

AForm *Intern::newPresidential(STR target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::newRobotomy(STR target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::newShrubbery(STR target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeForm(STR name, STR target)
{
	for (int i = 0; i < 3; i++)
	{
		if (name == this->arrForm[i])
		{
			COUT << B_PINK << "Intern creates Holy <" << name << ">" << DEFAULT << ENDL;
			return ((this->*func[i])(target));
		}
	}
	COUT << B_RED << "Intern cannot create Holy Form" << DEFAULT << ENDL;
	return (NULL);
}
