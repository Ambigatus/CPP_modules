/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:03:55 by hboichuk          #+#    #+#             */
/*   Updated: 2023/08/24 17:55:18 by hboichuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int	main(void)
{
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
	return 0;
	
}