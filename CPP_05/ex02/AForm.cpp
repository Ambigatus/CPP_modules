/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:43:11 by ddzuba            #+#    #+#             */
/*   Updated: 2023/07/25 18:30:48 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Unknown Form"), _sign(false), _gradeExec(150), _gradeSign(150)
{
}

AForm::AForm(std::string name, int gradeSign, int gradeExec)
: _name(name), _sign(false), _gradeExec(gradeExec), _gradeSign(gradeSign)
{
	if (_gradeExec <= 0 || _gradeSign <= 0)
		throw AForm::GradeTooHighExeption();
	if (_gradeExec > 150 || _gradeExec > 150)
		throw AForm::GradeTooLowExeption();
}

AForm::AForm(const AForm &copy) : _name(copy._name), _sign(false), _gradeExec(copy._gradeExec), _gradeSign(copy._gradeSign)
{
	*this = copy;
}

AForm &AForm::operator=(AForm const &copy)
{
	if (this == &copy)
		return *this;
	const_cast<STR &>(this->_name) = copy._name; // need to read more about const_cast
	const_cast<int &>(this->_gradeSign) = copy._gradeSign;
	const_cast<int &>(this->_gradeExec) = copy._gradeExec;
	this->_sign = copy._sign;
	return *this;
}

STR 	AForm::getName() const
{
	return (this->_name);
}

int		AForm::getGradeExec() const
{
	return (this->_gradeExec);
}

int		AForm::getGradeSign() const
{
	return (this->_gradeSign);
}

bool	AForm::getSign() const
{
	return (this->_sign);
}

void	AForm::beSigned(Bureaucrat &bur)
{
	if (bur.getGrade() <= this->_gradeSign)
		{
			if (this->_sign == true)
				throw (B_RED"This Form is already signed by you, maggot!" DEFAULT);
			this->_sign = true;
			COUT << B_GREEN << this->getName() << " Form is succefully signed. Well done, maggot!" << DEFAULT << ENDL;
		}
		else
		{
			throw AForm::GradeTooLowExeption();
		}
}

const char	*AForm::GradeTooHighExeption::what() const throw()
{
	return (B_PURPURE"The Grade of this Form is too high for you, maggot!" DEFAULT);
}

const char *AForm::GradeTooLowExeption::what() const throw()
{
	return (B_TURQUOISE"The Grade of this Form is too low for you, maggot!" DEFAULT);
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
	out << B_YELLOW << "Name of Holy Form: " << form.getName() << "\nSign status: " << form.getSign() << "\nRequirements to Sign: " <<
		form.getGradeSign() << "\nRequirements to Execute: " << form.getGradeExec() << DEFAULT;
	return out;
}
