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
    CCCParser::parseFileInput("hi.txt", lStringParts, lIntParts, lAllParts );

	CCCParser::printToFile("xd.txt", lIntParts);
    
	return Kot;
}
