/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 09:11:00 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/27 20:09:58 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void)
{
    std::string partition(50, '-');

    std::cout << partition << std::endl;
    std::cout << "// BASE TESTS //" << std::endl;
    std::cout << partition << std::endl;
    {
        const Animal* meta = new Animal();
        const Animal* i = new Cat();
        const Animal* j = new Dog();
        std::cout << meta->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        std::cout << j->getType() << " " << std::endl;
        meta->makeSound();
        i->makeSound(); //will output the cat sound!
        j->makeSound();
        delete meta;
        delete i;
        delete j;
    }
    std::cout << partition << std::endl;
    std::cout << "// WRONG SOUND //" << std::endl;
    std::cout << partition << std::endl;
    {
        const WrongAnimal* meta = new WrongAnimal();
        const WrongCat* i = new WrongCat();
        const WrongAnimal* j = new WrongCat();
        std::cout << meta->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        std::cout << j->getType() << " " << std::endl;
        meta->makeSound();
        i->makeSound();
        j->makeSound();//Unexpected behavior here
        delete meta;
        delete i;
        delete j;
    }
    std::cout << partition << std::endl;
    std::cout << "// SOUND TESTS //" << std::endl;
    std::cout << partition << std::endl;
    {
        Animal animal;
        Dog dog;
        Cat cat;

        animal.makeSound();
        dog.makeSound();
        cat.makeSound();
    }
    std::cout << partition << std::endl;
    std::cout << "// DESTRUCTION TESTS //" << std::endl;
    std::cout << partition << std::endl;
    {
        Cat cat;

        std::cout << cat.getType() << std::endl;
        cat.makeSound();

        Cat* gato = new Cat;

        std::cout << gato->getType() <<std::endl;
        gato->makeSound();
        delete gato;
    }
    std::cout << partition << std::endl;
    return (0);
}
