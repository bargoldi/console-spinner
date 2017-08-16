#ifndef INSTRUCTIONS_HEADER
#define INSTRUCTIONS_HEADER

#include "IPrintable.h"

class Instructions : public IPrintable
{
public:
	Instructions();
	~Instructions();
	virtual void print();
};

#endif