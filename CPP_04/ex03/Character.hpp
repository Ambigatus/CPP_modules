/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 21:51:41 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/27 10:44:56 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "ICharacter.hpp"
# include "AMateria.hpp"

# define INVENTORY_SIZE 4
# define STORAGE_SIZE 100

class Character : public ICharacter
{

    private:
        std::string _name;
        AMateria    *_inventory[INVENTORY_SIZE];
        AMateria    *_storage[STORAGE_SIZE];

        void    _nullInventoryAndStorage();

    public:
        Character();
        Character(std::string name);
        Character(Character const &src);
        Character   &operator=(Character const &rhs);
        ~Character();


        virtual std::string const   &getName() const;
        virtual void                equip(AMateria *m);
        virtual void                unequip(int idx);
        virtual void                use(int idx, ICharacter &target);
        void                        displayInventory() const;
        void                        displayStorage() const;
};

#endif