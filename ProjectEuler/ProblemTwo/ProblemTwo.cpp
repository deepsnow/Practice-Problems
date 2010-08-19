// ProblemTwo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

//unsigned int genFib()
//{
//	static unsigned int a = 0;
//	static unsigned int b = 1;
//	
//	unsigned int result = a + b;
//	a = b;
//	b = result;
//
//	return result;
//}


int _tmain(int argc, _TCHAR* argv[])
{

	//long long sum = 0;
	//unsigned int curr_num = genFib();
	//while(curr_num < 4000000)
	//{
	//	//if( (curr_num % 2) == 0 )
	//	if( !(curr_num & 1) )
	//		sum += static_cast<long long>(curr_num);
	//	curr_num = genFib();
	//}
	//cout << sum << endl;

	int a, b, fib, sum;
	a = fib = sum = 0;
	b = 1;

	do
	{
		fib = a + b;
		a = b;
		b = fib;
		if( !(fib & 1) )
			sum += fib;
	} while (fib < 4000000);
	cout << sum << endl;

	return 0;
}
