/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:11:45 by ddzuba            #+#    #+#             */
/*   Updated: 2023/07/31 11:35:50 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(STR target) :
AForm("Presidential Form", 25, 5), _target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) :
AForm(copy), _target(copy._target)
{
	*this = copy;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	if (this == &copy)
		return *this;
	AForm::operator=(copy);
	return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() <= this->getGradeExec() && this->getSign() == true)
		COUT << B_BLUE << "<" << this->_target 
		<< "> has been pardoned by Zafod Beeblebrox." << DEFAULT << ENDL;
	else if (!(this->getSign()))
		throw (B_RED"The Holy Form was not signed!" DEFAULT);
	else
		throw Bureaucrat::GradeTooLowException();
}
