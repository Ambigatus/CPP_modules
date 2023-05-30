/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:36:08 by ddzuba            #+#    #+#             */
/*   Updated: 2023/05/30 15:50:12 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

#include <iostream>
#include <string.h>

class Replace
{
		private:

		public:
			Replace();
			~Replace();\
			
		std::string my_replace(std::string line, std::string str1, std::string str2);
};

#endif