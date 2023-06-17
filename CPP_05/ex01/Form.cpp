/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 16:48:22 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/17 19:14:57 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* Initialize min and max grade for the Bureaucrat */
int const	Form::_minGrade = Bureaucrat::getMinGrade();
int const	Form::_maxGrade = Bureaucrat::getMaxGrade();

Form::Form()
: _name("Default"), _sign(false), _gradeSign(20), _gradeExec(5)
{
	COUT << B_YELLOW << "Called default constructor Form: " << _name << DEFAULT << ENDL;
}

Form::Form(std::string const name, int const signGrade, int const execGrade)
: _name(name), _sign(false), _gradeSign(signGrade), _gradeExec(execGrade)
{
	COUT << B_YELLOW << "Called parametric constructor " << _name << DEFAULT << ENDL;
}

Form::Form(Form const &copy)
: _name(copy._name), _sign(copy._sign), _gradeSign(copy._gradeSign), _gradeExec(copy._gradeExec)
{
	*this = copy;
	COUT << B_GREEN << "Called copy constructor Form " << _name << DEFAULT << ENDL;
}

Form &Form::operator=(Form const &copy)
{
	this->_sign = copy._sign;
	COUT << B_BLUE << "Called copy assignment constructor Form " << _name << DEFAULT << ENDL;
	return (*this);
}

Form::~Form()
{
	COUT << B_RED << "Called destructor Form " << _name << DEFAULT << ENDL;
	return ;
}

std::string const	Form::getName() const
{
	return (_name);
}

bool	Form::getSign() const
{
	return (_sign);
}

int	Form::getGradeSign() const
{
	return (_gradeSign);
}

int	Form::getGradeExec() const
{
	return (_gradeExec);
}

/****************************************************************************************/

void	Form::beSigned(Bureaucrat &bur)
{
	if (bur.getGrade() < _gradeSign)
	{
		throw GradeTooHighException();
	}
	else if (bur.getGrade() > _gradeSign)
	{
		throw GradeTooLowException();
	}
	else if (bur.getGrade() <= _gradeSign && bur.getGrade() > _gradeExec)
	{
		_sign = true;
	}
}

char const	*Form::GradeTooHighException::what() const throw()
{
	return ("This Bureaucrat is too professional for this kind of job!");
}

char const	*Form::GradeTooLowException::what() const throw()
{
	return ("This Bureaucrat have no idea, what he need to do with this job!");
}

/****************************************************************************************/

std::ostream &operator<<(std::ostream &out, Form const &form)
{
	out << B_TURQUOISE << "FORM NAME: " << form.getName() << DEFAULT << ENDL
		<< B_PURPURE << "SIGN GRADE: " << form.getGradeSign() << DEFAULT << ENDL
		<< B_PINK << "EXEC GRADE: " << form.getGradeExec() << DEFAULT << ENDL
		<< B_BLUE << "SIGN STATE: " << form.getSign() << DEFAULT << ENDL;
	return (out);
}
