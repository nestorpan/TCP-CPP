#include "../Cadena/Cadena.h"
#include "../Persona/Alumno.h"
#include "ClaseDesconocidaException.h"
#include "Serializable.h"


map<Cadena, Serializable*> Serializable::objetos = {{Cadena("Alumno"), new Alumno()}};
//map<Cadena, Serializable*> Serializable::objetos = {{Cadena("Fecha"), new Fecha()}};


Serializable* Serializable::deserializarStatic(istream& is)
{
    Cadena nombreClase;
    nombreClase.deserializar(is);

    Serializable* objeto;

    try
    {
        objeto = objetos.at(nombreClase);
    }
    catch (const out_of_range& e)
    {
        throw ClaseDesconocidaException("Clase desconocida: " + nombreClase);
    }

    return objeto->deserializarDin(is);
}
