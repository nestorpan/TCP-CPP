#include "File.h"


FileOut::FileOut(const char* path)
{
	fb.open(path, ios::out);
	os.rdbuf(fb);
}
