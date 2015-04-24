// FirstIsLess.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
using namespace std;

#include "defcell.h"

DEFCELL(char, CELL, LIST);

//typedef struct CELL *LIST;
//struct CELL {
//	char element;
//	LIST next;
//};

bool FirstIsLess(LIST firstl, LIST secondl)
{
	bool bresult = true;

	if(firstl == NULL && secondl == NULL) //I'm going to return false if the strings are equal.
		bresult = false;
	else if(firstl == NULL && secondl != NULL) //If the first string is shorter, then it's less than the second string.
		bresult = true;
	else if(firstl != NULL && secondl == NULL) //If the first string is longer, then it's greater than the second string.
		bresult = false;
	else if(firstl != NULL && secondl != NULL)
	{
		if(firstl->element == secondl->element)
			bresult = FirstIsLess(firstl->next, secondl->next);
		if(firstl->element < secondl->element)
			bresult = true;
		if(firstl->element > secondl->element)
			bresult = false;
	}

	return bresult;
}

LIST AllocList(char chararray[]) //requires a NULL terminated character array
{
	LIST lresult = NULL;
	if(chararray[0] != NULL)
	{
		lresult = (LIST)malloc(sizeof(CELL));
		lresult->element = chararray[0];
		lresult->next = AllocList(&chararray[1]);
	}
	return lresult;
}

void DeallocList(LIST firstcell)
{
	if(firstcell != NULL)
	{
		DeallocList(firstcell->next);
		free(firstcell);
	}
}

void PrintList(LIST firstcell)
{
	if(firstcell != NULL)
	{
		cout << firstcell->element;
		PrintList(firstcell->next);
	}
	else cout << endl;
}

int main(int argc, char* argv[])
{
	char bat[] = { 'b', 'a', 't' };
	char battery[] = { 'b', 'a', 't', 't', 'e', 'r', 'y' };
	char hat[] = { 'h', 'a', 't' };
	char rat[] = { 'r', 'a', 't' };

	LIST batlist = AllocList(bat);
	LIST batterylist = AllocList(battery);
	LIST hatlist = AllocList(hat);
	LIST ratlist = AllocList(rat);

	LIST douglist = AllocList("doug");
	LIST ryanlist = AllocList("ryan");
	
	cout << "Is bat less than hat? " << (FirstIsLess(batlist, hatlist) ? "yes" : "no") << endl;
	cout << "Is hat less than bat? " << (FirstIsLess(hatlist, batlist) ? "yes" : "no") << endl;
	cout << "Is bat less than battery? " << (FirstIsLess(batlist, batterylist) ? "yes" : "no") << endl;
	cout << "Is battery less than bat? " << (FirstIsLess(batterylist, batlist) ? "yes" : "no") << endl;
	cout << "Is rat less than hat? " << (FirstIsLess(ratlist, hatlist) ? "yes" : "no") << endl;
	cout << "Is NULL less than rat? " << (FirstIsLess(NULL, ratlist) ? "yes" : "no") << endl;
	cout << "Is ryan less than doug? " << (FirstIsLess(ryanlist, douglist) ? "yes" : "no") << endl;

	//PrintList(batlist);
	//PrintList(douglist);
	
	DeallocList(batlist);
	DeallocList(batterylist);
	DeallocList(hatlist);
	DeallocList(ratlist);

	DeallocList(douglist);
	DeallocList(ryanlist);

	return 0;
}
