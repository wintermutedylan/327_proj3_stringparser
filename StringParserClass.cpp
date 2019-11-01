/*
 * StringParserClass.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: keith
 */

#include <string>
#include <string.h>
#include <iostream>
#include "../327_proj3_test/includes/constants.h"
#include "../327_proj3_test/includes/StringParserClass.h"

using namespace KP_StringParserClass;
StringParserClass::StringParserClass(void){
	this->pStartTag = NULL;
	this->pEndTag = NULL;
	this->areTagsSet = false;
}
StringParserClass::~StringParserClass(){
	cleanup();
}

int StringParserClass::setTags(const char *pStart, const char *pEnd){
	if (pStart == NULL || pEnd == NULL){
		return ERROR_TAGS_NULL;
	}
	else {
		int lenS = strlen(pStart);
		pStartTag = new char[lenS + 1];
		int lenE = strlen(pEnd);
		pEndTag = new char[lenE + 1];

		strncpy(pStartTag, pStart, lenS);
		strncpy(pEndTag, pEnd, lenE);

		return SUCCESS;
	}


}


int StringParserClass::getDataBetweenTags(char *pDataToSearchThru, std::vector<std::string> &myVector){
	if (pStartTag == NULL || pEndTag == NULL){
		return ERROR_TAGS_NULL;
	}
	if (pDataToSearchThru == NULL){
		return ERROR_DATA_NULL;
	}
	myVector.clear();
	/*
	char *dataStart = pDataToSearchThru;
	char *dataEnd = pDataToSearchThru;
	for (unsigned int i = 0; i <strlen(pDataToSearchThru); ++i){
		dataEnd++;
	}
	*/

	bool foundStartTag = false;
	bool foundEndTag = false;
	std::string results;
	int startTagLength = strlen(pStartTag);
	int endTagLength = strlen(pEndTag);
	while(*pDataToSearchThru != '\0'){
		pDataToSearchThru++;
		if(*pDataToSearchThru == '<'){

			for(int i = 0; i < startTagLength; ++i){
				if (pDataToSearchThru[i] == pStartTag[i]){
					foundStartTag = true;
				}


			}

		}

		if (*pDataToSearchThru == '>'){
			pDataToSearchThru++;
			if (foundStartTag == true){
			while (*pDataToSearchThru != '<'){


				results += *pDataToSearchThru;
				pDataToSearchThru++;

			}
			if(*pDataToSearchThru == '<'){
				for(int i = 0; i < endTagLength; ++i){
					if (pDataToSearchThru[i] == pEndTag[i]){
						foundEndTag = true;
					}

				}

			}
			if (foundStartTag == true && foundEndTag == true){
				myVector.push_back(results);
			}

			foundStartTag = false;
			foundEndTag = false;
			results = "";


			}

		}



	}


	return SUCCESS;


}
void StringParserClass::cleanup(){
	if (pStartTag){
		delete[] pStartTag;
	}
	if (pEndTag){
		delete[] pEndTag;
	}
}

int StringParserClass::findTag(char *pTagToLookFor, char *&pStart, char *&pEnd){
	if (pStart == NULL || pEnd == NULL){
		return ERROR_TAGS_NULL;
	}
	/*
	while (!areTagsSet){
		if (*pStart == '<'){
			if (*pEnd == '>'){
				if (pStart++ == '/'){
					if (pStart++ == 't'){
						pStart++;
						if (pStart == 'o'){
								pStart = *pStart;
						}
					}
				}
				else if (pStart++ == 't'){
					pStart++;
					if (pStart == 'o'){
						pStart = *pStart;
					}
				}
				//test for to in the quotes between pStart and pEnd
			}
			pEnd--;
			continue;
		}
		pStart++;


	}
*/

	return SUCCESS;

}


//TODO Fill in
