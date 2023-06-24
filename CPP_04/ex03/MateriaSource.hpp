/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 21:16:44 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/24 22:10:21 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria*       materias[4];

    public:
        MateriaSource();
        ~MateriaSource();

        MateriaSource( MateriaSource const & );
        MateriaSource&  operator=( MateriaSource const & );

        AMateria*       getMateria( std::string const & type );
        AMateria*       createMateria( std::string const & type );
        void            learnMateria( AMateria* );
};


#endif