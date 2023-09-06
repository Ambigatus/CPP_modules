/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:03:55 by hboichuk          #+#    #+#             */
/*   Updated: 2023/09/06 18:54:10 by hboichuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	Data *data = new Data;

    data->name = "Hanna";
    data->age = 29;

    std::cout << "// WITHOUT ANY FUNCTIONS //" << std::endl;
    std::cout <<    "Address: " << &data << std::endl <<
                    "Content: " << data->age << "  " << data->name << std::endl;
    std::cout << std::endl;

	std::cout << "// SERIALIZED FUNCTION //" << std::endl;
    uintptr_t test = Serializer::serialize(data);
    std::cout <<    "Address: " << &test << std::endl <<
                    "Content: " << test << std::endl;
    std::cout << std::endl;

    std::cout << "// DESERIALIZED FUNCTION //" << std::endl;
    Data *data2 = new Data;
    data2 = Serializer::deserialize(test);
    std::cout <<    "Address: " << &data2 << std::endl <<
                    "Content: " << data2->age << "  " << data2->name << std::endl;
    std::cout << std::endl;

    delete data;
    return EXIT_SUCCESS;
}