/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:00:39 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/14 18:34:13 by ddzuba           ###   ########.fr       */
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
};

#endif 