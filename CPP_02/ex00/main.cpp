/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:59:58 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/13 08:02:39 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main( void ) {
	
Fixed a;
Fixed b( a );
Fixed c;

c = b;
std::cout << a.getRawBits() << std::endl;
std::cout << b.getRawBits() << std::endl;
std::cout << c.getRawBits() << std::endl;

return (0);
}