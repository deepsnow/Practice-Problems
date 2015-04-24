// FindLargestPrime.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
//#include <iomanip>
//#include <cmath>

using namespace std;

bool isPrime(unsigned long long num)
{
	bool is_prime = true;
	for(int i = 2; i*i <= num; i++)
	{
		if(num % i == 0)
		{
			is_prime = false;
			break;
		}
	}
	return is_prime;
}

int _tmain(int argc, _TCHAR* argv[])
{
	
	// Here's the "trial division" method for integer factorization in search of the largest prime factor

	// Here's the number to be factored.
	//const unsigned long long bignum = 600851475143;
	//const unsigned long long bignum = 13195;
	//const unsigned long long bignum = 35;
	//const unsigned long long bignum = 117;

	if(argc < 2)
	{
		cout << "Please pass one integer as the argument." << endl;
		exit(1);
	}

	// Set up storage
	unsigned long long lpf = 0; //this var will hold the end result, the largest prime factor
	size_t inputlen = wcslen(argv[1]);
	unsigned long long temp = _wcstoui64(argv[1], &argv[inputlen], 10);
	//unsigned long long temp = _wcstoui64(argv[1], NULL, 10);
	if(temp == 0)
	{
		cout << "Please ensure that the argument is an integer." << endl;
		exit(2);
	}
	const unsigned long long bignum = temp;
	//cout << "number to factor: " << bignum << endl;
	unsigned long long counterpart = 0;

	// Find the upper bound for the loop.
	//double d_bignum = static_cast<double>(bignum);
	//double sqrt_of_big = sqrtl(d_bignum);
	////cout << setprecision(10) << sqrt_of_big << endl;
	//unsigned long long loop_terminator = static_cast<unsigned long long>(sqrt_of_big); // I could round rather than just truncate: http://www.codeproject.com/Articles/58289/C-Round-Function.aspx
	//cout << "length of loop to search for factors: " << loop_terminator << endl;
	// No, just use i*i for loop termination test // See http://en.wikipedia.org/wiki/Trial_division
	
	// Loop to search for factors
	for(unsigned long long i = 2; i*i <= bignum; i++)
	{
		if((bignum % i) == 0) // if i is a factor, then check i and its counterpart for primacy
		{
			if(isPrime(i))
			{
				if(i > lpf)
				{
					lpf = i;
					//cout << lpf << endl;
				}
			}
			// Since i is a factor, I must inspect its counterpart for primacy
			counterpart = bignum / i;
			if(isPrime(counterpart))
			{
				if(counterpart > lpf)
				{
					lpf = counterpart;
					//cout << "counterpart: " << lpf << " while i: " << i << endl;
				}
			}
		}
	}

	// Output result
	if(lpf == 0)
		cout << bignum << " is a prime number" << endl;
	else
		cout << "largest prime factor: " << lpf << endl;

	return 0;
}
