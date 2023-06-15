/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 09:24:44 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/15 18:39:08 by ddzuba           ###   ########.fr       */
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

//for instanse with int arg without converting inside 
    Fixed(const int i);

//for instanse with float arg without converting inside 
    Fixed(const float i);
    
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

//new part 
//info - https://docs.google.com/document/d/1wNTDj8b6QlwpT8uuLbG0XYd8ltoZXn9KPVmO7_rFfJg/edit?usp=sharing

//checks if the left-hand side (*this) is greater than the right-hand side (rhs).
    bool    operator>( const Fixed &rhs ) const ;
// checks if the left-hand side (*this) is less than the right-hand side (rhs)
    bool    operator<( const Fixed &rhs ) const ;
// Checks if the left-hand side (*this) is greater than or equal to the right-hand side (rhs)
    bool    operator>=( const Fixed &rhs ) const ;
// Checks if the left-hand side (*this) is less than or equal to the right-hand side (rhs)
    bool    operator<=( const Fixed &rhs ) const ;
// Checks if the left-hand side (*this) is equal to the right-hand side (rhs)
    bool    operator==( const Fixed &rhs ) const ;
//Checks if the left-hand side (*this) is not equal to the right-hand side (rhs)
    bool    operator!=( const Fixed &rhs ) const ;

// Adds the value of the right-hand side (rhs) to the value of the left-hand side (*this)
    Fixed   operator+( const Fixed &rhs ) const ;
//Subtracts the value of the right-hand side (rhs) from the value of the left-hand side (*this)
    Fixed   operator-( const Fixed &rhs ) const ;
//Multiplies the value of the right-hand side (rhs) with the value of the left-hand side (*this)
    Fixed   operator*( const Fixed &rhs ) const ;
//Divides the value of the left-hand side (*this) by the value of the right-hand side (rhs) 
    Fixed   operator/( const Fixed &rhs ) const ;

//Prefix increment operator. It increments the value of the Fixed object by 1 
    Fixed&  operator++( void );
//Postfix increment operator. It increments the value of the Fixed object by 1 
    Fixed   operator++( int );
// Prefix decrement operator. It decrements the value of the Fixed object by 1 
    Fixed&  operator--( void );
// Postfix decrement operator. It decrements the value of the Fixed object by 1
    Fixed   operator--( int );
    
// compare two objects and return min or max
    static Fixed& min( Fixed &a, Fixed &b ); //can be modified
    static const Fixed& min( const Fixed &a, const Fixed &b ); //can't be modified
    static Fixed& max( Fixed &a, Fixed &b ); //can be modified
    static const Fixed& max( const Fixed &a, const Fixed &b ); //can't be modified
    
//end of new part
};

//control how our number is looking
std::ostream & operator<<( std::ostream & o, Fixed const & i );

#endif 