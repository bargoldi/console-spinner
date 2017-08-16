#include <iostream>
#include <map>
#include <vector>

#include "ColorMap.h"

ColorMap::ColorMap() {
	this->colorMap[R_BUTTON] = 4;
	this->colorMap[G_BUTTON] = 2;
	this->colorMap[B_BUTTON] = 1;
	this->colorMap[Y_BUTTON] = 14;
	this->colorMap[W_BUTTON] = 7;
}

ColorMap::~ColorMap() {
	delete &(this->colorMap);
}

int ColorMap::getColor(int asciiColorId) {
	return this->colorMap.at(asciiColorId);
}