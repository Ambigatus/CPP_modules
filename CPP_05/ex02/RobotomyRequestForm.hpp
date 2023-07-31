/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:22:27 by ddzuba            #+#    #+#             */
/*   Updated: 2023/07/31 11:25:24 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP_ROBOTOMYREQUESTFORM_HPP
# define CPP_ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		STR _target;
		RobotomyRequestForm();

	public:
		RobotomyRequestForm(STR target);
		~RobotomyRequestForm(){};
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);

	void execute(Bureaucrat const &executor) const;
};

#endif