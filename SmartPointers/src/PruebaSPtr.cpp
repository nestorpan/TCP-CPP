 #include <iostream>
#include "PruebaSPtr.h"


PruebaSPtr::PruebaSPtr(const string& nombre)
: nombre(nombre)
{}


PruebaSPtr::~PruebaSPtr()
{
	cout << "Se destruye el PruebaSPtr de nombre: " << this->nombre << endl;
}


const string& PruebaSPtr::getNombre()
{
	return this->nombre;
}


void PruebaSPtr::setOtro(shared_ptr<PruebaSPtr> otro)
{
	this->otro = otro;
}
