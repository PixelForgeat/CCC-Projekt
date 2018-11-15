#ifndef CCCPARSER_H
#define CCCPARSER_H
#include "List.h"
#include <fstream>
#include <iostream>
#include <string>


class CCCParser
{
public:
	CCCParser() {};
	virtual ~CCCParser() {};
	static void parseFileInput(std::string sFilePath, List<std::string>& lStringParts, List<int>& lIntParts, List<std::string>& lAllAsString )
	{
		std::ifstream fInputFile;
		std::string sFileContent;
		fInputFile.open(sFilePath);
		
		while (true)
		{
			sFileContent.clear();
			fInputFile >> sFileContent;
			if (sFileContent.empty())
			{
				break;
			}

			std::string::const_iterator it = sFileContent.begin();
			while (it != sFileContent.end() && isdigit(*it)) ++it;

			if ( it == sFileContent.end() )
			{
				lIntParts.append(std::stoi(sFileContent));
			}
			else
			{
				lStringParts.append(sFileContent);
			}
			lAllAsString.append(sFileContent);
		}
		fInputFile.close();
	}
};

#endif // !CCCPARSER_H

