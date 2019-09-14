#include "File.h"


File::File(const char* path)
{
	fb.open(path, ios::in | ios::out);
	
	ostream o(&fb);
	out = o;
	
	istream i(&fb);
	in = i;
}

