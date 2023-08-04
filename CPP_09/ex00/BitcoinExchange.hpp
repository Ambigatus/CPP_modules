/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:13:53 by hboichuk          #+#    #+#             */
/*   Updated: 2023/08/04 20:03:08 by hboichuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cmath>
#include <iomanip>

class BitcoinExchange 
{
	private:
	//container-map for our data from file
	std::map<std::string, double> value;
	
	public:
	//ortodox canonical style
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &copy);
		BitcoinExchange &operator=(BitcoinExchange const &copy);
	//getter and setter
	//give you access to our private member
		double	getValue(const std::string& date) const;
	// This function allows you to add an exchange rate for a specific date to the our map.
		void	setValue(const std::string& date, double rate);
	//This function allows you to get access to the entire map of exchange rates
		const	std::map<std::string, double>& getValue() const;
	 
};

#endif