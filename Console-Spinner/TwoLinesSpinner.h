#ifndef TWO_LINES_SPINNER_HEADER
#define TWO_LINES_SPINNER_HEADER

#include <string>

#include "Spinner.h"

using namespace std;

class TwoLinesSpinner : public Spinner
{
public:
	TwoLinesSpinner();
	~TwoLinesSpinner();
	virtual void initializeSpinner();
};

#endif