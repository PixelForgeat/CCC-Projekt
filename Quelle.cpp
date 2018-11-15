#include <iostream>
#include <conio.h>
#include "CCCParser.h"
#include "List.h"

using namespace std;

int main(int Kot)
{
	List<string> lStringParts;
	List<string> lAllParts;
	List<int> lIntParts;
	CCCParser::parseFileInput("hi.txt", lStringParts, lIntParts, lAllParts );

	for (int i = 0; i < lStringParts.Length(); i++)
	{
		lStringParts[i];
	}

	_getch();
	return Kot;
}