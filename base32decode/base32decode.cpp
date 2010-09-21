// This program illustrates how SHA1 hash values in base32 encoded form can be decoded
// and then re-encoded in base16.


#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

unsigned char Base16EncodeNibble( unsigned char value )
{
	if( value >= 0 && value <= 9 )
		return value + 48;
	else if( value >= 10 && value <= 15 )
		return (value-10) + 65;
	else //assert(false);
	{
		cout << "Error: trying to convert value: " << value << endl;
	}

	return 42; // sentinal for error condition
}

void Base32DecodeBase16Encode(const string & input, string & output)
{
	// Here's the base32 decoding:

		// The "Base 32 Encoding" section of http://tools.ietf.org/html/rfc4648#page-8
		// shows that every 8 bytes of base32 encoded data must be translated back into 5 bytes
		// of original data during a decoding process. The following code does this.

	int input_len = input.length();
	assert( input_len == 32 );
	const char * input_str = input.c_str();
	int output_len = (input_len*5)/8;
	assert( output_len == 20 );
		// Because input strings are assumed to be SHA1 hash values in base32, it is also assumed
		// that they will be 32 characters (and bytes in this case) in length, and so the output
		// string should be 20 bytes in length.
	unsigned char *output_str = new unsigned char[output_len];
	
	char curr_char, temp_char;
	long long temp_buffer = 0; //formerly: __int64 temp_buffer = 0;
	for( int i=0; i<input_len; i++ )
	{
		curr_char = input_str[i];
		if( curr_char >= 'A' && curr_char <= 'Z' )
			temp_char = curr_char - 'A';
		if( curr_char >= '2' && curr_char <= '7' )
			temp_char = curr_char - '2' + 26;

		if( temp_buffer )
			temp_buffer <<= 5; //temp_buffer = (temp_buffer << 5);
		temp_buffer |= temp_char;

		// if 8 encoded characters have been decoded into the temp location,
			// then copy them to the appropriate section of the final decoded location
		if( (i>0) && !((i+1) % 8) )
		{
			unsigned char * source = reinterpret_cast<unsigned char*>(&temp_buffer);
			//strncpy(output_str+(5*(((i+1)/8)-1)), source, 5);
			int start_index = 5*(((i+1)/8)-1);
			int copy_index = 4;
			for( int x=start_index; x<(start_index+5); x++, copy_index-- )
				output_str[x] = source[copy_index];
			temp_buffer = 0;

			// I could be mistaken, but I'm guessing that the necessity of copying
			// in "reverse" order results from temp_buffer's little endian byte order.
		}
	}

	// Here's the base16 encoding (for human-readable output and the chosen validation tests):

		// The "Base 16 Encoding" section of http://tools.ietf.org/html/rfc4648#page-10
		// shows that every byte original data must be encoded as two characters from the
		// base16 alphabet - one charactor for the original byte's high nibble, and one for
		// its low nibble.

	unsigned char out_temp, chr_temp;
	for( int y=0; y<output_len; y++ )
	{
		out_temp = Base16EncodeNibble( output_str[y] >> 4 ); //encode the high nibble
		output.append( 1, static_cast<char>(out_temp) );
		out_temp = Base16EncodeNibble( output_str[y] & 0xF ); //encode the low nibble
		output.append( 1, static_cast<char>(out_temp) );
	}

	delete [] output_str;
}

int _tmain(int argc, _TCHAR* argv[])
{
	//string input = "J3WEDSJDRMJHE2FUHERUR6YWLGE3USRH";
	vector<string> input_b32_strings, output_b16_strings, expected_b16_strings;

	input_b32_strings.push_back("J3WEDSJDRMJHE2FUHERUR6YWLGE3USRH");
	expected_b16_strings.push_back("4EEC41C9238B127268B4392348FB165989BA4A27");
	input_b32_strings.push_back("2HPUCIVW2EVBANIWCXOIQZX6N5NDIUSX");
	expected_b16_strings.push_back("D1DF4122B6D12A10351615DC8866FE6F5A345257");
	input_b32_strings.push_back("U4BDNCBAQFCPVDBL4FBG3AANGWVESI5J");
	expected_b16_strings.push_back("A7023688208144FA8C2BE1426D800D35AA4923A9");

	// Use the base conversion tool at http://darkfader.net/toolbox/convert/
	// to verify that the above base32/base16 pairs are equivalent.

	int num_input_strs = input_b32_strings.size();
	for(int i=0; i<num_input_strs; i++)
	{
		string temp;
		Base32DecodeBase16Encode(input_b32_strings[i], temp);
		output_b16_strings.push_back(temp);
	}

	for(int j=0; j<num_input_strs; j++)
	{
		cout << input_b32_strings[j] << endl;
		cout << output_b16_strings[j] << endl;
		cout << expected_b16_strings[j] << endl;

		if( output_b16_strings[j] != expected_b16_strings[j] )
		{
			cout << "Error in conversion for string " << j << endl;
		}
	}

	return 0;
}
