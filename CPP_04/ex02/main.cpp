/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 09:11:00 by ddzuba            #+#    #+#             */
/*   Updated: 2023/06/24 20:34:41 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


//if you need to check leaks - leaks -atExit --./a.out
// Abstract classes are used to represent general concepts (for example, Shape, Animal), 
// which can be used as base classes for concrete classes (for example, Circle, Dog).

// No objects of an abstract class can be created (except for base subobjects of a class derived from it)
//  and no non-static data members whose type is an abstract class can be declared.
int main()
{

//abstract class - test - error
// const Animal a; 
	
//right test from subject
const Animal* j = new Dog();
const Animal* i = new Cat();
delete j;//should not create a leak
delete i;

//wrong test with sounds
const WrongAnimal* WrongMeta = new WrongAnimal();
const WrongAnimal* c = new WrongCat();
std::cout << c->getType() << " " << std::endl;
c->makeSound(); //will output the wrong cat sound!
WrongMeta->makeSound();

// //a lot of animals test
// Dog basic;
//     {
//         Dog tmp = basic;
//     }

//     const Animal* animals[4] = { new Dog(), new Dog(), new Cat(), new Cat() };
//     for ( int i = 0; i < 4; i++ ) {
//         delete animals[i];
//     }

return 0;
}