/****************************************************************************
**
**Joshua Snyder
**Roman Numerals
**Total time taken:3 hours 47 minutes
**
****************************************************************************/
#include<iostream>
#include<sstream>
#include<vector>

std::string convertNumerals(std::string entry) {
	std::string result = "Invalid Character.";
	int length = entry.length();
	std::vector<int> data;

	//Step 1
	//Extract the Data and convert into their decimal forms
	std::string tempVal;
	for (int i = 0; i < length; i++) {
		tempVal = entry.at(i);
		if (tempVal == "I" || tempVal == "i") {
			data.push_back(1);
		}
		else if (tempVal == "V" || tempVal == "v") {
			data.push_back(5);
		}
		else if (tempVal == "X" || tempVal == "x") {
			data.push_back(10);
		}
		else if (tempVal == "L" || tempVal == "l") {
			data.push_back(50);
		}
		else if (tempVal == "C" || tempVal == "c") {
			data.push_back(100);
		}
		else if (tempVal == "D" || tempVal == "d") {
			data.push_back(500);
		}
		else if (tempVal == "M" || tempVal == "m") {
			data.push_back(1000);
		}
		else {
			return result;
		}
	}

	//Step 2
	//Error Checking
	//Each if statement only goes off if it equals the appropriate value and it has a number before it
	//Returns if the order is incorrect
	for (int i = 0; i < length; i++) {
		//Error checking for 10
		if (data[i] == 10 && i != 0) {
			if (data[i - 1] == 5) {
				result = "Invalid Ordering";
				return result;
			}
		}
		//Error Checking for 50
		if (data[i] == 50 && i != 0) {
			if (data[i - 1] == 5 || data[i - 1] == 1 || data[i - 1] == 50) {
				result = "Invalid Ordering";
				return result;
			}
		}
		//Error checking for 100
		if (data[i] == 100 && i != 0) {
			if (data[i - 1] == 1 || data[i - 1] == 5 || data[i - 1] == 50) {
				result = "Invalid Ordering";
				return result;
			}
		}
		//Error checking for 500
		if (data[i] == 1000 && i != 0) {
			if (data[i - 1] == 1 || data[i - 1] == 5 || data[i - 1] == 50 || data[i - 1] == 10 || data[i - 1] == 500) {
				result = "Invalid Ordering";
				return result;
			}
		}
		//Error checking for 1000
		if (data[i] == 1000 && i != 0) {
			if (data[i - 1] == 1 || data[i - 1] == 5 || data[i - 1] == 50 || data[i - 1] == 10 || data[i - 1] == 500) {
				result = "Invalid Ordering";
				return result;
			}
		}
	}

	//Step 3
	//Calculation
	int finalCount = 0;
	for (int i = 0; i < length; i++) {
		//If we haven't reached the last number yet
		if (i != (length - 1)) {
			//if the current number is smaller than the next number
			if (data[i] < data[i + 1]) {
				finalCount += (data[i + 1] - data[i]);
				i++;
			}
			else {
				finalCount += data[i];
			}
		}
		else {
			finalCount += data[i];
		}
	}
	//Convert to int
	result = std::to_string(finalCount);
	return result;
}

std::string convertInt(std::string entry) {
	std::string result = "Invalid Entry";
	//Convert back into a int
	std::stringstream convert(entry);
	int numeral = 0;
	convert >> numeral;

	//Error checking
	if (numeral >= 4000 || numeral <= 0) {
		result = "Decimal number out of range.";
		return result;
	}

	//Unique Values values
	int values[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
	std::string symbol[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
	std::ostringstream compiler;


	for (int i = 0; numeral != 0; i++) {
		//first base value that divides num is the one we want to start with
		while (numeral / values[i]) {  
			//Add symbol to ostringstream
			compiler << symbol[i];  
			//Reduce the value by the symbol's value
			numeral -= values[i];
		}
	}
	//Stringify the compiler
	result = compiler.str();
	return result;
}

int main(void) {
	//Welcome Statement
	std::cout << "Welcome to Roman Numeral to Decimal and vice versa translator" << std::endl << std::endl;
	bool cont = true;


	//Select which translation you will be doing today
	std::cout << "Enter r if you want to translate roman numerals to a decimal number (III->3)" << std::endl;
	std::cout << "Enter d if you want to translate a decimal number to roman numerals (3->III)" << std::endl;
	std::cout << "Enter q if you want to Quit" << std::endl;
	std::string option = "null";

	//Run continously to continue translating
	while (cont == true) {
		//Allow the user to select what translation they want
		if (option == "null") {
			std::cout << "Enter h if you want to see the options again" << std::endl;
			std::cout << "Entry: ";
			std::cin >> option;
		}
		else if (option == "r") {
			std::cout << "Enter the roman numerals in one statement without spaces." << std::endl;
			std::cout << "Capitlization does not matter." << std::endl;
			std::cout << "Please enter the roman numerals you would like converted: ";
			
			std::string numerals;
			//Enter result to be converted
			std::cin >> numerals;
			//Get conversion
			std::string result = convertNumerals(numerals);

			//Print results
			std::cout << std::endl << "Roman Numeral: " << numerals << " = Decimal Number: " << result << std::endl << std::endl;
			option = "null";
		}
		else if (option == "d") {
			//FIX ME put in a throw and catch here in case the entry is way out there
			std::cout << "Please refrain from entering multiple numbers, commas, or decimal numbers." << std::endl;
			std::cout << "Also please go no higher than 3,999 or lower than 1" << std::endl;
			std::cout << "Please enter the decimal number you would like converted: ";
			
			std::string decimal;
			//Enter result to be converted
			std::cin >> decimal;
			//Get conversion
			std::string result = convertInt(decimal);
			
			//Print results
			std::cout << std::endl << "Decimal Number: " << decimal << " = Roman Numeral: " << result << std::endl << std::endl;
			option = "null";
		}
		else if (option == "q") {
			cont = false;
		}
		else if (option == "h") {
			//Reprint options in case you have forgotten
			std::cout << "Enter r if you want to translate roman numerals to decimal numbers (III->3)" << std::endl;
			std::cout << "Enter d if you want to translate decimal numbers to roman numeral (3->III)" << std::endl;
			std::cout << "Enter q if you want to Quit" << std::endl;
			option = "null";
		}
		else {
			//Error handling
			std::cout << "You have entered an invalid response" << std::endl;
			option = "null";
		}
	}
}