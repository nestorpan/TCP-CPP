#include "ValidacionesException.h"

ValidacionesException::ValidacionesException()
{
    //ctor
}

ValidacionesException::ValidacionesException(const string& msj)
{
	this->mensaje = msj;
}


const string& ValidacionesException::getMensaje() const
{
	return this->mensaje;
}
