#include <iostream>
#include <conio.h>
#include <string>
#include <math.h>
#include <thread>
#include <Windows.h>

#include "Game.h"
#include "Spinner.h"
#include "Instructions.h"
#include "ColorMap.h"
#include "Utils.h"

using namespace std;

#define KEY_UP  72
#define KEY_DOWN  80
#define KEY_LEFT  75
#define KEY_RIGHT  77
#define KEY_SPACE  32

#define SPINNING_TIMEOUT_DEFAULT 150
#define TITLE_NUMBER_OF_LINES 2
#define NUMBER_OF_INSTRUCTIONS_LINES 7

Game::Game(Spinner spinner) {
	this->gameInsturctions = *(new Instructions());
	this->spinningTimeout = SPINNING_TIMEOUT_DEFAULT;
	this->isSpinning = true;	
	this->spinner = spinner;
	this->colorMap = (*new ColorMap());

	this->setCursor(TITLE_NUMBER_OF_LINES);
	this->gameInsturctions.print();

	thread bt(&Game::play, this);

	this->handleKeyboardEvents();

	bt.join();
}

Game::~Game(){
	delete &(this->gameInsturctions);
	delete &(this->spinner);
	delete &(this->colorMap);
}

void Game::play(){
	while (true){
		std::this_thread::sleep_for(std::chrono::milliseconds(spinningTimeout));
		if (this->isSpinning){						
			this->spinner.spin();
			this->setCursor(TITLE_NUMBER_OF_LINES + NUMBER_OF_INSTRUCTIONS_LINES);			
			this->spinner.print();
		}
	}
}

void Game::stopSpinning() {
	while (this->spinningTimeout < 1000){
		this->spinningTimeout += 10;
	}

	this->isSpinning = false;
}

void Game::startSpinning() {
	this->spinningTimeout = SPINNING_TIMEOUT_DEFAULT;
	isSpinning = true;
}

void Game::handleKeyboardEvents(){
	INPUT_RECORD InRec;
	DWORD NumRead;
	HANDLE hIn;

	hIn = GetStdHandle(STD_INPUT_HANDLE);

	ReadConsoleInput(hIn,
		&InRec,
		1,
		&NumRead);

	int c = 0;
	while (true){
		c = 0;

		switch ((c = _getch())) {
		case KEY_UP:
			this->spinningTimeout -= 10;
			break;
		case KEY_DOWN:
			this->spinningTimeout += 10;
			break;
		case KEY_LEFT:
			this->spinner.setDirection(LEFT_DIRECTION);
			break;
		case KEY_RIGHT:
			this->spinner.setDirection(RIGHT_DIRECTION);
			break;
		case KEY_SPACE:
			if (this->isSpinning) {
				this->stopSpinning();
			} else {
				this->startSpinning();
			}
			break;
		case R_BUTTON:
			Utils::setConsoleColor(this->colorMap.getColor(R_BUTTON));
			break;
		case G_BUTTON:
			Utils::setConsoleColor(this->colorMap.getColor(G_BUTTON));
			break;
		case B_BUTTON:
			Utils::setConsoleColor(this->colorMap.getColor(B_BUTTON));
			break;
		case Y_BUTTON:
			Utils::setConsoleColor(this->colorMap.getColor(Y_BUTTON));
			break;
		case W_BUTTON:
			Utils::setConsoleColor(this->colorMap.getColor(W_BUTTON));
			break;
		default:
			break;
		}
	}
}

void Game::setCursor(int line){
	HANDLE hOut;
	COORD KeyWhere;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	KeyWhere.X = 0;
	KeyWhere.Y = line;

	SetConsoleCursorPosition(hOut,
		KeyWhere);
}