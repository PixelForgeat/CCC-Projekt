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
	static void parseFileInput(std::string sFilePath, List<std::string>& lStringParts, List<int>& lIntParts, List<std::string>& lAllAsString)
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
			while (it != sFileContent.end() && (isdigit(*it) || *it == '-' )) ++it;

			if (it == sFileContent.end())
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

	static void printToFile(std::string sFilePath, List<std::string>& lStuffToWrite)
	{
		std::ofstream fOutputFile;
		std::string sFileContent;
		fOutputFile.open(sFilePath);

		for (lStuffToWrite.begin(); lStuffToWrite < lStuffToWrite.Length();)
		{
			fOutputFile << lStuffToWrite++ << " ";
		}

		fOutputFile.close();
	}

	static void printToFile(std::string sFilePath, List<int>& lStuffToWrite)
	{
		std::ofstream fOutputFile;
		std::string sFileContent;
		fOutputFile.open(sFilePath);

		for (lStuffToWrite.begin(); lStuffToWrite < lStuffToWrite.Length();)
		{
			fOutputFile << lStuffToWrite++ << " ";
		}

		fOutputFile.close();
	}
};

#endif // !CCCPARSER_H

