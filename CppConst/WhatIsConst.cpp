// WhatIsConst.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void PassByValueNonConst(int arg)
{
	arg = 7;
	cout << "PBVNC() arg: " << arg << endl;
}

void PassByValueConst(const int arg)
{
	//arg = 7; //compile error C3892
	cout << "PBVC() arg: " << arg << endl;
}

void PassByRefNonConst(int &arg)
{
	arg = 7;
	cout << "PBRNC() arg: " << arg << endl;
}

void PassByRefConst(const int &arg)
{
	//arg = 7; //compile error C3892
	cout << "PBRC() arg: " << arg << endl;
}

//void PassByConstRefNonConst(int & const arg) //compiler warning C4227: anachronism used : qualifiers on reference ignored
//{
//	arg = 7;
//	cout << "PBCRNC() arg: " << arg << endl;
//}
//
//void PassByConstRefConst(const int & const arg)  //compiler warning C4227: anachronism used : qualifiers on reference ignored
//{
//	//arg = 7; //compile error C3892
//	cout << "PBCRC() arg: " << arg << endl;
//}

void PassByNcPtrNcData(int *arg)
{
	*arg = 7;
	cout << "PBNcPNcD() arg data: " << *arg << endl;
	arg++;
	cout << "PBNcPNcD() arg addr: " << arg << endl;
}

void PassByNcPtrCData(const int *arg)
{
	//*arg = 7; //compile error C3892
	cout << "PBNcPCD() arg data: " << *arg << endl;
	arg--;
	cout << "PBNcPCD() arg addr: " << arg << endl;
}

void PassByCPtrNcData(int * const arg)
{
	*arg = 7;
	cout << "PBCPNcD() arg data: " << *arg << endl;
	//arg++; //compile error C3892
	cout << "PBCPNcD() arg addr: " << arg << endl;
}

void PassByCPtrCData(const int * const arg)
{
	//*arg = 7; //compile error C3892
	cout << "PBNcPCD() arg data: " << *arg << endl;
	//arg--; //compile error C3892
	cout << "PBNcPCD() arg addr: " << arg << endl;
}

class MyClass
{
private:
	//const int firstInt = 1; //compile error C2864
	static const int firstInt = 1;
	const int secondInt;
	int thirdInt;
public:
	MyClass() : secondInt(2) {
		//secondInt = 5; //compile error C2758
		thirdInt = 3;
	}
	void PrintAll() const { cout << firstInt << ", " << secondInt << ", " << thirdInt << endl; }
	//void ResetFirstInt() { firstInt+=10; cout << firstInt << endl; } //compile error C3892
	//void ResetSecondInt() { secondInt+=10; cout << secondInt << endl; } //compile error C2166
	void SetThirdInt() { thirdInt+=10; }
	void ResetThirdInt() { thirdInt=3; }
};

void PassObjByValueNonConst(MyClass myArg)
{
	cout << "POBVNC()..." << endl;
	myArg.SetThirdInt();
	myArg.PrintAll();
}

void PassObjByValueConst(const MyClass myArg)
{
	cout << "POBVC()..." << endl;
	//next call fails with C2662 unless it become const
	myArg.PrintAll();
	//myArg.SetThirdInt();
	cout << "POBVC() casts away const..." << endl;
	MyClass * vulnerableArg = const_cast<MyClass*>(&myArg);
	//vulnerableArg->PrintThirdInt();
	vulnerableArg->SetThirdInt();
	vulnerableArg->PrintAll();
}

void PassObjByRefNonConst(MyClass &myArg)
{
	cout << "POBRNC()..." << endl;
	myArg.SetThirdInt();
	myArg.PrintAll();
}

void PassObjByRefConst(const MyClass &myArg)
{
	cout << "POBRC()..." << endl;
	//myArg.SetThirdInt(); //compile error C2662 unless method is const
		//but if you make it a const method, you get error C2166 (presumably) because it attempts to modify a member variable
	myArg.PrintAll();
}

void PassObjByNcPtrNonConst(MyClass *myArg)
{
	cout << "POBNCPNC()..." << endl;
	myArg->SetThirdInt();
	myArg->PrintAll();
}

