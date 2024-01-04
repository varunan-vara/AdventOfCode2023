#include "aocFunctions.h"

void dayOneFunction() {
	std::ifstream dayOneText;
	dayOneText.open("dayOne.txt");

	std::vector<std::string> lines;
	std::string temp;

	while (std::getline(dayOneText, temp)) {
		lines.push_back(temp);
	}

	// Strategy: Loop over each line. In each line, loop over each charcter. Identify first and last digit char
	int digitSum = 0;
	for (int i = 0; i < lines.size(); i++) {
		std::vector<int> digits;
		for (char& c : lines[i]) {
			if (c >= 48 && c <= 57) {
				digits.push_back(int(c) - 48);
			}
		}
		// Calculate Calibration Value
		digitSum += (digits[0] * 10) + digits[digits.size() - 1];
		// std::cout << (digits[0] * 10) + digits[digits.size() - 1] << std::endl;
	}
	std::cout << "Part One: Sum of Calibration Values: " << digitSum << std::endl;



	// Strategy: Split each line into substrings, ones with digits and characters
	// Then, individually check if each substring has digit or written numbers
	int newDigitSum = 0; // reset digitSum
	for (int j = 0; j < lines.size(); j++) {
		std::vector<std::string> lineSubStrings;



		// Splitting into substrings
		int x = 0; std::string temp = "";
		while (x < lines[j].size()) {
			if (lines[j][x] >= 48 && lines[j][x] <= 57) {
				temp += lines[j][x];
				lineSubStrings.push_back(temp);
				temp = "";
				x++;
			}
			else if (lines[j][x] >= 97 && lines[j][x] <= 122) {
				while (lines[j][x] >= 97 && lines[j][x] <= 122) {
					temp += lines[j][x];
					x++;
				}
				lineSubStrings.push_back(temp);
				temp = "";
			}
		}

		std::cout << lines[j] << std::endl;

		for (int o = 0; o < lineSubStrings.size(); o++) {
			std::cout << lineSubStrings[o] << ", ";
		}
		std::cout << std::endl;
		
		std::map<std::string, int> characterToInt = {
			{"one",   1},
			{"two",   2},
			{"three", 3},
			{"four",  4},
			{"five",  5},
			{"six",   6},
			{"seven", 7},
			{"eight", 8},
			{"nine",  9}
		};


		// Filter through objects in order until a number is found for the first digit
		int firstDigit = 0, lastDigit = 0;
		for (int shdhfb = 0; shdhfb < 100000; shdhfb ++) { // Ensuring there is no infinite loop, random variable
			if (lineSubStrings[0][0] <= 57) {
				firstDigit = ((int)lineSubStrings[0][0] - 48);
				lineSubStrings.erase(lineSubStrings.begin());
				break;
			}
			else {
				int posOfCurrentKnownDigit = lineSubStrings[0].size() + 1;
				int currentDigit = 0;
				for (auto& x : characterToInt) {
					if ( lineSubStrings[0].find(x.first) != std::string::npos && 
						lineSubStrings[0].find(x.first) < posOfCurrentKnownDigit) {
						posOfCurrentKnownDigit = lineSubStrings[0].find(x.first);
						currentDigit = x.second;
					}
				}
				if (posOfCurrentKnownDigit != lineSubStrings[0].size() + 1) {
					firstDigit = (currentDigit);
					lineSubStrings.erase(lineSubStrings.begin());
					break;
				}
				else {
					lineSubStrings.erase(lineSubStrings.begin());
				}
			}
		}

		// Filter from rear to find the last digit
		for (int shdhfb = 0; shdhfb < 100000; shdhfb++) {
			if (lineSubStrings.size() <= 0) {
				lastDigit = 0;
				firstDigit = firstDigit;
				break;
			}
			std::string lastValue = lineSubStrings[lineSubStrings.size() - 1];			
			if (lastValue[0] <= 57) {
				lastDigit = ((int)lastValue[0] - 48);
				break;
			}
			else {
				int posOfCurrentKnownDigit = 0;
				int currentDigit = 0;
				for (auto& x : characterToInt) {
					if (lastValue.find(x.first) != std::string::npos &&
						lastValue.find(x.first) >= posOfCurrentKnownDigit) {
						posOfCurrentKnownDigit = lastValue.find(x.first);
						currentDigit = x.second;
					}
				}
				if (currentDigit != 0) {
					lastDigit = (currentDigit);
					break;
				}
				else {
					lineSubStrings.pop_back();
				}
			}
		}
		std::cout << (firstDigit * 10 + lastDigit) << std::endl;
		newDigitSum += (firstDigit * 10 + lastDigit);
	}

	std::cout << "Part Two: Sum of Calibration Values: " << newDigitSum << std::endl;
}