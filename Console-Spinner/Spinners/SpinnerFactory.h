#ifndef SPINNER_FACTORY_HEADER
#define SPINNER_FACTORY_HEADER

#include <map>
#include <vector>

#include "Spinner.h"

using namespace std;

class SpinnerFactory
{
public:
	SpinnerFactory();
	~SpinnerFactory();
	Spinner getSpinner(string spinnerType);
	vector<string> getAllNames();

private:
	map<string, Spinner*> spinnersMap;
};

#endif