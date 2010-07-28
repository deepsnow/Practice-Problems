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

void MerrickSort2(int inbuffer[], int length)
{
	int zero_count = 0;
	for(int i=0; i<length; i++)
	{
		if((i<length-zero_count) && (inbuffer[i] == 0))
		{
			//swap with non-zero from end of array
			zero_count++;
			while(inbuffer[length-zero_count] == 0)
				zero_count++;
			inbuffer[i] = inbuffer[length-zero_count];
			inbuffer[length-zero_count] = 0; //no need for 3-step swap
		}
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
	//first solution
	int inTrial1[] = { 8, 0, 1, 7, 5, 2, 0, 1, 7, 1 };
	int outTrial1[10];
	cout << "input buffer:\t\t\t";
	PrintBuffer(inTrial1, 10);
	MerrickSort1(inTrial1, outTrial1, 10);
	cout << "output buffer after sorting:\t";
	PrintBuffer(outTrial1, 10);

	//second solution
	int inTrial2[] = { 8, 0, 1, 4, 0, 4, 4, 3, 0, 3 };
	cout << "input buffer:\t\t\t";
	PrintBuffer(inTrial2, 10);
	MerrickSort2(inTrial2, 10);
	cout << "output buffer after sorting:\t";
	PrintBuffer(inTrial2, 10);
	int inTrial3[] = { 6, 5, 0, 8, 6, 2, 8, 0, 0, 0 };
	cout << "input buffer:\t\t\t";
	PrintBuffer(inTrial3, 10);
	MerrickSort2(inTrial3, 10);
	cout << "output buffer after sorting:\t";
	PrintBuffer(inTrial3, 10);
	int inTrial4[] = { 0, 0, 0, 5, 5, 5, 5, 5, 5, 5 };
	cout << "input buffer:\t\t\t";
	PrintBuffer(inTrial4, 10);
	MerrickSort2(inTrial4, 10);
	cout << "output buffer after sorting:\t";
	PrintBuffer(inTrial4, 10);

	return 0;
}
