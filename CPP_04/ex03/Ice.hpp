/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 21:53:58 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/24 22:03:13 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{

    public:
        Ice();
        ~Ice();

        Ice( Ice const & );
        Ice& operator=( Ice const & );

        virtual AMateria*   clone() const;
        virtual void        use(ICharacter& target);
};

#endif