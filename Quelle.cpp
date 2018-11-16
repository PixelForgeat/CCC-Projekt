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

	for (lAllParts.begin(); lAllParts < lAllParts.Length(); ) {
		cout << lAllParts++ << " ";
	}
	cout << endl;
	for (lStringParts.begin(); lStringParts < lStringParts.Length(); ) {
		cout << lStringParts++ << " ";
	}
	cout << endl;
	for (lIntParts.begin() ; lIntParts < lIntParts.Length(); ) {
		cout << lIntParts++ << " ";
	}
    
    cout << endl;
	return Kot;
}
