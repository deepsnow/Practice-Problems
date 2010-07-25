#pragma once
#include <iostream>
using namespace std;

class StringRecord
{
	friend ostream &operator<<( ostream &, StringRecord &);

public:
	StringRecord();
	void Init(char[],int);
	~StringRecord(void);
	bool operator<( StringRecord & );
	bool FirstIsLess(char[],int,char[],int);
	char* GetData() { return data; }

protected:
	char *data;
	int size;
};
