/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 16:28:41 by ddzuba            #+#    #+#             */
/*   Updated: 2023/08/09 15:09:57 by ddzuba           ###   ########.fr       */
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
# define COUT std::cout
# define CERR std::cerr
# define ENDL std::endl
# define STR  std::string
# define ERR_SUM			"ERROR: Not enough operands for the '+' operator!"
# define ERR_SUBS			"ERROR: Not enough operands for the '-'operator!"
# define ERR_MULT			"ERROR: Not enough operands for the '*' operator!"
# define ERR_DIV			"ERROR: Not enough operands for the '/' operator!"
# define ERR_ZERO			"ERROR: HOW DARE YOU TRYING DIVIDE BY ZERO?!"
# define ERR_INPUT			"ERROR: Invalid input element!"
# define ERR_NUMBER			"ERROR: Allowed numbers are between -9 and 9!"
# define ERR_OPERATORS		"ERROR: Not enough operators!"
# define ERR_ARGS			"ERROR: Only a string of operations allowed!"
# define EXAMPLE			"Example: ./RPN  5 3 4 + *"