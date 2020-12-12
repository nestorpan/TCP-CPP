#include <iostream>
#include <memory>
#include <vector>

#include "PruebaSPtr.h"


using namespace std;


shared_ptr<PruebaSPtr> func();
void func2(shared_ptr<PruebaSPtr> sptr);


int main()
{
	shared_ptr<PruebaSPtr> ptr = func();
	
	cout << "PruebaSPtr devuelto por func: " << ptr->getNombre() << endl;
	
	cout << endl;
	cout << "Caso de referencia cíclica:" << endl;
	
	shared_ptr<PruebaSPtr> ptrCicl1(new PruebaSPtr("PepeCiclico1"));
	shared_ptr<PruebaSPtr> ptrCicl2(new PruebaSPtr("PepeCiclico2"));
	
	ptrCicl1->setOtro(ptrCicl2);
	ptrCicl2->setOtro(ptrCicl1);
	
//	ptrCicl1->setOtro(NULL);
	
	return 0;
}


shared_ptr<PruebaSPtr> func()
{
	vector<shared_ptr<PruebaSPtr> > vecSPtr;
	
	for(int i = 1; i <= 10; i++)
	{
		string nombre = string("Pepe") + to_string(i);
		vecSPtr.push_back(shared_ptr<PruebaSPtr>(new PruebaSPtr(nombre)));
	}
	
	return vecSPtr[5];
}


void func2(shared_ptr<PruebaSPtr> sptr)
{
	cout << "El nombre del objeto visto desde func2 es: " << sptr->getNombre() << endl;
}

