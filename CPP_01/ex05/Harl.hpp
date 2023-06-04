/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 13:22:16 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/04 13:24:30 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string.h>

class Harl
{
	private:
		void debug( void );
		void info ( void);
		void warning ( void );
		void error ( void );

	public:
		Harl();
		~Harl();

		void complain( std::string level );
};

#endif