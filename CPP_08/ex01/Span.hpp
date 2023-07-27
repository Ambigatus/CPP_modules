/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:26:15 by hboichuk          #+#    #+#             */
/*   Updated: 2023/07/27 17:24:58 by hboichuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <exception>
#include <vector>
#include <list>


class Span
{
	private:
	
	public:
	//ortodox canonical style
		Span();
		~Span();
		Span(Span const &copy);
		Span &operator=(Span const &copy);

	//getters and setters for access to variables
	
};


#endif