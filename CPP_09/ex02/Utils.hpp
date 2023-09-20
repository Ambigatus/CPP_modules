/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:25:28 by ddzuba            #+#    #+#             */
/*   Updated: 2023/09/20 18:01:16 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/* Colors */
# define DEFAULT "\033[0;39m"
# define B_RED "\033[1;31m"
# define B_BLUE "\033[1;94m"
# define B_YELLOW "\033[1;33m"
# define B_GREEN "\033[1;32m"
# define B_PINK "\033[1;35m"
# define B_TURQUOISE "\033[36;1m"
# define U_RED	"\e[4;31m"
# define U_BLUE	"\e[4;34m"
# define U_YELLOW	"\e[4;33m"
# define U_GREEN	"\e[4;32m"
# define U_PINK	"\e[4;35m"
# define U_TURQUOSIE	" \e[4;36m"


# define COUT	std::cout
# define CERR	std::cerr
# define ENDL	std::endl
# define STR	std::string
# define SET	std::set
# define LIST	std::list
# define DEQUE	std::deque
# define DIST	std::distance
# define LINE	"==****************************************************************=="

/* Errors */
# define ERR_ARGC			"ERROR: For sorting we need more than one element!"
# define ERR_POSITIVE		"ERROR: We can sort only positive numbers and not more than max int value!"
# define ERR_DUPLICATE		"ERROR: Duplicates are not allowed!"
# define ERR_NO_CONTAINER	"ERROR: Container is not aviable right now."
