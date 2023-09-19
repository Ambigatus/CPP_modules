/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:25:28 by ddzuba            #+#    #+#             */
/*   Updated: 2023/09/19 18:44:38 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# define DEFAULT "\033[0;39m"
# define B_RED "\033[1;31m"
# define B_BLUE "\033[1;94m"
# define B_YELLOW "\033[1;33m"
# define B_GREEN "\033[1;32m"
# define B_PINK "\033[1;35m"
# define B_PURPURE "\033[1;35m"
# define B_TURQUOISE "\033[36;1m"
# define COUT	std::cout
# define CERR	std::cerr
# define ENDL	std::endl
# define STR	std::string
# define SET	std::set
# define LIST	std::list
# define DEQUE	std::deque
# define DIST	std::distance

/* Errors */
# define ERR_ARGC			"ERROR: For sorting we need more than one element!"
# define ERR_POSITIVE		"ERROR: We can sort only positive numbers!"
# define ERR_DUPLICATE		"ERROR: Duplicates are not allowed!"
# define ERR_NO_CONTAINER	"ERROR: Container is not aviable right now."
