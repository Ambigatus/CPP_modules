/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 21:16:44 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/27 11:18:39 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

# define MEMORY_SIZE 4

class MateriaSource : public IMateriaSource
{
    private:
        AMateria        *_inventory[MEMORY_SIZE];

        void            _nullInventory();

    public:
        MateriaSource();

        MateriaSource(MateriaSource const &copy);
        MateriaSource   &operator=(MateriaSource const &copy);
        ~MateriaSource();

        void            displayMemory() const;
        AMateria*       createMateria( std::string const & type );
        void            learnMateria( AMateria* );
};


#endif