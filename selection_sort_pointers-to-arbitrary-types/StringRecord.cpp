#include "StdAfx.h"
#include "StringRecord.h"
#include <cstring>

StringRecord::StringRecord()
{
	data = NULL;
	size = 0;
}

void StringRecord::Init(char buffer[], int length)
{
	data = new char[length];
	strncpy(data, buffer, length);
	size = length;
}

StringRecord::~StringRecord(void)
{
	delete [] data;
	data = NULL;
}

bool StringRecord::operator <(StringRecord &rvalue)
{
	return FirstIsLess(data, size, rvalue.data, rvalue.size);
}

bool StringRecord::FirstIsLess(char first[], int fsize, char second[], int ssize)
{
	bool bresult = true;

	if(fsize == 0 && ssize == 0) //I'm going to return false if the strings are equal.
		bresult = false;
	else if(fsize == 0 && ssize > 0) //If the first string is shorter, then it's less than the second string.
		bresult = true;
	else if(fsize > 0 && ssize == 0) //If the first string is longer, then it's greater than the second string.
		bresult = false;
	else if(fsize > 0 && ssize > 0)
	{
		if(first[0] == second[0])
			bresult = FirstIsLess(&first[1], fsize-1, &second[1], ssize-1);
		if(first[0] < second[0])
			bresult = true;
		if(first[0] > second[0])
			bresult = false;
	}

	return bresult;
}

ostream &operator<<(ostream &output, StringRecord &sr)
{
	output << sr.GetData();
	return output;
}
