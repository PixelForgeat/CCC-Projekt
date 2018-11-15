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
    
    int sum = 0;
    for (lIntParts = 0; lIntParts < lIntParts.Length(); lIntParts++) {
        sum += lIntParts.currentElement();
    }
    
    cout << sum << endl;
    
	return Kot;
}
