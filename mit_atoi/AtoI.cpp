#include "StdAfx.h"
#include "AtoI.h"
#include "string.h"
#include <iostream>


AtoI::AtoI(void)
{
}


AtoI::~AtoI(void)
{
}

int AtoI::conv(char numstr[])
{
	int result = 0;
	bool positive = true;
	int numDigits, numChars;
	int factor = 1;
	int order = 0;
	int currDigit = 0;

	numDigits = numChars = strlen(numstr);
	for (int i=0; i<numChars; i++)
	{
		if ((i==0) && (numstr[i] == '-'))
		{
			positive = false;
			numDigits--;
			continue;
		}

		char currChar = numstr[i];
		if ((currChar >= 48) && (currChar <= 57))
		{
			currDigit = (int)currChar - 48;
			if (positive)
				order = numDigits - 1 - i;
			else
				order = numDigits - i;
			for (int j=1; j<=order; j++)
			{
				factor *= 10;
			}
			if (factor > 1)
			{
				currDigit *= factor;
				factor = 1;
			}
			result += currDigit;
		}
		else throw currChar;
	}

	if (!positive)
		result = result * (-1);

	return result;
}