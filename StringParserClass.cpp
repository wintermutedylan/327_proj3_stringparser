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
	std::string tagsToFind(pDataToSearchThru);



	//findTag(pStartTag, pDataToSearchThru)
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
	std::string tagsToFind(pTagToLookFor);


	return SUCCESS;

}


//TODO Fill in

