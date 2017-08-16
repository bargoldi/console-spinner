#ifndef GAME_HEADER
#define GAME_HEADER

#include <iostream>

#include "ColorMap.h"
#include "Menus\Instructions.h"
#include "Spinners\Spinner.h"

class Game {
public:
	Game();
	Game(Spinner spinner);
	~Game();	
	bool isSpinning;
	int spinningTimeout;
	Instructions gameInsturctions;
	Spinner spinner;
	ColorMap colorMap;
	void setCursor(int line);
	void startSpinning();
	void stopSpinning();
	void handleKeyboardEvents();

private:
	void play();
};

#endif