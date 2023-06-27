/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 21:52:02 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/27 11:03:04 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

void    Character::_nullInventoryAndStorage()
{
    for (int i = 0; i < INVENTORY_SIZE; i++)
        _inventory[i] = NULL;
    for (int i = 0; i < STORAGE_SIZE; i++)
        _storage[i] = NULL;
}

Character::Character() : _name("Unknown")
{
    _nullInventoryAndStorage();
    std::cout << "Unknown person is here" << std::endl;
}

Character::Character(std::string name) : _name(name)
{
    _nullInventoryAndStorage();
    std::cout << "The " << _name << " is right here!" << std::endl;
}

Character::Character( Character const &src )
{
    _nullInventoryAndStorage();
    *this = src;
    std::cout << "Character " << this->_name << " is cloned!" << std::endl;
}

Character& Character::operator=( Character const & rhs )
{
    _name = rhs._name;
    for (int i = 0; i < INVENTORY_SIZE; i++)
    {
        if (_inventory[i])
            delete _inventory[i];
        if (rhs._inventory[i])
            _inventory[i] = rhs._inventory[i]->clone();
        else
            _inventory[i] = NULL;
    }
    for (int i = 0; i < STORAGE_SIZE; i++)
    {
        if (_storage[i])
            delete _storage[i];
        if (rhs._storage[i])
            _storage[i] = rhs._storage[i]->clone();
        else
            _storage[i] = NULL;
    }
    return (*this);
}

Character::~Character()
{
    for (int i = 0; i < INVENTORY_SIZE; i++)
    {
        if (_inventory[i])
        {
            delete _inventory[i];
            _inventory[i] = NULL;
        }
    }
    for (int i = 0; i < STORAGE_SIZE; i++)
    {
        if (_storage[i])
        {
            delete _storage[i];
            _storage[i] = NULL;
        }
    }
}

void    Character::equip( AMateria* m )
{
    if (m == NULL) 
    {
        std::cout << "No materia to equip." << std::endl;
        return;
    }
    for (int i = 0; i < INVENTORY_SIZE; i++) 
    {
        if (_inventory[i] == NULL) 
        {
            _inventory[i] = m->clone();
            delete m;
            std::cout << "Equiped " << _inventory[i]->getType() << " materia in slot " << i << "." << std::endl;
            return;
        }
    }
    std::cout << "Inventory is full. Cannot equip materia." << std::endl;
}

void    Character::unequip(int idx) 
{
    if (idx < 0 || idx > INVENTORY_SIZE - 1)
        std::cout << "Invalid inventory slot." << std::endl;
    for (int i = 0; i < STORAGE_SIZE; i++) 
    {
        if (_storage[i] == NULL) {
            _storage[i] = _inventory[idx];
            std::cout << "One " << _inventory[idx]->getType() << " materia was placed in storage." << std::endl;
            _inventory[idx] = NULL;
            return;
        }
    }
    std::cout << "Storage is full. Cannot unequip materia." << std::endl;
}

void    Character::use(int idx, ICharacter &target) 
{
    if (idx < 0 || idx > INVENTORY_SIZE - 1)
        std::cout << "Invalid inventory slot." << std::endl;
    else if (!_inventory[idx])
        std::cout << "Inventory slot is empty." << std::endl;
    else
        _inventory[idx]->use(target);
}

void    Character::displayInventory() const 
{
    std::cout << _name << " | Inventory:" << std::endl;
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        if (_inventory[i] != NULL) {
            std::cout << "Slot #" << i << ": " << _inventory[i]->getType() << " materia." << std::endl;
        }
        else
            return;
    }
}

void    Character::displayStorage() const 
{
    std::cout << _name << " | Storage:" << std::endl;
    for (int i = 0; i < STORAGE_SIZE; i++) {
        if (_storage[i] != NULL) {
            std::cout << "Slot #" << i << ": " << _storage[i]->getType() << " materia." << std::endl;
        }
        else
            return;
    }
}

std::string const   &Character::getName() const 
{
    return (_name);
}
