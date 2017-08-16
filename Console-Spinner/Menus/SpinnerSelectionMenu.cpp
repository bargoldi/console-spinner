#include <iostream>
#include <vector>

#include "SpinnerSelectionMenu.h"

using namespace std;

SpinnerSelectionMenu::SpinnerSelectionMenu(vector<string> selectionKeys){
	this->selectionKeys = selectionKeys;
}

SpinnerSelectionMenu::~SpinnerSelectionMenu(){
	delete &selectionKeys;
}

void SpinnerSelectionMenu::print() {
	cout << "WELCOME TO C++ SPINNER IMPLEMENTATION" << endl;
	cout << "--------------------------------------" << endl;

	int i = 1;

	for (auto const& value : this->selectionKeys) {
		cout << i << ". " << value << endl;
		i++;
	}
}