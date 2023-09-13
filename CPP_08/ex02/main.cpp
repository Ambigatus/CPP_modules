/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:03:55 by hboichuk          #+#    #+#             */
/*   Updated: 2023/09/13 18:30:17 by hboichuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int	main(void)
{
	std::cout << "\n\033[32m----- Simple test from subject -----\033[0m" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);//adding
	mstack.push(17); //adding
	std::cout << mstack.top() << std::endl; //show 17
	mstack.pop(); //delete 17
	std::cout << mstack.size() << std::endl; //1
	mstack.push(3);//adding
	mstack.push(5);//adding
	mstack.push(737);//adding

	mstack.push(0); //adding
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;//just show the iteration
	--it;//just show the iteration
	//show us all numbers in the stack without 17, we delete it
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "\n\033[32m----- Test with list container -----\033[0m" << std::endl;
	std::list<int> myList;

    // Adding elements to the list.
    myList.push_back(5);
    myList.push_back(17);

    // Show the top element (the last element in a list).
    if (!myList.empty()) {
        std::cout << myList.back() << std::endl;
    }

    // Delete the top element.
    if (!myList.empty()) {
        myList.pop_back();
    }

    // Print the size of the list.
    std::cout << myList.size() << std::endl;

    // Adding more elements.
    myList.push_back(3);
    myList.push_back(5);
    myList.push_back(737);
    myList.push_back(0);

    // Iterating through the list and printing elements.
    std::list<int>::iterator it2 = myList.begin();
    std::list<int>::iterator ite2 = myList.end();
    ++it2;
    --it2;

    while (it2 != ite2) {
        std::cout << *it2 << std::endl;
        ++it2;
    }

    // Create a std::list object using the elements from myList.
    std::list<int> s_list(myList);

	std::cout << "\n\033[32m----- Test with vector container -----\033[0m" << std::endl;
	std::vector<int> myVector;

    // Adding elements to the vector.
    myVector.push_back(5);
    myVector.push_back(17);

    // Show the top element (the last element in a vector).
    if (!myVector.empty()) {
        std::cout << myVector.back() << std::endl;
    }

    // Delete the top element.
    if (!myVector.empty()) {
        myVector.pop_back();
    }

    // Print the size of the vector.
    std::cout << myVector.size() << std::endl;

    // Adding more elements.
    myVector.push_back(3);
    myVector.push_back(5);
    myVector.push_back(737);
    myVector.push_back(0);

    // Iterating through the vector and printing elements.
    std::vector<int>::iterator it3 = myVector.begin();
    std::vector<int>::iterator ite3 = myVector.end();
    ++it3;
    --it3;

    while (it3 != ite3) {
        std::cout << *it3 << std::endl;
        ++it3;
    }

    // Create a std::vector object using the elements from myVector.
    std::vector<int> s_vector(myVector);
	
	return 0;
	
}