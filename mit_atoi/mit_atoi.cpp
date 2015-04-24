// mit_atoi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "atoiTests.h"

using namespace std;

int main(int argc, char* argv[])
{
	string userInput;
	int result = 0;

	if (argc > 1)
	{
		if (0 == strncmp(argv[1], "-test", 5))
		{
			atoiTests tests;
			if (tests.RunAllTests())
			{
				cout << "all tests passed" << endl;
			}
			else
			{
				cout << "one or more tests failed" << endl;
				result = -3;
			}
		}
		else
		{
			cout << "invalid arg" << endl;
			result = -2;
		}
	}
	else
	{
		cout << "must invoke with \'-test\'" << endl;
		result = -1;
	}

	cin >> userInput;
	return result;
}
