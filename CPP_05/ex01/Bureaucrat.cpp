/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:37:16 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/17 19:17:36 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

#define BUREAUCRAT_EXCEPTION_MSG(OBJ_FORM,OBJ_EXCEPT) CERR << B_RED << this->_name \
             << " couldn't signed " \
             << form.getName() << " because " \
             << e.what() << DEFAULT << ENDL; \

int const Bureaucrat::_max_grade = 1;
int const Bureaucrat::_min_grade = 150;

Bureaucrat::Bureaucrat() : _name("Nameless"), _grade(_min_grade)
{
	COUT << B_YELLOW << "Called default constructor Bureaucrat: " << _name << DEFAULT << ENDL;
	return ;
}

Bureaucrat::Bureaucrat(const std::string name, int range) : _name(name), _grade(range)
{
	std::cout << B_GREEN << "Called parametric constructor Bureaucrat: " << _name << DEFAULT << std::endl;
	try
	{
		if (range < Bureaucrat::_max_grade)
			throw GradeTooHighException();
		else if (range > Bureaucrat::_min_grade)
			throw GradeTooLowException();
		else
			_grade = range;
	}
	catch(GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
		std::cout << "GRADE is set to maximum!" << std::endl;
		_grade = Bureaucrat::_max_grade;
	}
	catch(GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
		std::cout << "GRADE is set to minimum!" << std::endl;
		_grade = Bureaucrat::_min_grade;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return ;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << B_RED << "Called destructor for: " << _name << DEFAULT << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	(*this) = copy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
	if (this == &copy)
		return (*this);
	const_cast<std::string &>(this->_name) = copy._name;
	this->_grade = copy._grade;
	return (*this);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

int	Bureaucrat::getMaxGrade()
{
	return (_max_grade);
}

int	Bureaucrat::getMinGrade()
{
	return (_min_grade);
}

std::string Bureaucrat::getName() const
{
	return (_name);
}

void Bureaucrat::incGrade()
{
	try
	{
		if (_grade == Bureaucrat::_max_grade)
		{
			throw GradeTooHighException();
		}
		else
		{
			_grade--;
		}
	}
	catch(GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}

void Bureaucrat::decGrade()
{
	try
	{
		if (_grade == Bureaucrat::_min_grade)
		{
			throw GradeTooLowException();
		}
		else
		{
			_grade++;
		}
	}
	catch(GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void Bureaucrat::signForm(Form &form)
{
    try
    {
        form.beSigned(*this);
        if (form.getSign() == true)
        {
            COUT << B_GREEN << this->_name << " signed " << form.getName() << DEFAULT << ENDL;
        }
    }
    catch( Form::GradeTooLowException& e)
    {
        BUREAUCRAT_EXCEPTION_MSG(form,e);
    }
    catch ( Form::GradeTooHighException &e)
    {
        BUREAUCRAT_EXCEPTION_MSG(form,e);
    }
    catch ( std::exception &e)
    {
        BUREAUCRAT_EXCEPTION_MSG(form,e);
    }
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("This Bureaucrat is too professional for this job!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("This Bureaucrat is not ready for this job!");
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bur)
{
	out << B_BLUE << bur.getName() << ", bureaucrat grade " << bur.getGrade() << ".";
	return (out);
}
