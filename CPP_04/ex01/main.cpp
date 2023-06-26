/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 09:11:00 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/26 18:49:30 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main(void)
{
    std::string partition(50, '-');

    std::cout << partition << std::endl;
    std::cout << "// BASE TESTS //" << std::endl;
    std::cout << partition << std::endl;
    {
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        delete j;//should not create a leak
        delete i;
    }
    std::cout << partition << std::endl;
    std::cout << "// DEEP COPIES //" << std::endl;
    std::cout << partition << std::endl;
    {
        Dog dog;
        Dog perro(dog);
        Dog tmp = dog;

        dog.setIdea(1, "Who is a good boy?");
        perro.setIdea(1, "Ball!");
        tmp.setIdea(1, "Squirrel!");
        std::cout << dog.getIdea(1) << std::endl;
        std::cout << perro.getIdea(1) << std::endl;
        std::cout << tmp.getIdea(1) << std::endl;
    }
    std::cout << partition << std::endl;
    std::cout << "// ANIMAL ARRAY //" << std::endl;
    std::cout << partition << std::endl;
    {
        int size = 6;
        Animal  *pets[size];

        for (int i = 0; i < size/2; i++)
            pets[i] = new Dog();
        for (int i = size/2; i < size; i++)
            pets[i] = new Cat();
        std::cout << pets[0]->getType() << std::endl;
        std::cout << pets[size - 1]->getType() << std::endl;
        for (int i = 0; i < size; i++)
            delete pets[i];
    }
    std::cout << partition << std::endl;
    return (0);
}