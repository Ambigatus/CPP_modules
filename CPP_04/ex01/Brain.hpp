/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:58:35 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/26 18:38:04 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
    private:
        std::string _ideas[100];

    public:
        Brain( void );
        Brain(Brain const &src);
        Brain &operator=(Brain const &src);
        ~Brain( void );

    void        setIdea(int index, std::string idea);
    std::string getIdea(int index) const;
};
 
#endif