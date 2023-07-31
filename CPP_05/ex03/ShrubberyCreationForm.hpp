/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:36:13 by ddzuba            #+#    #+#             */
/*   Updated: 2023/07/31 11:45:45 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP_SHRUBBERYCREATIONFORM_HPP
# define CPP_SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		STR _target;
		ShrubberyCreationForm();

	public:
		ShrubberyCreationForm(STR target);
		~ShrubberyCreationForm(){};
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);

	void execute(Bureaucrat const &executor) const;
};

#endif
