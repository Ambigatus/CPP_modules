/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:39:56 by ddzuba            #+#    #+#             */
/*   Updated: 2023/07/31 11:51:02 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(STR target) :
AForm("Shrubbery Form", 145, 137), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) :
AForm(copy), _target(copy._target)
{
	*this = copy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	if (this == &copy)
		return *this;
	AForm::operator=(copy);
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	std::ofstream	output;
	STR				filename;
	STR				buf;

	if (executor.getGrade() <= this->getGradeExec() && this->getSign() == true)
	{
		buf = "\n"
		"           *             ,\n"
		"                       _/^\\_\n"
		"                      <     >\n"
		"     *                 /.-.\\         *\n"
		"              *        `/&\\`                   *\n"
		"                      ,@.*;@,\n"
		"                     /_o.I %_\\    *\n"
		"        *           (`'--:o(_@;\n"
		"                   /`;--.,__ `')             *\n"
		"                  ;@`o % O,*`'`&\\\n"
		"            *    (`'--)_@ ;o %'()\\      *\n"
		"                 /`;--._`''--._O'@;\n"
		"                /&*,()~o`;-.,_ `\"\"`)\n"
		"     *          /`,@ ;+& () o*`;-';\\\n"
		"               (`\"\"--.,_0 +% @' &()\\\n"
		"               /-.,_    ``''--....-'`)  *\n"
		"          *    /@%;o`:;'--,.__   __.'\\\n"
		"              ;*,&(); @ % &^;~`\"`o;@();         *\n"
		"              /(); o^~; & ().o@*&`;&%O\\\n"
		"        jgs   `\"=\"==\"\"==,,,.,=\"==\"===\"`\n"
		"           __.----.(\\-''#####---...___...-----._\n"
		"         '`         \\)_`\"\"\"\"\"`\n"
		"                 .--' ')\n"
		"               o(  )_-\\\n"
		"                 `\"\"\"` `\n"
		"\n"
		"------------------------------------------------\n";
		filename = this->_target + "_shrubbery";
		output.open(filename);
		output << buf;
		output.close();
	}
	else if (!(this->getSign()))
		throw (B_RED"The Holy Form was not signed!" DEFAULT);
	else
		throw Bureaucrat::GradeTooLowException();
}
