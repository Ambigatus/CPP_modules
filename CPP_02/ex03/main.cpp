/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 09:20:05 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/15 20:34:19 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

// check with this - https://planetcalc.com/8108/
//false: Point(0, 0), Point(10, 30), Point(20, 0), Point(30, 15)
//true: Point(0, 0), Point(10, 30), Point(20, 0), Point(10, 15)

int main( void ) 
{
	
  if ( bsp( Point(0, 0), Point(10, 30), Point(20, 0), Point(10, 15) ) == true ) {
        std::cout << "True" << std::endl;
    } else {
        std::cout << "False" << std::endl;
    }
    return 0;

}
