/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:37:18 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/17 18:49:07 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "Utils.hpp"
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		std::string const	_name;
		int					_grade;
		static int const	_max_grade;
		static int const	_min_grade;
	
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int range);
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat &operator=(const Bureaucrat &copy);
		~Bureaucrat();

		std::string		getName() const;
		int				getGrade() const;
		void			incGrade();
		void			decGrade();
		static int		getMaxGrade();
		static int		getMinGrade();
		void			signForm(Form &form);

		class GradeTooHighException : public std::exception
		{
			public:
				GradeTooHighException(){};
				virtual ~GradeTooHighException() throw(){};

				virtual const char* what() const throw();
		};
		
		class GradeTooLowException : public std::exception
		{
			public:
				GradeTooLowException(){};
				virtual ~GradeTooLowException() throw(){};

				virtual const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bur);

#endif

/* Bureaucrat(){};: This is a private default constructor of the Bureaucrat class.
It is defined with empty curly braces {}. Since it is marked as private, it cannot 
be accessed from outside the class. This effectively makes the default constructor 
inaccessible to create instances of Bureaucrat directly.

The purpose of making the default constructor private in this case is to prevent 
the creation of Bureaucrat objects without providing valid values for the member 
variables. It ensures that an instance of Bureaucrat can only be created with a 
valid name and grade by using a different constructor or factory method, if provided. */