/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:50:44 by ddzuba            #+#    #+#             */
/*   Updated: 2023/05/30 16:00:50 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace()
{
    
}

Replace::~Replace()
{
    
}

std::string Replace::my_replace(std::string line, std::string str1, std::string str2)
{
    std::string result;
    std::string::size_type next = 0;
    size_t  prev;
    while (1)
    {
        prev = next;
        next = line.find(str1, prev);
        result.append(line.substr(prev, next - prev));
        if (next == std::string::npos)
            break;
        result.append(str2);
        next += str1.length();
    }
    return (result);
}