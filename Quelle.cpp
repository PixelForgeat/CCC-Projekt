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

    for (lIntParts = 0; lIntParts < lIntParts.Length(); lIntParts++) {
         cout << lIntParts.currentElement() << " ";
    }
	return Kot;
}
