// MoveZeros.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstring>
#include <iostream>

using namespace std;

void MerrickSort1(int inbuffer[], int outbuffer[], int length)
{
	int zero_count = 0;
	for(int i=0; i<length; i++)
	{
		if(inbuffer[i] == 0)
		{
			zero_count++;
			outbuffer[length-zero_count] = 0;
		}
		else
			outbuffer[i-zero_count] = inbuffer[i];
	}
}

void PrintBuffer(int buffer[], int length)
{
	for(int i=0; i<length; i++)
	{
		cout << buffer[i];
	}
	cout << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int inTrial1[] = { 8, 0, 1, 7, 5, 2, 0, 1, 7, 1 };
	int outTrial1[10];

	cout << "input buffer:\t\t\t";
	PrintBuffer(inTrial1, 10);
	MerrickSort1(inTrial1, outTrial1, 10);
	cout << "output buffer after sorting:\t";
	PrintBuffer(outTrial1, 10);

	return 0;
}
