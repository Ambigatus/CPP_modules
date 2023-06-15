/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 19:00:31 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/15 20:08:52 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//default constructor
Point::Point( void ) : _x(0), _y(0) { }

// constructor for float type
Point::Point( const float x, const float y ) : _x(x), _y(y) {}

//copy constructor for copying object
Point::Point( const Point &src ) : _x(src._x), _y(src._y) {}

//destructor
Point::~Point() {}

//copying constructor overloading
Point&  Point::operator=( const Point &rhs ) {
    if ( this != &rhs ) {
        ( Fixed ) this->_x = rhs.getX();
        ( Fixed ) this->_y = rhs.getY();
    }
    return *this;
}

//getter for X
Fixed Point::getX( void ) const {
    return this->_x;
}

//getter for Y
Fixed Point::getY( void ) const {
    return this->_y;
}
