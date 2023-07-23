/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:08:52 by hboichuk          #+#    #+#             */
/*   Updated: 2023/07/23 12:12:53 by hboichuk         ###   ########.fr       */
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

Converter::Converter(Converter const &copy)
{
	std::cout << "Converter: Copy constructor called" << std::endl;
	*this = copy;
}

Converter &Converter::operator=(Converter const &copy)
{
	std::cout << "Converter: operator= called" << std::endl;
	if ( this != &copy)
	{
		this->_i = copy.getI();
		this->_c = copy.getC();
		this->_f = copy.getF();
	}
	return *this;
}

Converter::~Converter()
{
	std::cout << "Converter: Destructor called" << std::endl;
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

e_type  Converter::getType( void ) const {
    return this->_type;
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
    this->setType();
    if ( getType() == NONE ) {
        throw Converter::ConverterException();
    }
	
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

//for recognizing types

bool    Converter::isChar( void ) const {
    return _str.length() == 1 && std::isalpha( _str[0] ) && std::isprint( _str[0] );
}

bool    Converter::isInt( void ) const {
    int    j = 0;
    if ( _str[j] == '-' || _str[j] == '+' )
        j++;
    for ( int i( j ); i < ( int ) _str.length(); i++ ) {
        if ( !std::isdigit( _str[i] ) )
            return false;
    }
    return true;
}

//npos is a static member constant value with the 
//greatest possible value for an element of type size_t.
// here = "until the end of the string"
bool Converter::isDouble( void ) const {

    if ( _str.find( '.' ) == std::string::npos || _str.find( '.' ) == 0 
        || _str.find( '.' ) == _str.length() - 1 )
        return false;
    int j = 0;
    int found = 0;
    if ( _str[j] == '-' || _str[j] == '+' )
        j++;
    for ( int i( j ); i < ( int ) _str.length(); i++ ) {
        if ( _str[i] == '.' )
            found++;
        if ( ( !std::isdigit( _str[i] ) && _str[i] != '.' ) || found > 1 )
            return false;
    }

    return true;
}

bool    Converter::isFloat ( void ) const {

    if ( _str.find( '.' ) == std::string::npos || _str.back() != 'f' 
        || _str.find( '.' ) == 0 || _str.find( '.' ) == _str.length() - 2 )
        return false;
    int found = 0;
    int j = 0;
    if ( _str[j] == '-' || _str[j] == '+' )
        j++;
    for ( int i( j ); i < ( int ) _str.length() - 1; i++ ) {
        if ( _str[i] == '.' )
            found++;
        if ( ( !std::isdigit( _str[i] ) && _str[i] != '.' ) || found > 1 )
            return false;
    }

    return true;
}

//check if it is impossible to convert the input 
//string _str to the desired type (INT, FLOAT, or DOUBLE).
//rewrite it - CPP11!
bool    Converter::isImpossible( void ) {
    try
    {
        if ( _type == INT ) {
            _i = std::stoi( _str );
        } else if ( _type == FLOAT ) {
            _f = std::stof( _str );
        } else if ( _type == DOUBLE ) {
            _d = std::stod( _str );
        }
    }
    catch ( std::exception& e )
    {
        _impossible = true;
        return true;
    }
    return false;
}

//functions for printing

void    Converter::printChar( void ) const {
    if ( this->isLiterals() || ( !std::isprint( _i ) && ( _i >= 127 ) ) ) {
        std::cout << "Impossible";
    } else if ( !std::isprint( this->_i ) ) {
        std::cout << "None displayable";
    } else {
        std::cout << "'" << getC() << "'";
    }
    std::cout << std::endl;
}

void    Converter::printInt( void ) const {
    if ( this->isLiterals() || ( !std::isprint( _i ) && ( _i >= 127 ) ) ) {
        std::cout << "Impossible";
    } else {
        std::cout << getI();
    }
    std::cout << std::endl;
}

void    Converter::printFloat( void ) const {
    if ( _str.compare( "nan" ) == 0 || _str.compare( "nanf" ) == 0 ) {
        std::cout << "nanf";
    } else if ( _str.compare( "+inff" ) == 0 || _str.compare( "+inf" ) == 0 ) {
        std::cout << "+inff";
    } else if ( _str.compare( "-inff" ) == 0 || _str.compare( "-inf" ) == 0 ) {
        std::cout << "-inff";
    } else if ( _impossible ) {
        std::cout << "Impossible";
    } else {
        if ( _f - static_cast< int > ( _f ) == 0 ) {
            std::cout << _f << ".0f";
        } else {
            std::cout << getF() << "f";
        }
    }
    std::cout << std::endl;
}

void    Converter::printDouble( void ) const {
    if ( _str.compare( "nan" ) == 0 || _str.compare( "nanf" ) == 0 ) {
        std::cout << "nan";
    } else if ( _str.compare( "+inff" ) == 0 || _str.compare( "+inf" ) == 0 ) {
        std::cout << "+inf";
    } else if ( _str.compare( "-inff" ) == 0 || _str.compare( "-inf" ) == 0 ) {
        std::cout << "-inf";
    } else if ( _impossible ) {
        std::cout << "Impossible";
    } else {
        if ( _d - static_cast< int > ( _d ) == 0 ) {
            std::cout << _d << ".0";
        } else {
            std::cout << getD() << "f";
        }
    }
    std::cout << std::endl;

}

//setting type 

void    Converter::setType( void ) {
    if ( isChar() ) {
        _type = CHAR;
    } else if ( isInt() ) {
        _type = INT;
    } else if ( isFloat() ) {
        _type = FLOAT;
    } else if ( isDouble() ) {
        _type = DOUBLE;
    } else if ( isLiterals() ) {
        _type = LITERALS;
    } else {
        _type = NONE;
    }
}

//for converting 
//static_cast is used in this context to ensure explicit type 
//conversions and avoid any potential loss of data. 
void    Converter::convert( void ) {
    if ( isImpossible() )
        return;
    switch ( _type ) {
    case CHAR:
        _c = _str[0];
        _i = static_cast< int >( _c );
        _f = static_cast< float >( _c );
        _d = static_cast< double >( _c );
        break;
    case INT:
        _i = std::stoi( _str );
        _f = static_cast< float >( _i );
        _d = static_cast< double >( _i );
        _c = static_cast< char >( _i );
        break;
    case FLOAT:
        _f = std::stof( _str );
        _i = static_cast< int >( _f );
        _d = static_cast< double >( _f );
        _c = static_cast< char >( _f );
        break;
    case DOUBLE:
        _d = std::stod( _str );
        _i = static_cast< int >( _d );
        _f = static_cast< float >( _d );
        _c = static_cast< char >( _d );
        break;
    default:
        break;
    }
}
//an implementation of the << operator 
std::ostream&    operator<<( std::ostream& out, const Converter& rhs ) {
    out << "char: "; rhs.printChar();
    out << "int: "; rhs.printInt();
    out << "float: "; rhs.printFloat();
    out << "double: "; rhs.printDouble();
    return out;
}
