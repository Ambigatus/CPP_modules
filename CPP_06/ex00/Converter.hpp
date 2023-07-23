/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:08:18 by hboichuk          #+#    #+#             */
/*   Updated: 2023/07/23 12:02:38 by hboichuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <limits>

enum e_type {
    NONE,
    INT,
    FLOAT,
    CHAR,
    DOUBLE,
    LITERALS 
};

class Converter
{
	// this literal must belong to one of the following a scalar types
	private:
		char 	_c;
		int		_i;
		float 	_f;
		double 	_d;

		bool	_impossible;
		
		std::string _str;
		e_type		_type;
		 

	public:
	//ortodox canonical style
		Converter();
		~Converter();
		Converter(Converter const &copy);
		Converter &operator=(Converter const &copy);

	//getters and setters for access to variables
		char    		getC( void ) const;
		int    			getI( void ) const;
		double  		getD( void ) const;
		float   		getF( void ) const;
		std::string    	getStr( void ) const;
		e_type			getType( void ) const;

		void    		setC( char c );
		void    		setI( int i );
		void    		setD( double d );
		void    		setF( float f );
		void    		setStr( std::string str );
		
	//for pseudo literals
		bool    		isLiterals( void ) const;
	//for recognizing types
		bool    		isChar( void ) const;
		bool    		isInt( void ) const;
		bool			isDouble( void ) const;
		bool    		isFloat ( void ) const;
		bool    		isImpossible( void );

		void    		setType( void );
	//for printing
		void   			printDouble( void ) const;
		void    		printFloat( void ) const;
		void    		printInt( void ) const;
		void    		printChar( void ) const;
		
	//for converting 
		void    		convert( void );
	//custom exeption 
	 class ConverterException : public std::exception {
        virtual const char* what() const throw() { return "Unknown type"; }
    };
};

std::ostream& operator<<( std::ostream& out, const Converter& rhs );

#endif