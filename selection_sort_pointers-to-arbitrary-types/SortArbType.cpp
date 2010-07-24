// SortArbType.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "RecordList.h"
#include <iostream>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	int intListA[3] = { 1, 2, 3 };
	int intListB[3] = { 1, 3, 2 };
	int intListC[3] = { 2, 1, 3 };
	int intListD[3] = { 2, 3, 1 };
	int intListE[3] = { 3, 1, 2 };
	int intListF[3] = { 3, 2, 1 };
	double doubleListG[7] = { 3.6, 9.5, 0.4, 6.8, 2.3, 4.1, 6.7 };

	RecordList<int> recListA(intListA, 3);
	recListA.printList();
	recListA.sortList();
	recListA.printList();
	cout << endl;

	RecordList<int> recListB(intListB, 3);
	recListB.printList();
	recListB.sortList();
	recListB.printList();
	cout << endl;

	RecordList<int> recListC(intListC, 3);
	recListC.printList();
	recListC.sortList();
	recListC.printList();
	cout << endl;

	RecordList<int> recListD(intListD, 3);
	recListD.printList();
	recListD.sortList();
	recListD.printList();
	cout << endl;

	RecordList<int> recListE(intListE, 3);
	recListE.printList();
	recListE.sortList();
	recListE.printList();
	cout << endl;

	RecordList<int> recListF(intListF, 3);
	recListF.printList();
	recListF.sortList();
	recListF.printList();
	cout << endl;

	RecordList<double> recListG(doubleListG, 7);
	recListG.printList();
	recListG.sortList();
	recListG.printList();
	cout << endl;

	return 0;
}

