#include "aocFunctions.h"

int numberOfLines(std::ifstream& inputFile) {
	int count = 0;
	if (inputFile.is_open()) {
		std::string temp;

		while (std::getline(inputFile, temp)) {
			count++;
		}
	}
	return count;
}


bool isThereAPart(std::vector<std::string> schematic, int height, int width, int maxHeight, int maxWidth) {
	bool returnbool = false;
	// Left
	if (width > 0) {
		if (schematic[height][width - 1] != '.' && (schematic[height][width - 1] < 48 || schematic[height][width - 1] > 57)) {
			returnbool = true;
		}
	}
	// Right
	if (width < maxWidth - 1) {
		if (schematic[height][width + 1] != '.' && (schematic[height][width + 1] < 48 || schematic[height][width + 1] > 57)) {
			returnbool = true;
		}
	}
	// Top
	if (height > 0) {
		if (schematic[height - 1][width] != '.' && (schematic[height - 1][width] < 48 || schematic[height - 1][width] > 57)) {
			returnbool = true;
		}
	}
	// Bottom
	if (height < maxHeight - 1) {
		if (schematic[height + 1][width] != '.' && (schematic[height + 1][width] < 48 || schematic[height + 1][width] > 57)) {
			returnbool = true;
		}
	}
	// Top Left
	if (width > 0 && height > 0) {
		if (schematic[height - 1][width - 1] != '.' && (schematic[height - 1][width - 1] < 48 || schematic[height - 1][width - 1] > 57)) {
			returnbool = true;
		}
	}
	// Top Right
	if (width < maxWidth - 1 && height > 0) {
		if (schematic[height - 1][width + 1] != '.' && (schematic[height - 1][width + 1] < 48 || schematic[height - 1][width + 1] > 57)) {
			returnbool = true;
		}
	}
	// Bottom Left
	if (width > 0 && height < maxHeight - 1) {
		if (schematic[height + 1][width - 1] != '.' && (schematic[height + 1][width - 1] < 48 || schematic[height + 1][width - 1] > 57)) {
			returnbool = true;
		}
	}
	// Bottom Right
	if (width < maxWidth - 1 && height < maxHeight - 1) {
		if (schematic[height + 1][width + 1] != '.' && (schematic[height + 1][width + 1] < 48 || schematic[height + 1][width + 1] > 57)) {
			returnbool = true;
		}
	}


	return returnbool;
}


