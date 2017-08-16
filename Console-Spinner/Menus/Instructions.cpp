#include <Windows.h>
#include <iostream>

#include "Instructions.h"

#define FASTER_KEY "UP Arrow Key"
#define SLOWER_KEY "DOWN Arrow Key"
#define LEFT_SPINNING "LEFT Arrow Key"
#define RIGHT_SPINNING "RIGHT Arrow Key"
#define TOGGLE_SPINNING "SPACE Button"

using namespace std;

Instructions::Instructions(){}

Instructions::~Instructions(){}

void setcolor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	return;
}

void Instructions::print()
{
	cout << "Use the next button to control your spinner:" << endl;
	cout << "- Use the " << FASTER_KEY << " to FASTEN your spinning" << endl;
	cout << "- Use the " << SLOWER_KEY << " to SLOWER your spinning" << endl;
	cout << "- Use the " << RIGHT_SPINNING << " to ROTATE RIGHT" << endl;
	cout << "- Use the " << LEFT_SPINNING << " to ROTATE LEFT" << endl;	
	cout << "- Use the " << TOGGLE_SPINNING << " to STOP / SPIN your spinner" << endl;
	cout << "- R - Red, G - Green, B - Blue, Y - Yellow, W - White" << endl;
}