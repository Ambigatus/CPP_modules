/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:06:30 by ddzuba            #+#    #+#             */
/*   Updated: 2023/08/01 15:15:18 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template <typename T>
void	iter(T *array, int len, void (*function)(T &param))
{
	for (int i = 0; i <len; i++)
		function(array[i]);
}

template <typename T>
void	print(T &element)
{
	std::cout << element << std::endl;
}

template <typename T>
void	square(T &element)
{
	element *= element;
}

#endif
