/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:12:26 by ddzuba            #+#    #+#             */
/*   Updated: 2023/07/25 18:10:22 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"


class AForm
{
	private:
		STR const		_name;
		bool			_sign;
		int const		_gradeExec;
		int const		_gradeSign;

	public:
		AForm();
		AForm(STR const name, int gradeSign, int gradeExec);
		AForm(AForm const &copy);
		AForm &operator=(AForm const &copy);
		virtual		~AForm();

		STR				getName() const;
		bool			getSign() const;
		int				getGradeExec() const;
		int				getGradeSign() const;
		
		void			beSigned(Bureaucrat &bur);
		virtual void	execute(Bureaucrat const &executor) const = 0;
		
		class GradeTooHighExeption : public std::exception
		{
			public:
				GradeTooHighExeption();
				virtual ~GradeTooHighExeption() throw ();
				
				virtual const char *what() const throw();
		};
		
		class GradeTooLowExeption : public std::exception
		{
			public:
				GradeTooLowExeption();
				virtual ~GradeTooLowExeption() throw();

				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const AForm &aform);

#endif