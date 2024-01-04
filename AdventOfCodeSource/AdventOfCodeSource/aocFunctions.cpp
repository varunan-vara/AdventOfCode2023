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