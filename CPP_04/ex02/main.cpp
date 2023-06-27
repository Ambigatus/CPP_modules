/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 09:11:00 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/26 19:21:41 by ddzuba           ###   ########.fr       */
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
    std::cout << "// ANIMAL IS ABSTRACT //" << std::endl;
    std::cout << partition << std::endl;
    {
//        Animal human;
    }
    std::cout << partition << std::endl;
    std::cout << "// DEEP COPIES //" << std::endl;
    std::cout << partition << std::endl;
    {
        Dog dog;
        Dog perro(dog);
        Dog tmp = dog;

        dog.setIdea(0, "Who is a good boy?");
        perro.setIdea(0, "Ball!");
        tmp.setIdea(0, "Squirrel!");
        std::cout << dog.getIdea(0) << std::endl;
        std::cout << perro.getIdea(0) << std::endl;
        std::cout << tmp.getIdea(0) << std::endl;
    }
    std::cout << partition << std::endl;
    return (0);
}