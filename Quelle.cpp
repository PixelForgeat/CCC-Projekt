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
    CCCParser::parseFileInput("level1_4.in", lStringParts, lIntParts, lAllParts );


	// CCC code start

	int sum = 0;

	List<int> output;

	for (lIntParts = 2; lIntParts < lIntParts.Length(); )
	{
		sum += lIntParts++;
	}

	if (sum > 0)
	{
		output.append(1);
	}
	else
	{
		output.append(0);
	}

	// CCC code end

	CCCParser::printToFile("output.txt", output);
	return Kot;
}
