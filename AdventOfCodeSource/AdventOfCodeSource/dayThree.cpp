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



}