#include "StdAfx.h"
#include "atoiTests.h"

atoiTests::atoiTests(void)
{
}

atoiTests::~atoiTests(void)
{
}

bool atoiTests::RunAllTests()
{
	return
		SingleDigit()
		&& SingleDigitNegative()
		&& MultiDigit()
		&& MultiDigitNegative()
		&& MultiDigitInvalidChar();
}

bool atoiTests::SingleDigit()
{
	return
		(atoi.conv("0") == 0)
		&& (atoi.conv("1") == 1)
		&& (atoi.conv("9") == 9);
}

bool atoiTests::SingleDigitNegative()
{
	return
		(atoi.conv("-1") == -1)
		&& (atoi.conv("-9") == -9);
}

bool atoiTests::MultiDigit()
{
	return 
		(atoi.conv("234") == 234)
		&& (atoi.conv("7890123") == 7890123);
}

bool atoiTests::MultiDigitNegative()
{
	return 
		(atoi.conv("-787") == -787)
		&& (atoi.conv("-1000001") == -1000001);
}

bool atoiTests::MultiDigitInvalidChar()
{
	bool result = true;

	try
	{
		atoi.conv("-3,333");
	}
	catch (char e)
	{
		result = (e == ',');
	}

	if (!result)
		return result;

	try
	{
		atoi.conv("10000.01");
	}
	catch (char e)
	{
		result = (e == '.');
	}

	return result;
}
