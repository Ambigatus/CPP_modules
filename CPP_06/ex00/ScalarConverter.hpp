/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:08:18 by hboichuk          #+#    #+#             */
/*   Updated: 2023/09/06 17:22:47 by hboichuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>

# define ERR_ARGC           "Wrong input: write one number,pls"
# define ERR_INVALID_INPUT  "Wrong input: we need char, int, double or float"

# define INT 0
# define FLOAT 1
# define DOUBLE 2
# define CHAR 3
# define PSEUDO 4
# define INVALID 5

class ScalarConverter {
private:
    ScalarConverter();
    ScalarConverter(ScalarConverter const &src);
    ScalarConverter &operator=(ScalarConverter const &src);
    virtual ~ScalarConverter();

public:
    static void convert(std::string const &input);
};

#endif