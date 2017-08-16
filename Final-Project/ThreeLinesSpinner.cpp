#include <iostream>

#include "ThreeLinesSpinner.h"

ThreeLinesSpinner::ThreeLinesSpinner()
	:Spinner("Three Lines Spinner", "A spinner consists of 3 lines")
{
	this->initializeSpinner();
}

ThreeLinesSpinner::~ThreeLinesSpinner(){}

void ThreeLinesSpinner::initializeSpinner() {
	char spinnerRepresentation[SPINNER_LENGTH][SPINNER_LENGTH] = {
		' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', '*', 'O', '*', ' ', ' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', '*', ' ', '*', ' ', ' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', '*', ' ', '*', ' ', ' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', '*', ' ', '*', ' ', ' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', '*', ' ', '*', ' ', ' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', '*', 'O', '*', ' ', ' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' ', '*', ' ', '*', ' ', '*', ' ', ' ', ' ', ' ',
		' ', ' ', ' ', '*', ' ', '*', ' ', '*', ' ', '*', ' ', ' ', ' ',
		' ', ' ', '*', ' ', '*', ' ', ' ', ' ', '*', ' ', '*', ' ', ' ',
		' ', '*', 'O', '*', ' ', ' ', ' ', ' ', ' ', '*', 'O', '*', ' ',
		' ', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', ' ',
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '
	};

	for (int i = 0; i < SPINNER_LENGTH; i++){
		for (int j = 0; j < SPINNER_LENGTH; j++){
			this->spinnerRepresentation[i][j] = spinnerRepresentation[i][j];
		}
	}
}
