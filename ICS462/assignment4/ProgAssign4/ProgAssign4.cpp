/****************************************************************************************************************
* ICS 462 SUMMER 2019
* Programming Assignment 4
* Shannon Fisher
* 06/16/2019
*
* Internet reference:
* https://github.com/jetsasank/OperatingSystems/blob/master/paging.c
*
* Demonstration of a function that is passed a virtual address (in decimal)
* and outputs the page number and offset for the given address.
****************************************************************************************************************/

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

const std::string OUTPUT_FILENAME = "Fisher_Shannon_ProgAssign4.txt";
unsigned int const ADDRESS_LIST[] = { 19986, 347892, 5978 };

int main(int argc, char *argv[])
{
	fstream outputFile;

	unsigned int address = 0;
	unsigned int pageNumber = 0;
	unsigned int offset = 0;

	outputFile.open(OUTPUT_FILENAME, ios::out);

	if (!outputFile)
	{
		cout << "Error: Could not create the output file." << endl;
		cout << "Exiting now." << endl;
		return 0;
	}

	outputFile << "Shannon Fisher" << endl;
	outputFile << "ICS 462 Programming Assignment 4" << endl << endl;

	for (int i = 0; i < 3; i++)
	{
		address = ADDRESS_LIST[i];

		// 32-bit addressing = 2^32; size of a page is a power of 2
		// Page size for this assignment is 4-KB (4096 bytes) or 2^12

		// Bit-shift the address to the right by 12-bits,
		// first 20 bits gives the page number
		pageNumber = address >> 12;

		// Last 12 bits gives the offset
		offset = address & 0xfff;

		outputFile << "Address " << ADDRESS_LIST[i] << " contains:" << endl;
		outputFile << "  Page number = " << pageNumber << endl;
		outputFile << "  Offset = " << offset << endl << endl;
	}

	outputFile.close();

	cout << "File " << OUTPUT_FILENAME << " created." << endl;
}