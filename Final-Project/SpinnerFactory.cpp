#include <iostream>
#include <map>
#include <vector>

#include "SpinnerFactory.h"
#include "OneLineSpinner.h"
#include "TwoLinesSpinner.h"
#include "ThreeLinesSpinner.h"

SpinnerFactory::SpinnerFactory() {	
	this->spinnersMap["1 Lines Spinner"] = new OneLineSpinner();
	this->spinnersMap["2 Lines Spinner"] = new TwoLinesSpinner();
	this->spinnersMap["3 Lines Spinner"] = new ThreeLinesSpinner();
}

SpinnerFactory::~SpinnerFactory(){
	for (auto const& key : this->spinnersMap) {
		delete this->spinnersMap.at(key.first);
	}

	delete &(this->spinnersMap);
}

vector<string> SpinnerFactory::getAllNames() {
	vector<string> keys;

	for (auto const& key : this->spinnersMap) {
		keys.push_back(key.first);
	}

	return keys;
}

Spinner SpinnerFactory::getSpinner(string spinnerType) {
	return *this->spinnersMap.at(spinnerType);
}