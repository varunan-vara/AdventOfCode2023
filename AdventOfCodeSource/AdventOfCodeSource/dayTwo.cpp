#include "aocFunctions.h"

void dayTwoFunction() {
	std::ifstream dayTwoText;
	dayTwoText.open("dayTwo.txt");

	std::vector<std::string> lines;
	std::string temp;

	while (std::getline(dayTwoText, temp)) {
		lines.push_back(temp);
	}


	// Part One & Two

	// Assumption: It doesn't matter in which turn the elf pulls out the balls,
	// and with which other balls. It is as if he pulled each type of coloured ball
	// out one at a time
	int idSum = 0;
	int maxRed = 12, maxGreen = 13, maxBlue = 14;
	int powerSum = 0;
	for (int i = 0; i < lines.size(); i++) {

		// Split string at ':'
		// Assumption: Game IDs are in order

		// Index to keep track of character iterator in string
		int charIndex = 0;
		while (lines[i][charIndex] != ':') {
			charIndex++;
		}
		lines[i].erase(0, charIndex + 2);
		

		// Pattern: int string, int string ... int string; ...
		charIndex = 0;
		// List to store line contents
		std::vector<std::string> lineContents;
		std::string temp;
		for (int j = 0; j < lines[i].size(); j++) {
			if (lines[i][j] != ' ') {
				temp += lines[i][j];
			}
			else {
				lineContents.push_back(temp);
				temp = "";
			}
		}
		lineContents.push_back(temp);

		// Index to keep track of array item indexes
		int vectorIndex = 0;
		int intStore = 0; 


		// Part One while loop
		while (vectorIndex < lineContents.size()) {
			
			if (lineContents[vectorIndex][0] >= 48 && lineContents[vectorIndex][0] <= 57) {
				intStore = stoi(lineContents[vectorIndex]);
			}
			else {
				// String is a colour
				if (lineContents[vectorIndex][0] == 'r') {
					if (intStore > maxRed) {
						break;
					}
				}
				else if (lineContents[vectorIndex][0] == 'b') {
					if (intStore > maxBlue) {
						break;
					}
				}
				else if (lineContents[vectorIndex][0] == 'g') {
					if (intStore > maxGreen) {
						break;
					}
				}
			}


			vectorIndex++;
		}




		if (vectorIndex >= lineContents.size()) {
			idSum += i + 1;
		}


		// Part Two while loop
		vectorIndex = 0;
		int redNum = 0, blueNum = 0, greenNum = 0, tempNum = 0;
		while (vectorIndex < lineContents.size()) {
			tempNum = stoi(lineContents[vectorIndex]);
			vectorIndex++;

			if (lineContents[vectorIndex][0] == 'r') {
				if (redNum < tempNum) {
					redNum = tempNum;
				}
			}
			if (lineContents[vectorIndex][0] == 'b') {
				if (blueNum < tempNum) {
					blueNum = tempNum;
				}
			}
			if (lineContents[vectorIndex][0] == 'g') {
				if (greenNum < tempNum) {
					greenNum = tempNum;
				}
			}

			vectorIndex++;
		}

		powerSum += (redNum * blueNum * greenNum);
	}

	std::cout << "Sum of IDs whose games are possible: " << idSum << std::endl;
	std::cout << "Sum of Powers of all sets: " << powerSum << std::endl;

}