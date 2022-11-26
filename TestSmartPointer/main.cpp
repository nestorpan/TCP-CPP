#include <iostream>
#include "../SmartPointer/SmartPointer.h"
#include "../Cadena/Cadena.h"

using namespace std;


void funcion(SPtr<Cadena> sptr);


int main()
{
    Cadena* c = new Cadena("1234");
	SPtr<Cadena> sptr1(c);

	funcion(sptr1);

	cout << *sptr1 << endl;

	//sptr1 = nullptr;

	try {
        cout << "Cadena convertida a int: " << sptr1->toInt() << endl;
	}
	catch(const NullPointerException& e) {
	    cout << e.getMensaje() << endl;
	}

	SPtr<Cadena> sptr4 = sptr1;
    cout << *sptr1 << endl;

	return 0;
}


void funcion(SPtr<Cadena> sptr)
{
	SPtr<Cadena> sptr3 ;

	sptr3 = sptr;

	cout << *sptr << endl;
}
