#include <iostream>
#include <string>
#include "CCCParser.h"
#include "List.h"

using namespace std;

int main(int Kot)
{
	List<string> lStringParts;
	List<string> lAllParts;
	List<int> lIntParts;
    CCCParser::parseFileInput("input.txt", lStringParts, lIntParts, lAllParts );


	// CCC code start


	// CCC code end

	CCCParser::printToFile("output.txt", lIntParts);
	cin.get();
	return Kot;
}
