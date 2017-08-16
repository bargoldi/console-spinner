#ifndef COLORMAP_HEADER
#define COLORMAP_HEADER

#include <map>
#include <string>

#define R_BUTTON 114
#define G_BUTTON 103
#define B_BUTTON 98
#define Y_BUTTON 121
#define W_BUTTON 119

using namespace std;

#define SPINNER_LENGTH 13

class ColorMap
{
public:
	ColorMap();
	~ColorMap();
	map <int, int> colorMap;
	int getColor(int asciiColorId);
};

#endif