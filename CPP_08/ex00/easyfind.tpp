/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:27:50 by hboichuk          #+#    #+#             */
/*   Updated: 2023/07/27 16:53:20 by hboichuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
# define EASYFIND_TPP

// A container is a holder object that stores a collection of other objects (its elements).
//  They are implemented as class templates, which allows a great flexibility in the types supported as elements.
//for example: array, vector, set, map (collection with pair key:value) - its our containers

//template - one variant of function for a few different types of value
//for example our value can be a number or float or double
template<typename T>
void	easyfind(T &container, int n)
{
	if ( std::find(container.begin(), container.end(), n) != container.end() )
		std::cout << "We found the value" << std::endl;
	else 
		std::cout << "We don't find the value" << std::endl;
}

#endif