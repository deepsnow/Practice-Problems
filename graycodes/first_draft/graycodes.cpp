// graycodes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printVal(const unsigned int data, const unsigned int num_bits)
{
	//I borrowed this code from my C++ text book.
	cout << data << "\t: ";
	const unsigned int inner_mask = 1 << (num_bits - 1);
	
	unsigned int temp = data;
	for( unsigned int count=0; count<num_bits; count++ )
	{
		cout << (temp & inner_mask ? '1' : '0');
		temp <<= 1;
	}
	cout << endl;
}

void iterativeSequence(unsigned int data, unsigned int num_bits, vector<unsigned int> &vect)
{
	vect.push_back(data);
	for( unsigned int digit=0; digit<num_bits; digit++ )
	{
		unsigned int outer_mask = 1 << digit;
		data = data ^ outer_mask;
		vect.push_back(data);
		unsigned int shift = digit;
		bool descending = true;

		for( unsigned int prev=1; prev<outer_mask; prev++ )
		{
			if( descending )
			{
				shift--;
				descending = ( shift != 0 );
			}
			else
			{
				shift++;
				descending = ( shift == (digit - 1) );
			}

			unsigned int n_mask = 1 << shift;
			data = data ^ n_mask;

			vect.push_back(data);
		}
	}
}

void testPermutations(unsigned int num_permutations, unsigned int bit_width)
{
	vector<unsigned int> control;
	for( unsigned int count=0; count<num_permutations; count++ )
		control.push_back(count);

	for( unsigned int start_val=0; start_val<num_permutations; start_val++ )
	{
		vector<unsigned int> vui;
		iterativeSequence(start_val, bit_width, vui);

		vector<unsigned int>::iterator itr;
		for( itr=vui.begin(); itr!=vui.end(); itr++ )
		{
			printVal(*itr, bit_width);
		}

		sort(vui.begin(), vui.end());

		for( unsigned int count=0; count<num_permutations; count++ )
			if( vui[count] != control[count] )
				cout << "Error in test " << start_val << " at element " << count << ": vui[count] contains " << vui[count] << " and control[count] contains " << control[count] << "." <<endl;

		cout << endl;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	//unsigned int bit_width = 4;
	unsigned int bit_width = 5;
	unsigned int num_permutations = 2;
	for( unsigned int count=1; count<bit_width; count++ )
		num_permutations *= 2;

	testPermutations(num_permutations, bit_width);

	return 0;
}
