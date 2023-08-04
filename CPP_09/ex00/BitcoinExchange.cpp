/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:13:42 by hboichuk          #+#    #+#             */
/*   Updated: 2023/08/04 20:36:38 by hboichuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
//ortodox construction
BitcoinExchange::BitcoinExchange()
{
	std::cout << "BitcoinExchange: Default constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy)
{
	std::cout << "BitcoinExchange: Copy constructor called" << std::endl;
	*this = copy;
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const &copy) {
	std::cout << "BitcoinExchange: operator= called" << std::endl;
    // Step 1: Check for self-assignment
    if (this == &copy) {
        return *this; // Return *this to support chained assignments
    }
    // Step 2: Copy the data from the source object (copy) to the current object (*this)
    value = copy.value;
    // Step 3: Return the reference to the current object
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "BitcoinExchange: Destructor called" << std::endl;
}

//getter and setter

double BitcoinExchange::getValue(const std::string& date) const 
{
	std::map<std::string, double>::const_iterator it = value.lower_bound(date);
	if (it == value.end()) {
		return 0.0; 
	}

	if (it != value.begin() && it->first != date) {
		--it; 
	}

	return it->second;
}

void BitcoinExchange::setValue(const std::string& date, double rate) 
{
	value[date] = rate;
}

const std::map<std::string, double>& BitcoinExchange::getValue() const 
{
	return value;
}

//checkers and other helpers
void	checkFile(void)
{
	std::ifstream dataFile("data.csv");
	if (!dataFile) {
		std::cerr << "Error: could not open data file." << std::endl;
		exit(1);
	}
}