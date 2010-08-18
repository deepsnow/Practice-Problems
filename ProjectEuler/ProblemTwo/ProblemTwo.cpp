// ProblemTwo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

unsigned int genFib()
{
	static unsigned int a = 0;
	static unsigned int b = 1;
	
	unsigned int result = a + b;
	a = b;
	b = result;

	return result;
}


int _tmain(int argc, _TCHAR* argv[])
{

	//for(int i = 0; i < 10; i++)
	//	cout << " " << genFib();
	//cout << endl;

	//long long sum = 0;
	//unsigned int curr_num = genFib();
	//for(int i = 0; i < 10; i++)
	//{
	//	if( (curr_num % 2) == 0 )
	//	{
	//		sum += static_cast<long long>(curr_num);
	//		cout << "sum: " << sum << endl;
	//	}
	//	curr_num = genFib();
	//}

	long long sum = 0;
	unsigned int curr_num = genFib();
	while(curr_num < 4000000)
	{
		//if( (curr_num % 2) == 0 )
		if( !(curr_num & 1) )
			sum += static_cast<long long>(curr_num);
		curr_num = genFib();
	}

	cout << sum << endl;

	return 0;
}

