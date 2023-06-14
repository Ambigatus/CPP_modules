/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 09:24:55 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/14 18:32:14 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) {
    std::cout << "Default constructor called" << std::endl;
    this->_numFixedPointValue = 0;
}

Fixed::Fixed(const int i) {
    std::cout << "Int constructor called" << std::endl;
    this->_numFixedPointValue = i << _numFractionalBits;
}

// The reason for calling setRawBits in the copy constructor is to ensure 
// that the newly created object has the same raw bits value as the object being copied. 
// It allows for a proper copy of the internal state of the object.
Fixed::Fixed( const Fixed &rhs ) {
    std::cout << "Copy constructor called" << std::endl;
    this->setRawBits(rhs.getRawBits());
    // *this = rhs; - another way for setting the value
	//but with sRB it's more controled
}

// Assignment operator overload: Updates the state of an already initialized object with 
// the values of another object. It is used when you want to assign the values of one object 
// to another object that already exists, allowing you to reuse and update an object
Fixed& Fixed::operator=( const Fixed &rhs ) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        this->_numFixedPointValue = rhs.getRawBits();
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// provide access to the raw representation of the 
// fixed-point number stored in the Fixed class.
//  By returning the raw bits, it allows users of the class 
//  to inspect and manipulate the internal representation if needed.
int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_numFixedPointValue;
}

// provide a way to set the raw value of the fixed-point number stored in the Fixed class. 
// It allows users of the class to initialize or modify the internal 
// representation of the fixed-point number directly.
void    Fixed::setRawBits( int const raw ) {
    this->_numFixedPointValue = raw;
}
