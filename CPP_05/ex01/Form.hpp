/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 16:31:54 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/17 19:15:49 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string	const	_name;
		bool				_sign;
		int	const			_gradeSign;
		int	const			_gradeExec;
		static int	const	_minGrade;
		static int	const	_maxGrade;

	public:
		Form();
		Form(std::string name, int const gradeSign, int const gradeExec);
		Form(const Form &copy);
		Form  &operator=(Form const &copy);
		~Form();

		std::string const	getName() const;
		int					getGradeExec() const;
		int					getGradeSign() const;
		bool				getSign() const;
		void				beSigned(Bureaucrat &bur);
		
		class GradeTooHighException : public std::exception
		{
			public:				
				virtual const char *what() const throw();
		};
		
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &out, const Form &form);

#endif