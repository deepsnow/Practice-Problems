#pragma once
#include "AtoI.h"


class atoiTests
{
public:
	atoiTests(void);
	~atoiTests(void);

	bool RunAllTests();

private:

	bool SingleDigit();
	bool SingleDigitNegative();
	bool MultiDigit();
	bool MultiDigitNegative();
	bool MultiDigitInvalidChar();

	AtoI atoi;
};

