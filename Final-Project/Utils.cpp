#include <Windows.h>

#include "Utils.h"

using namespace std;

void Utils::setConsoleColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}