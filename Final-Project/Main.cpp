#include "SpinnerSelectionMenu.h"
#include "Game.h"
#include "Spinner.h"
#include "SpinnerFactory.h"

using namespace std;

#define SPINNER_LENGTH 13
#define DEFAULT_SPINNING_TIMEOUT 150

void main() {
	SpinnerFactory* spinnerFactory = new SpinnerFactory();
	vector<string> spinnerNames = spinnerFactory->getAllNames();
	int spinnerNamesLength = spinnerNames.size();

	SpinnerSelectionMenu* spinnerSelectionMenu = new SpinnerSelectionMenu(spinnerNames);
	spinnerSelectionMenu->print();

	int spinnerChoice;
	cin >> spinnerChoice;

	while (spinnerChoice < 1 || spinnerChoice > spinnerNamesLength) {
		cin >> spinnerChoice;
	}

	Spinner spinner = spinnerFactory->getSpinner(spinnerNames.at(spinnerChoice-1));

	Game* game = new Game(spinner);

	delete spinnerFactory;
	delete &spinnerNames;
	delete spinnerSelectionMenu;
	delete &spinner;
	delete game;
}