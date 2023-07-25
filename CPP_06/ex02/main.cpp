/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:03:55 by hboichuk          #+#    #+#             */
/*   Updated: 2023/07/25 17:40:20 by hboichuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int	main(void)
{
	Base *ptr = generate();
    Base &ref = *ptr;

    identify(ptr);
    identify(ref);

    return EXIT_SUCCESS;
}