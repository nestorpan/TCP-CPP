#include <iostream>
#include "../SmartPointer/SmartPointer.h"
#include "../Cadena/Cadena.h"

using namespace std;


void funcion(SPtr<Cadena> sptr);


int main()
{
	SPtr<Cadena> sptr1(new Cadena("1234"));
	
	funcion(sptr1);
	
	cout << *sptr1 << endl;
	
	sptr1 = nullptr;
	
	cout << "Cadena convertida a int: " << sptr1->toInt() << endl;
	
	return 0;
}


void funcion(SPtr<Cadena> sptr)
{
	SPtr<Cadena> sptr3;
	
	sptr3 = sptr;
	
	cout << *sptr << endl;
}

