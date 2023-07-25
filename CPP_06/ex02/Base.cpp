/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:49:59 by hboichuk          #+#    #+#             */
/*   Updated: 2023/07/25 17:50:56 by hboichuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

//These four classes don’t have to be designed in the Orthodox
// Canonical Form
Base::~Base(){}

//randomly give some child
Base * generate(void)
{
	Base *ptr;

	// srand(time(NULL)) - seed the random-number generator with current time so that
	// * the numbers will be different every time we run
	srand(time(NULL));
	if ( std::rand() % 3 == 0 )
	{
		ptr = new A;
		std::cout << "Child A generated. Address:" << ptr << std::endl;
	}
    else if ( std::rand() % 3 == 1 )
    {
		ptr = new B;
		std::cout << "Child B generated. Address:" << ptr << std::endl;
	}
    else
    {
		ptr = new C;
		std::cout << "Child C generated. Address:" << ptr << std::endl;
	}
	return ptr;
}

//Dynamic Cast: A cast is an operator that converts data from one type to another type. 
//In C++, dynamic casting is mainly used for safe downcasting at run time. 
//To work on dynamic_cast there must be one virtual function in the base class. 
void identify(Base* p)
{
	A *Aptr = dynamic_cast< A *>(p);
	B *Bptr = dynamic_cast< B *>(p);
	C *Cptr = dynamic_cast< C *>(p);

	if (Aptr)
		std::cout << "Child A pointer. Address:" << Aptr << std::endl;
	else if (Bptr)
		std::cout << "Child B pointer. Address:" << Bptr << std::endl;
	else if (Cptr)
		std::cout << "Child C pointer. Address:" << Cptr << std::endl;
	else
		std::cout << "Child doesn't exist " << std::endl;
}

void identify(Base& p)
{
	//child A
	try
	{
		A &Aptr = dynamic_cast<A &>(p);
		std::cout << "Child A reference. Address:" << &Aptr << std::endl;
	}
	catch(std::exception &e)
	{
		//child B
		try
		{
			B &Bptr = dynamic_cast<B &>(p);
			std::cout << "Child B reference. Address:" << &Bptr << std::endl;
		}
		catch(std::exception &e)
		{
			//child C
			try
			{
				C &Cptr = dynamic_cast<C &>(p);
				std::cout << "Child C reference. Address:" << &Cptr << std::endl;
			}
			catch(std::exception &e)
			{
				std::cout << "Child doesn't exist " << std::endl;
			}
		}
	}
}	
