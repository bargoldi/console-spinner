#ifndef THREE_LINES_SPINNER_HEADER
#define THREE_LINES_SPINNER_HEADER

#include <string>

#include "Spinner.h"

using namespace std;

class ThreeLinesSpinner : public Spinner
{
public:
	ThreeLinesSpinner();
	~ThreeLinesSpinner();
	virtual void initializeSpinner();
};

#endif