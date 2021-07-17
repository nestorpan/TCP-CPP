#include <iostream>

#include "Algo.h"

using namespace std;


Algo::Algo(const string& nombre, const shared_ptr<Algo>& sig)
: nombre(nombre), sig(sig)
{}


Algo::~Algo()
{
	cout << "Se está destruyendo el objeto " << nombre << ".\n";
}


const string& Algo::getNombre() const
{
	return nombre;
}


const shared_ptr<Algo>& Algo::getSig() const
{
	return sig;
}


void Algo::setSig(const shared_ptr<Algo>& sig)
{
	this->sig = sig;
	this->sigWeak.reset();
}


void Algo::setSigWeak(const weak_ptr<Algo>& sigWeak)
{
	this->sig = nullptr;
	this->sigWeak = sigWeak;
}