std::vector<int> adjacentPartNumbers(std::vector<std::string> schematic, int height, int width, int maxHeight, int maxWidth) {

	// Index returns
	// 0 = number
	// 1 2 3
	// 4 * 5
	// 6 7 8
	//
	std::vector<int> partNumberCounter { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int tempHeight, tempWidth, tempMult;

	// Left
	if (width > 0) {
		if (schematic[height][width - 1] >= 48 && schematic[height][width - 1] <= 57) {
			partNumberCounter[0]++;

			// Calculate the part number by going down in width
			tempHeight = height, tempWidth = width - 1, tempMult = 1;
			while (tempWidth >= 0 && schematic[tempHeight][tempWidth] >= 48 && schematic[tempHeight][tempWidth] <= 57) {
				partNumberCounter[4] += (int) (schematic[tempHeight][tempWidth] - 48) * tempMult;
				tempMult *= 10;
				tempWidth--;
			}

		}
	}
	// Right
	if (width < maxWidth - 1) {
		if (schematic[height][width + 1] >= 48 && schematic[height][width + 1] <= 57) {
			partNumberCounter[0]++;

			// Calculate the part number by going up in width
			tempHeight = height, tempWidth = width + 1; //tempMult = 1;
			while (tempWidth < maxWidth && schematic[tempHeight][tempWidth] >= 48 && schematic[tempHeight][tempWidth] <= 57) {
				partNumberCounter[5] *= 10;
				partNumberCounter[5] += (int)(schematic[tempHeight][tempWidth] - 48);
				tempWidth++;
			}
		}
	}
	// Top
	if (height > 0) {
		if (schematic[height - 1][width] >= 48 && schematic[height - 1][width] <= 57) {
			partNumberCounter[0]++;
			// Calculate the part number by going down in width
			tempHeight = height - 1, tempWidth = width, tempMult = 1;
			while (tempWidth >= 0 && schematic[tempHeight][tempWidth] >= 48 && schematic[tempHeight][tempWidth] <= 57) {
				partNumberCounter[2] += (int)(schematic[tempHeight][tempWidth] - 48) * tempMult;
				tempMult *= 10;
				tempWidth--;
			}
			// Calculate the part number by going up in width
			tempHeight = height - 1, tempWidth = width + 1; //tempMult = 1;
			while (tempWidth < maxWidth && schematic[tempHeight][tempWidth] >= 48 && schematic[tempHeight][tempWidth] <= 57) {
				partNumberCounter[2] *= 10;
				partNumberCounter[2] += (int)(schematic[tempHeight][tempWidth] - 48);
				tempWidth++; 
			}
			
		}
		else {
			// Top Left
			if (width > 0 && height > 0) {
				if (schematic[height - 1][width - 1] >= 48 && schematic[height - 1][width - 1] <= 57) {
					partNumberCounter[0]++;
					// Calculate the part number by going down in width
					tempHeight = height - 1, tempWidth = width - 1, tempMult = 1;
					while (tempWidth >= 0 && schematic[tempHeight][tempWidth] >= 48 && schematic[tempHeight][tempWidth] <= 57) {
						partNumberCounter[1] += (int)(schematic[tempHeight][tempWidth] - 48) * tempMult;
						tempMult *= 10;
						tempWidth--;
					}
				}
			}
			// Top Right
			if (width < maxWidth - 1 && height > 0) {
				if (schematic[height - 1][width + 1] >= 48 && schematic[height - 1][width + 1] <= 57) {
					partNumberCounter[0]++;
					// Calculate the part number by going up in width
					tempHeight = height - 1, tempWidth = width + 1; //tempMult = 1;
					while (tempWidth < maxWidth && schematic[tempHeight][tempWidth] >= 48 && schematic[tempHeight][tempWidth] <= 57) {
						partNumberCounter[3] *= 10;
						partNumberCounter[3] += (int)(schematic[tempHeight][tempWidth] - 48);
						tempWidth++;
					}
				}
			}
		}
	}
	// Bottom
	if (height < maxHeight - 1) {
		if (schematic[height + 1][width] >= 48 && schematic[height + 1][width] <= 57) {
			partNumberCounter[0]++;
			// Calculate the part number by going down in width
			tempHeight = height + 1, tempWidth = width, tempMult = 1;
			while (tempWidth >= 0 && schematic[tempHeight][tempWidth] >= 48 && schematic[tempHeight][tempWidth] <= 57) {
				partNumberCounter[7] += (int)(schematic[tempHeight][tempWidth] - 48) * tempMult;
				tempMult *= 10;
				tempWidth--;
			}
			// Calculate the part number by going up in width
			tempHeight = height + 1, tempWidth = width + 1; //tempMult = 1;
			while (tempWidth < maxWidth && schematic[tempHeight][tempWidth] >= 48 && schematic[tempHeight][tempWidth] <= 57) {
				partNumberCounter[7] *= 10;
				partNumberCounter[7] += (int)(schematic[tempHeight][tempWidth] - 48);
				tempWidth++;
			}
		}
		else {
			// Bottom Left
			if (width > 0 && height < maxHeight - 1) {
				if (schematic[height + 1][width - 1] >= 48 && schematic[height + 1][width - 1] <= 57) {
					partNumberCounter[0]++;
					// Calculate the part number by going down in width
					tempHeight = height + 1, tempWidth = width - 1, tempMult = 1;
					while (tempWidth >= 0 && schematic[tempHeight][tempWidth] >= 48 && schematic[tempHeight][tempWidth] <= 57) {
						partNumberCounter[6] += (int)(schematic[tempHeight][tempWidth] - 48) * tempMult;
						tempMult *= 10;
						tempWidth--;
					}
				}
			}
			// Bottom Right
			if (width < maxWidth - 1 && height < maxHeight - 1) {
				if (schematic[height + 1][width + 1] >= 48 && schematic[height + 1][width + 1] <= 57) {
					partNumberCounter[0]++;
					// Calculate the part number by going up in width
					tempHeight = height + 1, tempWidth = width + 1; //tempMult = 1;
					while (tempWidth < maxWidth && schematic[tempHeight][tempWidth] >= 48 && schematic[tempHeight][tempWidth] <= 57) {
						partNumberCounter[8] *= 10;
						partNumberCounter[8] += (int)(schematic[tempHeight][tempWidth] - 48);
						tempWidth++;
					}
				}
			}
		}
	}




	return partNumberCounter;
}