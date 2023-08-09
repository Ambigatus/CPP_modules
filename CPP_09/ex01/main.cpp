/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:46:52 by ddzuba            #+#    #+#             */
/*   Updated: 2023/08/09 15:56:04 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool    isInputSizeRight(int argc) 
{
    if (argc == 2)
        return (true);
    COUT << B_RED << ERR_ARGS << ENDL << B_YELLOW << EXAMPLE << DEFAULT << ENDL;
    return (false);

}

int main(int argc, char *argv[]) 
{
    if (!isInputSizeRight(argc))
        return (-1);
    RPN rpn;
    rpn.calculate(argv[1]);
    return (0);
}

/*
Read 5: Push 5 onto the stack.
Read 3: Push 3 onto the stack.
Read 4: Push 4 onto the stack.
Read +: Pop 3 and 4 from the stack, add them (3 + 4 = 7), and push 7 onto the stack.
Read *: Pop 5 and 7 from the stack, multiply them (5 * 7 = 35), and push 35 onto the stack.
*/