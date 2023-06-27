/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 22:03:43 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/27 11:20:10 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

void    MateriaSource::_nullInventory() 
{
    for (int i = 0; i < MEMORY_SIZE; i++)
        _inventory[i] = NULL;
}

MateriaSource::MateriaSource() 
{
    _nullInventory();
}

MateriaSource::MateriaSource(MateriaSource const &other) 
{
    _nullInventory();
    *this = other;
}

MateriaSource   &MateriaSource::operator=(MateriaSource const &other) 
{
    for (int i = 0; i < MEMORY_SIZE; i++)
    {
        if (_inventory[i])
            delete _inventory[i];
        if (other._inventory[i])
            _inventory[i] = other._inventory[i]->clone();
        else
            _inventory[i] = NULL;
    }
    return (*this);
}

MateriaSource::~MateriaSource() 
{
    for (int i = 0; i < MEMORY_SIZE; i++)
    {
        if (_inventory[i])
        {
            delete _inventory[i];
            _inventory[i] = NULL;
        }
    }
}

void    MateriaSource::learnMateria(AMateria *m) 
{
    for (int i = 0; i < MEMORY_SIZE; i++) {
        if (_inventory[i] == NULL) {
            _inventory[i] = m->clone();
            delete m;
            std::cout << "Materia Source has memorized " << _inventory[i]->getType() << " materia in slot " << i << "." << std::endl;
            return;
        }
    }
    std::cout << "There are no available memory slots at Materia Source." << std::endl;
    delete m;
}

AMateria    *MateriaSource::createMateria(std::string const &type) 
{
    for (int i = 0; i < MEMORY_SIZE; i++) {
        if (_inventory[i]) {
            if (_inventory[i]->getType() == type) {
                std::cout << "Materia Source has created a materia of type: " << _inventory[i]->getType() << "." << std::endl;
                return _inventory[i]->clone();
            }
        }
    }
    std::cout << "No materia of that type exists in memory." << std::endl;
    return NULL;
}

void    MateriaSource::displayMemory() const 
{
    std::cout << "Memory:" << std::endl;
    for (int i = 0; i < MEMORY_SIZE; i++) {
        if (_inventory[i] != NULL) {
            std::cout << "Slot #" << i << ": " << _inventory[i]->getType() << " materia." << std::endl;
        }
        else
            return;
    }
}
