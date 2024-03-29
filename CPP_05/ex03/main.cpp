/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:54:01 by ddzuba            #+#    #+#             */
/*   Updated: 2023/07/31 14:25:23 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() {
    std::string partition(50, '-');

    std::cout << partition << std::endl;
    std::cout << "// PRESIDENTIAL PARDON FORM //" << std::endl;
    std::cout << partition << std::endl;
    {
        Bureaucrat  bossMan("Boss", 1);
        Intern      someRandomIntern;
        AForm       *form;
        form = someRandomIntern.makeForm("presidential pardon", "Bender");
        std::cout << *form << std::endl;
        std::cout << std::endl;

        bossMan.signForm(*form);
        bossMan.executeForm(*form);
        std::cout << *form << std::endl;

        delete form;
    }
    std::cout << partition << std::endl;
    std::cout << "// ROBOTOMY FORM //" << std::endl;
    std::cout << partition << std::endl;
    {
        Bureaucrat  bossMan("Boss", 1);
        Intern      someRandomIntern;
        AForm       *form;
        form = someRandomIntern.makeForm("robotomy request", "Bender");
        std::cout << *form << std::endl;

        std::cout << std::endl;
        bossMan.signForm(*form);
        bossMan.executeForm(*form);
        std::cout << *form << std::endl;

        delete form;
    }
    std::cout << partition << std::endl;
    std::cout << "// SHRUBBERY FORM //" << std::endl;
    std::cout << partition << std::endl;
    {
        Bureaucrat  bossMan("Boss", 1);
        Intern      someRandomIntern;
        AForm       *form;
        form = someRandomIntern.makeForm("shrubbery creation", "Bender");
        std::cout << *form << std::endl;
        std::cout << std::endl;

        bossMan.signForm(*form);
        bossMan.executeForm(*form);
        std::cout << *form << std::endl;

        delete form;
    }
    std::cout << partition << std::endl;
    std::cout << "// UNKNOWN FORM //" << std::endl;
    std::cout << partition << std::endl;
    {
        Bureaucrat  bossMan("Boss", 1);
        Intern      someRandomIntern;
        AForm       *form;
        form = someRandomIntern.makeForm("intern holiday request", "Bender");

        delete form;
    }
    std::cout << partition << std::endl;
    return (0);
}