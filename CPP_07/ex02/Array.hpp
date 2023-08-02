/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:19:52 by ddzuba            #+#    #+#             */
/*   Updated: 2023/08/02 14:51:46 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>


template <typename T>
class Array
{
	private:
		T				*_values;
		unsigned int	_size;

	public:
		Array();
		Array(unsigned int size);
		Array(Array<T> const &copy);
		Array &operator=(Array<T> const &copy);
		~Array();

	T					&operator[](size_t index) const;
	unsigned int		size() const;

	class OutOfBoundsExeption : public std::exception
	{
		public:
			const char	*what() const throw();
	};
};

# include "Array.tpp"

#endif