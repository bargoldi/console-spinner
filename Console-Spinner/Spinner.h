#ifndef SPINNER_HEADER
#define SPINNER_HEADER

#include <string>

#include "IPrintable.h"

using namespace std;

#define SPINNER_LENGTH 13
#define RIGHT_DIRECTION 1
#define LEFT_DIRECTION -1

class Spinner : public IPrintable
{	
public:
	Spinner();
	Spinner(string spinnerName, string spinnerDescription);
	Spinner(const Spinner & spinner);
	virtual ~Spinner();
	string name;
	string description;
	int direction;
	void setDirection(int direction);
	char spinnerRepresentation[SPINNER_LENGTH][SPINNER_LENGTH];
	virtual void spin();	
	virtual void print();
	virtual void initializeSpinner();

	void operator=(const Spinner& spinner);

private:
	void spinLeft();
	void spinRight();
};

#endif