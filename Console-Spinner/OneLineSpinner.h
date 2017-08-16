#ifndef ONE_LINES_SPINNER_HEADER
#define ONE_LINES_SPINNER_HEADER

#include <string>

#include "Spinner.h"

using namespace std;

class OneLineSpinner : public Spinner
{
public:
	OneLineSpinner();
	~OneLineSpinner();
	virtual void initializeSpinner();
};

#endif