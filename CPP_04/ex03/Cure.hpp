/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 21:53:38 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/27 11:05:03 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"


class Cure : public AMateria
{
    public:
        Cure();
        Cure(Cure const &copy);
        Cure    &operator=(Cure const &copy);
        virtual ~Cure();

        virtual AMateria    *clone() const;
        virtual void        use(ICharacter& target);
};

#endif