/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:13:42 by hboichuk          #+#    #+#             */
/*   Updated: 2023/09/16 16:42:07 by hboichuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
//ortodox construction
BitcoinExchange::BitcoinExchange()
{
	// std::cout << "BitcoinExchange: Default constructor called" << std::endl;
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
	// std::cout << "BitcoinExchange: Destructor called" << std::endl;
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
// 88?
void	startExchange(std::string _file)
{
	std::ifstream dataFile("data.csv");
	checkFile(dataFile);
	
	BitcoinExchange exchange;
	std::string dataLine;
	// Skip the header line in data.csv
	std::getline(dataFile, dataLine);
	while (std::getline(dataFile, dataLine)) {
		std::istringstream dataIss(dataLine);
		std::string date;
		double rate;

		if (std::getline(dataIss, date, ',') && dataIss >> rate) {
			exchange.setValue(date, rate);
		} else {
			std::cerr << "Error: invalid data exchange rate => " << dataLine << std::endl;
		}
	}

	// Read the input file (input.txt)
	std::ifstream inputFile(_file.c_str());
	if (!inputFile) {
		std::cerr << "Error: could not open input file." << std::endl;
		exit(0);
	}

	std::string inputLine;
	bool firstLine = true;
	while (std::getline(inputFile, inputLine)) {
		// Skip the header line in input.txt
		if (firstLine) {
			firstLine = false;
			continue;
		}

		std::istringstream inputIss(inputLine);
		std::string dateStr, valueStr;
		if (std::getline(inputIss, dateStr, '|') && std::getline(inputIss, valueStr)) {
			std::string date = dateStr;
			std::string::size_type pos = valueStr.find_first_not_of(" ");
			if (pos != std::string::npos) {
				valueStr = valueStr.substr(pos);
			}

			double value;
			std::istringstream valueIss(valueStr);
			if (!(valueIss >> value)) {
				std::cerr << "Error: invalid input value on line " << inputLine << std::endl;
				continue;
			}

			if (value <= 0) {
				std::cerr << "Error: not a positive number." << std::endl;
				continue;
			}

			double exchangeRate = exchange.getValue(date);
			if (exchangeRate == 0.0) {
				// Find the closest date in the data file
				std::map<double, double> dateToRate;
				for (std::map<std::string, double>::const_iterator it = exchange.getValue().begin(); \
					it != exchange.getValue().end(); ++it) {
					double dataDate = std::stod(it->first);
					if (dataDate < std::stod(date)) {
						dateToRate[std::stod(date) - dataDate] = it->second;
					}
				}

				if (dateToRate.empty()) {
					std::cerr << "Error: no exchange rate found for date " << date << " on line " << inputLine << std::endl;
					continue;
				}

				exchangeRate = dateToRate.begin()->second;
			}

			if (std::abs(value) > 1000) {
				std::cerr << "Error: too large a number." << std::endl;
			} else {
				double bitcoinValue = value * exchangeRate;
				if (value == static_cast<int>(value)) {
        			std::cout << date << " => " << value << " = " << std::setprecision(2) << bitcoinValue << std::endl;
    			} else {
					std::cout << date << " => " << value << " = " << std::fixed << std::setprecision(2) << bitcoinValue << std::endl;
    			}
			}
		} else {
			std::cerr << "Error: bad input => " << inputLine << std::endl;
		}
	}
}

void	checkFile(std::ifstream& dataFile)
{
	if (!dataFile) {
		std::cerr << "Error: could not open data file." << std::endl;
		exit(1);
	}
}

