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
		if((i < length-zero_count) && (inbuffer[i] == 0))
		{
			//swap with non-zero from end of array
			zero_count++;
			//there may already be zeros at the high end of the array
			while((i < length-zero_count) && (inbuffer[length-zero_count] == 0))
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
	const int length_t1 = sizeof(inTrial1) / sizeof(int);
	int outTrial1[length_t1];
	cout << "input buffer:\t\t\t";
	PrintBuffer(inTrial1, length_t1);
	MerrickSort1(inTrial1, outTrial1, length_t1);
	cout << "output buffer after sorting:\t";
	PrintBuffer(outTrial1, length_t1);

	//second solution
	int inTrial2[] = { 8, 0, 1, 4, 0, 4, 4, 3, 0, 3 };
	int length = sizeof(inTrial2) / sizeof(int);
	cout << "input buffer:\t\t\t";
	PrintBuffer(inTrial2, length);
	MerrickSort2(inTrial2, length);
	cout << "output buffer after sorting:\t";
	PrintBuffer(inTrial2, length);
	int inTrial3[] = { 6, 5, 0, 8, 6, 2, 8, 0, 0, 0 };
	length = sizeof(inTrial3) / sizeof(int);
	cout << "input buffer:\t\t\t";
	PrintBuffer(inTrial3, length);
	MerrickSort2(inTrial3, length);
	cout << "output buffer after sorting:\t";
	PrintBuffer(inTrial3, length);
	int inTrial4[] = { 0, 0, 0, 5, 5, 5, 5, 5, 5, 5 };
	length = sizeof(inTrial4) / sizeof(int);
	cout << "input buffer:\t\t\t";
	PrintBuffer(inTrial4, length);
	MerrickSort2(inTrial4, length);
	cout << "output buffer after sorting:\t";
	PrintBuffer(inTrial4, length);
	int inTrial5[] = { 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 };
	length = sizeof(inTrial5) / sizeof(int);
	cout << "input buffer:\t\t\t";
	PrintBuffer(inTrial5, length);
	MerrickSort2(inTrial5, length);
	cout << "output buffer after sorting:\t";
	PrintBuffer(inTrial5, length);
	int inTrial6[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	length = sizeof(inTrial6) / sizeof(int);
	cout << "input buffer:\t\t\t";
	PrintBuffer(inTrial6, length);
	MerrickSort2(inTrial6, length);
	cout << "output buffer after sorting:\t";
	PrintBuffer(inTrial6, length);
	int inTrial7[] = { 1, 1, 1, 1, 1 };
	length = sizeof(inTrial7) / sizeof(int);
	cout << "input buffer:\t\t\t";
	PrintBuffer(inTrial7, length);
	MerrickSort2(inTrial7, length);
	cout << "output buffer after sorting:\t";
	PrintBuffer(inTrial7, length);
	int inTrial8[] = { 1, 1, 1, 0, 0, 0 };
	length = sizeof(inTrial8) / sizeof(int);
	cout << "input buffer:\t\t\t";
	PrintBuffer(inTrial8, length);
	MerrickSort2(inTrial8, length);
	cout << "output buffer after sorting:\t";
	PrintBuffer(inTrial8, length);

	return 0;
}
