#ifndef SPINNER_SELECTION_MENU_HEADER
#define SPINNER_SELECTION_MENU_HEADER

#include <string>
#include <vector>

#include "..\IPrintable.h"

using namespace std;

class SpinnerSelectionMenu : public IPrintable
{
public:
	SpinnerSelectionMenu(vector<string> selectionKeys);
	~SpinnerSelectionMenu();
	vector<string> selectionKeys;
	virtual void print();
};

#endif