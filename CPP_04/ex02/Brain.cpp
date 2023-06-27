/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:58:23 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/26 18:36:25 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void )
{
    std::cout << "Brain created." << std::endl;
    return ;
}

Brain::~Brain( void )
{
    std::cout << "Brain destroyed." << std::endl;
    return ;
}

Brain::Brain(Brain const &src)
{
    *this = src;
    std::cout << "Brain is cloned" << std::endl;
    return ;
}

Brain& Brain::operator=(Brain const &src)
{
    for (int i = 0; i < 100; i++)
        _ideas[i] = src._ideas[i];
    std::cout << "<Brain.cpp:32> Brain copy called." << std::endl;
    return (*this);
}

void    Brain::setIdea(int index, std::string idea)
{
    if (index < 0 || index >= 100)
    {
        std::cout << "This brain is too small for this idea!" << std::endl;
        return ;
    }
    else
        _ideas[index] = idea;
    return ;
}

std::string Brain::getIdea(int index) const
{
    if (index < 0 || index >= 100)
    {
        std::cout << "There is no thougths here" << std::endl;
        return(NULL);
    }
    else
        return (_ideas[index]);
}
