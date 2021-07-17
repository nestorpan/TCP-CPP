#include <iostream>
#include <memory>
#include <vector>

#include "Algo.h"

using namespace std;

shared_ptr<Algo> crearAlgo(const string& nombre);


int main()
{
	shared_ptr<Algo> sptr1 = crearAlgo("Pepe"),	sptr2 = crearAlgo("Moni"), sptr3 = crearAlgo("Cocky");

	vector<shared_ptr<Algo> > vecAlgos;

	vecAlgos.push_back(sptr1);
	vecAlgos.push_back(sptr2);
	vecAlgos.push_back(sptr3);

	sptr1->setSig(sptr2);
	sptr2->setSig(sptr3);
	sptr3->setSigWeak(sptr1);

	//sptr1 = sptr2 = sptr3 = nullptr;
	//sptr3 = nullptr;

	//shared_ptr<Algo> cocky = vecAlgos.back();
	//vecAlgos.pop_back();

	for(vector<shared_ptr<Algo> >::iterator i = vecAlgos.begin(); i < vecAlgos.end(); i++)
		cout << "Nombre del objeto: " << (*i)->getNombre() << endl;

    return 0;
}


shared_ptr<Algo> crearAlgo(const string& nombre)
{
	return shared_ptr<Algo>(new Algo(nombre));
}
