/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:57:27 by ddzuba            #+#    #+#             */
/*   Updated: 2023/07/31 14:02:12 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP_INTERN_HPP
# define CPP_INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "Utils.hpp"

class Intern
{
	private:
		STR		arrForm[3];
		AForm	*(Intern::*func[3])(STR target);

		AForm	*newShrubbery(STR target);
		AForm	*newRobotomy(STR target);
		AForm	*newPresidential(STR target);

	public:
		Intern();
		~Intern();

		AForm	*makeForm(STR name, STR target);
};

#endif
