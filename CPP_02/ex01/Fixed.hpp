/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 09:24:44 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/14 18:20:09 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
//int to store the fixed-point number value
    int                 _numFixedPointValue;
    
//static const int to store the num of fractional bits
    static const int    _numFractionalBits = 8;

public:
//default constructor(classicaly without args)
    Fixed(void);
    
//copy constructor for creating a copy of obj
    Fixed( const Fixed &rhs );
    
//Assignment operator overloading allows you to define your own 
//implementation of the assignment operator for a class
    Fixed& operator=( const Fixed &rhs );
    
// destructor
    ~Fixed();
    
//returns the raw value of the fixed-point value
    int     getRawBits( void ) const;
    
//sets the raw value of the fixed-point number
    void    setRawBits( int const raw );

// converts the fixed-point value to a floating-point value
    float   toFloat( void ) const;

// converts the fixed-point value to an integer value
    int     toInt( void ) const;
};

//control how our number is looking
std::ostream & operator<<( std::ostream & o, Fixed const & i );

#endif 