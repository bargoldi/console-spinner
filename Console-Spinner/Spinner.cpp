#include <iostream>
#include <string>
#include <Windows.h>

#include "Spinner.h"

using namespace std;

Spinner::Spinner(){}

Spinner::Spinner(const Spinner & spinner){
	this->description = spinner.description;
	this->direction = spinner.direction;
	this->name = spinner.name;

	for (int i = 0; i < SPINNER_LENGTH; i++){
		for (int j = 0; j < SPINNER_LENGTH; j++){
			this->spinnerRepresentation[i][j] = spinner.spinnerRepresentation[i][j];
		}
	}
}

Spinner::Spinner(string spinnerName, string spinnerDescription)
{
	this->direction = RIGHT_DIRECTION;
	this->name = spinnerName;
	this->description = spinnerDescription;	
}


Spinner::~Spinner(){}

void Spinner::operator=(const Spinner& spinner){
	this->description = spinner.description;
	this->direction = spinner.direction;
	this->name = spinner.name;

	for (int i = 0; i < SPINNER_LENGTH; i++){
		for (int j = 0; j < SPINNER_LENGTH; j++){
			this->spinnerRepresentation[i][j] = spinner.spinnerRepresentation[i][j];
		}
	}
}

void Spinner::spin() {
	if (this->direction == LEFT_DIRECTION){
		this->spinLeft();
	} else{
		this->spinRight();
	}
}

void Spinner::print() {
	for (int i = 0; i < SPINNER_LENGTH; i++){
		cout << endl;
		for (int j = 0; j < SPINNER_LENGTH; j++){
			cout << this->spinnerRepresentation[i][j];
		}
	}
}

void Spinner::setDirection(int direction) {
	if (direction == RIGHT_DIRECTION || direction == LEFT_DIRECTION) {
		this->direction = direction;
	}
}

void Spinner::spinLeft(){
	int tmp;

	for (int i = 0; i < SPINNER_LENGTH / 2; i++)
	{
		for (int j = i; j < SPINNER_LENGTH - i - 1; j++)
		{
			tmp = this->spinnerRepresentation[SPINNER_LENGTH - j - 1][i];
			this->spinnerRepresentation[SPINNER_LENGTH - j - 1][i] = this->spinnerRepresentation[SPINNER_LENGTH - i - 1][SPINNER_LENGTH - j - 1];
			this->spinnerRepresentation[SPINNER_LENGTH - i - 1][SPINNER_LENGTH - j - 1] = this->spinnerRepresentation[j][SPINNER_LENGTH - i - 1];
			this->spinnerRepresentation[j][SPINNER_LENGTH - i - 1] = this->spinnerRepresentation[i][j];
			this->spinnerRepresentation[i][j] = tmp;
		}
	}
}

void Spinner::spinRight(){
	int tmp;
	for (int i = 0; i < SPINNER_LENGTH / 2; i++)
	{
		for (int j = i; j < SPINNER_LENGTH - i - 1; j++)
		{
			tmp = this->spinnerRepresentation[i][j];
			this->spinnerRepresentation[i][j] = this->spinnerRepresentation[j][SPINNER_LENGTH - i - 1];
			this->spinnerRepresentation[j][SPINNER_LENGTH - i - 1] = this->spinnerRepresentation[SPINNER_LENGTH - i - 1][SPINNER_LENGTH - j - 1];
			this->spinnerRepresentation[SPINNER_LENGTH - i - 1][SPINNER_LENGTH - j - 1] = this->spinnerRepresentation[SPINNER_LENGTH - j - 1][i];
			this->spinnerRepresentation[SPINNER_LENGTH - j - 1][i] = tmp;
		}
	}
}

void Spinner::initializeSpinner(){
}