#include "aocFunctions.h" // isThereAPart()

void dayThreeFunction() {
	std::ifstream dayThreeText;
	dayThreeText.open("dayThree.txt");

	std::vector<std::string> lines;
	std::string temp;

	while (std::getline(dayThreeText, temp)) {
		lines.push_back(temp);
	}

	int width = lines[0].size(), height = lines.size(), widthCounter = 0, heightCounter = 0;

	// Strategy for Part One: Go through each character, line by line, char by char
	// If the character is a number, analyze the values around it. If the value is not '.', it is a part. 
	// If it's neighbouring number is a number too, it should be analyzed as well.

	// if not a number, continue
	// 
	// if a number, check surrounding variables
	// if surrounding variables are not all '.' or numbers, it is a part: continue through loop until next variable 
	// is not a number
	// if surrounding variables are all '. or numbers', check if the next value is a number
	// if the next value is a number, redo the check from line 22
	// if the next variable is a '.', it is not a part


	int tempNum = 0;
	int sumOfPartNumbers = 0;
	while (heightCounter < height) {
		while (widthCounter < width) {
			if (lines[heightCounter][widthCounter] >= 48 && lines[heightCounter][widthCounter] <= 57) {             // is a number
				if (isThereAPart(lines, heightCounter, widthCounter, height, width)) {                              // there is a part
					while (lines[heightCounter][widthCounter] >= 48 && lines[heightCounter][widthCounter] <= 57) {
						tempNum = tempNum * 10;
						tempNum += (int)lines[heightCounter][widthCounter] - 48;
						widthCounter++;
					}
					sumOfPartNumbers += tempNum;
					tempNum = 0;

				}
				else {                                                                                              // is no part
					tempNum = tempNum * 10;
					tempNum += (int)lines[heightCounter][widthCounter] - 48;
					widthCounter++;
				}
			}
			else {                                                                                                  // is no number
				widthCounter++;
				tempNum = 0;
			}
		}
		widthCounter = 0; heightCounter++;
	}


	std::cout << "Sum of all part numbers: " << sumOfPartNumbers << std::endl;


	// Strategy for Part 2:
	// If a number is to the right or left of '*', that counts as one number always
	// If a number is directly to the bottom or top, that will always also count as one number always
	// If there is no number directly to the top or bottom, then each of the diagonls count as one additional number
	widthCounter = 0, heightCounter = 0;


	// std::cout << "2: " << adjacentPartNumbers(lines, 102, 51, height, width) << std::endl;


	std::vector<int> tempStore;
	int gearRatioSum = 0; 
	tempNum = 1;

	while (heightCounter < height) {
		while (widthCounter < width) {
			if (lines[heightCounter][widthCounter] != '*') {
				widthCounter++;
			}
			else {
				tempStore = adjacentPartNumbers(lines, heightCounter, widthCounter, height, width);
				if (tempStore[0] == 2) {
					for (int u = 1; u < 9; u++) {
						if (tempStore[u] != 0) {
							tempNum *= tempStore[u];
						}
					}
					gearRatioSum += tempNum;
					tempNum = 1;
				}


				widthCounter++;
			}


		}
		widthCounter = 0; heightCounter++;

	}

	std::cout << "Sum of all valid gear ratios: " << gearRatioSum << std::endl;
	
}