void PassObjByNcPtrConst(const MyClass *myArg)
{
	cout << "POBNCPC()..." << endl;
	//myArg->SetThirdInt(); //compile error C2662 unless method is const
		//but if you make it a const method, you get error C2166 (presumably) because it attempts to modify a member variable
	myArg->PrintAll();
}

void PassObjByCPtrNonConst(MyClass * const myArg)
{
	cout << "POBNCPNC()..." << endl;
	myArg->SetThirdInt();
	myArg->PrintAll();
	//MyClass tempObj;
	//myArg = &tempObj; //compile error C3892
}

void PassObjByCPtrConst(const MyClass * const myArg)
{
	cout << "POBNCPC()..." << endl;
	//myArg->SetThirdInt(); //compile error C2662 unless method is const
		//but if you make it a const method, you get error C2166 (presumably) because it attempts to modify a member variable
	myArg->PrintAll();
	//MyClass tempObj;
	//myArg = &tempObj; //compile error C3892
}

int _tmain(int argc, _TCHAR* argv[])
{
	int num = 5;
	cout << "main() num: " << num << endl;
	PassByValueNonConst(num);
	cout << "main() num: " << num << endl;
	PassByValueConst(num);
	cout << "main() num: " << num << endl;
	PassByRefNonConst(num);
	cout << "main() num: " << num << endl;
	num = 5;
	cout << "reset main() num: " << num << endl;
	PassByRefConst(num);
	cout << "main() num: " << num << endl;
		//the following methods are commented out above - they work, but they generate compiler errors
	//PassByConstRefNonConst(num);
	//num = 5;
	//cout << "reset main() num: " << num << endl;
	//PassByConstRefConst(num);
	//cout << "main() num: " << num << endl;
	cout << "main() num addr: " << &num << endl;
	PassByNcPtrNcData(&num);
	cout << "main() num: " << num << endl;
	cout << "main() num addr: " << &num << endl;
	num = 5;
	cout << "reset main() num: " << num << endl;
	cout << "main() num addr: " << &num << endl;
	PassByNcPtrCData(&num);
	cout << "main() num: " << num << endl;
	cout << "main() num addr: " << &num << endl;
	PassByCPtrNcData(&num);
	cout << "main() num: " << num << endl;
	cout << "main() num addr: " << &num << endl;
	num = 5;
	cout << "reset main() num: " << num << endl;
	cout << "main() num addr: " << &num << endl;
	PassByCPtrCData(&num);
	cout << "main() num: " << num << endl;
	cout << "main() num addr: " << &num << endl;

	cout << "main() exercises MyClass..." << endl;
	MyClass myObj;
	myObj.PrintAll();
	myObj.SetThirdInt();
	myObj.PrintAll();
	cout << "main() reset" << endl;
	myObj.ResetThirdInt();
	myObj.PrintAll();
	PassObjByValueNonConst(myObj);
	cout << "main() exercises MyClass..." << endl;
	myObj.PrintAll();
	PassObjByValueConst(myObj);
	cout << "main() exercises MyClass..." << endl;
	myObj.PrintAll();
	PassObjByRefNonConst(myObj);
	cout << "main() exercises MyClass..." << endl;
	myObj.PrintAll();
	cout << "main() reset" << endl;
	myObj.ResetThirdInt();
	myObj.PrintAll();
	PassObjByRefConst(myObj);
	cout << "main() exercises MyClass..." << endl;
	myObj.PrintAll();
	PassObjByNcPtrNonConst(&myObj);
	cout << "main() exercises MyClass..." << endl;
	myObj.PrintAll();
	cout << "main() reset" << endl;
	myObj.ResetThirdInt();
	myObj.PrintAll();
	PassObjByNcPtrConst(&myObj);
	cout << "main() exercises MyClass..." << endl;
	myObj.PrintAll();
	PassObjByCPtrNonConst(&myObj);
	cout << "main() exercises MyClass..." << endl;
	myObj.PrintAll();
	cout << "main() reset" << endl;
	myObj.ResetThirdInt();
	myObj.PrintAll();
	PassObjByCPtrConst(&myObj);

	return 0;
}
