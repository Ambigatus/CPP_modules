/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:25:35 by ddzuba            #+#    #+#             */
/*   Updated: 2023/07/31 11:35:34 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(STR target) :
AForm("Robotomy Form", 72, 45), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) :
AForm(copy), _target(copy._target)
{
	*this = copy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	if (this == &copy)
		return *this;
	AForm::operator=(copy);
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() <= this->getGradeExec() && this->getSign() == true)
	{
		COUT << B_GREEN << "....Bzzzzz....Phhhzzzzzz....Bbrrrrzzzzz....." << DEFAULT << ENDL;
		COUT << B_BLUE << "<" << this->_target << "> has been robotimized successfully 50% of the time." <<
		DEFAULT << ENDL;
	}
	else if (!(this->getSign()))
		throw (B_RED"The Holy Form was not signed!" DEFAULT);
	else
		throw Bureaucrat::GradeTooLowException();
}
