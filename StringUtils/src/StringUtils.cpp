#include <ctype.h>

#include "StringUtils.h"


string toLower(const string& str)
{
	string strL;

	for(string::const_iterator i = str.cbegin(); i < str.cend(); i++)
		strL.push_back(tolower(*i));

	return strL;
}
