/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:08:52 by hboichuk          #+#    #+#             */
/*   Updated: 2023/07/21 15:30:46 by hboichuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

Converter::Converter()
{
	std::cout << "Converter: Default constructor called" << std::endl;
	this->_c = '\0';
	this->_i = 0;
	this->_d = 0.0;
	this->_f = 0.0f;
}

Converter::~Converter()
{
	std::cout << "Converter: Denstructor called" << std::endl;
}

Converter::Converter(Converter const &copy)
{
	std::cout << "Converter: Copy constructor called" << std::endl;
	this->_type = copy._type;
}

Converter &Converter::operator=(Converter const &copy)
{
	std::cout << "Converter: operator= called" << std::endl;
	// if(this == &copy)
	// 	return *this;
	// this->_type = copy._type;
	if ( this != &copy)
	{
		this->_i = copy.getI();
		this->_c = copy.getC();
		this->_f = copy.getF();
	}
	return *this;
}

//getters 

char	Converter::getC(void) const 
{
	return this->_c;
}

int		Converter::getI(void) const 
{
	return this->_i;
}

double	Converter::getD(void) const 
{
	return this->_d;
}

float	Converter::getF(void) const 
{
	return this->_f;
}

//check it
std::string	Converter::getStr(void) const 
{
	return this->_str;
}

//setters

void	Converter::setC(char c)  
{
	this->_c = c;
}

void	Converter::setI(int i)  
{
	this->_i = i;
}

void	Converter::setD(double d)  
{
	this->_d = d;
}

void	Converter::setF(float f)  
{
	this->_f = f;
}

void	Converter::setStr(std::string str)  
{
	this->_str = str;
	
}

//for recognizing pseudo literals
bool    Converter::isLiterals( void ) const {
    if ( ( _impossible ) || ( _str.compare( "nan" ) == 0 ) || ( _str.compare( "nanf" ) == 0 )
        || ( _str.compare( "+inf" ) == 0 ) || ( _str.compare( "+inff" ) == 0 ) 
        || ( _str.compare( "-inf" ) == 0 ) || ( _str.compare( "-inff" ) == 0 ) 
        || ( _str.compare( "-inff" ) == 0 ) || ( _str.compare( "-inff" ) == 0 )  
        || ( _str.compare( "+inff" ) == 0 ) || ( _str.compare( "+inff" ) == 0 ) ) {
            return true;
    } 
    return false;
}