/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:59:48 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/15 20:26:14 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//we need always positive value
static Fixed   abs(Fixed x) {
    if (x < 0)
        return x * -1;
    return x;
}

//It calculates the area of the triangle formed by points a, b, and c
static Fixed   area( Point const a, Point const b, Point const c ) {
    return ( ( ( a.getX() * ( b.getY() - c.getY() ) ) +
             ( b.getX() * ( c.getY() - a.getY() ) ) +
             ( c.getX() * ( a.getY() - b.getY() ) ) ) / 2 );
}

// It calculates the areas of three sub-triangles formed by the given point and two vertices 
// of the original triangle using the area function.
// It compares the sum of the areas of the sub-triangles 
// (pabArea + pbcArea + pcaArea) with the area of the original triangle (abcArea).
// If the sum of the sub-triangle areas is equal to the area of the original triangle, 
// it means the point lies inside the triangle or on its boundary. In this case, the function returns true
bool bsp( Point const a, Point const b, Point const c, Point const point) {
    Fixed   abcArea = abs(area( a, b, c ));
    Fixed   pabArea = abs(area( point, a, b ));
    Fixed   pbcArea = abs(area( point, b, c ));
    Fixed   pcaArea = abs(area( point, c, a ));

    return  ( abcArea == pabArea + pbcArea + pcaArea );
}
