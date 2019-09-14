#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <fstream>

using namespace std;


class FileOut
{
private:
	filebuf fb;
	ostream os;
	
public:
	FileOut(char* path);
};

#endif // FILE_H
