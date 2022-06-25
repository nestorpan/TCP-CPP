#include "Alumno.h"


Alumno::Alumno(const Cadena& dni, const Cadena& nombre, const Cadena& apellido, const Fecha& fechaNacimiento, char sexo, int cantMatAprob, float promedio)
: Persona(dni, nombre, apellido, fechaNacimiento, sexo), cantMatAprob(cantMatAprob), promedio(promedio)
{}


int Alumno::getCantMatAprob() const
{
    return cantMatAprob;
}


void Alumno::setCantMatAprob(int cantMatAprob)
{
    this->cantMatAprob = cantMatAprob;
}


float Alumno::getPromedio() const
{
    return promedio;
}


void Alumno::setPromedio(float promedio)
{
    this->promedio = promedio;
}


void Alumno::imprimir() const
{
    Persona::imprimir();
    cout << "Cantidad de materias aprobadas: " << cantMatAprob << endl;
    cout << "Promedio: " << promedio << endl;
}


ostream& operator <<(ostream& sal, const Alumno& alumno)
{
    sal << (Persona&)alumno << '\t';
    sal << alumno.cantMatAprob << '\t';
    sal << alumno.promedio;
    return sal;
}


istream& operator >>(istream& is, Alumno& alumno)
{
    int cantMatAprob;
    float promedio;

    is >> (Persona&)alumno;
    
    is >> cantMatAprob;
    alumno.setCantMatAprob(cantMatAprob);

    is >> promedio;
    alumno.setPromedio(promedio);
    
    return is;
}
