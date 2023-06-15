/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 09:24:55 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/15 18:55:48 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath> //for roundf()

Fixed::Fixed(void) {
    this->_numFixedPointValue = 0;
}

Fixed::Fixed(const int i) {
    this->_numFixedPointValue = i << _numFractionalBits;
}

Fixed::Fixed(const float i) {
    //converts floating num in fixed-point num
    this->_numFixedPointValue = roundf( i * ( 1 << _numFractionalBits ));
}

// The reason for calling setRawBits in the copy constructor is to ensure 
// that the newly created object has the same raw bits value as the object being copied. 
// It allows for a proper copy of the internal state of the object.
Fixed::Fixed( const Fixed &rhs ) {
    this->setRawBits(rhs.getRawBits());
	// with sRB it's more controled
}

// Assignment operator overload: Updates the state of an already initialized object with 
// the values of another object. It is used when you want to assign the values of one object 
// to another object that already exists, allowing you to reuse and update an object
Fixed& Fixed::operator=( const Fixed &rhs ) {
    if (this != &rhs)
        this->_numFixedPointValue = rhs.getRawBits();
    return *this;
}

Fixed::~Fixed() {} //destructor

// provide access to the raw representation of the 
// fixed-point number stored in the Fixed class.
//  By returning the raw bits, it allows users of the class 
//  to inspect and manipulate the internal representation if needed.
int Fixed::getRawBits( void ) const {
    return this->_numFixedPointValue;
}

// provide a way to set the raw value of the fixed-point number stored in the Fixed class. 
// It allows users of the class to initialize or modify the internal 
// representation of the fixed-point number directly.
void    Fixed::setRawBits( int const raw ) {
    this->_numFixedPointValue = raw;
}

//extracts the integer part of the fixed-point value by shifting the bits to the right, 
// effectively removing the fractional part. This operation allows you to obtain the whole 
// number part of the fixed-point value.
float   Fixed::toFloat( void ) const {
    return static_cast<float>( this->getRawBits() ) / ( 1 << _numFractionalBits );
}

int     Fixed::toInt( void ) const {
    return this->_numFixedPointValue >> _numFractionalBits;
}

// In essence, this operator<< overload allows you to output a Fixed object to the output stream
//  by converting it to a float value and inserting that value into the stream.
std::ostream & operator<<( std::ostream & o, Fixed const & i ) {
    o << i.toFloat();
    return o;
}

//----------------- Comparison operators -----------------//

bool    Fixed::operator>( const Fixed &rhs ) const {
    return this->getRawBits() > rhs.getRawBits();
}

bool    Fixed::operator<( const Fixed &rhs ) const {
    return this->getRawBits() < rhs.getRawBits();
}

bool    Fixed::operator>=( const Fixed &rhs ) const {
    return this->getRawBits() >= rhs.getRawBits();
}

bool   Fixed::operator<=( const Fixed &rhs ) const {
    return this->getRawBits() <= rhs.getRawBits();
}

bool  Fixed::operator==( const Fixed &rhs ) const {
    return this->getRawBits() == rhs.getRawBits();
}

bool    Fixed::operator!=( const Fixed &rhs ) const {
    return this->getRawBits() != rhs.getRawBits();
}

//------------------ Arithmetic operators ------------------//

Fixed   Fixed::operator+( const Fixed &rhs ) const {
    return Fixed( this->toFloat() + rhs.toFloat() );
}

Fixed   Fixed::operator-( const Fixed &rhs ) const {
    return Fixed( this->toFloat() - rhs.toFloat() );
}

Fixed   Fixed::operator*( const Fixed &rhs ) const {
    return Fixed( this->toFloat() * rhs.toFloat() );
}

Fixed   Fixed::operator/( const Fixed &rhs ) const {
    return Fixed( this->toFloat() / rhs.toFloat() );
}

//------------------ Increment/Decrement operators ------------------//

Fixed&   Fixed::operator++( void ) {
    ++this->_numFixedPointValue;
    return *this;
}

Fixed   Fixed::operator++( int ) {
    Fixed tmp( *this );
    tmp._numFixedPointValue = this->_numFixedPointValue++;
    return tmp;
}

Fixed& Fixed::operator--( void ) {
    --this->_numFixedPointValue;
    return *this;
}

Fixed Fixed::operator--( int ) {
    Fixed tmp( *this );
    tmp._numFixedPointValue = this->_numFixedPointValue--;
    return tmp;
}

//----------------------- Max and Min ----------------------//

Fixed& Fixed::min( Fixed &a, Fixed &b ) {
    if ( a.getRawBits() < b.getRawBits() )
        return a;
    return b;
}

const Fixed& Fixed::min( const Fixed &a, const Fixed &b ) {
    if ( a.getRawBits() < b.getRawBits() )
        return a;
    return b;
}

Fixed& Fixed::max( Fixed &a, Fixed &b ) {
    if ( a.getRawBits() > b.getRawBits() )
        return a;
    return b;
}

const Fixed& Fixed::max( const Fixed &a, const Fixed &b ) {
    if ( a.getRawBits() > b.getRawBits() )
        return a;
    return b;
}
